#include "utils.h"
#include "gpio.h"
#include "display.h"


void FormatNumber(int numberToSplit,volatile uint8_t* digit_unites,volatile uint8_t* digit_dizaines,volatile uint8_t* digit_centaines) {
  *digit_unites = numberToSplit % 10;
  *digit_dizaines = (numberToSplit / 10) % 10;
  *digit_centaines = (numberToSplit / 100) % 10;
}

void DrawNumber(uint8_t display, uint8_t digit_unites, uint8_t digit_dizaines, uint8_t digit_centaines) {
  switch (display) {
    case 0:
      DisplayToUse(DISPLAY_1);
      NumberToDisplay(digit_unites);
      break;

    case 1:
      DisplayToUse(DISPLAY_2);
      NumberToDisplay(digit_dizaines);
      break;

    case 2:
      DisplayToUse(DISPLAY_3);
      NumberToDisplay(digit_centaines);
      break;
  }
}