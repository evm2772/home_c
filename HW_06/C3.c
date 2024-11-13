#include <stdio.h>

unsigned int middle(unsigned int n, unsigned int p)
{
    return (n + p)/2;
}

int main()
{
    unsigned int n, p;
    scanf("%u %u", &n, &p);
    printf("%d", middle(n, p));
}