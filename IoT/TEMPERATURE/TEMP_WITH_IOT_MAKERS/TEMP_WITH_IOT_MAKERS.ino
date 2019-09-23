#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

IoTMakers im;

#define deviceID      "slf201D1566797663568"
#define authRqtNo     "9ur3oqrhj"
#define extrSysID     "OPEN_TCP_001PTL001_1000007606"

#define WIFI_SSID     "ICT-LAB-2.4G"
#define WIFI_PASS     "12345678"

#define ONE_WIRE_BUS  2
#define TAG_ID        "Temperature"

OneWire ourWire (ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);

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

int send_temperature()
{
  sensors.requestTemperatures();
  float data = sensors.getTempCByIndex(0);

  Serial.print("Temperature : ");
  Serial.print(data);
  Serial.println(" Celsius");
  
  if(im.send_numdata(TAG_ID, (double)data) < 0)
  {
    Serial.println(F("fail"));
    return -1;
  }

  return 0;
}

void setup() {
  Serial.begin(9600);
  sensors.begin();
  
  /*SPEC 3 SOLUTION #BEGIN */
  Serial.print(F("Old Resolution: "));
  Serial.println(sensors.getResolution());
  sensors.setResolution(12); //change this value from 9 to 12 (higher value is higher resolution)
  Serial.print(F("New Resolution: "));
  Serial.println(sensors.getResolution());
  /*SPEC 3 SOLUTION #END */
  
  initIoTMakers();
}

void loop() {
  static unsigned long tick = millis();

  if(im.isServerDisconnected() == 1){
    initIoTMakers();
  }

  if((millis() - tick) > 2000){ //SPEC 1 SOLUTION
    send_temperature();
    tick = millis();
  }

  im.loop();
}
