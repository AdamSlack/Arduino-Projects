// Seven Segment Counter
// PIN IDX PIN NUMBER
// /---46---\
// |        |
// 57       35
// |        |
//  ---68---  
// |        |
// 24       02
// |        |
// \---13---/    .79


int pins[] = {
  2,3,4, 5,6,7, 8,9
};

int ZERO_PIN_IDXS[] = {
  0, 1, 2, 5, 4, 3,
};
int ZERO_PIN_COUNT = 6;

int ONE_PIN_IDXS[] = {
  0, 3
};
int ONE_PIN_COUNT = 2;

int TWO_PIN_IDXS[] = {
 1, 2, 3, 4, 6
};
int TWO_PIN_COUNT = 5;

int THREE_PIN_IDXS[] = {
  4, 3, 6, 0, 1
};
int THREE_PIN_COUNT = 5;

int FOUR_PIN_IDXS[] = {
  5, 6, 3, 0,
};
int FOUR_PIN_COUNT = 4; 

int FIVE_PIN_IDXS[] = {
  4, 5, 6, 0, 1
};
int FIVE_PIN_COUNT = 5;

int SIX_PIN_IDXS[] = {
  4, 5, 6, 0, 1, 2
};
int SIX_PIN_COUNT = 6;

int SEVEN_PIN_IDXS[] = {
  4, 3, 0
};
int SEVEN_PIN_COUNT = 3;

int EIGHT_PIN_IDXS[] = {
  0, 1, 2, 3, 4, 5, 6
};
int EIGHT_PIN_COUNT = 7;

int NINE_PIN_IDXS[] = {
  0, 3, 4, 5, 6,
};
int NINE_PIN_COUNT = 5;

int pinCount = 8;

void flashPin(int pinNumber) {
  // Serial.print(pinNumber);
  digitalWrite(pinNumber, HIGH);
  delay(250);
  digitalWrite(pinNumber, LOW);
  delay(250);
};

void flashSegment (int segmentIdx) {
  int segmentPinNumber = pins[segmentIdx];
  flashPin(segmentPinNumber);
};

void flashSegments (int segmentIdxs[], int segmentCount) {
  for(int i = 0; i < segmentCount; i++) {
    int segmentPinNumber = pins[segmentIdxs[i]];
    digitalWrite(segmentPinNumber, HIGH);
  };
  delay(250);
  for(int i = 0; i < segmentCount; i++) {
    int segmentPinNumber = pins[segmentIdxs[i]];
    digitalWrite(segmentPinNumber, LOW);
  };
  delay(250);
}

void setup() {
  for(int i = 0; i < pinCount; i++) {
    pinMode(pins[i], OUTPUT);
  };
};

// the loop function runs over and over again forever
void loop() {
  flashSegments(ZERO_PIN_IDXS, ZERO_PIN_COUNT);
  flashSegments(ONE_PIN_IDXS, ONE_PIN_COUNT);
  flashSegments(TWO_PIN_IDXS, TWO_PIN_COUNT);
  flashSegments(THREE_PIN_IDXS, THREE_PIN_COUNT);
  flashSegments(FOUR_PIN_IDXS, FOUR_PIN_COUNT);
  flashSegments(FIVE_PIN_IDXS, FIVE_PIN_COUNT);
  flashSegments(SIX_PIN_IDXS, SIX_PIN_COUNT);
  flashSegments(SEVEN_PIN_IDXS, SEVEN_PIN_COUNT);
  flashSegments(EIGHT_PIN_IDXS, EIGHT_PIN_COUNT);
  flashSegments(NINE_PIN_IDXS, NINE_PIN_COUNT);
};