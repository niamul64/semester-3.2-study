#include<LiquidCrystal.h>   // LCD header
#include<Servo.h>          // Servo header

void switching_off_the_Gas();//function prototype
void switching_ON_the_Gas();//function prototype

Servo Motor; // motor object
int angle = 1; // motor angle variable
int gasOn ; // switch
int sw; // switch

LiquidCrystal lcd(12 , 11 , 5 , 4 , 3 , 2); // Crystal display setup
int Gas = 9;  // gas High/Low comes in
int redLed = 7;
int greenLed = 6;
int gasOnSW = 8; ///// manually off gas On gas switch


void setup() {

  Motor.attach(10);   // attach the signal pin of servo to pin10 of arduino
  pinMode(Gas , INPUT); // gas High/Low
  pinMode(13 , INPUT); // system switch
  pinMode(gasOnSW , INPUT);// gas on/off switch

  pinMode(6 , OUTPUT);//for green LED
  pinMode(7 , OUTPUT);//for red LED

}

void loop() {
  sw = digitalRead(13); /// system switch
  gasOn = digitalRead(8); /// manually off gas On gas switch



  if (sw == HIGH) { // system switch On


    if (gasOn == LOW && angle != 0 ) { /// manually off the gas
      switching_off_the_Gas(); //calling function to turn off the gas
    }

    if (digitalRead(Gas) == HIGH) { ///if gas detected
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Gas Detected");
      delay(25);
      digitalWrite(7 , HIGH); // red led ON
      digitalWrite(6, LOW);
      delay(25);
      if (angle != 0) { // if the gas is not off
        switching_off_the_Gas(); // if the gas is not off then colling function to switch off the gas
      }

    } ///if gas detected

    else {  ///if not gas detected
      lcd.setCursor(0, 0);
      lcd.print("No Gas Detected");
      delay(20);
      digitalWrite(6, HIGH);
      digitalWrite(7 , LOW);
      if (angle != 90 && gasOn == HIGH ) { // if the gas is off and situation is safe and want to On the gas
        switching_ON_the_Gas(); //calling function to switch ON the gas
      }

    } ///if not gas detected

  }

  else { // when the system is off
    digitalWrite(7 , LOW);
    digitalWrite(6, LOW);
    lcd.clear();
  }
}// end of void loop



void switching_off_the_Gas() {// function to turn off the gas


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("switching off gas");
  delay(20);
  for (angle = 90; angle >= 0; angle -= 1) // command to move from 90 degrees to 0 degrees
  {
    Motor.write(angle);
    delay(20);
  }
  angle = 0;
  Motor.write(angle);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("gas off now");
  delay(20);
}



void switching_ON_the_Gas() {// function to turn ON the gas

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("switching ON gas");
  delay(20);
  for (angle = 0; angle <= 90; angle += 1) // command to move from 0 degrees to 90 degrees
  {
    Motor.write(angle);                    //command to rotate the servo to the specified angle
    delay(20);
  }
  angle = 90;
  Motor.write(angle);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("gas ON now");
  delay(15);

}
