/*
 Basic functions for the reading of temperature sensors

 There is one on the board and one (optional) off the board
*/


//Read the on board TMP102 digital temperature sensor
//Return celsius
//Code comes from bildr
float getLocalTemperature()
{
  Wire.requestFrom(tmp102Address, 2);

  byte MSB = Wire.read();
  byte LSB = Wire.read();

  //It's a 12bit int, using two's compliment for negative
  int TemperatureSum = ((MSB << 8) | LSB) >> 4;

  float celsius = TemperatureSum * 0.0625;
  return celsius;
}

//Read the remote DS18B20 sensor
//Return celsius
//Code comes from PJRC: http://www.pjrc.com/teensy/td_libs_OneWire.html
