angular.module("tccApp").service("alarmsAPI", function($http, arduino) {

  this.getAlarms = function() {
    return $http.get(arduino.baseUrl + "/alarm");
  };

});