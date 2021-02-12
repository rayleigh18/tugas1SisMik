#include <Arduino.h>
#define PIN_LED PIN_A5
#define PIN_BUTTON 3
#define LOOP_PERIOD_IN_US 500000

void toggleLED();
bool lamp_state = 0;
bool last_button_state;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, lamp_state);
  
  attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), toggleLED, FALLING);
}



void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_LED, lamp_state);

}

void toggleLED(){
  lamp_state = !lamp_state;
  
}