/**
 * @file pwm.h
 * @date Dezembro 2020
 * @brief Arquivo de definição dos objetos e funções relacionados à saída PWM.
 */
 
#ifndef _PWM_LIB_H_
  #define _PWM_LIB_H_

  #include <Arduino.h>
  
  #define PWM_MAX_OUTPUT  255                           // Máximo valor para saída PWM
  #define PWM_MIN_OUTPUT  0                             // Mínimo valor para saída PWM

  class PWM_lib {
    public:
      float duty_cycle, max_pwm;

      PWM_lib(int pin_, float max_pwm_);
      void set_heater(float v);

    private:
      int pin;
  };

#endif /*_PWM_LIB_H_*/
