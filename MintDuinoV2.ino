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
#include <LiquidCrystal_I2C.h> // Library for LCD
#include <Wire.h> // Library for I2C communication

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // takes (address, width, height)

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Hello World!"); 
  lcd.setCursor(2,1);
  lcd.print(millis());
}
