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

// I2C Wiring Guide:
// I2C LCD Controller   Arduino
// ............ GND ---- GND
// ............ VCC ---- 5 V
// ............ SDA ---- A4
// ............ SCL ---- A5

LiquidCrystal_I2C lcd =
    LiquidCrystal_I2C(0x27, 16, 2);  // takes (address, width, height)

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
