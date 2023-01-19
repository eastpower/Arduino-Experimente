#define ledRt 13
#define ledGb 12
#define ledGn 11
#define S1 2
#define S2 3
#define S3 4

const byte wertS1 = 3;
const byte wertS2 = 2;
byte count1, count2;  // Variablen, die nicht initialisiert werden erhalten den Startwert 0

void ledAus() {
  digitalWrite(ledRt, LOW);
  digitalWrite(ledGb, LOW);
  digitalWrite(ledGn, LOW);
}

void countNull() {
  count1 = 0;
  count2 = 0;
}

void setup() {
  Serial.println(115200);
  pinMode(ledRt, OUTPUT);
  pinMode(ledGb, OUTPUT);
  pinMode(ledGn, OUTPUT);
  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);
  pinMode(S3, INPUT_PULLUP);
  //ledAus();
}

void loop() {
  if (!digitalRead(S1)) {
    delay(50);
    if (!digitalRead(S1)) {
      digitalWrite(ledGb, HIGH);
      count1++;

      do {
      } while (!digitalRead(S1));
      digitalWrite(ledGb, LOW);
    }
  }
  // erst, wenn S1 3x gedrückt wurde, wird S2 abgefragt
  if (count1 == wertS1) {
    if (!digitalRead(S2)) {
      delay(50);
      if (!digitalRead(S2)) {
        digitalWrite(ledGb, HIGH);
        count2++;

        do {
        } while (!digitalRead(S2));
        digitalWrite(ledGb, LOW);
      }
    }
  } else {
    digitalWrite(ledGb, (digitalRead(S2)? LOW: HIGH));
  }

  if (!digitalRead(S3)) {
    delay(50);
    if (!digitalRead(S3) && count1 == wertS1 && count2 == wertS2) {
      digitalWrite(ledGn, HIGH);
      countNull();
      delay(2000);
    } else {
      digitalWrite(ledRt, HIGH);
      countNull();
      delay(2000);
    }
  }
  ledAus();
}
