#include <Arduino.h>
#define PIN_LED PIN_A5
#define PIN_BUTTON 3
#define LOOP_PERIOD_IN_MS 500

bool lamp_state = 0;
bool curr_button_state;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  digitalWrite(PIN_LED, lamp_state);
  curr_button_state = digitalRead(PIN_BUTTON);
}

void loop() {
  // put your main code here, to run repeatedly:

  do{
    curr_button_state = digitalRead(PIN_BUTTON);
  }while (curr_button_state != 0);

  do{
    curr_button_state = digitalRead(PIN_BUTTON);
  }while (curr_button_state != 1);

  // proses
  lamp_state = !lamp_state;
  digitalWrite(PIN_LED, lamp_state);  
  
}