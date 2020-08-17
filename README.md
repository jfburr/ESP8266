# ESP8266_DHT11

ESP8266 software for DHT11 sesor

This is a web server providing a basic API and web interface to share data and temperature for a DHT11 sensor with an ESP8266 connecting to wifi.

```
WARNING: This project is under R&D in alpha mode (concept working) and is meant to be improved.
It should not use in production as it is.
There is currently no test coverage.
```

## Sources

This work is based/copies/inspired by

- Wifi and communication: Mike Barela for Adafruit Industries work, based on ESP8266Webserver, DHTexample, and BlinkWithoutDelay work: https://learn.adafruit.com/esp8266-temperature-slash-humidity-webserver/code
- Project structure: https://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/

# Setup

## Configuration

Following constants are mandatory to fill:

- const char \*ssid = "WIFI NAME";
- const char \*password = "WIFI PASS";
- const char \*device = "DEVICE NAME";

## Send to device

### Mac

Installation on macOS 10.15.6

#### Arduino

> brew cask install arduino

- Source: https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/

#### Fix compile error with python

- Source: https://www.esp8266.com/viewtopic.php?t=20561

#### DHT11

Install DHT sensor labs in arduino IDE as library

- Source: https://github.com/adafruit/DHT-sensor-library
- Follow source: https://lastminuteengineers.com/esp8266-dht11-dht22-web-server-tutorial/

# Functions

## Hello

- Path: /
  A basic hello message giving the name of the device

## Cockpit

- Path: /cockpit
  An url is dedicated to display current values of temperature and humidity.

## API

- Path: /values
  This will anwser a JSON with following structure:
  `{"infos":{ "temperature": "XX", "humidite": "YY"}}`

