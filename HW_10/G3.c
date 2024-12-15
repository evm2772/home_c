#include <stdio.h>
#define LENGTH 1000

int main()
{
    char str[LENGTH + 1];
    signed char c;
    unsigned char length = 0;
    FILE *rf;
    rf = fopen("input.txt", "r");
    if(rf == NULL)
    {
        printf("Error open file to read...\n");
        return 1;
    }
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
    
    for (int i = 0; i < (length - 1); i++)
    {
        if (str[i] == str[length - 1])
        {
            fputc('0' + i, wf);
            fputc(' ', wf);
        }
    } 
    fclose(wf);
    return 0;
}
    
    
