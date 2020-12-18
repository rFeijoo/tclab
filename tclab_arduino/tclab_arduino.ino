/*
  TCLab Temperature Control Lab Firmware
  Jeffrey Kantor, Bill Tubbs, John Hedengren, Shawn Summey
  June 2020

  This firmware provides a high level interface to the Temperature Control Lab. The
  firmware scans the serial port for commands. Commands are case-insensitive. Any
  unrecognized command results in sleep mode. Each command returns a result string.

  A         software restart. Returns "Start".
  LED float set LED to float for 10 sec. range 0 to 100. Returns actual float
  P1 float  set pwm limit on heater 1, range 0 to 255. Default 200. Returns P1.
  P2 float  set pwm limit on heater 2, range 0 to 255. Default 100. Returns P2.
  Q1 float  set Heater 1, range 0 to 100. Returns value of Q1.
  Q2 float  set Heater 2, range 0 to 100. Returns value of Q2.
  Q1B float set Heater 1, range 0 to 100. Returns value of Q1 as a 32-bit float.
  Q2B float set Heater 2, range 0 to 100. Returns value of Q2 as a 32-bit float.
  R1        get value of Heater 1, range 0 to 100
  R2        get value of Heater 2, range 0 to 100
  SCAN      get values T1 T2 Q1 Q1 in line delimited values
  T1        get Temperature T1. Returns value of T1 in °C.
  T2        get Temperature T2. Returns value of T2 in °C.
  T1B       get Temperature T1. Returns value of T1 in °C as a 32-bit float.
  T2B       get Temperature T2. Returns value of T2 in °C as a 32-bit float.
  VER       get firmware version string
  X         stop, enter sleep mode. Returns "Stop"

  Limits on the heater can be configured with the constants below.

  Status is indicated by LED1 on the Temperature Control Lab. Status conditions are:

      LED1        LED1
      Brightness  State
      ----------  -----
      dim         steady     Normal operation, heaters off
      bright      steady     Normal operation, heaters on
      dim         blinking   High temperature alarm on, heaters off
      bright      blinking   High temperature alarm on, heaters on

  The Temperature Control Lab shuts down the heaters if it receives no host commands
  during a timeout period (configure below), receives an "X" command, or receives
  an unrecognized command from the host.

  The constants can be used to configure the firmware.

  Code refactored by Rafael Feijó & Bismark Cotrim (2020).
*/

#include "config.h"
#include "NTC.h"
#include "pwm.h"
#include "communication.h"

NTC_lib NTC1(NTC_T1);
NTC_lib NTC2(NTC_T2);
PWM_lib heater1(HEATER_Q1, 200);
PWM_lib heater2(HEATER_Q2, 100);
Communication_lib bus;

void setup(void) {
  Serial.begin(SERIAL_BAUDRATE);
  while (!Serial)
    ;

  Serial.flush();

  heater1.set_heater(0);
  heater2.set_heater(0);
  
  bus.timeout = millis() + 1000;
}

void loop(void) {
  bus.read_command();

  #ifdef DEBUG_MODE
    bus.echo_command();
  #endif /*DEBUG_MODE*/

  bus.parse_command();

  bus.dispatch_command(&heater1, &heater2, &NTC1, &NTC2);

  if (NTC1.is_alarm_triggered() || NTC2.is_alarm_triggered())
    bus.alarm = true;

  bus.set_led_status(&heater1, &heater2);
}
