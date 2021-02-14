/* Response.cpp - Library to create response strings.
 * Created by Leonardo Sposina, April/2016.
 * INFNET GADS2013.3T-M TCC
 */

#include "Response.h"

// Control constants
#define RLY_NUM 8
#define ALR_NUM 2

// Light dependent resistor port
#define LDR_PIN A3

// DHT11 humidity/temperature sensor
#define DHT_PIN A2
#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

Response::Response(EthernetClient client) {
  this->_client = client;
}

// Return a list of all relays as json.
void Response::listRelays(Relay rList[]) {
  return200();
  this->_client.print(F("["));
  for (byte i = 0; i < RLY_NUM; i++) {
    this->_client.print(rList[i].toJson());
    if(i < (RLY_NUM - 1)) {
      this->_client.print(F(","));
    }
  }
  this->_client.print(F("]"));
}

// Return a list of all alarms as json.
void Response::listAlarms(Alarm aList[]) {
  aList[0].setValue(!digitalRead(aList[0].getPort()));
  aList[1].setValue(!digitalRead(aList[1].getPort()));
  
  return200();
  this->_client.print(F("["));
  for (byte i = 0; i < ALR_NUM; i++) {
    this->_client.print(aList[i].toJson());
    if (i < (ALR_NUM - 1)) {
      this->_client.print(F(","));  
    }
  }
  this->_client.print(F("]"));  
}

// Return a list of all sensors as json.
void Response::listSensors() {
  static float tempMin = 99;
  static float tempCur, tempMax;
  
  tempCur = dht.readTemperature();
  if (tempCur > tempMax) {
    tempMax = tempCur;
  }
  if (tempCur < tempMin) {
    tempMin = tempCur;
  }

  return200();
  this->_client.print(F("{\"lighting\":"));
  this->_client.print(analogRead(LDR_PIN)); // value [0, 1023]
  this->_client.print(F(",\"humidity\":"));
  this->_client.print(dht.readHumidity());
  this->_client.print(F(",\"temperature\":{\"min\":"));
  this->_client.print(tempMin); // lower temperature.
  this->_client.print(F(",\"cur\":"));
  this->_client.print(tempCur); // current temperature.
  this->_client.print(F(",\"max\":"));
  this->_client.print(tempMax); // higher temperature.
  this->_client.print(F("}}"));
}

void Response::actRelay(Relay rList[], String param) {
  if(param == "allOff") {
    this->offRelays(rList);
  } else {
    for (byte i = 0; i < RLY_NUM; i++) {
      if (rList[i].getId() == param) {
        rList[i].toogle();
        return200();
        this->_client.println(rList[i].getValue());
        return;
      }
    }
    return404();
  }
}

void Response::offRelays(Relay rList[]) {
  for (byte i = 0; i < RLY_NUM; i++) {
    digitalWrite(rList[i].getPort(), LOW);
    rList[i].setValue(LOW);
  }
  return200();
}

void Response::headers() {
  this->_client.println(F("Access-Control-Allow-Origin: *"));
  this->_client.println(F("Access-Control-Allow-Methods: GET, PUT, OPTIONS"));
  this->_client.println(F("Access-Control-Allow-Headers: Content-Type"));
  this->_client.println(F("Content-Type: application/json"));
  this->_client.println();
}

void Response::return200() {
  this->_client.println(F("HTTP/1.1 200 OK"));
  headers();
}

void Response::return404() {
  this->_client.println(F("HTTP/1.1 404 Not Found"));
  headers();
}

void Response::return501() {
  this->_client.println(F("HTTP/1.1 501 Not Implemented"));
  headers();  
}
