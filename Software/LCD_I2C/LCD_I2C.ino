/*
 * Uhr mit LCD-Anzeige und führenden Nullen
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // LCD-Adresse 0x27 (bzw. 0x3F), 16 Zeichen, 2 Zeilen


void setup()
{
    lcd.init();
    lcd.backlight();
}

void loop()
{
    lcd.setCursor(0,0);
    lcd.print("Anzeigetest");
    lcd.setCursor(0, 1);
    lcd.print("DM6RAC");
}
