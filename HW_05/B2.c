#include <stdio.h>

int main()
{
    unsigned char start, end;
    scanf("%hhu %hhu", &start, &end);
    for (int i = start; i <= end; i++)
        printf("%d ",i*i);
}
