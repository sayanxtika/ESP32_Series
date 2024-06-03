#include<NewPing.h>
#define thrs 1
int c1=15, c2=4, c3=32, trig=17, echo=16;
NewPing sensor(trig, echo);

void setup() {
  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(c3, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200); //baudrate of ESP32
}

void loop() {
  // put your main code here, to run repeatedly:
  int dist= sensor.ping_cm(); //inbuilt fuct for calculation of distance for ultrasonic
  Serial.println(dist);
  if(dist>0 && dist<=5)
  {
    digitalWrite(c1, HIGH);
    delay(1000);
    digitalWrite(c1, LOW);
    delay(1000);

  }
  else if(dist>5 && dist<=10)
  {
    digitalWrite(c2, HIGH);
    delay(1000);
    digitalWrite(c2, LOW);
    delay(1000);
  }
  else
  {
    digitalWrite(c3, HIGH);
    delay(1000);
    digitalWrite(c3, LOW);
    delay(1000);
  } 

}
