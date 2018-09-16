//cara lain memberi nama pada pin
#define led 9 
#define ldrSensor A0

void setup() {
  pinMode(led, OUTPUT);
  pinMode(ldrSensor, INPUT);
}

void loop() {
  int intensitasCahaya = map(analogRead(ldrSensor), 0, 1023, 0, 255); //untuk membaca nilai sensor LDR dan mapping ke rentangan nilai 0-255
  analogWrite(led, intensitasCahaya);
}
