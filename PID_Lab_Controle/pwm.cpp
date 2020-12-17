#include "pwm.h"

void PWM_lib::set_pwm(int t) {
  set_duty_cycle(t);
  
  pwm_write(t);
}

void PWM_lib::pwm_write(int t) {
  int pwm_out = map(t, MIN_TEMPERATURE, MAX_TEMPERATURE, PWM_MIN_OUTPUT, PWM_MAX_OUTPUT);

  analogWrite(PWM_PIN, pwm_out);
}

void PWM_lib::set_duty_cycle(int t) {
  duty_cycle = map(t, MIN_TEMPERATURE, MAX_TEMPERATURE, PWM_MIN_OUTPUT, PWM_MAX_OUTPUT);
}

int PWM_lib::get_pwm(void) {
  return (duty_cycle);
}
