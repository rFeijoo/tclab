/**
 * @file config.h
 * @date Dezembro 2020
 * @brief Arquivo de definição dos objetos globais de configuração do Arduino.
 */
 
#ifndef _CONFIG_H_
  #define _CONFIG_H_

  #include <Arduino.h>

  #define LED_PIN   9                                   // GPIO attached to LED1
  #define NTC_T1    A1                                  // GPIO attached to NTC sensor 1
  #define NTC_T2    A2                                  // GPIO attached to NTC sensor 2
  #define HEATER_Q1 5                                   // GPIO attached to heater 1
  #define HEATER_Q2 3                                   // GPIO attached to heater 2

  #define SERIAL_BAUDRATE 115200

  // Uncomment for activate debug mode
  //#define DEBUG_MODE

#endif /*_CONFIG_H_*/
