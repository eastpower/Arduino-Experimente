/*
* Schaltzeiten:
* Zustand                         Zeit
* 0       A1: rt      A2: gn      5s
* 1       A1: rt      A2: gb      2s
* 2       A1: rt-gb   A2: gb      1s
* 3       A1: gn      A2: rt      5s
* 4       A1: gb      A2: rt      2s
* 5       A1: gb      A2: rt-gb   1s
*/

const byte zustand[6][7] = {
  // Schaltzustände Ampel
  //    A1        A2
  //rt gb gn rt gb gn zeit
  { 1, 0, 0, 0, 0, 1, 5 },  // Zustand 0
  { 1, 0, 0, 0, 1, 0, 2 },  // Zustand 1
  { 1, 1, 0, 0, 1, 0, 1 },  // Zustand 2
  { 0, 0, 1, 1, 0, 0, 5 },  // Zustand 3
  { 0, 1, 0, 1, 0, 0, 2 },  // Zustand 4
  { 0, 1, 0, 1, 1, 0, 1 }   // Zustand 5
};

const byte ampel[] = { 13, 12, 11, 9, 8, 7 };  // A1: 0...2; A2: 3...5

const byte LED_WS = 5;
const byte F_GN = 10;
const byte F_RT = 6;
const int ZEIT = 1000;  // Zeit für Pause
const byte S1 = 2;
bool flag = false;

// Funktion zeit() statt delay()
void zeit(int wert) 
{
    unsigned long time = millis();
    do {     
    } while (millis() <= time + wert);
}

void schaltung(byte zust) {
  for (byte i = 0; i < 6; i++) {
    digitalWrite(ampel[i], zustand[zust][i]);
  }
  if (flag && zust == 3) {
    digitalWrite(F_GN, HIGH);
    digitalWrite(F_RT, LOW);
    digitalWrite(LED_WS, LOW);
    flag = false;
  } else {
    digitalWrite(F_GN, LOW);
    digitalWrite(F_RT, HIGH);
  }
  zeit(ZEIT * zustand[zust][6]);
}

void wsEin() {
  flag = true;
  digitalWrite(LED_WS, HIGH);
}

void setup() {
  Serial.begin(115200);
  for (byte i = 5; i <= 13; i++) {
    pinMode(i, OUTPUT);    // P1 ... P9 Ausgang
    digitalWrite(i, LOW);  // alle LED aus
  }
  pinMode(S1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(S1), wsEin, LOW);
}

void loop() {
  for (byte i = 0; i <= 5; i++) {
    schaltung(i);
  }
}
