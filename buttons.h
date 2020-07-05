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
    bool lastState;
    unsigned long timeHeldDown;
    unsigned long startHold;
} Button;

typedef struct {
    Button A;
    Button B;
    Button C;
    Button D;
    Button *number[3];
    bool allHeldDown;
    bool oneHeldDown;
} Buttons;

Button A = {8};
Button B = {7};
Button C = {6};
Button D = {5};

void updateArray(Buttons *btns) {
    btns->number[0] = &btns->A;
    btns->number[1] = &btns->B;
    btns->number[2] = &btns->C;
    btns->number[3] = &btns->D;
}

void updateLastState(Buttons *btns) {
    for (byte i = 0; i < 4; i++) {
        btns->number[i]->lastState = btns->number[i]->state;
    }
}

void updateState(Buttons *btns) {
    for (byte i = 0; i < 4; i++) {
        btns->number[i]->state = digitalRead(btns->number[i]->pin);
    }
}

void updateStartHold(Buttons *btns) {
    for (byte i = 0; i < 4; i++) {
        if (btns->number[i]->state == 0) {
            btns->number[i]->startHold = 0;
        } else if (btns->number[i]->state == 1 &&
                   btns->number[i]->lastState == 0) {
            btns->number[i]->startHold = millis();
        }
    }
}

void updateTimeHeldDown(Buttons *btns) {
    for (byte i = 0; i < 4; i++) {
        if (btns->number[i]->startHold > 0) {
            unsigned long timeDelta = millis() - btns->number[i]->startHold;
            btns->number[i]->timeHeldDown = timeDelta;
        } else {
            btns->number[i]->timeHeldDown = 0;
        }
    }
}

Buttons updateButtons() {
    Buttons btns = {A, B, C, D};
    updateArray(&btns);
    updateLastState(&btns);
    updateState(&btns);
    updateStartHold(&btns);
    updateTimeHeldDown(&btns);

    return btns;
}