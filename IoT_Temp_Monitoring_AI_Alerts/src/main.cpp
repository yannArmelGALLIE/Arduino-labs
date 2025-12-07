#include <DHT.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define DHTPIN 26
#define DHTTYPE DHT22

const char* ssid = "CANALBOX-6163-2G";
const char* password = "3ZvgxDFHca";
const char* mqtt_server = "192.168.1.66";

DHT dht(DHTPIN, DHTTYPE);

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  Serial.println(F("Démarrage du test DHT22..."));

  dht.begin();
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }

  client.setServer(mqtt_server, 1883); 
}

void loop() {
  if (!client.connected()) {
    while (!client.connected()) {
      client.connect("esp32");
    }  
  }

  client.loop();

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Erreur dans la lecture du DHT22!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  client.publish("esatic/temp", String(t).c_str());

  Serial.print(F("Humidité: "));
  Serial.print(h);
  Serial.print(F("% Température: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print("\n");

  delay(2000);
}