//led modul dihubungkan pada pin 9
//pin 9 diberi nama "led"
int led = 9;

//pushButton modul dihubungkan pada pin 2
//pin 2 diberi nama "pushButton"
int pushButton = 2;

//fungsi setup() yang hanya dijalankan sekali
void setup() {
  //inisialisasi pin digital 9(led) sebagai output
  pinMode(led, OUTPUT);
  //inisialisasi pin digital 2(pushButton) sebagai input
  pinMode(pushButton, INPUT);
}

//fungsi loop() yang dijalankan terus-menerus selama arduino hidup
void loop() {
  int statusButton = digitalRead(pushButton); //membaca status pushbutton serta menyimpan nilainya pada variable statusButton
  
  //jika tombol ditekan (statusButton = HIGH), maka led menyala
  if(statusButton == HIGH){
    digitalWrite(led, HIGH);
  }
  else{ //kalau tombol tidak ditekan (statusButton = HIGH), maka led mati
    digitalWrite(led, LOW);
  }
}
