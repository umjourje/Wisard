#ifndef TERMOMETRO_H
#define TERMOMETRO_H

#define QTD_SENSORS         8
#define N_BITS              1024
#define SENSOR_MIN          0
#define SENSOR_MAX          1023

void termometerCoding(int valorTermometro, int *arraySensor);

#endif
