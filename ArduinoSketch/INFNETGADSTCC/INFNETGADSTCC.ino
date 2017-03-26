/*
** INFNET GADS 2013.3T-M :: TCC
** Created by Leonardo Sposina
** Project: Arduino Uno + W5100 Ethernet Shield + 8 Channel Relay Module + Single Page Application( AngularJS + Bootstrap )
*/

#include <Ethernet.h> // Arduino Ethernet Shield library (version 1.1.2)
#include "Relay.h"
#include "Alarm.h"
#include "Request.h"
#include "Response.h"

// I/O ports definition 
#define BTN1 A0
#define BTN2 A1
#define SDCARD 4 // not used

// Request string length
#define REQUESTSTRGLEN 25

// Request string content
String requestString;

// Relay array
Relay relayList[] = {
//Relay (<id>, <label>, <value>, <port>)  [label max length = 15]
  Relay ("rly1","Relay 1", LOW, 2),
  Relay ("rly2","Relay 2", LOW, 3),
  Relay ("rly3","Relay 3", LOW, 5),
  Relay ("rly4","Relay 4", LOW, 6),
  Relay ("rly5","Relay 5", LOW, 7),
  Relay ("rly6","Relay 6", LOW, 8),
  Relay ("rly7","Relay 7", LOW, 9),
  Relay ("rly8","Relay 8", LOW, A5)
};

// Alarm array
Alarm alarmList[] = {
//Alarm (<id>, <label>, <value>)  [label max length = 15]
  Alarm ("alr1", "Alarme 1", LOW, BTN1),
  Alarm ("alr2", "Alarme 2", LOW, BTN2)
};
  
// Ethernet W5100
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,150);
IPAddress subnet(255,255,255,0);
IPAddress gateway(192,168,1,1);
EthernetServer server(80);

/*****************************************************************************
** Initial setup
*****************************************************************************/
void setup() {
  
  // Set I/O ports "pinMode"
  pinMode(SDCARD, OUTPUT);

  // Set I/O port status
  digitalWrite(SDCARD, HIGH); // Disable SD card.
  
  // Init: Serial communication
  Serial.begin(9600);
  Serial.println(F("# Starting..."));

  // Init: W5100
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print(F("> W5100 ("));
  Serial.print(Ethernet.localIP());
  Serial.print(F(")"));

  // Reserve memory to avoid heap fragmentation.
  requestString.reserve(REQUESTSTRGLEN);
}

/*****************************************************************************
** Main program loop
*****************************************************************************/
void loop() {

  EthernetClient client = server.available();

  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read(); //
        if (requestString.length() < REQUESTSTRGLEN) {
          requestString += c; // Append character to the request string.
        } else {
          Request request(requestString);
          Response response(client);
          if (request.compareMethod("OPTIONS")) {
            response.return200();
          } else if (request.compareMethod("GET")) {
            if (request.compareUri("/relay")) {
              if(request.getId() == "") {
                response.listRelays(relayList);  
              } else {
                response.return501();
              }
            } else if (request.compareUri("/alarm")) {
              if(request.getId() == "") {
                response.listAlarms(alarmList);
              } else {
                response.return501();
              }
            } else if (request.compareUri("/sensor")) {
              if(request.getId() == "") {
                response.listSensors();
              } else {
                response.return501();
              }
            } else {
              response.return404();
            }
          } else if (request.compareMethod("PUT")) {
            if (request.compareUri("/relay")) {
              response.actRelay(relayList, request.getId());
            } else {
              response.return404();
            }
          } else {
            response.return501();
          }
          break;
        }
      }
    }
    delay(1);
    requestString = "";
    client.stop();
  }
}
