/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
    
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
const int trigPin = 8;
const int echoPin = 7;
long duration;
int distance;


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

SoftwareSerial SerialBLE(10, 11); // RX, TX

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void bacaDataJarak()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
  Blynk.virtualWrite(V5,distance);
  Serial.println(distance);
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");

  timer.setInterval(1000L, bacaDataJarak);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
