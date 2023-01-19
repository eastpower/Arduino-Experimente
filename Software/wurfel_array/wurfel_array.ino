#define S1 2
bool sch;
byte zufallszahl = 0;

byte matrix[7][7] = {
  // P1 P2 P3 P4 P5 P6 P7
    {0, 0, 0, 0, 0, 0, 0},  // 0
    {0, 0, 0, 1, 0, 0, 0},  // 1
    {0, 0, 1, 0, 1, 0, 0},  // 2
    {0, 0, 1, 1, 1, 0, 0},  // 3
    {1, 0, 1, 0, 1, 0, 1},  // 4
    {1, 0, 1, 1, 1, 0, 1},  // 5
    {1, 1, 1, 0, 1, 1, 1}   // 6
};

byte led[] = {13, 12, 11, 10, 9, 8, 7};     // P1 ... P7

void setup() {
  Serial.begin(115200);
  for (byte i = 0; i < 7; i++) {
    pinMode(led[i], OUTPUT);
  }
  pinMode(S1, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(S1)) {
    do {
      for (byte i = 1; i <= 6; i++) {
        zufallszahl = i;
        if (digitalRead(S1)) break;
      }
    } while (!digitalRead(S1));
  }
  Serial.println(zufallszahl);
  for (byte i = 0; i < 7; i++) {
    digitalWrite(led[i], matrix[zufallszahl][i]);
  }
}
