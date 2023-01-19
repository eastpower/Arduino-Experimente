#include <LiquidCrystal.h> 	//LCD-Bibliothek laden

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //D12: RS, D11: E, D5: DB4, D4: DB5, D3; DB6, D2: DB7

void setup() {
  lcd.begin(16, 2); 		// 16 Zeichen in 2 Zeilen.
}

void loop() {
  lcd.setCursor(0, 0); 		// Startposition: Erstes Zeichen, erste Zeile.
  lcd.print("Anzeigetest"); // Text schreiben  
  lcd.setCursor(0, 1); 		// erstes Zeichen, zweite Zeile.
  lcd.print("DM6RAC");
}