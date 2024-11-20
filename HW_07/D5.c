#include <stdio.h>

void to_binary(unsigned int n)
{
    if (n < 2)
        printf("%d", n);
    else
    {
        to_binary(n / 2);  
        printf("%d", n % 2);
    }
    
}

int main()
{   unsigned int num;
    scanf("%u", &num);
    to_binary(num);
}
