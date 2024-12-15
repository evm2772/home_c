#include <stdio.h>

int main()
{
    // File ro read
    FILE *rf = fopen("input.txt", "r");
    if (rf == NULL)
    {
        perror("File open error...");
        return 1;
    }
    
    // File to write
    FILE *wf = fopen("output.txt", "w");
    if(wf == NULL)
    {
        printf("Error open file to write...\n");
        return 1;
    }

    char c;
    while((c = fgetc(rf)) != EOF)
    {
        if ((c == 'A'))
        {
            fputc('B', wf);
            continue;
        }
        
        if ((c == 'a'))
        {
            fputc('b', wf);
            continue;
        }
        if ((c == 'B'))
        {
            fputc('A', wf);
            continue;
        }
        
        if ((c == 'b'))
        {
            fputc('a', wf);
            continue;
        }
        fputc(c, wf);
    }
    fclose(rf);
    fclose(wf);
    return 0;
}
    
    
