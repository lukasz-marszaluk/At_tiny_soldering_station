#ifndef _SOLDERING_STATION_SENSOR_
#define _SOLDERING_STATION_SENSOR_

//  ============================================================================
#define SLOPE 1.0f
#define CONSTANT 0

//  ============================================================================
void init_sensor();

unsigned int read_temp();

//  ============================================================================
#endif //!_SOLDERING_STATION_SENSOR_