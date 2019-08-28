#include <SoftwareSerial.h>

#define BT_TX 2
#define BT_RX 3

SoftwareSerial serialSW(BT_TX, BT_RX);

void setup() {
  Serial.begin(9600);
  serialSW.begin(9600);
}

void loop() {
  
  //Response AT
  if (serialSW.available()){
    Serial.write(serialSW.read());
  }

  //Request AT
  if (Serial.available()){
    delay(5);
    serialSW.write(Serial.read());
  }
}
