#include <Wire.h>
#include <L3G.h>

L3G gyro;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }

  gyro.enableDefault();
}

void loop() {
  gyro.read();

  int x_value = (int)gyro.g.x;
  int y_value = (int)gyro.g.y;

  if (x_value < -10000 || x_value > 10000 || y_value < -10000 || y_value > 10000) {
    Serial.println("¡Ha ocurrido un accidente!");
  }

  delay(100);
}
