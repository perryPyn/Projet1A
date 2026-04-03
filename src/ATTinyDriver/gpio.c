#include "gpio.h"
#include "display.h"
#include <avr/interrupt.h>

/* --- Configuration et Driver pour les pins --- */
void PIN_Configure(void) {
    DDRA |= 0b10101111; 
    DDRB |= 0b00000111;
}

void PIN_Driver(volatile uint8_t *port, uint8_t pin, uint8_t state) {
    if (state) {
        *port |= (1 << pin);
    } else {
        *port &= ~(1 << pin);
    }
}

/* --- Configuration du Timer et des interruptions --- */
void Timer_Init(void) {
    TCCR0A = (1 << WGM01); // Mode CTC
    
    TCCR0B = (1 << CS01) | (1 << CS00); // Prescaler 64 (Horloge système / 64)
    
    OCR0A = 199; // = (Temps * f_CPU) / (Prescaler - 1)
    
    TIMSK0 |= (1 << OCIE0A); // Activer l'interruption de comparaison A
}

static uint8_t currentDisplay = 0;
static uint8_t currentNumber = 15;
ISR(TIMER0_COMPA_vect) { // Comparaison avec OCR0A

    DisplayOff(); // PORTB &= 0xF8;

    if (currentDisplay > 2){currentDisplay = 0;}
    DisplayToUse(currentDisplay);
    NumberToDisplay(currentNumber);

    currentDisplay++;
}