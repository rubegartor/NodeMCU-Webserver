#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

const char *ssid = "SSID";
const char *password = "Password";

WebServer server(80);

const int port1 = 2;

bool port1Status = false;

void setup(void) {
  pinMode(port1, OUTPUT);
  digitalWrite(port1, LOW);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.print("Connecting");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/LampOnOff", []() {
    if(port1Status == false){
      digitalWrite(port1, HIGH);
    }else{
      digitalWrite(port1, LOW);
    }

    port1Status = !port1Status;
    server.send(200, "text/plain", "");
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
}
