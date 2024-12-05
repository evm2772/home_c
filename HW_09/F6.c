#include <stdio.h> 
int is_two_same(int size, int a[])
{	
	int i = 0;
	for (int i=0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if ( *(a + i) == *(a + j))
				return 1;
		}
	}
	return 0;
}