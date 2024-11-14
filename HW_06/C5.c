#include <stdio.h>

unsigned int sum(unsigned int x)
{
    unsigned int result = 0;
    for (int i = 1; i <= x; i++)
        result += i;
    return result;
}

int main()
{   
    unsigned int x;
    scanf("%u", &x);
    printf("%d", sum(x));
}
