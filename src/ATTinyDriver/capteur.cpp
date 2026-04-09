#include <Wire.h>
#include "capteur.h"
#include "gpio.h"

extern "C" {

  void Capteur_Configure(void) {
    Wire.begin();
  }

  void Capteur_Read(void) {
    Wire.beginTransmission(0x52);
    
    Wire.write(0x00); 
    uint8_t error = Wire.endTransmission();
    setNumberToDisplay(error);
    
    if (error == 0) {
        Wire.requestFrom(0x52, 1);
        if (Wire.available()) {
            // setNumberToDisplay(Wire.read());
        }
    }else{
    }
  }
}