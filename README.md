
# NodeMCU-Webserver
Implementación de servidor web para NodeMCU (ESP32)
## Requisitos:
1. Board Manager URL: https://dl.espressif.com/dl/package_esp32_index.json
2. Instalar Board: **ESP32** by **SP32 by Espressif Systems**

## Configuración
**SSID**: Nombre de la red WiFi

**Password**: Contraseña de la red WiFi

## Añadir rutas

    server.on("/PATH", []() {
	    server.send(200, "text/plain", "");
    });
