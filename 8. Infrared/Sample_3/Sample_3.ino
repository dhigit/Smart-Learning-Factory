#define IR_PIN A0
#define BUZZER 6

#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>

IoTMakers im;

#define deviceID      "slf201D1566886825451"
#define authRqtNo     "2q0kd27ch"
#define extrSysID     "OPEN_TCP_001PTL001_1000007606"

#define WIFI_SSID     "ICT-LAB-2.4G"
#define WIFI_PASS     "12345678"

#define TAG_ID        "IRSENSOR"

int distance=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initIoTMakers();
  
  pinMode(BUZZER, OUTPUT);
  pinMode(IR_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int volt = map(analogRead(IR_PIN), 0, 1023, 0, 5000);
  distance = (27.61 / (volt - 0.1696)) * 1000;

  //buzz if distance <= 20 cm
  if (distance<=20){
    tone(BUZZER, 400);
    delay(distance * 3);
    noTone(BUZZER);
    delay(distance * 3);
  }else{
    delay(500);
  }

  im.send_numdata(TAG_ID, (double)distance);

  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
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
