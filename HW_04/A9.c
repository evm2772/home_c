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
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	printf("%d", max_of_three(a, b , max_of_three(c, d, e)));
}
