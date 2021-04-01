#include <IRremote.h>

#define IR_INPUT_PIN 2

#define RED_PIN 7
#define GREEN_PIN 6
#define BLUE_PIN 5
#define NUM_KEY_VALUES_LENGTH 12
#define LED_OPERATIONS_COUNT 4

#include "TinyIRReceiver.cpp.h"

typedef void (*GeneralFunction) ();

uint8_t numKeyValues[] = { 22, 12, 24, 94, 8, 28, 90, 66, 82, 74 };
uint8_t selectedOperation = 0;
boolean needToRunLedOp = true;

int8_t findIdx(uint8_t integerArray[], uint8_t valueToFind) {
  for(uint8_t idx = 0; idx < NUM_KEY_VALUES_LENGTH; idx++) {
    if(integerArray[idx] == valueToFind) {
      return idx;
    }
  }
  return -1;
}

void flashPin(uint8_t pinNumber) {
  digitalWrite(pinNumber, HIGH);
  delay(250);
  digitalWrite(pinNumber, LOW);
};

void flashRGB() {
  flashPin(BLUE_PIN);
  flashPin(GREEN_PIN);
  flashPin(RED_PIN);
}

void lightRed() {
  Serial.println("Lighting Red");
  digitalWrite(BLUE_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(RED_PIN, HIGH);
  needToRunLedOp = false;
}

void lightBlue() {
  Serial.println("Lighting Blue");
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  needToRunLedOp = false;
}

void lightGreen() {
  Serial.println("Lighting Green");
  digitalWrite(BLUE_PIN, LOW);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  needToRunLedOp = false;
}

GeneralFunction ledOperations[] = {
  flashRGB,
  lightRed,
  lightBlue,
  lightGreen,
};

void setup(){
  Serial.begin(115200);
  initPCIInterruptForTinyReceiver();
}

void loop(){
  if(needToRunLedOp) {
    ledOperations[selectedOperation]();
  }
}

void handleReceivedTinyIRData(uint16_t aAddress, uint8_t aCommand, bool isRepeat) {
  int8_t ledOperationIdx = findIdx(numKeyValues, aCommand);
  if(ledOperationIdx == -1) {
    Serial.println("ERROR: OP CODE NOT FOUND");
  }
  else if(ledOperationIdx >= LED_OPERATIONS_COUNT) {
    Serial.println("ERROR: NO OPERATION ASSIGNED");
  }
  else {
    selectedOperation = ledOperationIdx;
    needToRunLedOp = true;
  }
}