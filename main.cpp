//C++
//
int redledpin=12;//assigning red pin to 12
int yellowledpin=7;//assigning yellow pin to 7
int greenledpin=4;//assigning green pin to 4
int pushbutton=2;// assigning the push button to 2
unsigned long nextlight=0;
unsigned long waitfor=2000;

void setup(){
  pinMode(redledpin, OUTPUT);//setting outputs pins
  pinMode(yellowledpin, OUTPUT);
  pinMode(greenledpin, OUTPUT);
  pinMode(pushbutton, INPUT);// assigning onput
}
void loop(){
  int signal=digitalRead(pushbutton);//reading the high or low values of pushbutton
  unsigned long now =millis();//reading current time
  if (signal==HIGH){//reads if signal is high or low
    digitalWrite(redledpin, HIGH);
    digitalWrite(yellowledpin, LOW);
    digitalWrite(greenledpin, LOW);//if signal is high this all will be excuted
  }else{//if low the following codes run
    if(now-nextlight>=waitfor){//checks the interval of time and lights up led
      nextlight=now;//sets nextlight value to cureent millis
      if (digitalRead(greenledpin) == HIGH){//starts the light show from green
        digitalWrite(greenledpin, LOW);
        digitalWrite(yellowledpin, HIGH);
      }
      else if(digitalRead(yellowledpin) == HIGH){//second the yellow led lights up
        digitalWrite(yellowledpin, LOW);
        digitalWrite(redledpin, HIGH);
      }
      else{
        digitalWrite(greenledpin,HIGH);//red led ligts up
        digitalWrite(redledpin, LOW);
      }// finishes the codes
    }
  }
}
