/* Relay.cpp - Library to handle relay operation.
 * Created by Leonardo Sposina, April/2016.
 * INFNET GADS2013.3T-M TCC
 */
 
#include "Relay.h"

Relay::Relay(String id, String label, byte value, byte port) {
  this->_id = id;
  this->_label = label;
  this->_value = value;
  this->_port = port;

  pinMode(port, OUTPUT);
  digitalWrite(port, value);
}

void Relay::toogle() {
  byte result = ((this->getValue() == HIGH) ? LOW : HIGH);
  digitalWrite(this->_port, result);
  this->setValue(result);
}
