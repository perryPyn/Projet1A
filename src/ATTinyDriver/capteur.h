#ifndef CAPTEUR_H
#define CAPTEUR_H

// #include <stdint.h>
#include <Wire.h>
#include <VL53L1X.h>
#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

void Capteur_Configure(void);
void Capteur_Read(void);

#ifdef __cplusplus
}
#endif

#endif