

int redLed = 12;
int greenLed = 11;
int smoke=9;



void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  pinMode(smoke, INPUT);
  pinMode(5, INPUT);


}

void loop() {
  int Sensor = digitalRead(smoke);
int sw=digitalRead(5);



  if (Sensor == HIGH )
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);

  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);

  }


}
