#define BUZZER_PIN 10

void setupBuzzer() {
  pinMode(BUZZER_PIN, OUTPUT);
  buzzerBeep();
}

void buzzerBeep() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(100);
  digitalWrite(BUZZER_PIN, LOW);
}
