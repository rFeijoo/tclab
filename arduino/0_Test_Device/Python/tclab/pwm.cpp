#include "pwm.h"

PWM_lib::PWM_lib(int pin_, float max_pwm_) {
  pin = pin_;
  
  max_pwm = max_pwm_;

  duty_cycle = 0;
}

void PWM_lib::set_heater(float v) {
  duty_cycle = max(0., min(v, 100.));

  analogWrite(pin, (duty_cycle * max_pwm) / 100);
}
