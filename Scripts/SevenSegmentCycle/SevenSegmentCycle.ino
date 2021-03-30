
int pins[] = {
  2,3,4, 5,6,7, 8,9
};

int pinCount = 8;

void flashPin(int pinNumber) {
  digitalWrite(pinNumber, HIGH);
  delay(250);
  digitalWrite(pinNumber, LOW);
  delay(250);
}

void flashSegment (int segmentIdx) {
  int segmentPinNumber = pins[segmentIdx];
  flashPin(segmentPinNumber);
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for(int i = 0; i < pinCount; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  for(int i = 0; i < pinCount; i++) {
    flashSegment(i);
  }
}