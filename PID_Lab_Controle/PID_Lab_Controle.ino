#include "NTC.h"
#include "pwm.h"

#define POT_PIN A0

NTC_lib NTC;
PWM_lib pwm;

void setup(void)
{
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Initial temperature: " + String(NTC.get_temperature()) + "ºC\n\n");
}

void loop(void)
{
  pwm.set_pwm(analogRead(POT_PIN));

  Serial.println("Temperature: " + String(NTC.get_temperature()) + "ºC");

  delay(500);
}
