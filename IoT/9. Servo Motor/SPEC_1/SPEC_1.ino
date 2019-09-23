#include <Servo.h>
Servo srv;
int angle = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  srv.attach(3);
}

static unsigned long tickStarted;
int motorLoop = 10;
int motorDelay = 20;
void loop() {
  // put your main code here, to run repeatedly:
  
  for (angle=0; angle < 180; angle++){
    srv.write(angle);
    delay(motorDelay);
  }

  for (angle=180; angle >0; angle--){
    srv.write(angle);
    delay(motorDelay);
  }

  if (motorLoop < 10 ){
    motorLoop++;
    Serial.print("Loop: ");
    Serial.println(motorLoop);
  }else{
    long elapseTimeWithDelay = millis() - tickStarted;
    long elapseTime = elapseTimeWithDelay - (10*(motorDelay*360));
    Serial.print(F("Elapse Time 10 loop: "));
    Serial.println(elapseTime);

    Serial.print(F("Elapse Time per Loop: "));
    Serial.println(elapseTime/10);

    Serial.print(F("Elapse Time per 60*: "));
    Serial.println(elapseTime/10/6);
    
    motorLoop = 0;
    tickStarted = millis();
  }
}
