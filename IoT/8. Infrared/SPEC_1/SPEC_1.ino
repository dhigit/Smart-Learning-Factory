#define IR_PIN A0

int distance=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR_PIN, INPUT);
}

static unsigned long tick = millis();

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if ((millis() - tick) > 500){
    int volt = map(analogRead(IR_PIN), 0, 1023, 0, 5000);
    distance = (27.61 / (volt - 0.1696)) * 1000;
  
    Serial.print(distance);
    Serial.println(" cm");

    tick = millis();
  }
}
