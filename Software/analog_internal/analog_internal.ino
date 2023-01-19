#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int analogPin = A1;
int bitWert;
float spannung;

void setup() {
  lcd.begin(16, 2);
  analogReference(INTERNAL);
}

void loop() {
  bitWert = analogRead(analogPin);
  spannung = map(bitWert, 0, 1023, 0, 110);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Spannung:");
  lcd.setCursor(0, 1);
  lcd.print(bitWert);
  lcd.print(" = ");
  lcd.print(spannung / 100);
  lcd.print(" V");
  delay(500);
}
