#include <stdio.h>
#include <locale.h>

int main(int argc, char **argv)
{   
    setlocale(LC_ALL, "");
    printf("Hello MIPT World!\n");
    printf("Привет мир!\n");
    return 0;
}

