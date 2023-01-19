#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte h = 17;
byte m = 7;
byte s = 30;

// führende Null in Abhängigkeit Stunden, Minuten, Sekunden
void nullWert(byte zahl, String typ) {
    if (typ.equals("h")) lcd.setCursor(0,1);
    if (typ.equals("m")) lcd.setCursor(3,1);
    if (typ.equals("s")) lcd.setCursor(6,1); 
    if (zahl <= 9) lcd.print("0");
}

// die eigentliche Uhr
void uhr() {
    s++;
    if (s == 60) {
        s = 0; 
        m++;
    }
    if (m == 60) {
        m = 0;
        h++;
    }
    if (h == 24) h = 0;
}

void setup() {
    lcd.begin(16, 2);
}

void loop() {
    lcd.setCursor(0,0);
    lcd.print("Aktuelle Zeit:");
    // Stunden
    nullWert(h, "h");
    lcd.print(h);
    lcd.setCursor(2,1);
    lcd.print(":");
    // Minuten 
    nullWert(m, "m");
    lcd.print(m);
    lcd.setCursor(5,1);
    lcd.print(":");
    // Sekunden
    nullWert(s, "s");
    lcd.print(s);
    delay(1000);
    uhr();
}
