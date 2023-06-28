void devicesCheckNode(void){
  Serial.println("Revision de sensores i2c");
  byte error, address;
  int nDevices;
  Serial.println("Analizando ............");
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("Dispositivo i2c encontrado en la direccion 0x");
      if (address<16) Serial.print("0");
       Serial.println(address,HEX); 
      if (address == 104){
        Serial.println("MPU_6050 detectado - Calibrando Gyro");
        calibrateGyro();
        mpu6050_OK = 1;
      }
      if (address == 118){
        Serial.println("BMP280 detectado - Calibrando BMP");
        calibrateBMP280();
        bmp280_OK = 1;
      }
     
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Error desconocido en la direccion i2c 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("Ningun dispositivo i2c detectado");
Serial.println("**********Finalizada la revision de sensores i2c**********");
}
void calibrateGyro(void){
  Wire.beginTransmission(MPU6050_ADDRESS); 
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission(); 
  for (RateCalibrationNumber=0; RateCalibrationNumber<2000; RateCalibrationNumber ++) {
    gyro_signals();
    RateCalibrationRoll+=RateRoll;
    RateCalibrationPitch+=RatePitch;
    RateCalibrationYaw+=RateYaw;
    delay(1);
  }
  RateCalibrationRoll/=2000;
  RateCalibrationPitch/=2000;
  RateCalibrationYaw/=2000;
  RateCalibrationNumber=0;
}
void calibrateBMP280(void){
  Wire.beginTransmission(BMP280_ADDRESS);
  Wire.write(0xF4);
  Wire.write(0x57);
  Wire.endTransmission();   
  Wire.beginTransmission(BMP280_ADDRESS);
  Wire.write(0xF5); 
  Wire.write(0x14);
  Wire.endTransmission();   
  uint8_t data[24], i=0; 
  Wire.beginTransmission(BMP280_ADDRESS);
  Wire.write(0x88);
  Wire.endTransmission();
  Wire.requestFrom(BMP280_ADDRESS,24);      
  while(Wire.available()){
    data[i] = Wire.read();
    i++;
  }
  dig_T1 = (data[1] << 8) | data[0]; 
  dig_T2 = (data[3] << 8) | data[2];
  dig_T3 = (data[5] << 8) | data[4];
  dig_P1 = (data[7] << 8) | data[6]; 
  dig_P2 = (data[9] << 8) | data[8];
  dig_P3 = (data[11]<< 8) | data[10];
  dig_P4 = (data[13]<< 8) | data[12];
  dig_P5 = (data[15]<< 8) | data[14];
  dig_P6 = (data[17]<< 8) | data[16];
  dig_P7 = (data[19]<< 8) | data[18];
  dig_P8 = (data[21]<< 8) | data[20];
  dig_P9 = (data[23]<< 8) | data[22]; delay(250);
  for (RateCalibrationNumber=0; RateCalibrationNumber<2000; RateCalibrationNumber ++) {
    barometer_signals();
    AltitudeBarometerStartUp+=AltitudeBarometer;
    delay(1);
  }
  AltitudeBarometerStartUp/=2000;
  RateCalibrationNumber = 0;  
}

