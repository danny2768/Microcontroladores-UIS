
const int Ptrig = 8;
const int Pecho = 9;

void setup() {
    Serial.begin(9600);
    Serial.println("CONECTADO");
    
    pinMode(Ptrig, OUTPUT);
    pinMode(Pecho, INPUT);

    delay(200);
}

void loop() {
    int getDistance() {
        digitalWrite(Ptrig, LOW);
        delayMicroseconds(2);
        digitalWrite(Ptrig, HIGH);
        delayMicroseconds(10);
        digitalWrite(Ptrig, LOW);

        int duration = pulseIn(Pecho, HIGH);
        int distance = duration * 0.034 / 2;

        return distance;
    }

    void sendDistance() {
        int distance = getDistance();
        Serial.println(distance + "cm");
    }


}
