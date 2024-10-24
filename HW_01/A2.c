
#include <stdio.h>


void print_with_spaces(const char *s, int space_n, int endline);

int main()
{   
    print_with_spaces("*", 5, 1);
    print_with_spaces("***", 4, 1);
    print_with_spaces("*****", 3, 1);
    print_with_spaces("*******", 2, 1);
    print_with_spaces("HHOHH", 3, 1);
    print_with_spaces("ZZZZZ", 3, 0);
    return 0;
}

void print_with_spaces(const char *s, int space_n, int endline)
{   
    int counter = 0;
    while(counter < space_n){
        printf(" ");
        counter++;
    }
    if (endline == 1)
        printf("%s\n", s);
    else 
        printf(s);
   
}