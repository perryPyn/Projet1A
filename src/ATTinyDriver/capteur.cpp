#include <Wire.h>
#include "capteur.h"
#include "gpio.h"

#define VL53L1X_ADDRESS 0x29 // Attention l'adresse est 0x52 en format 8-bits mais Wire prend du 7-bits. (0x52>>1)

extern "C" {

  void Capteur_Configure(void) {
    Wire.begin();
  }

  void Capteur_Read(void) {
    Wire.beginTransmission(VL53L1X_ADDRESS);

    Wire.write(0x00);
    uint8_t status = Wire.endTransmission();

    if (status == 0) {
      Wire.requestFrom(0x52, 1);
      if (Wire.available()) {
        setNumberToDisplay(Wire.read());
      }
    } else {
      setNumberToDisplay(880+status);
    }
  }
}