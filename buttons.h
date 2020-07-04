/*
 * This file handles buttons and button presses.
 * It is used in MintDuino.ino
 */

// LiquidCrystal_I2C.h: https://github.com/johnrickman/LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

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

Buttons updateButtons() {
    Buttons btns = {A, B, C, D, 0, 0};
    btns.A.state = digitalRead(btns.A.pin);
    btns.B.state = digitalRead(btns.B.pin);
    btns.C.state = digitalRead(btns.C.pin);
    btns.D.state = digitalRead(btns.D.pin);

    return btns;
}