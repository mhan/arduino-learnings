const int LED = 9;
const int BUTTON = 7;
const int ON = 1;
const int OFF = 0;

int state = OFF;

boolean is_pressed = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  if (digitalRead(BUTTON)) {
    is_pressed = true;
  }
  else {
    if (is_pressed) {
      delay(10);
      is_pressed = false;
      
      state = !state;
      
      if (state == OFF) {
        digitalWrite(LED, LOW);
      }
      else {
        digitalWrite(LED, HIGH);
      }
    }
  }
}
