const char *ssid = "SSID";
const char *password = "PASS";
const char *device = "DEVICE";

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "chip/getValues.hpp"

ESP8266WebServer server(80);

String webString = ""; // String to display
void path_root()
{
    webString = "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>MarkSheet</title><meta name=\"description\" content=\"Temperature and humidity output\"></head><body>";
    webString = "<table style=\"text-align:center;width:100%;font-size:8vw;border-collapse: collapse;font-family: Arial;\">";
    webString += "<tr><td style=\"background-color:#2E9AFE;color:white\">esp8266 #1</td></tr><tr><td>" + String(device) + "</td></tr>";
    webString += "<tr><td style=\"background-color:#2E9AFE;color:white\">Cockpit</td></tr><tr><td><a href=\"/cockpit\">/cockpit</a></td></tr>";
    webString += "<tr><td style=\"background-color:#2E9AFE;color:white\">Values in Json</td></tr><tr><td><a href=\"/data\">/values</a></td></tr>";
    webString += "</table>";
    webString += "</body></html>";
    server.send(200, "text/html", webString);
    delay(100);
}

void path_cockpit()
{
    float *values = ::chip::getvalues();
    float temp_c = (values[1] - 32) * 5 / 9;
    webString = "<table style=\"text-align:center;width:100%;font-size:8vw;border-collapse: collapse;font-family: Arial;\">";
    webString += "<tr><td style=\"background-color:#2E9AFE;color:white\">Temperature</td></tr><tr><td>" + String((float)temp_c) + " C</td></tr>"; // Arduino has a hard time with float to string
    webString += "<tr><td style=\"background-color:#2E9AFE;color:white\">Humidity</td></tr><tr><td>" + String((float)values[0]) + "%</td></tr>";
    webString += "</table>";
    server.send(200, "text/html", webString); // send to someones browser when asked
}

void path_data()
{
    float *values = ::chip::getvalues();
    float temp_c = (values[1] - 32) * 5 / 9;
    String webString = "{\"infos\":{ \"temperature\": \"" + String((float)temp_c) + "\", \"humidite\": \"" + String((float)values[0]) + "\"}}";
    server.send(200, "application/json", webString); // send to someones browser when asked
}

void setup(void)
{
    // Connect to WiFi network
    WiFi.begin(ssid, password);
    Serial.print("\n\r \n\rWorking to connect");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("DHT temperature and humidity from DHT11");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", path_root);

    server.on("/cockpit", path_cockpit);

    server.on("/data", path_data);

    server.begin();
    Serial.println("HTTP server started");
}

void loop(void)
{
    server.handleClient();
}
