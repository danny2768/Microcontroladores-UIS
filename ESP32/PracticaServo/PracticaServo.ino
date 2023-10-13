#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#include <Servo.h>
Servo servoMotor;

#include<Keypad.h>
const byte filas = 4;
const byte columnas = 3;
byte pinesF[filas] = {4,5,6,7};
byte pinesC[columnas] = {11,12,10};

char teclas [filas][columnas] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

Keypad teclado = Keypad(makeKeymap(teclas), pinesF, pinesC, filas, columnas);
char tecla;

String numeroIngresado = "";

void setup() {
  Serial.begin(9600);
  servoMotor.attach(9);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("Servo Teclado");
  lcd.setCursor(6, 1);
  lcd.print("LCD");
  delay(3000);
  lcd.clear();
}

void mostrarMensaje(String mensaje1, String mensaje2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(mensaje1);
  lcd.setCursor(0, 1);
  lcd.print(mensaje2);
}

void procesarAsterisco() {
  int numIngresado = numeroIngresado.toInt();

  if (numIngresado >= 0 && numIngresado <= 180) {
    servoMotor.write(numIngresado);
  } else if (numIngresado > 180) {
    mostrarMensaje("Ingresar numero", "entre 0 y 180");
  }
}

void limpiarNumeroIngresado() {
  numeroIngresado = "";
  mostrarMensaje("Numero parcial:", "");
}

void posicionInicialServo() {
  servoMotor.write(0);
}

void loop() {
  tecla = teclado.getKey();
  if (tecla != 0) {
    if (tecla == '*') {
      procesarAsterisco();
    } else if (tecla == '#') {
      limpiarNumeroIngresado();
      posicionInicialServo();
    } else {
      numeroIngresado += tecla;
      Serial.print(tecla);
      mostrarMensaje("Numero parcial:", numeroIngresado);
    }
  }
}
