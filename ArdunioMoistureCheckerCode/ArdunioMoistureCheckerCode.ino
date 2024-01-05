
#include <Wire.h> 
//Import LCD Library (I2C)
#include <LiquidCrystal_I2C.h>
//Set Input Pins for moisture sensor
int sensorPin = A0;
int sensorValue = 0;
int percentValue = 0;
LiquidCrystal_I2C lcd(0x27,16,2);

//LCD setup
void setup() {                       
Serial.begin(9600);
lcd.init();
}

void loop() {
 //get value
 sensorValue = analogRead(sensorPin);
  percentValue = map(sensorValue, 1023, 200, 0, 100);
  lcd.setCursor(0, 0);
  lcd.print("  Soil Moisture ");
  lcd.setCursor(7, 1);
//print value
  lcd.print(percentValue);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}
