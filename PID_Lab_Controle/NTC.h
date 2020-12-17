/**
 * @file NTC.h
 * @date Dezembro 2020
 * @brief Arquivo de definição dos objetos e funções relacionados à medição de temperatura.
 */
 
#ifndef _NTC_LIB_H_
  #define _NTC_LIB_H_

  #include <Arduino.h>

  #define NTC_PIN A5                                    // GPIO attached to NTC

//  #define MAX_TEMPERATURE 100.0                         // Absolute maximum temperature reading
//  #define MIN_TEMPERATURE 0.0                           // Absolute minimum temperature reading

  #define MAX_TEMPERATURE 1023.0                        // Absolute maximum temperature reading
  #define MIN_TEMPERATURE 0.0                           // Absolute minimum temperature reading

  #define ZERO_KELVIN 273.5                             // 0ºC in Kelvin
  #define TEMP_AMB_C   25.0                             // Ambient temperature (ºC)

  #define NTC_BETA  3600.0                              // NTC beta parameter
  #define NTC_R0    10000.0                             // NTC resistance at 25ºC
  #define NTC_T0    (ZERO_KELVIN + TEMP_AMB_C)          // Ambient temperature (Kelvin)
  #define NTC_RX    (NTC_R0 * exp(-NTC_BETA / NTC_T0))  // NTC's resistances lookup table

  #define VCC_VOLTAGE     5.0                           // Arduino VCC voltage
  #define ADC_RESOLUTION  1024.0                        // Arduino ADC resolution (10 bits)
  
  #define SERIES_R    10000.0                           // NTC's series resistance

  #define SAMPLE_DEPTH    20                            // Number of samples to be read
  #define SAMPLE_INTERVAL 5                             // Interval time between readings (ms)

  class NTC_lib {
    public:
      float get_temperature(void);

    private:
      float get_raw(void);
  };

#endif /*_NTC_LIB_H_*/
