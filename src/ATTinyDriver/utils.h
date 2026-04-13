#ifndef UTILS_H
#define UTILS_H

#include <avr/io.h> 


#ifdef __cplusplus
extern "C" {
#endif

void FormatNumber(int numberToSplit,volatile uint8_t* digit_1,volatile uint8_t* digit_2,volatile uint8_t* digit_3);
void DrawNumber(uint8_t display, uint8_t digit_1, uint8_t digit_2, uint8_t digit_3);

#ifdef __cplusplus
}
#endif

#endif