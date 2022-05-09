#define CATCH_CONFIG_MAIN  
#include "test/catch.hpp"
#include "sensorDataAcquisition.h"
#include <string.h>
#include <stdio.h>

SCENARIO("Validate JSON Data format")
{
    GIVEN("sensor data of battery temperature and charging current")
    {
		char actualData[64];
		char *expectedData = "{\"Temperature\": 14.6, \"ChargingCurrent\": 4.9}";
		BMS sensor_data;
		sensor_data.temperature = 14.6;
		sensor_data.chargingCurrent = 4.9;

        WHEN("postProcessingSensorData() is called with given sensor data")
        {
            postProcessingSensorData (sensor_data, actualData);
			printf ("actual is %s\nexpected is %s\n", actualData, expectedData);
            THEN("raw sensor data will be converted to Json format")
            {
                REQUIRE(strcmp(actualData, expectedData) == 0);
            }
        }
    }
}