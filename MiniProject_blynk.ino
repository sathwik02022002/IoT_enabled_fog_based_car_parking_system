#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLh9MyxLqj"
#define BLYNK_DEVICE_NAME "IR"
#define BLYNK_AUTH_TOKEN "BWcD1WfAoccuGff1mOkXwj32YgQKm5K5"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SPI.h>
#include <Ethernet.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Shash";
char pass[] = "shash1234";

int IR_sensor = D1;
WidgetLCD lcd(V0);
BlynkTimer timer;

void sensor1(){
  int count=0;
  int value = digitalRead(IR_sensor);
  if(value == HIGH){
     lcd.clear(); //Use it to clear the LCD Widget
     delay(2000);
//     lcd.setCursor(0,0);
     lcd.print(0,0,"S1 - Slot is empty"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
     delay(2000);
  }
  else{
     lcd.clear(); //Use it to clear the LCD Widget
     delay(2000);
//     lcd.clear();
     lcd.print(0,0,"Slots are full!!"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
     delay(2000);
  }  
}
void setup()
{
  pinMode(IR_sensor,INPUT);
  timer.setInterval(300L,sensor1);
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  sensor1();
//  delay(1000);
  timer.run();
}
