angular.module("tccApp").service("sensorsAPI", function($http, arduino) {

  this.getSensors = function() {
    return $http.get(arduino.baseUrl + "/sensor");
  };

});