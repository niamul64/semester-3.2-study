#define pin 11
//int pin=11;
void setup() {
Serial.begin(9600);
pinMode(pin,OUTPUT);

}

void loop() {
int incoming;
digitalWrite(pin,HIGH);
    delay(2000);
if(Serial.available()){
  incoming=Serial.read();
  incoming-=48;
  if(incoming==0){
    digitalWrite(pin,HIGH);
 
  }
  else if(incoming==1){
    digitalWrite(pin,LOW);
    Serial.print("Hello world");
   

   
  }
  }
 




}
