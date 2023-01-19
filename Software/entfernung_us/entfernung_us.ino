#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int trigPin = 6;
int echoPin = 7;
float v = 331.5 + 0.606 * 20;             // m/s

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    lcd.begin(16, 2);
}

float entfernungInM() {
    // Sendet Schallinpuls
    digitalWrite(trigPin, LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);

    // Lauscht auf Echo
    float tUs = pulseIn(echoPin, HIGH);     //Mikrosekunden
    float t = tUs /1000.0 / 1000.2;     // s
    float d = t * v / 2;                // m (Hin- und Rückweg)
    return d;
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Entfernung:");
  lcd.setCursor(0, 1);
  lcd.print(entfernungInM());
  lcd.print(" m");
  delay(200);
}
