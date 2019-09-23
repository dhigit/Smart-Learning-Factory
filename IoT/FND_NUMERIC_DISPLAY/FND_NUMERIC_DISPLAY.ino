
int fnd_pin[8] = {2, 3, 4, 5, A2, A3, A4, A5};
int fnd_digits[10][8] = {
  {1,1,1,1,1,1,0,0}, //0
  {0,1,1,0,0,0,0,0}, //1
  {1,1,0,1,1,0,1,0}, //2
  {1,1,1,1,0,0,1,0}, //3
  {0,1,1,0,0,1,1,0}, //4
  {1,0,1,1,0,1,1,0}, //5
  {1,0,1,1,1,1,1,0}, //6
  {1,1,1,0,0,0,0,0}, //7
  {1,1,1,1,1,1,1,0}, //8
  {1,1,1,1,0,1,1,0}  //9
};

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<8; i++){
    pinMode(fnd_pin[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //display(12345);
  for (int i=9; i>=0; i--){
    display(i);
  }

  for (int i=0; i<5; i++){
    displayOff();
    display(8);
  }

  displayOff();
  displayDot();
  displayOff();
}

void display(int num){

  int outputNum;
  
  do {
    outputNum = num%10;
    num = num/10;
    for (int i=0; i<8; i++){
      digitalWrite(fnd_pin[i], fnd_digits[outputNum][i]);
    }
    delay(500);
  }while(num>0);
  
  
}

void displayOff(){
  for (int i=0; i<8; i++){
    digitalWrite(fnd_pin[i], 0);
  }
  delay(500);
}

void displayDot(){
  for (int i=0; i<8; i++){
    digitalWrite(fnd_pin[i], i<7 ? 0 : 1);
  }
  delay(500);
}
