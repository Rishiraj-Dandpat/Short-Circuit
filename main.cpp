//C++
//
int redledpin=12;
int yellowledpin=7;
int greenledpin=4;
int pushbutton=2;
unsigned long nextlight=0;
unsigned long waitfor=2000;

void setup(){
  pinMode(redledpin, OUTPUT);
  pinMode(yellowledpin, OUTPUT);
  pinMode(greenledpin, OUTPUT);
  pinMode(pushbutton, INPUT);
}
void loop(){
  int signal=digitalRead(pushbutton);
  unsigned long now =millis();
  if (signal==HIGH){
    digitalWrite(redledpin, HIGH);
    digitalWrite(yellowledpin, LOW);
    digitalWrite(greenledpin, LOW);
  }else{
    if(now-nextlight>=waitfor){
      nextlight=now;
      if (digitalRead(greenledpin) == HIGH){
        digitalWrite(greenledpin, LOW);
        digitalWrite(yellowledpin, HIGH);
      }
      else if(digitalRead(yellowledpin) == HIGH){
        digitalWrite(yellowledpin, LOW);
        digitalWrite(redledpin, HIGH);
      }
      else{
        digitalWrite(greenledpin,HIGH);
        digitalWrite(redledpin, LOW);
      }
    }
  }
}
