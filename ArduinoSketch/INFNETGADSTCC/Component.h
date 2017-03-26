/* Component.h - Base class for peripheral components.
 * Created by Leonardo Sposina, April/2016.
 * INFNET GADS2013.3T-M TCC
 */

#ifndef Component_h
#define Component_h

#include "Arduino.h"

class Component {
  protected:
    String _id, _label;
    byte _value, _port;
    
  public:
    String getId();
    String getLabel();
    byte getValue();
    byte getPort();
    void setValue(byte value);
    String toJson();
};

#endif
