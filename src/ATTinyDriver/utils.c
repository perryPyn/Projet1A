#include "utils.h"
#include "gpio.h"
#include "display.h"


void FormatNumber(uint16_t numberToSplit, volatile uint8_t* digit_1, volatile uint8_t* digit_2, volatile uint8_t* digit_3) {
  if (numberToSplit < 10) {
    numberToSplit *= 100;
    decimalPoint = 3;

  } else if (numberToSplit < 100) {
    numberToSplit *= 10;
    decimalPoint = 2;

  } else if (numberToSplit < 1000) {
    decimalPoint = 1;

  } else {
    numberToSplit = numberToSplit % 1000;
    decimalPoint = 0;
  }

  *digit_1 = numberToSplit % 10;
  *digit_2 = (numberToSplit / 10) % 10;
  *digit_3 = (numberToSplit / 100) % 10;
}

void DrawDecimalPoint(uint8_t display,uint8_t dp) {
  if (display!=dp){
    DecimalToDisplay();
    return;
  }
}

void DrawNumber(uint8_t display, uint8_t digit_1, uint8_t digit_2, uint8_t digit_3) {
  switch (display) {
    case 0:
      DisplayToUse(DISPLAY_1);
      NumberToDisplay(digit_1);
      break;

    case 1:
      DisplayToUse(DISPLAY_2);
      NumberToDisplay(digit_2);
      break;

    case 2:
      DisplayToUse(DISPLAY_3);
      NumberToDisplay(digit_3);
      break;
  }
}