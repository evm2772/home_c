
#include <stdio.h>


int main()
{   
    printf("%*s\n", 6, "*");
    printf("%*s\n", 7, "***");
    printf("%*s\n", 8, "*****");
    printf("%*s\n", 9, "*******");
    printf("%*s\n", 8, "HHOHH");
    printf("%*s", 8, "ZZZZZ");
    return 0;
}
