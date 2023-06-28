void gyro_signals(void) {
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission();
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x1C);
  Wire.write(0x10);
  Wire.endTransmission();
  Wire.beginTransmission(MPU6050_ADDRESS);

  Wire.write(0x3B);
  Wire.endTransmission(); 
  Wire.requestFrom(MPU6050_ADDRESS,6);
  int16_t AccXLSB = Wire.read() << 8 | Wire.read();
  int16_t AccYLSB = Wire.read() << 8 | Wire.read();
  int16_t AccZLSB = Wire.read() << 8 | Wire.read();
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x1B); 
  Wire.write(0x8);
  Wire.endTransmission();     
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(MPU6050_ADDRESS,6);
  int16_t GyroX=Wire.read()<<8 | Wire.read();
  int16_t GyroY=Wire.read()<<8 | Wire.read();
  int16_t GyroZ=Wire.read()<<8 | Wire.read();
  RateRoll=(float)GyroX/65.5;
  RatePitch=(float)GyroY/65.5;
  RateYaw=(float)GyroZ/65.5;
  AccX=(float)AccXLSB/4096-0.02;//offset X de calibracion del Acelerometro
  AccY=(float)AccYLSB/4096+0.01;//offset Y de calibracion del Acelerometro
  AccZ=(float)AccZLSB/4096+0.11;//offset Z de calibracion del Acelerometro
  AngleRoll=atan(AccY/sqrt(AccX*AccX+AccZ*AccZ))*1/(3.142/180);
  AnglePitch=-atan(AccX/sqrt(AccY*AccY+AccZ*AccZ))*1/(3.142/180);
}
void barometer_signals(void){
  Wire.beginTransmission(0x76);
  Wire.write(0xF7);
  Wire.endTransmission();
  Wire.requestFrom(0x76,6);
  uint32_t press_msb = Wire.read();
  uint32_t press_lsb = Wire.read();
  uint32_t press_xlsb = Wire.read();
  uint32_t temp_msb = Wire.read();
  uint32_t temp_lsb = Wire.read();
  uint32_t temp_xlsb = Wire.read();
  uint32_t adc_P = (press_msb << 12) | (press_lsb << 4) | (press_xlsb >>4);
  int32_t adc_T = (temp_msb << 12) | (temp_lsb << 4) | (temp_xlsb >>4);
  int32_t var1, var2;

  var1 = ((((adc_T >> 3) - ((int32_t)dig_T1 << 1))) * ((int32_t)dig_T2)) >> 11;
  var2 = (((((adc_T >> 4) - ((int32_t)dig_T1)) * ((adc_T >> 4) - ((int32_t)dig_T1))) >> 12) * ((int32_t)dig_T3)) >> 14;
  int32_t t_fine = var1 + var2;
  tempBMP =(float)((t_fine * 5 + 128) >> 8)/100.0;

  uint32_t p;
  var1 = (((int32_t)t_fine)>>1) - (int32_t)64000;
  var2 = (((var1>>2) * (var1>>2)) >> 11) * ((int32_t)dig_P6);
  var2 = var2 + ((var1*((int32_t)dig_P5)) <<1);
  var2 = (var2>>2)+(((int32_t)dig_P4)<<16);
  var1 = (((dig_P3 * (((var1>>2)*(var1>>2)) >> 13))>>3)+((((int32_t)dig_P2) * var1)>>1))>>18;
  var1 = ((((32768+var1))*((int32_t)dig_P1)) >>15);
  if (var1 == 0) { p=0;}    
  p = (((uint32_t)(((int32_t) 1048576)-adc_P)-(var2>>12)))*3125;
  if(p<0x80000000){ p = (p << 1) / ((uint32_t) var1);}
  else { p = (p / (uint32_t)var1) * 2;  }
  var1 = (((int32_t)dig_P9) * ((int32_t) (((p>>3) * (p>>3))>>13)))>>12;
  var2 = (((int32_t)(p>>2)) * ((int32_t)dig_P8))>>13;
  p = (uint32_t)((int32_t)p + ((var1 + var2+ dig_P7) >> 4));
  pressure =(double)p/100;
}