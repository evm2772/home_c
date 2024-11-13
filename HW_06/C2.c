#include <stdio.h>

unsigned int power(unsigned int n, unsigned int p)
{
    unsigned int result = 1;
    for (int i = 0; i < p; i++)
        result *= n;
    return result;
}

int main()
{
    unsigned int n, p;
    scanf("%u %u", &n, &p);
    printf("%d", power(n, p));
}