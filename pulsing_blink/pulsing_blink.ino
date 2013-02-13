const int LED = 9;
int i = 0;

void setup() {
  pinMode(LED, OUTPUT);
}


void setLEDBrightness(int brightness) {
  analogWrite(LED, brightness);
  delay(10);
}

void loop() {
  for (i = 0; i < 255; i++) {
    setLEDBrightness(i);
  }
  
  for (; i > 0; i--) {
    setLEDBrightness(i);
  }
}

