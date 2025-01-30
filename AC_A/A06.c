#include <stdio.h>
#include <inttypes.h>

int main()
{
    uint32_t num, mask = 0xFF000000;
    scanf("%u", &num);
    printf ("%u", num ^ mask);    
    return 0;

}