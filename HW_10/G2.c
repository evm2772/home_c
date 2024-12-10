#include <stdio.h>

int get_digit(void)
{
    static int j = 0;
    j = (j == 0) ? 2: (j + 2) % 10;
    if (j == 0)
        j = 2;
    return j;
      
}

int main()
{
    FILE *rf;
    rf = fopen("input.txt", "r");
    if(rf == NULL)
    {
        printf("Error open file to read...\n");
        return 1;
    }
    int number;
    fscanf(rf, "%d", &number);
    fclose(rf);
    
    FILE *wf = fopen("output.txt", "a");
    if(wf == NULL)
    {
        printf("Error open file to write...\n");
        return 1;
    }
    
    for (int i = 0; i < number; i++)
    {
        fputc((i % 2) ?  get_digit() + '0': i/2 + 'A', wf);
    }
    fclose(wf);
    return 0;
}
    
    
