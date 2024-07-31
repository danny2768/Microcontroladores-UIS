#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int buzzer = 9;
LiquidCrystal_I2C lcd(0x20, 16, 2);

float temp1 = 0;
float temp2 = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  pinMode(12, INPUT); // Pulsador para esclavo 1
  pinMode(2, OUTPUT); // Led para esclavo 1

  pinMode(11, INPUT); // Pulsador para esclavo 2
  pinMode(3, OUTPUT); // Led para esclavo 2

  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Practica");
  lcd.setCursor(5, 1);
  lcd.print("I2C");
  delay(1000);
  lcd.clear();
}

void loop() {
  char tempChar[5];
  char tempeChar[5];// Declarar una cadena para almacenar los caracteres
  int i = 0;
  int esc = 0;
  
// Esclavo 1
  Wire.requestFrom(1, 5);
  while (Wire.available()) {
      char temp = Wire.read();
      tempChar[i] = temp;
      i++;
  
      //Serial.print(temp);

  }
  
        temp1 = atof(tempChar);
  
  if (digitalRead(12) == HIGH) {
    int esc = 1;
    printLcd(esc, temp1);
    shootBuzzer();
    
    digitalWrite(2, HIGH);
    delay(300);
    digitalWrite(2, LOW);
    delay(300);
  }
// Esclavo 2
  i=0;
  Wire.requestFrom(2, 5);
  while (Wire.available()) {
      char tempe = Wire.read();
      tempeChar[i] = tempe;
      i++;
  }
   
  temp2 = atof(tempeChar);
  
  Serial.println(temp2);
  
  if (digitalRead(11) == HIGH) {
    int esc = 2;
    printLcd(esc, temp2);
    shootBuzzer();
    
    digitalWrite(3, HIGH);
    delay(300);
    digitalWrite(3, LOW);
    delay(300);
        
  }

  shootBuzzerLCD();

  delay(500);
}

void shootBuzzer() {
  if (temp1 >= 30 || temp2 >= 30) {
    tone(buzzer, 1000);
    //printLcd();
  } else {
    noTone(buzzer);
  }
}

void shootBuzzerLCD() {
  if (temp1 >= 30 && temp2 >= 30) {
    lcd.setCursor(0, 0);
    lcd.print("Esclavo 1 y 2");
    lcd.setCursor(0, 1);
    lcd.print("ALARMA !!!!!!!");
    delay(1000);
    lcd.clear();
    tone(buzzer, 1000);
  } 
  if (temp1 < 30 && temp2 < 30) {
    noTone(buzzer);
    lcd.setCursor(0, 0);
    lcd.print("Temperatura");
    lcd.setCursor(0, 1);
    lcd.print("¡¡¡Segura!!");
    delay(1000);
    lcd.clear();
   }
  if (temp1 >= 30 || temp2 >= 30) {
    if (temp1 >= 30) {
      int esc = 1;
      tone(buzzer, 1000);
      printLcd(esc, temp1);
    }if (temp2 >= 30) {
      tone(buzzer, 1000);
      int esc = 2;
      printLcd(esc, temp2);
    } 
    
  }
}

void printLcd(int esclavo, float temp) {
  lcd.setCursor(1, 0);
  lcd.print("Esclavo: ");
  lcd.print(esclavo);
  lcd.setCursor(0, 1);
  lcd.print("Temp ");
  lcd.setCursor(6, 1);
  lcd.print(temp);
}