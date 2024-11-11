#include <stdio.h>

int main()
{
    unsigned char start, end;
    unsigned int sum = 0;
    scanf("%hhu %hhu", &start, &end);
    for (int i = start; i <= end; i++)
        sum += i*i;
    printf("%d ",sum);
}
