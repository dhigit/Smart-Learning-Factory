#define SW 8
int rLED = 4;
int gLED = 3;
int bLED = 2;

int ir = 255;
int ig = 0;
int ib = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(bLED, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  //setColor(ir,ig,ib);
}

void loop() {
  if (digitalRead(SW)==0){
    setColor(0,0,0);
  }else{
    setColor(random(255), random(255), random(255));
    delay(500);
  }
}

void setColor(int r, int g, int b){
  analogWrite(rLED, 255-r);
  analogWrite(gLED, 255-g);
  analogWrite(bLED, 255-b);
}

//void loop(){
//  if (digitalRead(SW)==0){
//    if (ir==255){
//      ir=0;
//      ib=255;
//      ig=0;
//    }else if (ig==255){
//      ir=0;
//      ib=0;
//      ig=255;
//    }else{
//      ir=255;
//      ib=0;
//      ig=0;
//    }
//  }
//
//  setColor(ir,ig,ib);
//}
