/* Relay.h -  Library to handle relay operation.
 * Created by Leonardo Sposina, April/2016.
 * INFNET GADS2013.3T-M TCC
 */
 
#ifndef Relay_h
#define Relay_h

#include "Arduino.h"
#include "Component.h"

class Relay : public Component {
  public:
    Relay(String id, String label, byte value, byte port);
    void toogle();
};

#endif
