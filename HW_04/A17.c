#include <stdio.h>

int main()
{
	unsigned char month_num;
	scanf("%hhu", &month_num);
	if (month_num < 3 || month_num == 12)
		printf("winter");
	else if (month_num < 6)
		printf("spring");
	else if (month_num < 9)
		printf("summer");
	else
		printf("autumn");
		
}

