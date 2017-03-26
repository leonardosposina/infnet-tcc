/* Request.h - Library to handle client requests.
 * Created by Leonardo Sposina, April/2016.
 * INFNET GADS2013.3T-M TCC
 */

#ifndef Request_h
#define Request_h

#include "Arduino.h"

class Request {

  private:
    String _method, _uri, _id, _param;
    
  public:
    Request(String request);
    String getId();
    String getParam();
    boolean compareMethod(String method);
    boolean compareUri(String uri);
};

#endif
