/*
***********************Firmware de Nodo de Monitoreo*************************************
Version: 0.1 - Fecha: 26.04.2023 
Descripcion version: Inicial de desarrollo
Funcionalidades: Adquision y procesamiento de data sensores
                 Envio de trama de datos por serial
                 Recepcion de comandos por puerto serial desde interfaz externa
                 Soporte buzzer y led de alerta 
Salida datos serial:
nodoID | incX_deg | incY_deg | accX_g | accY_g | accZ_g | tBMP_degC | pBMP_Pa | hSoil_per | rain | alarm  
*****************************************************************************************
Codigo de procesamiento y adquicion de angulos basados en el proyecto: 
    -One-dimensional Kalman filter- de Carbon Aeronautics:
    https://github.com/CarbonAeronautics/Part-XV-1DKalmanFilter
Codigo de recepcion de comandos seriales basados en el proyecto:
    -Serial Port Windows Application Basic with Arduino- de Ta Luc Gia Hoang:
    https://github.com/TaLucGiaHoang/serial-port-win-app-basic
*****************************************************************************************
Autores: M. Reyes, I. Peralta, L. Quintanilla (Grupo 4 - curso LPOO - PUCP)
*****************************************************************************************
*/
#include <Wire.h>

#define MPU6050_ADDRESS 0x68 //Direccion i2c del sensor MPU6050 - 0x77 BMP180
#define BMP280_ADDRESS 0x76 //Direccion del 
#define PIN_LED_ALARM 7 // Led de alarma
#define PIN_BUZZER 11
#define PIN_HUM A0
#define PIN_RAI 12

uint8_t nodoID = 0; //Firmware soporta hasta 256 nodos de monitoreo
uint32_t serialTimer_ms = 500; //Tiempo de envio de datos por serial default 0.5 segundos
uint32_t buzzerTimer_ms = 1000;
uint32_t lastTimeSerial_ms = 0;
uint32_t lastTimeBuzzer_ms = 0;
bool mpu6050_OK, bmp280_OK = 0;
uint16_t freqBuzzer = 3000;
uint16_t durBuzzer = 400;


uint16_t dig_T1, dig_P1;
int16_t  dig_T2, dig_T3, dig_P2, dig_P3, dig_P4, dig_P5;
int16_t  dig_P6, dig_P7, dig_P8, dig_P9; 
float AltitudeBarometer, AltitudeBarometerStartUp;
double pressure;
float tempBMP;

float RateRoll, RatePitch, RateYaw;
float RateCalibrationRoll, RateCalibrationPitch, RateCalibrationYaw;
int RateCalibrationNumber;
float AccX, AccY, AccZ;
float AngleRoll, AnglePitch;
float KalmanAngleRoll=0, KalmanUncertaintyAngleRoll=2*2;
float KalmanAnglePitch=0, KalmanUncertaintyAnglePitch=2*2;
float Kalman1DOutput[]={0,0};

volatile int stateALRM = 0;   // Estado de la alarma (0 desactivado)
unsigned int count = 0;   // count to 15; interval timer (15 * 200 = 3000 ms) 
                          // to toggle LED and send UART
String inputString = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

typedef enum {
  PROCESS_ALRM_TURN_OFF = 0,  // LED on
  PROCESS_ALRM_TURN_ON,       // LED off
  PROCESS_NOT_SUPPORTED,      // Error
  PROCESS_SETID,
} process_type_def;

process_type_def process_id = PROCESS_NOT_SUPPORTED;

void setup() {
  Serial.begin(38400);
  Wire.setClock(400000);
  Wire.begin();
  delay(250);
  devicesCheckNode();
  delay(1000);
  pinMode(PIN_LED_ALARM, OUTPUT);
  digitalWrite(PIN_LED_ALARM, LOW);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_RAI, INPUT);
  inputString.reserve(200);
}
void loop() {
  if(mpu6050_OK){
    gyro_signals();
    RateRoll-=RateCalibrationRoll;
    RatePitch-=RateCalibrationPitch;
    RateYaw-=RateCalibrationYaw;
    kalman_1d(KalmanAngleRoll, KalmanUncertaintyAngleRoll, RateRoll, AngleRoll);
    KalmanAngleRoll=Kalman1DOutput[0]; 
    KalmanUncertaintyAngleRoll=Kalman1DOutput[1];
    kalman_1d(KalmanAnglePitch, KalmanUncertaintyAnglePitch, RatePitch, AnglePitch);
    KalmanAnglePitch=Kalman1DOutput[0]; 
    KalmanUncertaintyAnglePitch=Kalman1DOutput[1];
  }
  else{
    KalmanAngleRoll = 100;
    KalmanAnglePitch = 100;
  }  
  if(bmp280_OK){
    barometer_signals();
    AltitudeBarometer-=AltitudeBarometerStartUp;
  }
  else pressure = -1;
  uint16_t humSoilRaw = analogRead(PIN_HUM);
  bool rainRead = digitalRead(PIN_RAI);


  if (stringComplete) {
    // Receive a string from UART    
    process_id = processMessage(inputString);
      switch(process_id) {
        case PROCESS_ALRM_TURN_OFF: {stateALRM = 0; setAlarmNode(0); break;}
        case PROCESS_ALRM_TURN_ON: {stateALRM = 1; setAlarmNode(1); break;}
        case PROCESS_SETID: {nodoID = inputString.substring(6,9).toInt(); break;}
        default:{ /* PROCESS_NOT_SUPPORTED */ break;}
      }
    // Reset variables
    count = 0;  // reset counter
    process_id = PROCESS_NOT_SUPPORTED;
    inputString = "";  // clear the string:
    stringComplete = false;
  } 
 uint32_t currentTime_ms = millis();
  if ((currentTime_ms - lastTimeBuzzer_ms > buzzerTimer_ms) && (stateALRM == 1)){
    tone(PIN_BUZZER,freqBuzzer, durBuzzer);
    lastTimeBuzzer_ms = currentTime_ms;
  }
  if (currentTime_ms - lastTimeSerial_ms > serialTimer_ms){
    sendDataSerialPort(humSoilRaw, rainRead);
    lastTimeSerial_ms = currentTime_ms;
  } 
}

/*nodoID | incX_deg | incY_deg | accX_g | accY_g | accZ_g | tBMP_degC | pBMP_Pa | hSoilRaw | rain | alarm*/ 
void sendDataSerialPort(uint16_t humSoilRaw, bool rainDetected){
  Serial.print(nodoID);
  Serial.print(" ");
  Serial.print(KalmanAngleRoll);
  Serial.print(" ");
  Serial.print(KalmanAnglePitch);
  Serial.print(" ");
  Serial.print(AccX);
  Serial.print(" ");
  Serial.print(AccY);
  Serial.print(" ");
  Serial.print(AccZ);
  Serial.print(" ");
  Serial.print(tempBMP);  
  Serial.print(" ");
  Serial.print(pressure);
  Serial.print(" ");
  Serial.print(humSoilRaw);//por implementar humedad del terreno
  Serial.print(" ");
  Serial.print(rainDetected);//por implementar lluvia si=1/no=0
  Serial.print(" ");
  Serial.println(stateALRM);  
  
}
static void setAlarmNode(int stateALRM) {
  switch(stateALRM) {
    case 0: {
      digitalWrite(PIN_LED_ALARM, LOW);    // turn the LED off by making the voltage LOW
      noTone(PIN_BUZZER);
      break;
    }
    case 1: {
      digitalWrite(PIN_LED_ALARM, HIGH);   // turn the LED on (HIGH is the voltage level)
      break;
    }
    default: {
      break;  // keep previous stateALRM
    }
  }
}
static int processMessage(String text) { 
  if (text.startsWith("ALRM_off")) { return PROCESS_ALRM_TURN_OFF; } 
  else if (text.startsWith("ALRM_on")) { return PROCESS_ALRM_TURN_ON;  }
  else if(text.startsWith("setID")) { return PROCESS_SETID;}
  else { return PROCESS_NOT_SUPPORTED; }
}
/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
   
   if (inChar == '\n') {
      stringComplete = true;
    }
  }
}