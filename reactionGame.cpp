#include <LiquidCrystal.h>

#define PIEZO 8
#define BTN_PLAY 6
#define BTN_HIT 7
#define LED_RED 9
#define LED_YELLOW 10
#define LED_BLUE 13

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

long bestTime = 9999;

void waitRandom() {
  // random delay between 2 and 6 seconds
  delay(random(2000, 6000));
}

void setup() {
  pinMode(BTN_PLAY, INPUT_PULLUP);
  pinMode(BTN_HIT, INPUT_PULLUP);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  randomSeed(analogRead(A0));
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Reaction Timer");
  lcd.setCursor(0, 1);
  lcd.print("Press START!");
}

void loop() {
  if (digitalRead(BTN_PLAY) == LOW) {
    delay(200);

    // Countdown
    digitalWrite(LED_RED, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Get ready...");
    tone(PIEZO, 500, 100);
    delay(1000);

    digitalWrite(LED_YELLOW, HIGH);
    tone(PIEZO, 600, 100);
    delay(1000);

    // Check if button pressed too early
    if (digitalRead(BTN_HIT) == LOW) {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("TOO EARLY!");
      lcd.setCursor(0, 1);
      lcd.print("Cheater! :p");
      tone(PIEZO, 200, 500);
      delay(2000);
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_BLUE, LOW);
      noTone(PIEZO);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Press START!");
      return;
    }

    // Random wait before GO
    waitRandom();

    // Check again if jumped early
    if (digitalRead(BTN_HIT) == LOW) {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("TOO EARLY!");
      lcd.setCursor(0, 1);
      lcd.print("Cheater! :p");
      tone(PIEZO, 200, 500);
      delay(2000);
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_BLUE, LOW);
      noTone(PIEZO);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Press START!");
      return;
    }

    // GO!
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_BLUE, HIGH);
    tone(PIEZO, 1000, 150);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("HIT IT!!!");

    long startTime = millis();

    // Wait for button hit
    while (digitalRead(BTN_HIT) == HIGH);

    long reactionTime = millis() - startTime;

    // Turn off LED
    digitalWrite(LED_BLUE, LOW);
    noTone(PIEZO);

    // Victory beep
    tone(PIEZO, 800, 100);
    delay(120);
    tone(PIEZO, 1000, 100);
    delay(120);
    tone(PIEZO, 1200, 150);

    // Check if new best
    if (reactionTime < bestTime) {
      bestTime = reactionTime;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("NEW BEST!");
      lcd.setCursor(0, 1);
      lcd.print(reactionTime);
      lcd.print("ms");
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Time: ");
      lcd.print(reactionTime);
      lcd.print("ms");
      lcd.setCursor(0, 1);
      lcd.print("Best: ");
      lcd.print(bestTime);
      lcd.print("ms");
    }

    delay(3000);
    noTone(PIEZO);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Press START!");
  }
}
