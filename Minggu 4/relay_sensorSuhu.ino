int val;
int tempPin = A0;
int relayPin = 9;

void setup()
{
  pinMode(tempPin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(tempPin);
  float mv = ( val/1024.0)*5000; 
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;
  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();

  if(cel>25){
    digitalWrite(relayPin, LOW); //relay on
  }
  else{
    digitalWrite(relayPin, HIGH); //relay off
  }
  delay(1000);
}
