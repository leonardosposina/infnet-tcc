angular.module("tccApp").controller('configurationsController', function($scope, configurationsAPI, arduino) {
  
  $scope.title = "Configurações";
  $scope.arduino = arduino;

});