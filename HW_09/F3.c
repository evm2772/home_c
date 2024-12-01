#include <stdio.h>

int main()
{
    int count[10] = {0};
    char n;
    while((n = getchar()) != '\n')
    {   
        count[(int)n - 48] += 1;
    }
    for (int i=0; i < 10; i++)
        if (count[i]) 
            printf("%d %d\n", i, count[i]);
}   

