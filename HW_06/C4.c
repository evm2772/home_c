#include <stdio.h>

int foo(int x)
{
    if (x < -2)
        return 4;
    if (x >= 2)
        return x*x + 4*x + 5;
    return x*x;
}

int main()
{   
    int n, result, val;
    scanf("%d", &n);
    result = foo(n);
    while(1)
    {
        scanf("%d", &n);
        if (!n) 
            break;
        val = foo(n);
        if (val > result)
            result = val;
            
    }
    printf("%d", result);
}
