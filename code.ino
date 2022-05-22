
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
Servo servo1;
int pos=120;


const int trigPin = 13;  
const int echoPin = 12;  

const int relay = 10; 

long duration;
int distance;
int safetyDistance;

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(relay, OUTPUT);
  servo1.attach(9);
  servo1.write(0);
  Serial.begin(9600); 
}


void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  safetyDistance = distance;
  if (safetyDistance <= 10) {
    digitalWrite(relay, HIGH);
    
    servo1.write(150);
    
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("WELCOME");
    lcd.setCursor(6,1);
    lcd.print("!!!!");

    
    delay(5400);
    servo1.write(0);
  }
  else {
    digitalWrite(relay, LOW);
    lcd.clear();
    lcd.setCursor(255,0);
    lcd.print("PLACE HAND HERE");
    lcd.setCursor(6,1);
    lcd.print("!!!!");
    
  }
Serial.print("Distance: ");
Serial.println(distance);
}
}
