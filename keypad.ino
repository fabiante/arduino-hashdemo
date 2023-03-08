// Falls wir ein Keypad verwenden wird Keypad by Mark Standley, Alexander Brevig benötigt.
// Dieser Code wurde von hier übernommen: https://funduino.de/nr-04-tastenfeld

#include "Keypad.h"

const byte COLS = 4; // Spalten
const byte ROWS = 4; // Zeilen

char keypadCharMap[ROWS][COLS]={
  {'D','#','0','*'},
  {'C','9','8','7'},
  {'B','6','5','4'},
  {'A','3','2','1'}
};

byte colPins[COLS] = {2,3,4,5}; // Pins für die 4 Spalten
byte rowPins[ROWS] = {6,7,8,9}; // Pins für die 4 Zeilen

char keypadChar;
Keypad keypad = Keypad(makeKeymap(keypadCharMap), rowPins, colPins, ROWS, COLS); //Das Keypad kann absofort mit myKeypad angesprochen werden

void handleKeypad() {
  keypadChar = keypad.getKey();
  if (keypadChar) {
    Serial.print("Keypad: ");
    Serial.print(keypadChar);
    Serial.print("\n");
  }
}