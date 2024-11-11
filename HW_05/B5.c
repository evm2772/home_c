#include <stdio.h>

int main()
{
    unsigned int num, rem, sum = 0, base = 10;
    scanf("%u", &num);
    while (num >= base)
    {
        rem = num % base;
        num = num / base;
        sum += rem;
    }
    printf ("%d", sum + num);
}
