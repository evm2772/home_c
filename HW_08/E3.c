#include <stdio.h>

 void input_array(int *array, int length)
{
    for (int i=0; i < length; i++)
    {
        scanf("%d", (array + i));
    }
   
}

void print_min_max(int *array, int length)
{
    int min_i = 0, max_i = 0;
    int min = array[0], max = array[0];
    for (int i=0; i < length; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
            min_i = i;
        };
        if (array[i] > max)
        {
            max = array[i];
            max_i = i;
        }
    }
    printf ("%d %d %d %d", max_i + 1, max, min_i + 1, min);
}

int main()
{   
    int n = 10;
    int array[n];
    input_array(array, n);
    print_min_max(array, n);
}
