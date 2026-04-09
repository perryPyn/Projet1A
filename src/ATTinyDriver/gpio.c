#include "gpio.h"
#include "display.h"
#include <avr/interrupt.h>

int numberToDisplay = 123;
int digit_unites, digit_dizaines, digit_centaines;

/* --- Configuration et Driver pour les pins --- */
void PIN_Configure(void) {
    DDRB |= 0b00000111;
    DDRA |= 0b10101111;
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
    
    OCR0A = 249; // = (Temps * f_CPU) / (Prescaler - 1)
    
    TIMSK0 |= (1 << OCIE0A); // Activer l'interruption de comparaison A
    
    sei(); // Autoriser les interruptions globales
}

void setNumberToDisplay(int n){
    numberToDisplay = n;
}


int i=0;
ISR(TIMER0_COMPA_vect) { // Comparaison avec OCR0A
    FormatNumber(numberToDisplay, &digit_unites, &digit_dizaines, &digit_centaines);
    
    DisplayOff();
    DrawNumber(i,digit_unites, digit_dizaines, digit_centaines);
    i=(i+1)%3;
}