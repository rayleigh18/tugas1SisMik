#include <Arduino.h>
#include "TimerOne.h"
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
  pinMode(PIN_BUTTON, INPUT);
  digitalWrite(PIN_LED, lamp_state);
  last_button_state = digitalRead(PIN_BUTTON);
  
  Timer1.initialize(LOOP_PERIOD_IN_US);
  Timer1.attachInterrupt(toggleLED);
}



void loop() {
  // put your main code here, to run repeatedly:

}

void toggleLED(){
  bool curr_button_state = digitalRead(PIN_BUTTON);
  if (curr_button_state != last_button_state && last_button_state == 0){
    lamp_state = !lamp_state;
    digitalWrite(PIN_LED, lamp_state);
  }  
  last_button_state = curr_button_state;
}