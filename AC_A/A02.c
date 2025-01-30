#include <stdio.h>
#include <inttypes.h>

int main()
{
    uint32_t num, shift, result;
    scanf("%u %u", &num, &shift);
    result = (uint32_t)(num >> shift) | (uint32_t)(num << (32 - shift));
    printf ("%u", (uint32_t)result);
    return 0;

}