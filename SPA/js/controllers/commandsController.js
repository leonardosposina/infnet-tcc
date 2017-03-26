angular.module("tccApp").controller('commandsController', function($scope, $interval, relaysAPI) {
  
  $scope.title = "Comandos";
  $scope.responseStatus = false;

  var getRelays = function() {
    relaysAPI.getRelays()
    .then( function successCallback(response) {
      $scope.relayList = response.data;
      $scope.responseStatus = true;
    }, function errorCallback(response) {
      $scope.responseStatus = false;
      console.log(">> Não foi possível receber os dados dos relays! # status: "+ response.statusText);
    });
  };

  getRelays();
  
  var timerPromise = $interval(function() {
    getRelays();
  }, 10000);

  $scope.actRelay = function(relay) {
    relaysAPI.actRelay(relay)
    .then( function successCallback(response) {
      relay.value = response.data;
      console.log(">> O botão "+ relay.label +" foi acionado! # status: "+ response.statusText);
    }, function errorCallback(response) {
      console.log(">> O botão "+ relay.label +" não foi acionado. # status: "+ response.statusText);
    });
  };

  $scope.offRelays = function() {
    relaysAPI.offRelays()
    .then( function successCallback(response) {
      getRelays();
      console.log(">> Todos os relays foram desativados! # status: "+ response.statusText);
    }, function errorCallback(response) {
      console.log(">> O estado dos relays não foi alterado! # status: "+ response.statusText);
    });
  };

  $scope.isSomeActive = function(list = []) {
    return list.some( function(item) {
      return (item.value === 1);
    });
  };

  $scope.isRelayActive = function(relay) {
    if (relay.value === 1) {
      return "lime";
    } else if (relay.value === 0) {
      return "red";
    }
  };

  $scope.$on('$destroy', function() {
    $interval.cancel(timerPromise);
  });

});