#include <stdio.h>

int find_max_array(int size, int a[])
{   
    int max = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
};

/*
int main()
{
    //Test:
    int array[] = {2, 45, 34 , 23, 678, 23, 1, -23, -34};
    int size = sizeof(array) / sizeof(int);
    printf("%d", find_max_array(size, array));
}
*/
