/* Request.cpp - Library to handle client requests.
 * Created by Leonardo Sposina, March/2016.
 * INFNET GADS2013.3T-M TCC
 */
 
#include "Request.h"

Request::Request(String request) {
  byte ref1 = request.indexOf('/');
  byte ref2 = request.indexOf('H');
  this->_method = request.substring(0, (ref1 - 1));
  String tmp = request.substring(ref1, (ref2 - 1));
  if (tmp.length() <= 7) {
    this->_uri = tmp;
  } else {
    ref1 = tmp.lastIndexOf('/');
    this->_uri = tmp.substring(0, ref1);
    this->_id = tmp.substring((ref1 + 1));
  }
  
// # Serial Debug #
  Serial.print(F("method: "));
  Serial.println(this->_method);
  Serial.print(F("tmp: "));
  Serial.println(tmp);
  Serial.print(F("uri: "));
  Serial.println(this->_uri);
  Serial.print(F("id: "));
  Serial.println(this->_id);
  Serial.println(F(""));
}

String Request::getId() {
  return this->_id;  
}

String Request::getParam() {
  return this->_param;
}

boolean Request::compareMethod(String method) {
  return (this->_method == method) ? true : false;  
}

boolean Request::compareUri(String uri) {
  return (this->_uri == uri) ? true : false;  
}
