#include <stdio.h>

void print_digit(char s[])
{
    
    int count[10] = {0};
    int code;
    while(*s != '\0')
    {   
        code = (int)(*s);
        if (code > 47 && code < 58)
            count[code - 48] += 1;
        s++;
    }
    
    for (int i=0; i < 10; i++)
        if (count[i]) 
            printf("%d %d\n", i, count[i]);
        
} 
/*
int main()
{
    print_digit("1.");    
}
*/
  

