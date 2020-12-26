#define pin 11
//int pin=11;
void setup() {
  // put your setup code here, to run once:
pinMode(pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int fade_value=0; fade_value<=255; fade_value+=5)
{
  analogWrite(pin,fade_value);
  delay(1000);
}
for(int fade_value1=255;fade_value1>=0;fade_value1-=5)
{ 
  analogWrite(pin,fade_value1);
  delay(1000);
}



}
