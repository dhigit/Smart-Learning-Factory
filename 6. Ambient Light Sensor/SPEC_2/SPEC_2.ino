#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>

IoTMakers im;

#define deviceID      "slf201D1566881836776"
#define authRqtNo     "fqkk5lsau"
#define extrSysID     "OPEN_TCP_001PTL001_1000007606"

#define WIFI_SSID     "ICT-LAB-2.4G"
#define WIFI_PASS     "12345678"

#define TAG_ID        "LIGHTSENSOR"

#define LIGHT A3
#define BUZZER 6

void setup() {
  // put your setup code here, to run once:
  initIoTMakers();
  Serial.begin(9600);
  pinMode(LIGHT, INPUT);

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

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(LIGHT);
  int data = map(value, 0, 1023, 1023, 0);

  Serial.print("Light: ");
  Serial.print(value);
  Serial.print(":");
  Serial.println(data);

  im.send_numdata(TAG_ID, (double)data);
  
  if (data<800){
    tone(BUZZER, 400);
    delay(100);
    noTone(BUZZER);
    delay(100);
  }

  delay(250);
}
