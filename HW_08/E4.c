#include <stdio.h>

 void input_array(int *array, int length)
{
    for (int i=0; i < length; i++)
    {
        scanf("%d", (array + i));
    }
   
}


int sum_2_max(int *array, int length)
{   
    int sum = array[0] + array[1]; 
    for (int i = 0; i < length; i++)
    {   
        for (int j = 0; j < length; j++)
        {
            if (j == i) 
                continue;
            if ((array[i] + array[j]) > sum)
            {
                sum = array[i] + array[j];
            }
        }
    }
    
    return sum;
}

int main()
{   
    int n = 10;
    int array[n];
    input_array(array, n);
    printf ("%d", sum_2_max(array, n));
}
