#include <stdio.h>

int abs(int num)
{
    if (num < 0)
        return -num;
    else
        return num;
}

int main()
{
    unsigned int n;
    scanf("%u", &n);
    printf("%d", abs(n));
}