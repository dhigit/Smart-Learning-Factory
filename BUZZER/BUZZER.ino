int BUZZER = 6;
int iTone = 2;
#define SW 8

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(SW)==0){
    iTone++;
    iTone = iTone > 2 ? 0 : iTone;
  }
  
  if (iTone==1)
    C();
  else if (iTone==2)
    D();
  else
    E();
    
  delay(500);

  //allTone();
  //Serial.println("OFF");
  noTone(BUZZER);
  delay(500);
}

void C(){
  tone(BUZZER, 261.6256);
}

void D(){
  tone(BUZZER, 293.6648);
}

void E(){
  tone(BUZZER, 329.6276);
}

void Ft(){
  tone(BUZZER, 349.2283);
}

void G(){
  tone(BUZZER, 391.5594);
}

void A(){
  tone(BUZZER, 440);
}

void B(){
  tone(BUZZER, 493.8833);
}

void allTone(){
  C(); delay(500); 
  D(); delay(500); 
  E(); delay(500); 
  Ft(); delay(500); 
  G(); delay(500); 
  A(); delay(500); 
  B();
}
