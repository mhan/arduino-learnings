const int BUTTON = 7;
const int LED = 9;

unsigned long start_time = 0;

int current_brightness = 0;

boolean did_press = false;
boolean did_hold = false;
boolean on = false;

void setup() {
    pinMode(BUTTON, INPUT);
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
}

// Prevent oscillations in the switch pins from triggering the logic
int debounceButton() {
  delay(10);
  return digitalRead(BUTTON);
}

void toggleLED() {
  current_brightness = (on ? 0 : 255);
  analogWrite(LED, current_brightness);
  on = !on;
}

void loop() {
  int current_time = millis();
  if (debounceButton()) {
    did_press = true;
    if (start_time == 0) start_time = current_time;
    
    did_hold = (current_time - start_time) > 500;
    if (did_hold) {
      if (++current_brightness > 255) {
        current_brightness = 0;
        on = false;
      }
      else {
        on = true;
      }
      analogWrite(LED, current_brightness);
    }
  }
  else {
    if (did_press) {
      if (!did_hold) {
        toggleLED();
      }
      start_time = 0;
    }
    did_press = false;
  }
}
