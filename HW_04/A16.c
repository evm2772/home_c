#include <stdio.h>

int main()
{
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	if ((x < y) && (y < z))
		printf("YES");
	else
		printf("NO");
}

