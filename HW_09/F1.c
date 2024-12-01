#include <stdio.h>

void sort_array(int size, int a[])
{   
    int temp, i;
    while(1)
    {
        int sorted = 1;
        for (i=0; i < size - 1; i++)
        {
            if (a[i] > a[i + 1]) 
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                sorted  = 0;
            }
        };
        if (sorted) 
            break; 
    }
};
/*
int main()
{
    //Test:
    int array[] = {2, 45, 34 , 23, 678, 23, 1, -23, -34};
    int size = sizeof(array) / sizeof(int);
    sort_array(size, array);
    for (i = 0; i < size; i++)
    {
        printf("%d ", *(a + i));
    }
}
*/
