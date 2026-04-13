#ifndef CAPTEUR_H
#define CAPTEUR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void Capteur_Configure(void);
void Capteur_Read(void);

#ifdef __cplusplus
}
#endif

#endif