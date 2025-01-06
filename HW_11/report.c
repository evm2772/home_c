#include <stdio.h>
#include "sensor.h"
#include "temp_api.h"

#define DATA_SIZE 5

int main()
{
    record_t data[DATA_SIZE];
    add_test_data(data);
    print_data(data, DATA_SIZE);
    return 0;
}
