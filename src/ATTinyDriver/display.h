#ifndef DISPLAY_H
#define DISPLAY_H

#include <avr/io.h> 


#ifdef __cplusplus
extern "C" {
#endif

void NumberToDisplay(int numberToDisplay);
void DisplayToUse(uint8_t display);
void DisplayOff();

#ifdef __cplusplus
}
#endif

#endif