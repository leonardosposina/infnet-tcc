/* Component.cpp - Base class for peripheral components.
 * Created by Leonardo Sposina, April/2016.
 * INFNET GADS2013.3T-M TCC
 */

#include "Component.h"

String Component::getId() {
  return this->_id;
}

String Component::getLabel() {
  return this->_label;
}

byte Component::getValue() {
  return this->_value;
}

byte Component::getPort() {
  return this->_port;
}

void Component::setValue(byte value) {
  this->_value = value;
}

String Component::toJson() {
  return "{\"id\":\""+ this->_id +"\",\"label\":\""+ this->_label +"\",\"value\":"+ this->_value +"}";
}
