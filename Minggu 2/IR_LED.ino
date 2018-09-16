#define LED_MODULE 9
#define IR_SENSOR A0

int lowBrightness = 1023, highBrightness = 0;

void fadeLED(int times, int delayTime) {
  for (int i = 0; i < times; i++) {
    for (int j = 0; j < 255; j += 5) {
      analogWrite(LED_MODULE, j);
      delay(delayTime);
    }
    for (int j = 255; j >= 0; j -= 5) {
      analogWrite(LED_MODULE, j);
      delay(delayTime);
    }
  }
}

void calibrate(int times) {
  for (int i = 0; i < times; i++) {
    int brightness = analogRead(IR_SENSOR);
    if (brightness <= lowBrightness) {
      lowBrightness = brightness;
    }
    if (brightness >= highBrightness) {
      highBrightness = brightness;
    }
    delay(10);
  }
}


void setup() {
  pinMode(LED_MODULE, OUTPUT);
  //Sekali kalibrasi akan memerlukan waktu selama 300*10 ms
  //Setelah menyalakan Arduino pada pertama kalinya, proses pertama yang dilakukan adalah kalibrasi selama 3 detik
  //tutup IR sensor dengan obyek yang akan ditentukan jaraknya untuk menentukan brightness tertinggi dan lepas untuk menentukan birghtness terendah
  calibrate(300);
}

void loop() {
  int distance;
  distance = map(analogRead(IR_SENSOR), lowBrightness, highBrightness, 30, 1);
  if (distance > 30) {
    distance = 30;
  }
  else if (distance < 1) {
    distance = 1;
  }
  fadeLED(1, distance);
}
