#ifndef DISPLAY_H
#define DISPLAY_H

#include <avr/io.h> 


#ifdef __cplusplus
extern "C" {
#endif

void NumberToDisplay(uint8_t numberToDisplay);
void DecimalToDisplay(void);
void DisplayToUse(uint8_t display);
void DisplayOff(void);

#ifdef __cplusplus
}
#endif

#endif