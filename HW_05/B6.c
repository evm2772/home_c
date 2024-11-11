#include <stdio.h>

int main()
{
    unsigned int num, digit, base = 10;
    scanf("%u", &num);
    if (num < base)
        {
            printf("NO");
            return 0;
        }
        
    unsigned int next_digit = 10;
    while (num >= base)
    {
        digit = num % base;
        if (next_digit == digit)
        {
            printf("YES");
            return 0;
        }
        num = num / base;
        next_digit = digit;
    }
    if (num == digit)
        {
            printf("YES");
            return 0;
        }
    printf("NO");
    return 0;
}
