#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

float temperatura =0;
float valor=0;
const int buzzer = 9;

void setup() {
    Serial.begin(9600);
    Serial.println("CONECTADO");
    pinMode(LED_BUILTIN,OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, INPUT);
    pinMode(buzzer, OUTPUT);
    delay(200);

    lcd.init();
    lcd.backlight();
    lcd.setCursor(3, 0);
    lcd.print("Practica");
    lcd.setCursor(0, 1);
    lcd.print("Temp Buzzer Lcd");
    delay(1000);
    lcd.clear();
}

void loop() {
    valor = analogRead(0);
    Serial.println("El valor analogico es: ");
    Serial.println(valor);
    temperatura=(5*valor*100)/1023;
    Serial.println("Latemperatura es: ");
    Serial.println(temperatura);

    lcd.setCursor(9,0);
    lcd.print(temperatura);
    lcd.setCursor(14,0);
    lcd.print((char)223);

    digitalWrite(7, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);

    if(digitalRead(8) == LOW){
        lcd.setCursor(2,1);
        lcd.print("No pulsado");   
        noTone(buzzer);
    }    

    if(temperatura >=20 && temperatura <26){
        lcd.setCursor(1,0);
        lcd.print("Normal");
        
        digitalWrite(7, HIGH);        
    }
    if(temperatura >=26 && temperatura <30){
        lcd.setCursor(1,0);
        lcd.print("Alerta");
        
        digitalWrite(7, HIGH);
        digitalWrite(6, HIGH);

        tone(buzzer, 1000, 100);
    }
    if(temperatura >=30){
        lcd.setCursor(1,0);
        lcd.print("Alarma");
        
        digitalWrite(7, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);

        tone(buzzer, 1000, 0);
    }

    if(digitalRead(8) == HIGH){
        lcd.setCursor(2,1);
        lcd.print("Pulsado   ");
        tone(buzzer, 1000);
    } 

    delay(1000);
}