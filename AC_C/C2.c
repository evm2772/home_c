
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define STACK_MAX_SIZE 256

typedef int T;

typedef struct Stack_tag 
{
    T data[STACK_MAX_SIZE];
    size_t size;
} Stack_t;

 
void push(Stack_t *stack, const T value) 
{
    if (stack->size >= STACK_MAX_SIZE) {
        exit(STACK_OVERFLOW);
    }
    stack->data[stack->size] = value;
    stack->size++;
}

T pop(Stack_t *stack) 
{
    if (stack->size == 0) {
        exit(STACK_UNDERFLOW);
    }
    stack->size--;
    return stack->data[stack->size];
}


void printStackValue(const T value) {
    printf("%d", value);
}
 
void printStack(const Stack_t *stack, void (*printStackValue)(const T)) {
    int i;
    int len = stack->size - 1;
    printf("stack %d > ", stack->size);
    for (i = 0; i < len; i++) {
        printStackValue(stack->data[i]);
        printf(" | ");
    }
    if (stack->size != 0) {
        printStackValue(stack->data[i]);
    }
    printf("\n");
}

void operate( Stack_t *stack, char c) 
{
    T arg1 = pop(stack), arg2 = pop(stack);
    switch(c)
    {
        case '+':
            push(stack,  arg1 + arg2);
        break;
        case '-':
            push(stack, arg2-arg1);
        break;      
        case '*':
            push(stack, arg1*arg2);
        break;              
        case '/':
            push(stack, arg2/arg1);
        break;              
    }
}
_Bool isDigit(char c) // проверяем является ли символ цифрой
{
    return (( c>='0' ) && (c <= '9'));
}   

_Bool isOperator(char c) {
    return c=='+' ||  c=='-' ||  c=='*' || c=='/';
}


int main(void)
{
    char c;
    Stack_t stack;
    stack.size = 0;
    char str[1000];    
    int len=0;    
    while((c=getchar())!='.')
        str[len++]=c;
        
    for(int i=0; i < len; i++)    
    {
        if(isDigit(str[i]))
        {
            T number;
            for(number = 0; isDigit(str[i]); i++) 
                number = number*10 + str[i] - '0';
            push(&stack, number);
        }        
        else
        {
            if(i >= len)            
                break;
            if(isOperator(str[i]))
                 operate(&stack, str[i]);
        }
    }
    printf("%d\n",pop(&stack));    
    return 0;
}
