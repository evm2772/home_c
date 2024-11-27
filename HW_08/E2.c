#include <stdio.h>

 void input_array(int *array, int length)
{
    for (int i=0; i < length; i++)
    {
        scanf("%d", (array + i));
    }
   
}

int get_min(int *array, int length)
{
    int min = array[0];
    for (int i=1; i < length; i++)
    {
        if (array[i] < min)
            min = array[i];
    }
    return min;
}

int main()
{
    int n = 5;
    int array[n];
    input_array(array, n);
    printf("%d",get_min(array, n));
}
