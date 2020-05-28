#include "DS1672.h"
#include <LiquidCrystal_attiny.h> 

#define GPIO_ADDR     0x3F
LiquidCrystal_I2C lcd(GPIO_ADDR, 16, 2); // set address & 16 chars / 2 lines

DS1672 ds1672;

//DateTime now(2020,5,28,9,41,0); //if you wanna set

DateTime test(0,0,0,0,0,0);
void setup() {
  // put your setup code here, to run once:
  TinyWireM.begin();
  lcd.init();                           // initialize the lcd
  lcd.backlight();                      
  lcd.print("DS1672");                  // Print a message to the LCD.
  
  pinMode(7, INPUT_PULLUP);
  
  //ds1672.set_time(now);       //if you wanna set
  
  test=ds1672.get_time();
  
  ds1672.enable();

}

char buffer[2]; // 0,1,2,3,4... needs to be 01,02,03,04...

void loop() {
  // put your main code here, to run repeatedly:

rightNow=ds1672.get_time();

if(rightNow.hour()<10){
  lcd.setCursor(4, 1);
  int n=sprintf(buffer,"0%d",rightNow.hour());
  lcd.print(buffer);
}else{
  lcd.setCursor(1, 1);
  lcd.print(rightNow.hour());
}
lcd.setCursor(3, 1);
lcd.print(':');

if(rightNow.minute()<10){
  lcd.setCursor(4, 1);
  int n=sprintf(buffer,"0%d",rightNow.minute());
  lcd.print(buffer);
}else{
  lcd.setCursor(4, 1);
  lcd.print(rightNow.minute());
}
lcd.setCursor(6, 1);
lcd.print(':');

if(rightNow.second()<10){
  lcd.setCursor(7, 1);
  int n=sprintf(buffer,"0%d",rightNow.second());
  lcd.print(buffer);
}else{
  lcd.setCursor(7, 1);
  lcd.print(rightNow.second());
}
delay(1000);
  
}
