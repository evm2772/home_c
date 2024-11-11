#include <stdio.h>

int main()
{
    unsigned char num;
    scanf("%hhu", &num);
    for (int i = 1; i <= num; i++)
        printf("%d %d %d\n", i, i*i, i*i*i);
}
