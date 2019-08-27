#include <Servo.h>
#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>

Servo srv;
int angle = 0;

IoTMakers im;

#define deviceID      "slf201D1566886825451"
#define authRqtNo     "2q0kd27ch"
#define extrSysID     "OPEN_TCP_001PTL001_1000007606"

#define WIFI_SSID     "ICT-LAB-2.4G"
#define WIFI_PASS     "12345678"

#define TAG_ID        "SERVOANGLE"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initIoTMakers();
  srv.attach(3);
}

static unsigned long tickStarted;

void loop() {
  angle = angle > 180 ? 0 : angle+1;
  srv.write(angle);
  delay(15);
  
  if ((millis() - tickStarted) >= 500){
    Serial.println(angle);
    im.send_numdata(TAG_ID, angle);
    tickStarted = millis();
  }
}

void initIoTMakers(){
  while (1){
    Serial.print(F("Connecting to AP . . ."));

    while (im.begin(WIFI_SSID, WIFI_PASS) <0 ) {
      Serial.println(F("Retrying..."));
      delay (100);
    }

    Serial.println("Success");
    im.init(deviceID, authRqtNo, extrSysID);
    Serial.println(F("Connect to platform ..."));

    while (im.connect() <0 ){
      Serial.println(F("Retrying..."));
      delay (100);
    }

    Serial.println(F("Success"));
    Serial.println(F("Auth..."));

    if (im.auth_device() >= 0){
      Serial.println(F("Success"));
      return;
    }
  }
}
