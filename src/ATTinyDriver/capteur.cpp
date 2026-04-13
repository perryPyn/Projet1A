#include <Wire.h>
#include <VL53L1X.h>
#include "capteur.h"
#include "gpio.h"

VL53L1X sensor;


void Capteur_Configure(void) {
  Wire.begin();
  Wire.setClock(100000);

  sensor.setTimeout(500);
  if (!sensor.init()) {
    setNumberToDisplay(888);
    return;
  }
  sensor.setDistanceMode(VL53L1X::Long);
  sensor.setMeasurementTimingBudget(100000);  // 100ms
  sensor.startContinuous(150);
}

void Capteur_Read(void) {
  if (sensor.dataReady()) {
    uint16_t distance = sensor.read();
    uint8_t status = sensor.ranging_data.range_status;

    if (status == 0) {
      if (distance > 999) distance = 999;
      setNumberToDisplay((int)distance);
    }

    // Signal est trop faible (status 2) ou trop loin (status 4)
    else if (status == 2 || status == 4) {
      setNumberToDisplay(999);  // On affiche le max
    }
  }
}