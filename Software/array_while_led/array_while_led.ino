// array_while_led.ino

byte led[] = {13, 12, 11, 10, 9, 8, 7, 6, 5};

void setup() {
  Serial.begin(115200);
  for (byte i = 0; i < 9; i++) {
    pinMode(led[i], OUTPUT);
  }
  ledAus();
}

void ledAus() {
  for (byte i = 0; i < 9; i++) {
    digitalWrite(led[i], LOW);
  }
}

void loop() {
  byte i = 0;
  ledAus();
  delay(1000);
  while (i < 9) {
    digitalWrite(led[i], HIGH);
    delay(1000);
    i++;
  }
}
