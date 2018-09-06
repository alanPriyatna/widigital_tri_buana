//led modul dihubungkan pada pin 9
//pin 9 diberi nama "led"
int led = 9;

//fungsi setup() yang hanya dijalankan sekali
void setup() {
  //inisialisasi pin digital 9(led) sebagai output
  pinMode(led, OUTPUT);
}

//fungsi loop() yang dijalankan terus-menerus selama arduino hidup
void loop() {
  digitalWrite(led, HIGH); //led on
  delay(1000);
  digitalWrite(led, LOW); //led off
  delay(1000);
}
