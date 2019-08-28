#include <SoftwareSerial.h>

#define BT_TX 2
#define BT_RX 3

SoftwareSerial serialSW(BT_TX, BT_RX);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serialSW.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (serialSW.available()){
    Serial.write(serialSW.read());
  }else{
    delay(5);
    serialSW.write(Serial.read());
  }
}
