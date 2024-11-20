#include <stdio.h>

unsigned int sum(unsigned int n)
{
    if (n > 1)
        return sum(n - 1) + n;
    return 1;    
    
}

int main()
{   unsigned int num;
    scanf("%u", &num);
    printf("%u", sum(num));
}
