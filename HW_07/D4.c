#include <stdio.h>

void print_digits(unsigned int n)
{
    if (n < 10)
        printf("%d ", n);
    else
    {
        print_digits(n / 10);  
        printf("%d ", n % 10);
    }
    
}

int main()
{   unsigned int num;
    scanf("%u", &num);
    print_digits(num);
}
