#define trigPin 11
#define echoPin 12
#define BUZZER 6

int rLED = 4;
int gLED = 3;
int bLED = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(bLED, OUTPUT);
}

void setColor(int r, int g, int b){
  analogWrite(rLED, 255-r);
  analogWrite(gLED, 255-g);
  analogWrite(bLED, 255-b);
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
    //Serial.println("Unable to measure distance");
  }else{
    Serial.print(distance);
    Serial.println(" cm");

    //buzz if distance < 30 cm
    if (distance<30){
      tone(BUZZER, 400);
      delay(100);
      noTone(BUZZER);
      delay(100);
    }

    //Light Warning with RGB
    if (distance>60){
      setColor(0, 0, 255);
    }else if (distance > 30){
      setColor(0, 255, 0);
    }else{
      setColor(255, 0, 0);
    }
//    int color = 255 - ((distance > 255) ? 255 : distance);
//    setColor(color, color, color);
//    delay(500);
  }
}
