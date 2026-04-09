#include "display.h"


void NumberToDisplay(int numberToDisplay) {
  /*
    *  numberToDiplsay est un entier entre 0 et 9
    *  Le décodeur est relié aux 4 pins dont l'état est géré par les bits 0 à 3 de PORTA
  */

  PORTA = (PORTA & 0xF0) | (numberToDisplay & 0x0F);
}

void DisplayToUse(uint8_t display) {
  PORTB = (PORTB & 0xF8) | (1 << display);
}

void DisplayOff() {
  /*
    *  Permet d'éteindre tout les afficheur en cas de mauvaise synchronisation
  */
  PORTB &= 0xF8;
}