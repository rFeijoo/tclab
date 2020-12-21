#include "communication.h"

void Communication_lib::read_command(void) {
  while (Serial && (Serial.available() > 0) && (!new_data)) {
    int byte = Serial.read();

    if ((byte != '\r') && (byte != '\n') && index < BUFFER_LENGTH)
      buffer[index++] = byte;
    else
      new_data = true;
  }
}

void Communication_lib::echo_command(void) {
  if (new_data) {
    Serial.write("Received Command: ");
    Serial.write(buffer, index);
    Serial.write('\n');
    Serial.flush();
  }
}

void Communication_lib::parse_command(void) {
  if (new_data) {
    String str = String(buffer);

    int pos = str.indexOf(' ');

    command = str.substring(0, pos);
    command.trim();
    command.toUpperCase();

    String data = str.substring(pos + 1);
    data.trim();
    cmd_val = data.toFloat();

    memset(buffer, 0, sizeof(buffer));
    index = 0;
    new_data = false;
  }
}

void Communication_lib::dispatch_command(PWM_lib *q1, PWM_lib *q2, NTC_lib *t1, NTC_lib *t2) {
  if (command == "A") {
    q1->set_heater(0);
    q2->set_heater(0);
    
    send_response("Start");
  }
  else if (command == "LED") {
    timeout = millis() + 10000;
    
    LED_bright = max(0, min(100, cmd_val));

    send_response(String(LED_bright));
  }
  else if (command == "P1") {
    q1->max_pwm = max(0, min(255, cmd_val));

    send_response(String(q1->max_pwm));
  }
  else if (command == "P2") {
    q2->max_pwm = max(0, min(255, cmd_val));

    send_response(String(q2->max_pwm));
  }
  else if (command == "Q1") {
    q1->set_heater(cmd_val);

    send_response(String(q1->duty_cycle));
  }
  else if (command == "Q2") {
    q2->set_heater(cmd_val);

    send_response(String(q2->duty_cycle));
  }
  else if (command == "R1") {
    send_response(String(q1->duty_cycle));
  }
  else if (command == "R2") {
    send_response(String(q2->duty_cycle));
  }
  else if (command == "SCAN") {
    send_response(String(t1->get_temperature()));
    send_response(String(q1->duty_cycle));
    
    send_response(String(t2->get_temperature()));
    send_response(String(q2->duty_cycle));
  }
  else if (command == "T1") {
    send_response(String(t1->get_temperature()));
  }
  else if (command == "T2") {
    send_response(String(t2->get_temperature()));
  }
  else if (command == "VER") {
    send_response("TCLab Firmware " + String(FIRMWARE_VERSION) + " " + String(BOARD_TYPE));
  }
  else if (command == "X") {
    q1->set_heater(0);
    q2->set_heater(0);

    send_response("Stop");
  }
  else if (command.length() > 0) {
    q1->set_heater(0);
    q2->set_heater(0);

    send_response(command);
  }

  Serial.flush();

  command = "";
}

void Communication_lib::send_response(String msg) {
  Serial.println(msg);
}

void Communication_lib::set_led_status(PWM_lib *q1, PWM_lib *q2) {
  led_status = 1;

  if (q1->duty_cycle > 0 || q2->duty_cycle > 0)
    led_status = 2;

  if (alarm) {
    led_status += 2;
    alarm = false;
  }

  if (millis() < timeout)
    analogWrite(LED_PIN, LED_bright);
  else {
    switch (led_status) {
      case 1:  // Alarme desligado, aquecedor desligado
        analogWrite(LED_PIN, loLED);
        break;
      case 2:  // Alarme desligado, aquecedor ligado
        analogWrite(LED_PIN, hiLED);
        break;
      case 3:  // Alarme ligado, aquecedor desligado
        if ((millis() % 2000) > 1000)
          analogWrite(LED_PIN, loLED);
        else
          analogWrite(LED_PIN, loLED/4);
        break;
      case 4:  // Alarme ligado, aquecedor ligado
        if ((millis() % 2000) > 1000)
          analogWrite(LED_PIN, hiLED);
        else
          analogWrite(LED_PIN, loLED);
        break;
    }
  }
}
