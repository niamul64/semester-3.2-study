void serially(); //function prototype
void lightUp(); //function prototype
void lightDown(); //function prototype

void blink_blink();//function prototype
void allFunc();//function prototype
void upDownFunc();//function prototype
void turnOffAll();//function prototype

void setup() {     //void setup start
  pinMode(13, INPUT); // pin 13 for input
  pinMode(12, OUTPUT);// pin 12 for input
  pinMode(11, OUTPUT);// pin 11 for input
  pinMode(10, OUTPUT);// pin 10 for input
  pinMode(9, OUTPUT);// pin 9 for input
  pinMode(8, OUTPUT);// pin 8 for input
  pinMode(7, OUTPUT);// pin 7 for input
  pinMode(6, OUTPUT);// pin 6 for input
  pinMode(5, OUTPUT);// pin 5 for input
  pinMode(4, OUTPUT);// pin 4 for input
  pinMode(3, OUTPUT);// pin 3 for input
  pinMode(2, OUTPUT);// pin 2 for input
  pinMode(1, OUTPUT);// pin 1 for input
  pinMode(0, INPUT);// pin 0 for input
}                 //void setup end

void loop() {     //void loop start
  int Switch = digitalRead(13); // system switch input
  int Func = digitalRead(0); // functionallity changing switch
  if (Switch == HIGH) { // if system switch  ON
    if (Func == HIGH) { //if functionallity changing switch is ON, show up/down lighting functionality
      upDownFunc(); // calling function to show a lighting functionality
    }
    else {// else, show 2nd lighting functionality
      allFunc(); // calling function to show a lighting functionality
    }
  }
  else { // if system switch  Off
    turnOffAll();
  }

}                  //void loop end


void allFunc() {   //allFunc start
  blink_blink();
  lightUp();
  lightDown();
  blink_blink();
  serially();
  blink_blink();

}                  //allFunc end

void upDownFunc() { //upDownFunc start
  lightUp();
  lightDown();
}                  //upDownFunc end

void blink_blink() {
  delay(200);
  for (int i = 0; i < 2; i++) {
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(1, HIGH);
    delay(200);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    digitalWrite(1, LOW);
    delay(200);
  }
  delay(200);
}

void lightUp() {
  for (int i = 1; i < 13; i++)
  {
    digitalWrite(i, HIGH);
    delay(100);
  }
  for (int i = 12; i > 0; i--)
  {
    digitalWrite(i, LOW);
    delay(100);
  }
}

void lightDown() {
  for (int i = 12; i > 0; i--)
  {
    digitalWrite(i, HIGH);
    delay(100);
  }
  for (int i = 1; i < 13; i++)
  {
    digitalWrite(i, LOW);
    delay(100);
  }
}

void serially() {
  delay(120);
  for (int i = 1 ; i < 13; i++)
  {
    digitalWrite(i, HIGH);
    digitalWrite(13 - i, HIGH);
    delay(150);
    digitalWrite(i, LOW);
    digitalWrite(13 - i, LOW);
  }
  delay(120);
}
void turnOffAll() {
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  digitalWrite(1, LOW);
}
