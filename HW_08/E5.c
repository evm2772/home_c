#include <stdio.h>

 void input_array(int *array, int length)
{
    for (int i=0; i < length; i++)
    {
        scanf("%d", (array + i));
    }
   
}

int sum_all_positive(int *array, int length)
{   
    int sum = 0; 
    for (int i = 0; i < length; i++)
    {   
        if (array[i] > 0)
            sum += array[i];
    }
    return sum;
}

int main()
{   
    int n = 10;
    int array[n];
    input_array(array, n);
    printf ("%d", sum_all_positive(array, n));
}
