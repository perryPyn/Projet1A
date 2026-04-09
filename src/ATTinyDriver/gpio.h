#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>

/*
Schéma de configuration des pins de l'ATTiny841 :

                           ATTiny841
                        +------U------+
                  VCC  1|             |14  GND
     (DISPLAY_1)  PB0  2|             |13  PA0  (BIT_0)
     (DISPLAY_2)  PB1  3|             |12  PA1  (BIT_1)
         (RESET)  PB3  4|             |11  PA2  (BIT_2)
     (DISPLAY_3)  PB2  5|             |10  PA3  (BIT_3)
        (X_SHUT)  PA7  6|             |9   PA4  (I2C_SCL)
       (I2C_SDA)  PA6  7|             |8   PA5  (DECIMAL)
                        +-------------+

*/

/* --- Pins liason I2C --- */
#define I2C_SCL PA4 // Clock
#define I2C_SDA PA6 // Data

/* --- Pins pour I/O les display 7-segments --- */
#define DISPLAY_1 PB0
#define DISPLAY_2 PB1
#define DISPLAY_3 PB2

/* --- Pins pour le décodeur --- */
#define BIT_0 PA0
#define BIT_1 PA1
#define BIT_2 PA2
#define BIT_3 PA3

/* --- Pins pour les décimales des afficheurs --- */
#define DIXIEME  PA5
#define CENTIEME PA7

/* === Prototypage des fonctions === */
#ifdef __cplusplus
extern "C" {
#endif

void PIN_Configure(void);
void PIN_Driver(volatile uint8_t *port, uint8_t pin, uint8_t state);

void Timer_Init(void);

void setNumberToDisplay(int n);

#ifdef __cplusplus
}
#endif

#endif