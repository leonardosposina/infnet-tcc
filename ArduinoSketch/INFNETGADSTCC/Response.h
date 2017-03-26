/* Response.cpp - Library to create response strings.
 * Created by Leonardo Sposina, April/2016.
 * INFNET GADS2013.3T-M TCC
 */

#ifndef Response_h
#define Response_h

#include "Arduino.h"
#include "Relay.h"
#include "Alarm.h"

#include <Ethernet.h> // Arduino Ethernet Shield library (version 1.1.2)
#include <DHT.h> // DHT11 Humidity/Temperature sensor (version 1.2.3)

class Response {
  private:
    EthernetClient _client;
    void offRelays(Relay rList[]);
    void headers();
    
  public:
    Response(EthernetClient client);
    void listRelays(Relay rList[]);
    void listAlarms(Alarm aList[]);
    void listSensors();
    void actRelay(Relay rList[], String param); 
    void return200();
    void return404();
    void return501();
};

#endif
