/**
 * @file NTC.h
 * @date Dezembro 2020
 * @brief Arquivo de definição dos objetos e funções relacionados à medição de temperatura.
 */
 
#ifndef _NTC_LIB_H_
  #define _NTC_LIB_H_

  #include <Arduino.h>

  #define MAX_TEMPERATURE 50.0                          // Trigger superior de temperatura
  #define MIN_TEMPERATURE 0.0                           // Trigger inferior de temperatura

  #define ZERO_KELVIN 273.5                             // 0ºC em Kelvin
  #define TEMP_AMB_C   25.0                             // Temperatura ambiente em ºC

  #define NTC_BETA  3600.0                              // Parâmetro BETA do NTC
  #define NTC_R0    10000.0                             // Resistência do NTC à 25ºC
  #define NTC_T0    (ZERO_KELVIN + TEMP_AMB_C)          // Temperatura ambiente em Kelvin
  #define NTC_RX    (NTC_R0 * exp(-NTC_BETA / NTC_T0))  // Lookup table dos possíveis valores de resistência para o NTC

  #define VCC_VOLTAGE     5.0                           // Tensão de alimentação do sistema
  #define ADC_RESOLUTION  1024.0                        // Resolução do Arduino (10 bits)
  
  #define SERIES_R    10000.0                           // Resistência em série com o NTC

  #define SAMPLE_DEPTH    20                            // Número de amostras para cálculo da média
  #define SAMPLE_INTERVAL 5                             // Intervalo de tempo, em ms, para amostragem

  class NTC_lib {
    public:
      NTC_lib(int pin_);
      float get_temperature(void);
      bool is_alarm_triggered(void);

    private:
      int pin;
      
      float get_raw(void);
  };

#endif /*_NTC_LIB_H_*/
