angular.module("tccApp").controller('projectController', function($scope) {
  
  $scope.title = "Projeto";

  $scope.pinData = [
    {port:"0", io:"INPUT", connection:"Serial RX", status:"LOW", color:"default"},
    {port:"1", io:"OUTPUT", connection:"Serial TX", status:"LOW", color:"default"},
    {port:"2", io:"OUTPUT", connection:"Relay 1", status:"LOW", color:"success"},
    {port:"3", io:"OUTPUT", connection:"Relay 2", status:"LOW", color:"success"},
    {port:"4", io:"OUTPUT", connection:"SD CARD (desativado)", status:"HIGH", color:"danger"},
    {port:"5", io:"OUTPUT", connection:"Relay 3", status:"LOW", color:"success"},
    {port:"6", io:"OUTPUT", connection:"Relay 4", status:"LOW", color:"success"},
    {port:"7", io:"OUTPUT", connection:"Relay 5", status:"LOW", color:"success"},
    {port:"8", io:"OUTPUT", connection:"Relay 6", status:"LOW", color:"success"},
    {port:"9", io:"OUTPUT", connection:"Relay 7", status:"LOW", color:"success"},
    {port:"10", io:"SS (Slave Select)", connection:"W5100 Shield", status:"-", color:"primary"},
    {port:"11", io:"MOSI (Master Out Slave In)", connection:"W5100 Shield", status:"-", color:"primary"},
    {port:"12", io:"MISO (Master In Slave Out)", connection:"W5100 Shield", status:"-", color:"primary"},
    {port:"13", io:"SCK (Serial Clock)", connection:"W5100 Shield", status:"-", color:"primary"},
    {port:"A0", io:"INPUT_PULLUP", connection:"Botão pull-up 1", status:"HIGH", color:"warning"},
    {port:"A1", io:"INPUT_PULLUP", connection:"Botão pull-up 2", status:"HIGH", color:"warning"},
    {port:"A2", io:"INPUT", connection:"Sensor DHT11 (umidade/temperatura)", status:"-", color:"info"},
    {port:"A3", io:"INPUT", connection:"Light Dependent Resistor", status:"[0-1023]", color:"info"},
    {port:"A4", io:"-", connection:"-", status:"-", color:"default"},
    {port:"A5", io:"OUTPUT", connection:"Relay 8", status:"LOW", color:"success"}
  ];

});
