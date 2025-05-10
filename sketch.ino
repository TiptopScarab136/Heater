#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

#define wire 12
#define lcdAdd 0x27
#define lcdCol 20
#define lcdLines 4
#define potValue A1
#define idle 11
#define heating 10
#define stabilizing 9
#define target 8
#define overled 7
#define overbuzz 6
#define start 5
#define heat 1

LiquidCrystal_I2C lcd(lcdAdd, lcdCol, lcdLines);
OneWire oneWire(wire);
DallasTemperature sensors(&oneWire);

int set = 0;

void setup() {
  pinMode(5, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(3, INPUT);
  lcd.init();
  lcd.backlight();
  sensors.begin();
  Serial.begin(9600);
}

void loop() {
  sensors.requestTemperatures();
  float temperature = analogRead(potValue) / 1023.0 * 100.0;
  int rounded = ceil(temperature);
  lcd.setCursor(0, 0);
  lcd.print(rounded);
  int tempreal = ceil(sensors.getTempCByIndex(0));


  if(digitalRead(start) == 0){
    digitalWrite(idle, HIGH);
    digitalWrite(heating, LOW);
    digitalWrite(stabilizing, LOW);
    digitalWrite(target, LOW);
    digitalWrite(overled, LOW);
    digitalWrite(overbuzz, LOW);
    digitalWrite(heat, LOW);
    Serial.println("Idle");
  }

  else{
    if(rounded>tempreal){
      set = 0;
      digitalWrite(idle, LOW);
      digitalWrite(heating, HIGH);
      digitalWrite(stabilizing, LOW);
      digitalWrite(target, LOW);
      digitalWrite(overled, LOW);
      digitalWrite(overbuzz, LOW);
      if(rounded>tempreal){
        digitalWrite(heat, HIGH);
      }
      else{
        digitalWrite(heat, LOW);
      }
      Serial.println("Heating...");
    }
    else if(rounded == tempreal){
      if(set == 1){
        goto jmp;
      }
      digitalWrite(idle, LOW);
      digitalWrite(heating, LOW);
      digitalWrite(stabilizing, HIGH);
      digitalWrite(target, LOW);
      digitalWrite(overled, LOW);
      digitalWrite(overbuzz, LOW);
      Serial.println("Stabilizing...");
      delay(3000);
      if(rounded>tempreal){
        digitalWrite(heat, HIGH);
      }
      else{
        digitalWrite(heat, LOW);
      }
      delay(3000);
      if(rounded>tempreal){
        digitalWrite(heat, HIGH);
      }
      else{
        digitalWrite(heat, LOW);
      }
      jmp:
      digitalWrite(stabilizing, LOW);
      digitalWrite(target, HIGH);
      Serial.println("Target Reached...");
      set = 1;
    }
    else{
      digitalWrite(idle, LOW);
      digitalWrite(heating, LOW);
      digitalWrite(stabilizing, LOW);
      digitalWrite(target, LOW);
      digitalWrite(overled, HIGH);
      digitalWrite(overbuzz, HIGH);
      Serial.println("Overheating!!!");
    }
  }
}