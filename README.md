# Arduino Reaction Timer

A reaction speed game built with an Arduino Uno. A countdown sequence triggers a blue LED — hit the button as fast as you can! Your time is shown in milliseconds on the LCD and your best score is tracked across rounds.

---

## Features

- Random delay between countdown and GO signal so you can't cheat by timing it
- Catches early button presses and calls you out
- Displays your reaction time in milliseconds on the LCD
- Tracks your best time across rounds
- LED countdown sequence: Red → Yellow → Blue (GO!)
- Piezo beeps on countdown, GO signal, and a victory fanfare on hit

---

## Hardware Required

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| 16x2 LCD Display | 1 |
| Red LED | 1 |
| Yellow LED | 1 |
| Blue LED | 1 |
| Piezo buzzer | 1 |
| Push buttons | 2 |
| 220Ω resistors (for LEDs) | 3 |
| 10kΩ potentiometer (LCD contrast) | 1 |
| Breadboard & jumper wires | — |

---

## Wiring

### 16x2 LCD (4-bit mode)
| LCD Pin | Arduino Pin |
|---|---|
| VSS (GND) | GND |
| VDD | 5V |
| V0 (contrast) | Potentiometer middle pin |
| RS | Digital 12 |
| RW | GND |
| EN | Digital 11 |
| D4 | Digital 5 |
| D5 | Digital 4 |
| D6 | Digital 3 |
| D7 | Digital 2 |
| A (backlight+) | 5V |
| K (backlight-) | GND |

### Potentiometer (LCD contrast)
| Pot Pin | Arduino Pin |
|---|---|
| Left leg | GND |
| Middle leg | LCD V0 |
| Right leg | 5V |

### LEDs
Each LED: long leg (positive) → Arduino pin, short leg (negative) → 220Ω resistor → GND

| LED | Arduino Pin |
|---|---|
| Red | Digital 9 |
| Yellow | Digital 10 |
| Blue | Digital 13 |

### Buttons
Each button: one leg → Arduino pin, other leg → GND. No resistors needed (uses INPUT_PULLUP).

| Button | Arduino Pin |
|---|---|
| START button | Digital 6 |
| HIT button | Digital 7 |

### Piezo Buzzer
| Piezo Pin | Arduino Pin |
|---|---|
| Positive (longer leg) | Digital 8 |
| Negative (shorter leg) | GND |

---

## How to Play

1. Power on — LCD shows `Reaction Timer / Press START!`
2. Press the **START button** to begin a round
3. Red LED lights up with a beep — get ready
4. Yellow LED lights up with a beep — almost time
5. After a **random delay** the blue LED lights up and piezo beeps — **HIT the button as fast as you can!**
6. Your reaction time shows on the LCD in milliseconds
7. If you beat your best time it shows `NEW BEST!`
8. Press **START** again for another round

---

## Cheat Detection

If you press the HIT button before the blue LED lights up the game shows `TOO EARLY! Cheater! :p` and resets. The random delay between yellow and blue means you can't time it by counting.

---

## Reaction Time Reference

| Time | Rating |
|---|---|
| Under 150ms | Superhuman |
| 150ms – 200ms | Excellent |
| 200ms – 250ms | Good |
| 250ms – 350ms | Average |
| Over 350ms | Keep practising! |

---

## Libraries Required

- **LiquidCrystal** — built into the Arduino IDE, no installation needed

---

## Setup & Upload

1. Wire components as described above
2. Open the `.ino` file in Arduino IDE
3. Select your board: **Tools → Board → Arduino Uno**
4. Select your port: **Tools → Port**
5. Click **Upload**
6. If the LCD is blank or shows black boxes, adjust the potentiometer to set the contrast
