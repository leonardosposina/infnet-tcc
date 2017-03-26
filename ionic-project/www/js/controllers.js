angular.module('starter.controllers', [])

.controller('AppCtrl', function($scope, $ionicModal, SettingsAPI, MessageAPI) {

  $ionicModal.fromTemplateUrl('templates/loading.html', {
    scope: $scope
  }).then( function(modal) {
    $scope.modal = modal;
  });

  showConnecting = function() {
    $scope.modal.show();
  };

  hideConnecting = function() {
    $scope.modal.hide();
  };

  if (SettingsAPI.getUrl() === "") MessageAPI.showPopup();

})

.controller('RelaysCtrl', function($scope, RelayAPI, MessageAPI, $interval) {

  $scope.relaysList = [];
  showConnecting();

  var getRelays = function() {
    RelayAPI.getRelays()
    .success( function(response) {
      $scope.relaysList = response.filter( function(relay) {
        relay.value = (relay.value === 1) ? true : false;
        return relay;
      });
      hideConnecting();
    })
    .error( function(response, status) {
      showConnecting();
    });
  };

  $scope.actRelay = function(relay) {
    RelayAPI.actRelay(relay)
    .error( function(response, status) {
      MessageAPI.showAlert("Comandos:","Falha ao executar o comando: " + status);
    });
  };

  $scope.offRelays = function() {
    RelayAPI.offRelays()
    .success( function(response) {
      getRelays();
    })
    .error( function(response, status) {
      MessageAPI.showAlert("Comandos:","Falha ao desativar os relays: " + status);
    });
  };

  $scope.isSomeActive = function(list) {
    return list.some( function(item) {
      return item.value;
    });
  };

  var timerPromise = $interval(function() {
    getRelays();
  }, 10000);

  getRelays();

  $scope.$on('$destroy', function() {
    $interval.cancel(timerPromise);
  });

})

.controller('SensorsCtrl', function($scope, SensorAPI, $interval) {

  $scope.sensorsList = {};
  $scope.alarmsList = [];
  showConnecting();

  var getSensors = function() {
    SensorAPI.getSensors()
    .success( function(response) {
      $scope.sensorsList = response;
      $scope.sensorsList.lighting = ((1023 - $scope.sensorsList.lighting) * 100) / 1023;
      hideConnecting();
    })
    .error( function(response, status) {
      showConnecting();
    });
  };

  var getAlarms = function() {
    SensorAPI.getAlarms()
    .success ( function(response) {
      $scope.alarmsList = response;
    })
    .error( function(response, status) {
      showConnecting();
    });
  }

  $scope.isAlarmActive = function(alarm) {
    if (alarm.value === 1) {
      return "alarm-active";
    }
  };

  var timerPromise = $interval( function() {
    getSensors();
    getAlarms();
  }, 10000);

  getSensors();
  getAlarms();

  $scope.$on('$destroy', function() {
    $interval.cancel(timerPromise);
  });

})

.controller('SettingsCtrl', function($scope, SettingsAPI, MessageAPI) {

  $scope.arduinoAddress = SettingsAPI.getUrl().substring(7);

  $scope.saveAddress = function(address) {
    SettingsAPI.setUrl(address);
    MessageAPI.showAlert("Configurações:","Configurações salvas com sucesso!");
  };

});