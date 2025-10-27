#include <EEPROM.h>

#define segA 12
#define segB 11
#define segC 8
#define segD 7
#define segE 6
#define segF 10
#define segG 9
#define BUTTON 2
#define BLUE_LED 4
#define TIMER_DELAY 100 //in ms (1-250)

struct Settings {
  int magic_num;
  volatile int display_freeze;
  volatile int sensor_value;
};

Settings settings = {
  0, //Magic Num
  0, //Display state
  0, //Displayed sensor value
};

int timer_ticks = 0;
ISR(TIMER1_COMPA_vect) {
  OCR1A += timer_ticks;
  settings.sensor_value = map(analogRead(A5), 0, 1023, 0, 9);
}

void button_press() {
  settings.display_freeze = !settings.display_freeze;
  EEPROM.put(0, settings);
}

void setup() {
  pinMode(A5, INPUT);
  pinMode(BUTTON, INPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  
  EEPROM.get(0, settings);
  if (settings.magic_num == 35) {
    if (settings.display_freeze == 1) {
       display_value(settings.sensor_value);
    }
  } else {
    settings.magic_num = 35;
    settings.display_freeze = 0;
    settings.sensor_value = 0;
  }

  attachInterrupt(digitalPinToInterrupt(BUTTON), button_press, RISING);
  
  timer_ticks = 250000/(1000/TIMER_DELAY);
  TCCR1A = 0;           // Init Timer1
  TCCR1B = 0;           // Init Timer1
  TCCR1B |= B00000011;  // Prescalar = 64
  OCR1A = timer_ticks;  // Timer CompareA Register
  TIMSK1 |= B00000010;  // Enable Timer COMPA Interrupt
}

void loop() {
  if (settings.display_freeze == 0) {
    display_value(settings.sensor_value);
    digitalWrite(BLUE_LED, LOW);
  } else {
    digitalWrite(BLUE_LED, HIGH);
  }
}

void display_value(int val) {
  display_clear();
  switch (val) {
    case 0:
      display0();
      break;
    case 1:
      display1();
      break;
    case 2:
      display2();
      break;
    case 3:
      display3();
      break;
    case 4:
      display4();
      break;
    case 5:
      display5();
      break;
    case 6:
      display6();
      break;
    case 7:
      display7();
      break;
    case 8:
      display8();
      break;
    case 9:
      display9();
      break;
  }
}

void display_clear() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
}

void display1() {
  digitalWrite(segB,HIGH);
  digitalWrite(segC,HIGH);
}

void display2() {
  digitalWrite(segA,HIGH);
  digitalWrite(segB,HIGH);
  digitalWrite(segD,HIGH);
  digitalWrite(segE,HIGH);
  digitalWrite(segG,HIGH);
}

void display3() {
  digitalWrite(segA,HIGH);
  digitalWrite(segB,HIGH);
  digitalWrite(segC,HIGH);
  digitalWrite(segD,HIGH);
  digitalWrite(segG,HIGH);
}

void display4() {
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void display5() {
  digitalWrite(segA,HIGH);
  digitalWrite(segC,HIGH);
  digitalWrite(segD,HIGH);
  digitalWrite(segF,HIGH);
  digitalWrite(segG,HIGH);
}

void display6() {
  digitalWrite(segA, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
} 

void display7() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB,HIGH);
  digitalWrite(segC,HIGH);
}

void display8() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
} 

void display9() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
} 

void display0() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
} 
