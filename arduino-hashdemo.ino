// This project requires you to import these libraries via the Arduino Library Manager:
// - Crypto by Rhys Weatherley
// - LiquidCrystal I2C by Frank de Brabander

#include "Crypto.h"
#include "SHA256.h"
#include "LiquidCrystal_I2C.h"

const byte ENTER = 0xA;
const byte CLEAR = 0x21;
const byte HASH_BUFFER_SIZE = 32;

SHA256 hasher;

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("> Ready");
}

void loop() {
  // Variablen vorbereiten
  byte key = -1;
  byte hashBuffer[32];

  // Etwas warten bevor wir erneut auf ein Signal warten
  delayMicroseconds(10);

  handleKeypad();

  // Zentraler Loop - Tastendrücke auslesen
  while (Serial.available() > 0) {
    key = Serial.read();

    // Je nach gedrückter Taste unterschiedlich agieren
    switch (key) {
      case CLEAR:
        lcd.clear();
        lcd.setCursor(0, 0);
        break;
      case ENTER:
        // Enter schließt den Hash ab und lässt ihn anzeigen.
        hasher.finalize(&hashBuffer, HASH_BUFFER_SIZE);
        hasher.reset();

        // An Computer senden
        Serial.print("Hash: ");
        for (int i = 0; i < HASH_BUFFER_SIZE; i++) {
          Serial.print(hashBuffer[i], HEX);
        }
        Serial.print("\n");

        // Auf LCD darstellen
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Hash: ");
        for (int i = 0; i < HASH_BUFFER_SIZE; i++) {
          String temp = String(hashBuffer[i], HEX);
          lcd.print(temp);
        }
        Serial.print("\n");

        break;
      default:
        // Bei allen anderen Tasten fügen wir den Wert der Taste zum Hash hinzu.
        hasher.update(&key, 1);

        break;
    }
  }
}
