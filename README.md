# serveur_esp8266NodeMcu
C'est un code arduino. J'envoie des données depuis mon application flutter ou android (java) et je les recupèrent dans la carte ESP8266 NodeMCU
Dans l'application nous envoyons les données sous format json à l'url de la carte
# code flutter
var data = {
  "patientID":"1253",
  "prescriptionText" : "Paracetamol"
  } voilà un exemple de ce que nous envoyions 
