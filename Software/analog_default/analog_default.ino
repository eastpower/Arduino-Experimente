#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int analogPin = A0;
int bitWert;
float spannung;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(115200);
}

void loop() {
  bitWert = analogRead(analogPin);
  spannung = map(bitWert, 0, 1023, 0, 500);
  Serial.println(bitWert);
  Serial.println(spannung);
  Serial.println();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Spannung:");
  lcd.setCursor(0, 1);
  lcd.print(bitWert);
  lcd.print(" = ");
  lcd.print(spannung/100);
  lcd.print(" V");
  delay(500);
}
