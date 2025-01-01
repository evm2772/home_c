#include <stdio.h>
#include "sensor.h"

void add_record(record_t *data,
                int index,
                uint16_t year,
                uint8_t month,
                uint8_t day,
                uint8_t hh,
                uint8_t mm,
                int8_t t)
{   

    (data + index)->year = year;
    (data + index)->month = month;
    (data + index)->day = day;
    (data + index)->hh = hh;
    (data + index)->mm = mm;
    (data + index)->temperature = t;
}


int add_test_data(record_t* data)
{
    int index=0;  
    add_record(data, index++, 2021, 9, 16, 23, 56, -12);
    add_record(data, index++, 2021, 9, 17, 23, 56, -10);
    add_record(data, index++, 2023, 5, 23, 23, 56, -4);
    add_record(data, index++, 2020, 9, 31, 23, 34, -1);
    add_record(data, index++, 2021, 11, 16, 23, 56, -10);
    return index;
}


void print_data(record_t* data,int number)
{
    printf("===================================\n");        
    for(int i = 0; i < number; i++)
        printf("%04d-%02d-%02d %02d:%02d t = %3d\n",    
            data[i].year,
            data[i].month,
            data[i].day,
            data[i].hh,
            data[i].mm,
            data[i].temperature
        );
}
