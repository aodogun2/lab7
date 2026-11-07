#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int analogPin = A0;
const float R1 = 330.0; 
const float R2 = 330.0;
const float R3 = 10000.0; //10k

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Voltage Measurement");
  delay(1000);
  lcd.clear();
}

void loop() {
  int analogVal = analogRead(analogPin);
  float total = R1 + R2 + R3;
  float vOut = (analogVal * 5.0) / 1024.0;
  
  float vIn = vOut * (total / R3);

  lcd.setCursor(0, 0);
  lcd.print("Volts: ");
  lcd.print(vIn);
  lcd.print(" V  ");

  delay(500);
}