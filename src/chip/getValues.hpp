#ifndef _GET_VALUES_H_
#define _GET_VALUES_H_

#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN 2

namespace chip
{
    void init(void)
    {
    }

    float *getvalues()
    {
        Serial.begin(115200); // Serial connection from ESP-01 via 3.3v console cable
        DHT dht(DHTPIN, DHTTYPE, 11);
        dht.begin();            // initialize temperature sensor
        float humidity, temp_f; // Values read from sensor
        // Generally, you should use "unsigned long" for variables that hold time
        unsigned long previousMillis = 0; // will store last temp was read
        const long interval = 2000;       // interval at which to read sensor
        // Wait at least 2 seconds seconds between measurements.
        // if the difference between the current time and last time you read
        // the sensor is bigger than the interval you set, read the sensor
        // Works better than delay for things happening elsewhere also
        unsigned long currentMillis = millis();

        if (currentMillis - previousMillis >= interval)
        {
            // save the last time you read the sensor
            previousMillis = currentMillis;

            // Reading temperature for humidity takes about 250 milliseconds!
            // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
            float results[1];
            results[0] = dht.readHumidity();        // Read humidity (percent)
            results[1] = dht.readTemperature(true); // Read temperature as Fahrenheit
            // Check if any reads failed and exit early (to try again).

            if (isnan(humidity) || isnan(temp_f))
            {
                Serial.println("Failed to read from DHT sensor!");
            }
            else
            {
                return results;
            }
        }
    }
} // namespace chip
#endif // !_GET_VALUES_H_