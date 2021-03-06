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

#include "buttons.h"

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

void setup() {
    Buttons btns = updateButtons();
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
    Buttons btns = updateButtons();

    // Prints all button states
    lcd.setCursor(0, 0);
    for (byte i = 0; i < 4; i++) {
        lcd.print(btns.number[i]->lastState);

        if (i < 3) {
            lcd.print(", ");
        }
    }

    lcd.setCursor(0, 1);
    for (byte i = 0; i < 4; i++) {
        lcd.print(btns.number[i]->state);

        if (i < 3) {
            lcd.print(", ");
        }
    }
}
