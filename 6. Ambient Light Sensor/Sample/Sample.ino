#define LIGHT A3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LIGHT, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(LIGHT);
  int data = map(value, 0, 1023, 1023, 0);

  Serial.print("Light: ");
  Serial.print(value);
  Serial.print(":");
  Serial.println(data);

  delay(250);
}
