#include <stdio.h>

void print_digits_rev(unsigned int n)
{
    if (n < 10)
        printf("%d ", n);
    else
    {
        printf("%d ", n % 10);
        print_digits_rev(n / 10);   
    }
    
}

int main()
{   unsigned int num;
    scanf("%u", &num);
    print_digits_rev(num);
}
