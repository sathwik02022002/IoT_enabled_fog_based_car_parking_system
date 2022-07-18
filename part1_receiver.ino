#include <Printers.h>
#include <XBee.h>

#include<SoftwareSerial.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(2,3,4,5,6,7);

//int led = 7;

int received = 0;

int i;

SoftwareSerial XBee(12,13);

void setup() {
 

  Serial.begin(9600);
  delay(1000);
   lcd.begin(16,2);
  lcd.clear();
  lcd.print("   16 X 2 LCD   "); 

  XBee.begin(9600);
  

  //pinMode(led, OUTPUT);

}

void loop() {

  if (XBee.available() > 0) {

  received = XBee.read();
  lcd.clear();

    if (received == '1'){
      lcd.setCursor(0, 0);
    lcd.print("Vacant Slot :- ");
    lcd.setCursor(0, 1);
    lcd.print("S1 ");
    delay(1000);
    delay(1000);
    Serial.println("Slot Is Empty");
    delay(1000);

    //digitalWrite(led, HIGH);

    
  }
    else {
    lcd.setCursor(0, 0);
    lcd.print("Parking is full!!");
    lcd.setCursor(0, 1);
    lcd.print("No new car entry");
    delay(1000);
    delay(1000);
    Serial.println("Slot Is Full");
    delay(1000);
    //digitalWrite(led, LOW);
    


    }

}

}
