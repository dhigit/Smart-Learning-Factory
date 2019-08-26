#define SW 8
int rLED = 4;
int gLED = 3;
int bLED = 2;

int colorVal = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(bLED, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SW), interuptLED, CHANGE);
}

void loop() {
  setColor(colorVal,0,0);
  delay(500);
  setColor(0,colorVal,0);
  delay(500);
  setColor(0,0,colorVal);
  delay(500);
}

void setColor(int r, int g, int b){
  analogWrite(rLED, 255-r);
  analogWrite(gLED, 255-g);
  analogWrite(bLED, 255-b);
}

void interuptLED(){
  colorVal = colorVal - 50;
  if (colorVal<0)
    colorVal = 255;
}
