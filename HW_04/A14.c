#include <stdio.h>

int max_of_three(int a, int b, int c)
{
	if (a > b && a > c)
		return a;
	else
		return (b > c ? b: c);
}


int main()
{
	int a;
	scanf("%d", &a);
	printf("%d", max_of_three(a / 100, a % 100 / 10, a % 10));
}
