void OR(int);
void And(int);


void setup() {
  // put your setup code here, to run once:
pinMode (13, OUTPUT);
pinMode(10,INPUT);

pinMode(0,INPUT);
pinMode(5,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int a=digitalRead(10);
  int b=digitalRead(0);
  int c=digitalRead(5);
  if (c==HIGH){
    Or(a,b);
    
  }
  else{
    And(a,b);
  }
 
}
void And(int a, int b){
 if(a==HIGH && b ==HIGH){
    digitalWrite(13,HIGH);
    
  }
  else {
    digitalWrite(13,LOW);
  }
}
void Or(int a ,int b){
 if(b==HIGH || a== HIGH){
    digitalWrite(1,LOW);
    
  }
  else {
    digitalWrite(1,HIGH);
  }
}
