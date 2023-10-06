#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Practica LCD");
  delay(3000);
  lcd.clear();
}

void loop(){
  lcd.setCursor(2,0);
  lcd.print("Mi primer");
  lcd.setCursor(2,1);
  lcd.print("Proyecto :)");
  delay(2000);
  lcd.clear();
  
}