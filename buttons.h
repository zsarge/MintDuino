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
