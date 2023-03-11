// Die restliche Implementierung ist nur aktiv, wenn der Buzzer genutzt werden soll.
#ifdef USE_BUZZER

#define BUZZER_PIN 17

void setupBuzzer() {
  pinMode(BUZZER_PIN, OUTPUT);
  buzzerBeep();
}

void buzzerBeep() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(100);
  digitalWrite(BUZZER_PIN, LOW);
}

#endif
