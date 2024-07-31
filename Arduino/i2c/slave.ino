//esclavo1
#include <Wire.h>
float temp;
char tempC[5];

void setup(){
  Wire.begin(1);                
  Wire.onRequest(EventoPeticion); 
  Serial.begin(9600);                             
  pinMode(7,OUTPUT); // Led
}

void loop(){
  temp=analogRead(A2);
  temp=(5.0*temp*100)/1024;
  temp = (temp-32)*5/9;
  
  EventoPeticion();
  
  dtostrf(temp, 3,2,tempC);
  Serial.println("Valor local");
  Serial.print(temp);
  Serial.println(" C");
  Serial.println("Valor TX");
  Serial.print(tempC);
  Serial.println(" C");
  delay(500);
}
void EventoPeticion(){
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(7, LOW);
  delay(100);
  Wire.write(tempC);
}
