#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

int contains(int *arr, int size, int number) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == number) 
        {
            return 1;
        }
    }
    return 0;
}

int main() {
    char number[MAX_LEN]; 
    scanf("%s", number);
    int len = strlen(number); 
    int uniqueNumbers[1000];  
    int count = 0;           

    for (int i = 0; i < len; i++) 
    {
        for (int j = i + 1; j < len; j++) 
        {
            for (int k = j + 1; k < len; k++)
             {
                int threeDigitNumber = (number[i] - '0') * 100 +
                                      (number[j] - '0') * 10 +
                                      (number[k] - '0');

                if (threeDigitNumber >= 100 && !contains(uniqueNumbers, count, threeDigitNumber)) 
                {
                    uniqueNumbers[count++] = threeDigitNumber;
                }
            }
        }
    }
    printf("%d", count);
    return 0;
}