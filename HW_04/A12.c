#include <stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	printf("%d", a / 100 + a % 100 / 10 + a % 10);
}
