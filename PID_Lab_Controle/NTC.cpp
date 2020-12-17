#include "NTC.h"

float NTC_lib::get_temperature(void) {
  int raw = get_raw();

  double voltage = raw * (VCC_VOLTAGE / (ADC_RESOLUTION - 1));

  double ntc_resistance = SERIES_R / ((VCC_VOLTAGE / voltage) - 1);

  double k_temp = NTC_BETA / log(ntc_resistance / NTC_RX);

  return (k_temp - ZERO_KELVIN);

  return raw;
}

float NTC_lib::get_raw(void) {
  int raw = 0;

  for (int i=0; i<SAMPLE_DEPTH; i++) {
    raw += analogRead(NTC_PIN);
    delay(SAMPLE_INTERVAL);
  }

  float average = float(raw / SAMPLE_DEPTH);

  return (average);
}
