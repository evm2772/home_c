#include <stdio.h>
#include <inttypes.h>

int main()
{
    uint32_t num, k, result;
    scanf("%u %u", &num, &k);
    result = num << (32 - k);
    result = result >> (32 - k);
    printf ("%u",result);
    return 0;

}