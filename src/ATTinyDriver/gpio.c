#include "gpio.h"
#include "display.h"
#include <avr/interrupt.h>

int volatile numberToDisplay = 111;
uint8_t volatile digit_unites=0, digit_dizaines=0, digit_centaines=0;

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
void Timer_Configure(void) {
  TCCR0A = (1 << WGM01);  // Mode CTC

  TCCR0B = (1 << CS02);  // Prescaler 256

  OCR0A = 255;  // = (Temps * f_CPU) / (Prescaler - 1)

  TIMSK0 |= (1 << OCIE0A);  // Activer l'interruption de comparaison A

  sei();  // Autoriser les interruptions globales
}

void setNumberToDisplay(int n){
    numberToDisplay = n;
}


int i = 0;
ISR(TIMER0_COMPA_vect) {  // Comparaison avec OCR0A
  
  DisplayOff();
  DrawNumber(i, digit_unites, digit_dizaines, digit_centaines);
  i = (i + 1) % 3;

}