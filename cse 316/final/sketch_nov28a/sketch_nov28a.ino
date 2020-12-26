#include<LiquidCrystal.h>

LiquidCrystal lcd(12 , 11 , 5 , 4 , 3 , 2);
int Gas = 9;
int redLed = 7;
int greenLed = 6;

void setup() {

  pinMode(Gas , INPUT);
    pinMode(13 , INPUT);

}

void loop() {
int sw= digitalRead(13);
if(sw == HIGH){
  if (digitalRead(Gas) == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("Gas Detected");
    digitalWrite(7 , HIGH);
    digitalWrite(6, LOW);
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("No Gas Detected");
    digitalWrite(6, HIGH);
    digitalWrite(7 , LOW);
  }
  delay(500);
  lcd.clear();
}

else{
   digitalWrite(7 , LOW);
 digitalWrite(6, LOW);
  
}

}
