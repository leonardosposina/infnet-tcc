angular.module("tccApp").controller('sensorsController', function($scope, $interval, sensorsAPI, alarmsAPI) {
  
  $scope.title = "Sensores";
  $scope.responseStatus = {sensors: false, alarms: false};

  var getSensors = function() {
    sensorsAPI.getSensors()
    .then( function successCallback(response) {
      $scope.sensorList = response.data;
      $scope.sensorList.lighting = ((1023 - $scope.sensorList.lighting) * 100) / 1023;
      $scope.responseStatus.sensors = true;
    }, function errorCallback(response) {
      $scope.responseStatus.sensors = false;
      console.log(">> Não foi possível receber os dados dos sensores! # status: "+ response.statusText);
    });
  };

  var getAlarms = function() {
    alarmsAPI.getAlarms()
    .then( function successCallback(response) {
      $scope.alarmList = response.data;
      $scope.responseStatus.alarms = true;
    }, function errorCallback(response) {
      $scope.responseStatus.alarms = false;
      console.log(">> Não foi possível receber os dados dos alarmes! # status: "+ response.statusText);
    });
  };

  getSensors();
  getAlarms();

  var timerPromise = $interval( function() {
    getSensors();
    getAlarms();
  }, 5000);

  $scope.isAlarmActive = function(alarm) {
    if (alarm.value === 1) {
      return "alarm-active";
    }
  };

  $scope.$on('$destroy', function() {
    $interval.cancel(timerPromise);
  });

});