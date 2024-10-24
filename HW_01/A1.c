
#include <stdio.h>

void print_spaces(int space_n)
{   
    int counter = 0;
    while(counter < space_n)
    {
        printf(" ");
        counter++;
    }
}


int main()
{   
    printf("\t Let's\n");
    printf("\t\t   go\n");
    //printf("%20s","Hello world!");
    //print_trailed("sssssss", 3);
    return 0;
}

