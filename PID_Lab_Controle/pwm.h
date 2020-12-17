/**
 * @file pwm.h
 * @date Dezembro 2020
 * @brief Arquivo de definição dos objetos e funções relacionados à saída PWM.
 */
 
#ifndef _PWM_LIB_H_
  #define _PWM_LIB_H_

  #include <Arduino.h>
  #include "NTC.h"

  #define PWM_PIN 3                                     // GPIO attached to PWM driver

  #define PWM_MAX_OUTPUT  255                           // Absolute maximum pwm output
  #define PWM_MIN_OUTPUT  0                             // Absolute minimum pwm output

  class PWM_lib {
    public:
      void set_pwm(int t);
      int  get_pwm(void);

    private:
      int duty_cycle = 0;
      
      void pwm_write(int t);
      void set_duty_cycle(int t);
  };

#endif /*_PWM_LIB_H_*/
