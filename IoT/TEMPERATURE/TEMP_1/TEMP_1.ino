#include <OneWire.h>
OneWire ds(2);

#define BUZZER 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = getTemp();

  if (temp>26.0){
    tone (BUZZER, 400);
    delay(100);
    noTone(BUZZER);
    delay(100);
  }
}

float getTemp(){
  byte i;
  byte present;

  byte data[12];
  byte addr[8];
  float temp;

  if (!ds.search(addr)){
    ds.reset_search();
    return;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);
  delay(1000);

  present = ds.reset();
  ds.select(addr);
  ds.write(0xBE);

  for (i=0; i<9; i++){
    data[i] = ds.read();
  }

  temp = (data[1]<<8) + data[0];
  temp = temp/16;

  Serial.print("temp=");
  Serial.println(temp);

  return temp;
}
