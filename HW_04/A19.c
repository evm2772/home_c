#include <stdio.h>

int main()
{
	unsigned int a, b, c;
	scanf("%u %u %u", &a, &b, &c);
	if ((a + b) > c && (a + c) > b && (c + b) > a)
		printf("YES");
	else 
		printf("NO");
}
