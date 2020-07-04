/*
 * MintDuino
 * Goal: Play games on an arduino, in an Altoids tin.
 * Status: Hardware finished, software unfinished
 *
 * This code is released under the MIT license.
 * If a copy of the license is not included,
 * it can be found at https://opensource.org/licenses/MIT
 *
 * This code has short diagrams and pictures to help understanding.
 * A diagram should precede code that deals with its subject matter.
 */

// LiquidCrystal_I2C.h: https://github.com/johnrickman/LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

/*
 * I2C Wiring Guide:
 * I2C LCD Controller   Arduino
 * ............ GND ---- GND
 * ............ VCC ---- 5V
 * ............ SDA ---- A4
 * ............ SCL ---- A5
 */

LiquidCrystal_I2C lcd =
    LiquidCrystal_I2C(0x27, 16, 2);  // takes (address, width, height)

/*
 *  Button layout on device:
 *  __A____B__
 *  [ Screen ]
 *  [_C____D_]
 *
 * The user's index fingers rest on A and B
 * The user's thumbs rest on C and D
 */

typedef struct {
    byte pin;
    bool state;
    int timeHeldDown;
} Button;

typedef struct {
    Button A;
    Button B;
    Button C;
    Button D;
    bool allHeldDown;
    bool oneHeldDown;
} Buttons;

Button A = {8, 0, 0};
Button B = {7, 0, 0};
Button C = {6, 0, 0};
Button D = {5, 0, 0};
Buttons btns = {A, B, C, D, 0, 0};

void setup() {
    pinMode(btns.A.pin, INPUT);
    pinMode(btns.B.pin, INPUT);
    pinMode(btns.C.pin, INPUT);
    pinMode(btns.D.pin, INPUT);

    lcd.init();
    lcd.clear();
    lcd.backlight();  // Turns on backlight. Default is off.
    lcd.display();
}

void loop() {
    btns.A.state = digitalRead(btns.A.pin);
    btns.B.state = digitalRead(btns.B.pin);
    btns.C.state = digitalRead(btns.C.pin);
    btns.D.state = digitalRead(btns.D.pin);

    lcd.setCursor(0, 1);
    lcd.print(btns.A.state);
    lcd.print(", ");
    lcd.print(btns.B.state);
    lcd.print(", ");
    lcd.print(btns.C.state);
    lcd.print(", ");
    lcd.print(btns.D.state);
}
