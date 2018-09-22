#define buzzer 9
#define mq2Sensor A0

// Your threshold value
int sensorThres = 400;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(mq2Sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(mq2Sensor);

  Serial.print("mq2Sensor Value: ");
  Serial.println(analogSensor);
  // cek jika nilai sensor melebihi treshold yang telah ditentukan
  if (analogSensor > sensorThres)
  {
    tone(buzzer, 1000, 200);
  }
  else
  {
    noTone(buzzer);
  }
  delay(100);
}
