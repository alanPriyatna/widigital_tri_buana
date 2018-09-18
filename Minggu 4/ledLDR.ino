#define ldrPin A0
#define ledPin 9

void setup() {
  // put your setup code here, to run once:
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilai= analogRead(ldrPin);
  Serial.print("Nilai LDR: ");
  Serial.println(nilai);
 
  if(nilai < 100){ //100 bisa diganti dengan nilai yang diinginkan
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  
}
