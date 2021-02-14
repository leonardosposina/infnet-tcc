/* Alarm.h -  Library to handle alarm tiggers.
 * Created by Leonardo Sposina, April/2016.
 * INFNET GADS2013.3T-M TCC
 */
 
#ifndef Alarm_h
#define Alarm_h

#include "Arduino.h"
#include "Component.h"

class Alarm : public Component {
  public:
    Alarm(String id, String label, byte value, byte port);
};

#endif
