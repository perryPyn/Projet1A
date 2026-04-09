#include "utils.h"
#include "gpio.h"
#include "display.h"
#include "capteur.h"

/*

PORTA : I2C(4,6), BIT(0,1,2,3), DIXIEME(5), CENTIEME(7)
PORTB : DISPLAY(0,1,2), RESET(3)

*/

void setup() {

  PIN_Configure();
  // Capteur_Configure();

  Timer_Init();
}

void loop() {
  FormatNumber(numberToDisplay, &digit_unites, &digit_dizaines, &digit_centaines);
  // Capteur_Read();
}
