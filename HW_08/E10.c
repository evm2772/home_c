#include <stdio.h>
#define ARRAY_SIZE 12
#define SHIFT 4
#define LEFT 1
#define RIGHT 0

 void input_array(int *array, int length)
{
    for (int i=0; i < length; i++)
    {
        scanf("%d", (array + i));
    }
   
}

void print_array(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", *(array + i));
    }
}

void cilcle_shift_step(int *array, int length, int d)
{
    int temp;
    if (d == 1)
    {
        temp = array[0];
        for (int i = 0 ; i < length - 1; i++)
            array[i] = array[i + 1];
        array[length - 1] = temp;
        
    }
    else
    {
        temp = array[length - 1];
        for (int i = length - 1 ; i > 0; i--)
            array[i] = array[i - 1];
        array[0] = temp;
    }

}

int main()
{   
    int array[ARRAY_SIZE];
    input_array(array, ARRAY_SIZE);
    int i = 0;
    while(i < SHIFT)
        {
            cilcle_shift_step(array, ARRAY_SIZE, RIGHT);
            i++;
        }
    print_array(array, ARRAY_SIZE);
}
