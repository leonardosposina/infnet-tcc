angular.module("tccApp", ['ngRoute']).config( function($routeProvider, $locationProvider) {
  
  $locationProvider.hashPrefix('');

  $routeProvider
    .when('/', {
      templateUrl: 'partials/home.html',
      controller: 'homeController'
    })
    .when('/commands', {
      templateUrl: 'partials/commands.html',
      controller: 'commandsController'
    })
    .when('/sensors', {
      templateUrl: 'partials/sensors.html',
      controller: 'sensorsController'
    })
    .when('/configurations', {
      templateUrl: 'partials/configurations.html',
      controller: 'configurationsController'
    })
    .when('/project', {
      templateUrl: 'partials/project.html',
      controller: 'projectController'
    })
    .otherwise({
      redirectTo: '/'
    });

});