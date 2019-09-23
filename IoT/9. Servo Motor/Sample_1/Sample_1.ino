#include <Servo.h>
Servo srv;
int angle = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  srv.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (angle=0; angle < 180; angle++){
    srv.write(angle);
    delay(15);
  }

  for (angle=180; angle >0; angle--){
    srv.write(angle);
    delay(15);
  }
}
