/*
 * MintDuino V2
 * Goal: Play games on an arduino, in an Altoids tin.
 * Status: Unfinished
 *
 * This code is released under the MIT license.
 * If a copy of the license is not included,
 * it can be found at https://opensource.org/licenses/MIT
 */

// LiquidCrystal_I2C.h: https://github.com/johnrickman/LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>  // Library for LCD
#include <Wire.h>               // Library for I2C communication

LiquidCrystal_I2C lcd =
    LiquidCrystal_I2C(0x27, 16, 2);  // takes (address, width, height)

const int buttonPin = 7;
int buttonState = 0;

void setup() {
    pinMode(buttonPin, INPUT);

    lcd.init();
    lcd.clear();
    lcd.backlight();
}

void loop() {
    buttonState = digitalRead(buttonPin);

    lcd.setCursor(0, 0);
    if (buttonState == HIGH) {
        lcd.print(buttonState);
    } else {
        lcd.print(buttonState);
    }
}
