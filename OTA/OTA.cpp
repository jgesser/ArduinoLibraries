#include "OTA.h"
#include <ArduinoOTA.h>

OTA::OTA() {
}

void OTA::setup() {
    ArduinoOTA.onStart([]() {
        Serial.println("OTA Update begin...");
    });
    ArduinoOTA.onEnd([]() {
        Serial.println("End!");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progress: %u%%", (progress / (total / 100)));
        Serial.println();
    });
    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR) {
            Serial.println("Authentication Failed");
        } else if (error == OTA_BEGIN_ERROR) {
            Serial.println("Begin Failed");
        } else if (error == OTA_CONNECT_ERROR) {
            Serial.println("Connect Failed");
        } else if (error == OTA_RECEIVE_ERROR) {
            Serial.println("Receive Failed");
        } else if (error == OTA_END_ERROR) {
            Serial.println("End Failed");
        }
    });
    ArduinoOTA.begin();
}

void OTA::loop() {
    ArduinoOTA.handle();
}
