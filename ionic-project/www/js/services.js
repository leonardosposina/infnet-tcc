angular.module('starter.services', [])

.service('SettingsAPI', function($window) {

  this.getUrl = function() {
    var url = $window.localStorage["arduinoAddress"];
    if (!url) url = "";
    return url;
  };

  this.setUrl = function(address) {
    $window.localStorage["arduinoAddress"] = "http://" + address;
    return true;
  };

})

.service('RelayAPI', function($http, SettingsAPI) {

  this.getRelays = function() {
    return $http.get(SettingsAPI.getUrl() + "/relay");
  };

  this.actRelay = function(relay) {
    return $http.put(SettingsAPI.getUrl() + "/relay/" + relay.id)
  };

  this.offRelays = function() {
    return $http.put(SettingsAPI.getUrl() + "/relay/allOff");
  };

})

.service('SensorAPI', function($http, SettingsAPI) {
  
  this.getSensors = function() {
    return $http.get(SettingsAPI.getUrl() + "/sensor");
  };

  this.getAlarms = function() {
    return $http.get(SettingsAPI.getUrl() + "/alarm");
  };
  
})

.service('MessageAPI', function($ionicPopup, $timeout, $state) {
  
  this.showAlert = function(title, template) {
    var alertWindow = $ionicPopup.alert({
      title: title,
      template: template  
    });

    $timeout( function() {
      alertWindow.close();
    }, 5000);
  };

  this.showPopup = function() {
    $ionicPopup.show({
      title: '<b>Domótica com Arduino:</b>',
      subTitle: '<br/><b>Bem-vindo ao aplicativo de controle para automação residencial com Arduino!</b><br/><br/>Para que seja possível acessar suas funcionalidades, é necessário inserir as configurações de rede do Arduino.',
      buttons:[{
        text: 'ir para <b>Configurações</b>...',
        type: 'button-balanced',
        onTap: function(e) {
          $state.go('app.settings');
        }
      }]
    });
  };

});