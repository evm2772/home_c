#include <stdio.h>
#define MAX_LEN 1000


int is_palindrom(char *str)
{
    int len;
    for (len = 0; len < MAX_LEN; len++)
    {   
        if(str[len] == '\0' || str[len] == 10)
        {
            break;
        }
    }
    for (int i = 0; i < len/2; i++)
    {
        if (str[i] != str[len - i -1])
            return 0;
        //printf("\n%c -- %c", str[i], str[len - i -1]);
    }
    return 1;
}

int main()
{
    // File ro read
    char str[MAX_LEN] = {'\0'};
    FILE *rf = fopen("input.txt", "r");
    if (rf == NULL)
    {
        perror("File open error...");
        return 1;
    }
    fgets(str, MAX_LEN, rf);
    fclose(rf);
    
    FILE *wf = fopen("output.txt", "w");
    if(wf == NULL)
    {
        printf("Error open file to write...\n");
        return 1;
    }
    if (is_palindrom(str))
        fputs("YES", wf);
    else
        fputs("NO", wf);
    fclose(wf);
    return 0;
}
    
    
