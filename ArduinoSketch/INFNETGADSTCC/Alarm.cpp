/* Alarm.cpp -  Library to handle infrared emissions.
 * Created by Leonardo Sposina, April/2016.
 * INFNET GADS2013.3T-M TCC
 */

#include "Alarm.h"

Alarm::Alarm(String id, String label, byte value, byte port) {
  this->_id = id;
  this->_label = label;
  this->_value = value;  
  this->_port = port;
  
  pinMode(port, INPUT_PULLUP);
}
