#include "capteur.h"

/*
code erreur : signification
        555 : capteur pas prêt
        666 : data pas prêt
        702 : signal trop faible
        703 : ciblre trop proche (7cm)
        704 : cible trop loin
        707 : cible trouvée mais pas de phase correspondante
        70n : cf doc
        999 : bloquage de la liason I2C
*/


VL53L1X sensor;


void Capteur_Configure(void) {
  Wire.begin();
  Wire.setClock(100000);
  sensor.setTimeout(500);

  if (!sensor.init()) {  // Data pas prêt
    setNumberToDisplay(555);
    return;
  }

  sensor.setDistanceMode(VL53L1X::Short);
  sensor.setMeasurementTimingBudget(100000);  // 100ms
  sensor.startContinuous(200);
}


uint8_t errorCounter = 0;
void Capteur_Read(void) {
  if (!sensor.dataReady()) {  // Watchdog
    errorCounter++;
    if (errorCounter > 200) {
      sensor.stopContinuous();
      sensor.startContinuous(150);
      errorCounter = 0;
    }
    return;
  }
  errorCounter = 0;

  if (sensor.timeoutOccurred()) {
    setNumberToDisplay(999);      // Il y a eu un timeout sur la liaison
    sensor.startContinuous(150);  // On force le redémarrage
    return;
  }

  if (!sensor.dataReady()) {  // Data pas prêt
    // setNumberToDisplay(666);
    return;
  }

  uint16_t distance = sensor.read();
  uint8_t status = sensor.ranging_data.range_status;
  if (status != 0) {  // Erreur dans la lecture
    setNumberToDisplay(700 + status);
    return;
  }

  setNumberToDisplay((int)distance);
}