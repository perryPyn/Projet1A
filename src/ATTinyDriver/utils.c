#include"utils.h"
#include "gpio.h"
#include "display.h"


void FormatNumber(int numberToSplit, int* digit_unites, int* digit_dizaines, int* digit_centaines) {
    digit_unites    =  numberToSplit % 10;
    digit_dizaines  = (numberToSplit / 10) % 10;
    digit_centaines = (numberToSplit / 100) % 10;
}

void DrawNumber(int digit_unites, int digit_dizaines, int digit_centaines){

  DisplayToUse(DISPLAY_1);
  NumberToDisplay(digit_unites);
  // DisplayOff();
  
  DisplayToUse(DISPLAY_2);
  NumberToDisplay(digit_dizaines);
  // DisplayOff();
  
  DisplayToUse(DISPLAY_3);
  NumberToDisplay(digit_centaines);
  // DisplayOff();
}