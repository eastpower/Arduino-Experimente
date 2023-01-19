#define ledRt 10

void setup() {
  pinMode(ledRt, OUTPUT);
}

void loop() {
  for (byte i = 0; i < 255; i++) {
    analogWrite(ledRt, i);
    delay(20);
  }
  for (byte i = 255; i > 0; i--) {
    analogWrite(ledRt, i);
    delay(20);
  }
}
