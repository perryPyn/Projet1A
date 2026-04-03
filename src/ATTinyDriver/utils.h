#ifndef UTILS_H
#define UTILS_H

#include <avr/io.h> 


#ifdef __cplusplus
extern "C" {
#endif

void FormatNumber(int numberToSplit, int* digit_unites, int* digit_dizaines, int* digit_centaines);
void DrawNumber(int digit_unites, int digit_dizaines, int digit_centaines);

#ifdef __cplusplus
}
#endif

#endif