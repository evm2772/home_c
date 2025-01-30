#include <stdio.h>
#include <inttypes.h>

int main()
{
    uint32_t num, bit_1 = 0;
    scanf("%u", &num);
    while(num > 1)
    {
        bit_1 +=  num % 2;
        num /= 2;
    }
    printf ("%u", bit_1 + num);    
    return 0;

}