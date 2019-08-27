#define trigPin 11
#define echoPin 12
#define BUZZER 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 17 / 1000;

  if (distance >= 200 || distance <= 0){
    Serial.println("Unable to measure distance");
  }else{
    Serial.print(distance);
    Serial.println(" cm");
    
    if (distance<30){
      tone(BUZZER, 400);
      delay(100);
      noTone(BUZZER);
      delay(100);
    }
  }
}
