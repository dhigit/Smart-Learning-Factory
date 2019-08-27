#define VIB_SENSOR A0

#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>

IoTMakers im;

#define deviceID      "slf201D1566886825451"
#define authRqtNo     "2q0kd27ch"
#define extrSysID     "OPEN_TCP_001PTL001_1000007606"

#define WIFI_SSID     "koreatech314 2.4G"
#define WIFI_PASS     "koreatech314"

#define TAG_ID        "VIBSENSOR"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initIoTMakers();
  pinMode(VIB_SENSOR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = analogRead(VIB_SENSOR);
  Serial.println(data);
  im.send_numdata(TAG_ID, data);
  delay(100);
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
