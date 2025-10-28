## Problem
Measure light level of an area and display it's value. Give a user an option, to stop device from updating a display value. Everything should work asynchronously.

## Usage
- Press a button, to freeze display with it's current value;
- When display is frozen, the blue LED will light up.

## EEPROM
Everything is saved in a form of a struct:
- Magic number (int);
- Display state (int);
- Displayed sensor value (int).

## Timer
- Set delay using variable TIMER_DELAY. Delay can be any value from 1ms to 250ms;
- The delay will be converted to ticks, which will be used in timer CompareA register (OCR1A).

## Future improvements
- Use an LCD screen instead of 7-segment display, to show more information;
- Implement debouncing for a push button, for less double-clicks;
- More sensors, for more averaged out value.

## Components

| Component | Quantity |
| --------- | :--------: |
| Arduino Uno R3 | 1 |
| 7-segment display | 1 |
| Push Button | 1 |
| Photoresistor | 1 |
| Blue LED | 1 |
| Resistor 220R | 8 |
| Resistor 1kR | 1 |
| Resistor 10kR | 1 |

## Wiring
![Wiring](https://github.com/user-attachments/assets/2bed05b8-1086-4aa0-a314-286adb98c609)

## Demo
https://github.com/user-attachments/assets/51bb8e5d-bd55-4add-b2d2-0a3043535929

