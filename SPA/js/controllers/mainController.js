angular.module("tccApp").controller('mainController', function($scope, $location) {
  
  $scope.title = "Arduino Web Client";
  
  $scope.isActive = function (viewLocation) {
    return viewLocation === $location.path();
  };

});