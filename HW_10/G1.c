#include <stdio.h>
#define NUMBER 3


int main()
{
    FILE *rf;
    rf = fopen("input.txt", "r");
    if(rf == NULL)
    {
        printf("Error open file to read...\n");
        return 1;
    }
    char str[100] = {0};
    signed char c;
    unsigned char length = 0;
    
    while((c = fgetc(rf)) != EOF)
    {
        if (c != '\n')
        {
            str[length] = c;
            length++;
        } 
    }
    fclose(rf);
    
    FILE *wf = fopen("output.txt", "a");
    if(wf == NULL)
    {
        printf("Error open file to write...\n");
        return 1;
    }

    for (int i = 0; i < NUMBER - 1; i++)
    {

        fprintf(wf, "%s, ", str);
    }
    fprintf(wf, "%s %d", str, length);
    fclose(wf);
    return 0;
}
    
    
