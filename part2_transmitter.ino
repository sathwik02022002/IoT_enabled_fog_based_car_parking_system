#include "SoftwareSerial.h"

SoftwareSerial XBee(2,3);

int BUTTON = 7;

boolean toggle = false;

void setup()

{

  Serial.begin(9600);

  pinMode(BUTTON, INPUT);

  XBee.begin(9600);

}

void loop()

{

  if (digitalRead(BUTTON) == HIGH && toggle)

  {

    Serial.println("No empty slots");

    toggle = false;

    XBee.write('1');

    delay(1000);

  }

  else if (digitalRead(BUTTON) == LOW && !toggle)

  {

    Serial.println("Empty slot - S1");

    toggle = true;

    XBee.write('0');

    delay(1000); 

  }

}
