#ifndef SENSOR_H
#define SENSOR_H

#include <inttypes.h>

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hh;
    uint8_t mm;
    int8_t temperature;
} record_t;

void add_record(record_t *data,
                int index,
                uint16_t year,
                uint8_t month,
                uint8_t day,
                uint8_t hh,
                uint8_t mm,
                int8_t t);

int add_test_data(record_t* data);

void print_data(record_t* data, int number);

#endif
