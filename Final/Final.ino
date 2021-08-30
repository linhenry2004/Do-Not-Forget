#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Stepper.h>

#define STEPS 200

Stepper stepper1(STEPS, 7, 5, 6, 4);
Stepper stepper2(STEPS, 12, 10, 11, 9);

LiquidCrystal_I2C lcd(0x3f,16,2);  

int hour;
int minute;
int second;

long hour_setting = 3600000;
long minute_setting = 60000;
long second_setting = 1000;
unsigned long start_time;

void setup()
{
  stepper1.setSpeed(160);
  stepper2.setSpeed(160);

  lcd.init(); 
  lcd.backlight();
}

void loop() {
  start_time = millis();

  Time();
  Rotate();
}

void Rotate () {
  if (hour == timeOne && minute == timeTwo) {
    simul(2048);
  } else if (hour == timeThree && minute == timeFour) {
    simul(2048);
  } else if (hour == timeFive && minute == timeSix) {
    simul(2048);
  }
}

void Time () {
  hour = start_time / hour_setting;
  minute = (start_time % hour_setting) / minute_setting;
  second = ((start_time % hour_setting) % minute_setting) / second_setting;

  String strhour = String(hour);
  String strmin = String(minute);
  String strsec = String(second);

  lcd.setCursor(4,0);
  if (hour < 10) {
    lcd.print("0");
    lcd.setCursor(5,0);
  }
  lcd.print(strhour + ":");
  lcd.setCursor(7,0);
  if (minute < 10) {
    lcd.print("0");
    lcd.setCursor(8,0);
  }
  lcd.print(strmin + ":");
  lcd.setCursor(10,0);
  if (second < 10) {
    lcd.print("0");
    lcd.setCursor(11,0);
  }
  lcd.print(strsec);  
}

void simul (int x) {
  bool positive = x > 0;
  if (positive){
    int i = 0;
    while (i < x){ 
      stepper1.step(1); 
      stepper2.step(-1); 
      i++;
    } 
  }
  if (!positive){
    int i = x;
    while (i > 0){
      stepper1.step(-1);
      stepper2.step(1);
      i--;
    }
  }
}
