#include<Keypad.h>
const byte filas = 4;
const byte columnas = 4;
byte pinesF[filas] = {8,9,10,11};
byte pinesC[columnas] = {7,6,5,4};

char teclas [columnas][filas] = {
    {'1','2','3', 'A'},
    {'4','5','6', 'B'},
    {'7','8','9', 'C'},
    {'*','0','#', 'D'}
};

Keypad teclado = Keypad(makeKeymap(teclas), pinesF, pinesC, filas, columnas);
char tecla;

void setup() {
    Serial.begin(9600);
}

void loop() {
    tecla = teclado.getKey();
    if (tecla != 0) {
        Serial.print(tecla);
    }
}