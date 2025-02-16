#include <stdio.h>
#include <inttypes.h>

typedef struct list 
{   uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

uint64_t findMaxBlock(list *head)
{
    size_t max_size = 0;
    uint64_t result = 0; 
    while (head) 
    {

        if (head->size > max_size) 
        {
            max_size = head->size;
            result = head->address;
        }
        head = head->next;
    }
    return result;
};


