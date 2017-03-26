angular.module("tccApp").service("relaysAPI", function($http, arduino) {
  
  this.getRelays = function() {
    return $http.get(arduino.baseUrl + "/relay");
  };

  this.actRelay = function(relay) {
    return $http.put(arduino.baseUrl + "/relay/" + relay.id)
  };

  this.offRelays = function() {
    return $http.put(arduino.baseUrl + "/relay/allOff");
  };

});