#define ledRt 10
#define ledGn 8
#define ledBl 9

void setup() {
  pinMode(ledRt, OUTPUT);
  pinMode(ledGn, OUTPUT);
  pinMode(ledBl, OUTPUT);
}

void loop() {
  digitalWrite(ledRt, HIGH);
  delay(1000);
  digitalWrite(ledGn, HIGH);
  delay(1000);
  digitalWrite(ledBl, HIGH);
  delay(1000);
  digitalWrite(ledRt, LOW);
  delay(1000);
  digitalWrite(ledGn, LOW);
  delay(1000);
  digitalWrite(ledBl, LOW);
  delay(1000);
}
