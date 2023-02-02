
#include <Servo.h>
#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

int colorR = 255;
int colorG = 48;
int colorB = 48;

Servo myservo;  

int val;    
int timer;
void setup() {
  myservo.attach(8);  
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.setCursor(0, 0);
}

void loop() {
while(digitalRead(7)==0)
{       
  lcd.clear();
  val = map(analogRead(A1), 0, 1023, 0, 180);    
  myservo.write(val); 
  lcd.print("the angle is ");
  lcd.print(map(analogRead(A1),0,1023,0,180));         
  lcd.setCursor(0,1);       
  timer = millis()/1000;
  lcd.print(timer); 
  lcd.print("s"); 
  lcd.print(" by knob"); 
  delay(66);
}
while(digitalRead(7)==1);
while(digitalRead(7)==0)
{      
   lcd.clear();
  val = map(analogRead(A3)*1, 0, 757, 0, 181);    
  myservo.write(val);
  lcd.print("the angle is ");
  lcd.print(map(analogRead(A3),0,757,0,181));      
  lcd.setCursor(0,1);   
  timer = millis()/1000;
  lcd.print(timer);   
  lcd.print("s"); 
  lcd.print(" by sensor");      
  delay(66);
}
while(digitalRead(7)==1);
                     
}
