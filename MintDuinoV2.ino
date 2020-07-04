/*
 * MintDuino V2
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
 * ............ VCC ---- 5 V
 * ............ SDA ---- A4
 * ............ SCL ---- A5
 */

LiquidCrystal_I2C lcd =
    LiquidCrystal_I2C(0x27, 16, 2);  // takes (address, width, height)

/*
 *  Button layout on device:
 *  __1____2__
 *  [ Screen ]
 *  [_3____4_]
 *
 * The user's index fingers rest on 1 and 2
 * The user's thumbs rest on 3 and 4
 */

const int buttonPin = 8;
const int buttonPin2 = 7;
const int buttonPin3 = 6;
const int buttonPin4 = 5;
int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

void setup() {
    pinMode(buttonPin, INPUT);
    pinMode(buttonPin2, INPUT);
    pinMode(buttonPin3, INPUT);
    pinMode(buttonPin4, INPUT);

    lcd.init();
    lcd.clear();
    lcd.backlight();  // Turns on backlight. Default is off.
}

void loop() {
    buttonState = digitalRead(buttonPin);
    buttonState2 = digitalRead(buttonPin2);
    buttonState3 = digitalRead(buttonPin3);
    buttonState4 = digitalRead(buttonPin4);

    lcd.setCursor(0, 0);
    lcd.print(buttonState);
    lcd.print(", ");
    lcd.print(buttonState2);
    lcd.print(", ");
    lcd.print(buttonState3);
    lcd.print(", ");
    lcd.print(buttonState4);
}
