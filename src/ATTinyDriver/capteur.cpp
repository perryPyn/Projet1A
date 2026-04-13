#include <Wire.h>
#include <VL53L1X.h>
#include "capteur.h"
#include "gpio.h"

/*
code erreur : signification
        555 : capteur pas prêt
        666 : data pas prêt
        702 : signal trop faible
        704 : cible trop loin
        707 : cible trouvée mais pas de phase correspondante
        70n : cf doc
        
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

  sensor.setDistanceMode(VL53L1X::Long);
  sensor.setMeasurementTimingBudget(100000);  // 100ms
  sensor.startContinuous(150);
}

void Capteur_Read(void) {

  if (!sensor.dataReady()) {  // Data pas prêt
    // setNumberToDisplay(666);
    return;
  }

  uint8_t status = sensor.ranging_data.range_status;
  if (status != 0) { // Erreur dans la lecture
    setNumberToDisplay(770+status);
    return;
  }

  uint16_t distance = sensor.read();
  if (distance > 999) distance = 999; // Distance tronquée le temps d'ajouter les décimales
  setNumberToDisplay((int)distance);
}


























