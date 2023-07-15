#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Nom de votre Wifi";
const char* password = "Mot de passe de votre wifi";
String valeurParametre1, valeurParametre2;
ESP8266WebServer server(80);

void handleRoot() {
  if (server.hasArg("prescriptionText")) {
    valeurParametre1 = server.arg("prescriptionText");
    Serial.print("Valeur de parametre1 : ");
    Serial.println(valeurParametre1);
  }

  if (server.hasArg("patientId")) {
    valeurParametre2 = server.arg("patientId");
    Serial.print("Valeur de parametre2 : ");
    Serial.println(valeurParametre2);
  }

  if (server.hasArg("prescriptionText") && server.hasArg("patientId")) {
    String content = "Contenu du card : " + valeurParametre1 + " " + valeurParametre2;
    Serial.println(content);
  }

  server.send(200, "text/plain", valeurParametre1 + " " + valeurParametre2);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Attente de la connexion WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connecté à : ");
  Serial.println(ssid);
  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("Serveur démarré !");
}

void loop() {
  server.handleClient();
}
