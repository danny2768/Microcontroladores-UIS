int led = 13;
int sensor = A0;
int value;
float temperatureSensor;
float temperature;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}

void loop()
{
  temperatureSensor = analogRead(sensor);
  
  temperature = temperatureSensor / 1024; //find percentage of input reading
  temperature = temperature * 5;//multiply by 5V to get voltage
  temperature = temperature - 0.5;
  temperature = temperature * 100;
  
  Serial.println(temperature);
  
  if(temperature > 30)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}