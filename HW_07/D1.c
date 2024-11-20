#include <stdio.h>

void print_n(unsigned int n)
{
    if(n > 1)
        print_n(n-1);    
    printf("%d ", n);
}

int main()
{   unsigned int num;
    scanf("%u", &num);
    print_n(num);
}
