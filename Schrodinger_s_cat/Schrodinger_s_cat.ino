#include <LiquidCrystal.h>

LiquidCrystal lcd(D0, D1, D2, D3, D4, D5); // named D0, D1,... cause using an ESP32. Can be called 2, 3, ... for PIN numbers
int buttonState = 0;
int lastButtonState = 0;

// Tableau des caractères personnalisés
byte hg[8] = {B00000, B00000, B00010, B00101, B00100, B00110, B00111, B00010};
byte hm[8] = {B00000, B00000, B00000, B00000, B11111, B00000, B00000, B00000};
byte hd[8] = {B00000, B00000, B01000, B10100, B00100, B01100, B11100, B01000};
byte bg[8] = {B00110, B00100, B00111, B00010, B00001, B00000, B00001, B00010};
byte bm1[8] = {B10001, B10001, B00100, B00000, B00000, B11111, B00100, B00000};
byte bm2[8] = {B10001, B11011, B10001, B00100, B00000, B11111, B00100, B00000};
byte bm3[8] = {B10001, B11001, B10000, B00100, B00000, B11111, B00100, B00000};
byte bd[8] = {B01100, B00100, B11100, B01000, B10000, B00000, B10000, B01000};

void setup() {
  lcd.createChar(0, hg);
  lcd.createChar(1, hm);
  lcd.createChar(2, hd);
  lcd.createChar(3, bg);
  lcd.createChar(4, bm1);
  lcd.createChar(5, bm2);
  lcd.createChar(6, bm3);
  lcd.createChar(7, bd);

  lcd.begin(16, 2);
}

void loop() {
  buttonState = digitalRead(D6);
  if (buttonState != lastButtonState) {
    lcd.clear();
    if (buttonState == HIGH) {
      int aleatoire = random(2);
      if (aleatoire == 0) {
        lcd.setCursor(0, 0);
        lcd.write(byte(0));
        lcd.write(byte(1));
        lcd.write(byte(2));
        lcd.print(" Le chat est");
              
        lcd.setCursor(0, 1);
        lcd.write(byte(3));
        lcd.write(byte(5));
        lcd.write(byte(7));
        lcd.print("    mort !");
      }
      else {
        lcd.setCursor(0, 0);
        lcd.write(byte(0));
        lcd.write(byte(1));
        lcd.write(byte(2));
        lcd.print(" Le chat est");
              
        lcd.setCursor(0, 1);
        lcd.write(byte(3));
        lcd.write(byte(4));
        lcd.write(byte(7));
        lcd.print("   vivant !");
      }
    }
  // Sinon, si le bouton est relâché
    else {
      lcd.setCursor(0, 0);
      lcd.write(byte(0));
      lcd.write(byte(1));
      lcd.write(byte(2));
      lcd.print(" Le chat est");
              
      lcd.setCursor(0, 1);
     lcd.write(byte(3));
      lcd.write(byte(6));
      lcd.write(byte(7));
      lcd.print("mort & vivant");
    }
// Pause pour éviter les scintillements
  delay(100);
  }
  lastButtonState = buttonState;
}

