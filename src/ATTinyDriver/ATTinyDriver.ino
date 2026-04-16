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
  
  Capteur_Configure();
  
  Timer_Configure();

}



void loop() {

  Capteur_Read();
  FormatNumber(numberToDisplay, &digit_1, &digit_2, &digit_3);
  // delay(10)
}