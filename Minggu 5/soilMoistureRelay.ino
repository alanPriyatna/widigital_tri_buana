#define sensorPin A0
#define pumpPin 8
void setup() {
    // put your setup code here, to run once:
    pinMode(sensorPin, INPUT);
    pinMode(pumpPin, OUTPUT);
    Serial.begin(9600);
    Serial.println("SMART IRIGRATION PUMP");
    digitalWrite(pumpPin, HIGH);
}
void loop() {
    // put your main code here, to run repeatedly:
    int valSensor = analogRead(sensorPin);
    Serial.println(valSensor);
    if(valSensor >900){
        digitalWrite(pumpPin, LOW); //turn on the pump
    }else {
        digitalWrite(pumpPin, HIGH); //turn off the pump
    }
    delay(1000);
}
