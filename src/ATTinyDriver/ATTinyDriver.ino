#include "utils.h"
#include "gpio.h"
#include "display.h"

/*

PORTA : I2C(4,6), BIT(0,1,2,3), DIXIEME(5), CENTIEME(7)
PORTB : DISPLAY(0,1,2), RESET(3)

*/

int numberToDisplay = 8;
int digit_unites, digit_dizaines, digit_centaines;

void setup() {
  PIN_Configure();

  Timer_Init();

  // PIN_Driver(&PORTA, CENTIEME_PIN, 1); // Ligne de test
}

void loop() {
  // FormatNumber(numberToDisplay, &digit_unites, &digit_dizaines, &digit_centaines);

  // DrawNumber(digit_unites, digit_dizaines, digit_centaines);
}
