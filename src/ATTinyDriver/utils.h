#ifndef UTILS_H
#define UTILS_H

#include <avr/io.h> 


#ifdef __cplusplus
extern "C" {
#endif

void FormatNumber(int numberToSplit,volatile uint8_t* digit_unites,volatile uint8_t* digit_dizaines,volatile uint8_t* digit_centaines);
void DrawNumber(uint8_t display, uint8_t digit_unites, uint8_t digit_dizaines, uint8_t digit_centaines);

#ifdef __cplusplus
}
#endif

#endif