#include "utils.h"
#include "gpio.h"
#include "display.h"

/*

PORTA : I2C(4,6), BIT(0,1,2,3), DIXIEME(5), CENTIEME(7)
PORTB : DISPLAY(0,1,2), RESET(3)

*/

int numberToDisplay = 8;
int digit_0, digit_1, digit_2;

void setup() {
  PIN_Configure();

  // PIN_Driver(&PORTA, CENTIEME, 1); // Ligne de test

  Timer_Init();

  sei(); // Autoriser les interruptions globales
}

void loop() {
  // FormatNumber(numberToDisplay, &digit_0, &digit_1, &digit_2);
  // DrawNumber(digit_0, digit_1, digit_2);

  // for(int i=0; i<10; i++)
  // {
  //   NumberToDisplay(i);
  //   delay(1000);
  // }

  // for(int i=0; i<3; i++)
  // {
  //   DisplayToUse(i);
  //   delay(1000);
  // }
  // DisplayOff();
  // delay(1000);

}
