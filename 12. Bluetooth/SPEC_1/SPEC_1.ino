#include <SoftwareSerial.h>

#define BT_TX 2
#define BT_RX 3

SoftwareSerial serialSW(BT_TX, BT_RX);
String stringIn = "";

void setup() {
  Serial.begin(9600);
  serialSW.begin(9600);
}

void loop() {
  
  while (serialSW.available()){
    char charIn = (char)serialSW.read();
    stringIn += charIn;
    delay(5);
  }

  if(!stringIn.equals("")){
    Serial.println("Recieved: " + stringIn);
    stringIn = "";
  }
}
