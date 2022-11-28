#include <Arduino.h>
#include <IPAddress.h>

#include <config.hpp>

#include "AsyncMqttClient.h"
#include "ESP8266WiFi.h"

#if !RELEASE
void PRINT_MQTT_DISCONNECT_REASON(AsyncMqttClientDisconnectReason reason) {
    PRINT("Mqtt Disconnect Reason: ");
    switch (reason) {
        case AsyncMqttClientDisconnectReason::TCP_DISCONNECTED: PRINTLN("TCP_DISCONNECTED"); break;
        case AsyncMqttClientDisconnectReason::MQTT_UNACCEPTABLE_PROTOCOL_VERSION:
            PRINTLN("MQTT_UNACCEPTABLE_PROTOCOL_VERSION");
            break;
        case AsyncMqttClientDisconnectReason::MQTT_IDENTIFIER_REJECTED:
            PRINTLN("MQTT_IDENTIFIER_REJECTED");
            break;
        case AsyncMqttClientDisconnectReason::MQTT_SERVER_UNAVAILABLE:
            PRINTLN("MQTT_SERVER_UNAVAILABLE");
            break;
        case AsyncMqttClientDisconnectReason::MQTT_MALFORMED_CREDENTIALS:
            PRINTLN("MQTT_MALFORMED_CREDENTIALS");
            break;
        case AsyncMqttClientDisconnectReason::MQTT_NOT_AUTHORIZED:
            PRINTLN("MQTT_NOT_AUTHORIZED");
            break;
        case AsyncMqttClientDisconnectReason::ESP8266_NOT_ENOUGH_SPACE:
            PRINTLN("ESP8266_NOT_ENOUGH_SPACE");
            break;
        case AsyncMqttClientDisconnectReason::TLS_BAD_FINGERPRINT:
            PRINTLN("TLS_BAD_FINGERPRINT");
            break;
    }
}
void PRINT_WIFI_DISCONNECT_REASON(const WiFiEventStationModeDisconnected &ev) {
    PRINTF("Disconnected from Wi-Fi with ssid: %s\r\n", ev.ssid.c_str());
    PRINTF("Reason code: %d | ", ev.reason);
    PRINT("\tReasonStr =>");
    switch (ev.reason) {
        case WIFI_DISCONNECT_REASON_UNSPECIFIED:
            PRINTLN("WIFI_DISCONNECT_REASON_UNSPECIFIED");
            break;
        case WIFI_DISCONNECT_REASON_AUTH_EXPIRE:
            PRINTLN("WIFI_DISCONNECT_REASON_AUTH_EXPIRE");
            break;
        case WIFI_DISCONNECT_REASON_AUTH_LEAVE: PRINTLN("WIFI_DISCONNECT_REASON_AUTH_LEAVE"); break;
        case WIFI_DISCONNECT_REASON_ASSOC_EXPIRE:
            PRINTLN("WIFI_DISCONNECT_REASON_ASSOC_EXPIRE");
            break;
        case WIFI_DISCONNECT_REASON_ASSOC_TOOMANY:
            PRINTLN("WIFI_DISCONNECT_REASON_ASSOC_TOOMANY");
            break;
        case WIFI_DISCONNECT_REASON_NOT_AUTHED: PRINTLN("WIFI_DISCONNECT_REASON_NOT_AUTHED"); break;
        case WIFI_DISCONNECT_REASON_NOT_ASSOCED:
            PRINTLN("WIFI_DISCONNECT_REASON_NOT_ASSOCED");
            break;
        case WIFI_DISCONNECT_REASON_ASSOC_LEAVE:
            PRINTLN("WIFI_DISCONNECT_REASON_ASSOC_LEAVE");
            break;
        case WIFI_DISCONNECT_REASON_ASSOC_NOT_AUTHED:
            PRINTLN("WIFI_DISCONNECT_REASON_ASSOC_NOT_AUTHED");
            break;
        case WIFI_DISCONNECT_REASON_DISASSOC_PWRCAP_BAD:
            PRINTLN("WIFI_DISCONNECT_REASON_DISASSOC_PWRCAP_BAD");
            break;
        case WIFI_DISCONNECT_REASON_DISASSOC_SUPCHAN_BAD:
            PRINTLN("WIFI_DISCONNECT_REASON_DISASSOC_SUPCHAN_BAD");
            break;
        case WIFI_DISCONNECT_REASON_IE_INVALID: PRINTLN("WIFI_DISCONNECT_REASON_IE_INVALID"); break;
        case WIFI_DISCONNECT_REASON_MIC_FAILURE:
            PRINTLN("WIFI_DISCONNECT_REASON_MIC_FAILURE");
            break;
        case WIFI_DISCONNECT_REASON_4WAY_HANDSHAKE_TIMEOUT:
            PRINTLN("WIFI_DISCONNECT_REASON_4WAY_HANDSHAKE_TIMEOUT");
            break;
        case WIFI_DISCONNECT_REASON_GROUP_KEY_UPDATE_TIMEOUT:
            PRINTLN("WIFI_DISCONNECT_REASON_GROUP_KEY_UPDATE_TIMEOUT");
            break;
        case WIFI_DISCONNECT_REASON_IE_IN_4WAY_DIFFERS:
            PRINTLN("WIFI_DISCONNECT_REASON_IE_IN_4WAY_DIFFERS");
            break;
        case WIFI_DISCONNECT_REASON_GROUP_CIPHER_INVALID:
            PRINTLN("WIFI_DISCONNECT_REASON_GROUP_CIPHER_INVALID");
            break;
        case WIFI_DISCONNECT_REASON_PAIRWISE_CIPHER_INVALID:
            PRINTLN("WIFI_DISCONNECT_REASON_PAIRWISE_CIPHER_INVALID");
            break;
        case WIFI_DISCONNECT_REASON_AKMP_INVALID:
            PRINTLN("WIFI_DISCONNECT_REASON_AKMP_INVALID");
            break;
        case WIFI_DISCONNECT_REASON_UNSUPP_RSN_IE_VERSION:
            PRINTLN("WIFI_DISCONNECT_REASON_UNSUPP_RSN_IE_VERSION");
            break;
        case WIFI_DISCONNECT_REASON_INVALID_RSN_IE_CAP:
            PRINTLN("WIFI_DISCONNECT_REASON_INVALID_RSN_IE_CAP");
            break;
        case WIFI_DISCONNECT_REASON_802_1X_AUTH_FAILED:
            PRINTLN("WIFI_DISCONNECT_REASON_802_1X_AUTH_FAILED");
            break;
        case WIFI_DISCONNECT_REASON_CIPHER_SUITE_REJECTED:
            PRINTLN("WIFI_DISCONNECT_REASON_CIPHER_SUITE_REJECTED");
            break;
        case WIFI_DISCONNECT_REASON_BEACON_TIMEOUT:
            PRINTLN("WIFI_DISCONNECT_REASON_BEACON_TIMEOUT");
            break;
        case WIFI_DISCONNECT_REASON_NO_AP_FOUND:
            PRINTLN("WIFI_DISCONNECT_REASON_NO_AP_FOUND");
            break;
        case WIFI_DISCONNECT_REASON_AUTH_FAIL: PRINTLN("WIFI_DISCONNECT_REASON_AUTH_FAIL"); break;
        case WIFI_DISCONNECT_REASON_ASSOC_FAIL: PRINTLN("WIFI_DISCONNECT_REASON_ASSOC_FAIL"); break;
        case WIFI_DISCONNECT_REASON_HANDSHAKE_TIMEOUT:
            break;
            PRINTLN("WIFI_DISCONNECT_REASON_HANDSHAKE_TIMEOUT");
            break;
    }
}
#endif