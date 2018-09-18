#include<dht.h>
#define dhtPin A0
#define buzzerPin 9
dht DHT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  DHT.read11(dhtPin);
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity);
  Serial.println("%");
  Serial.print("Temperature: ");
  Serial.print(DHT.temperature);
  Serial.println(" 'C");

  if(DHT.humidity < 60 && DHT.temperature > 30){
    tone(buzzerPin, 1000); 
    delay(1000);       
    noTone(buzzerPin);    
    delay(1000);        
  }
  else{
    noTone(buzzerPin);
  }
}
