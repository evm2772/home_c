#include <stdio.h>

 void input_array(int *array, int length)
{
    for (int i=0; i < length; i++)
    {
        scanf("%d", (array + i));
    }
   
}

float get_mean(int *array, int length)
{
    int sum = 0;
    for (int i=0; i < length; i++)
    {
        sum+=*(array+i);
    }
    return sum/(float)length;
}

int main()
{
    int n = 5;
    int array[n];
    input_array(array, n);
    printf("%.3f",get_mean(array, n));
    
}
