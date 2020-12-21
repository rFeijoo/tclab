/**
 * @file communication.h
 * @date Dezembro 2020
 * @brief Arquivo de definição dos objetos e funções relacionados ao barramento serial.
 */
 
#ifndef _COMMUNICATION_H_
  #define _COMMUNICATION_H_

  #include <Arduino.h>
  #include "NTC.h"
  #include "pwm.h"
  #include "config.h"

  #if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
    #define BOARD_TYPE "Arduino Uno"
  #elif defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
    #define BOARD_TYPE "Arduino Leonardo/Micro"
  #elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    #define BOARD_TYPE "Arduino Mega"
  #else 
    #define BOARD_TYPE "Unknown board"
  #endif

  #define FIRMWARE_VERSION "1.4.3"

  #define BUFFER_LENGTH 64

  class Communication_lib {
    public:
      bool alarm = false, new_data = false;
      char buffer[BUFFER_LENGTH];
      long  timeout = 0;
      
      void read_command(void);
      void echo_command(void);
      void parse_command(void);
      void dispatch_command(PWM_lib *q1, PWM_lib *q2, NTC_lib *t1, NTC_lib *t2);
      void set_led_status(PWM_lib *q1, PWM_lib *q2);

    private:
      String command;
      int led_status, index = 0;
      float cmd_val, LED_bright = 100;
      
      const int hiLED = 60;
      const int loLED = hiLED / 16;

      void send_response(String msg);
  };

#endif /*_COMMUNICATION_H_*/
