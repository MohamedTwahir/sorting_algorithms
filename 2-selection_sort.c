#include "sort.h"

int main()
{
	int a[] = {5, 9, 7, 3, 2, 1};
	int length = 7;
	/* to go through the array we will use for loop */

	for (int i = 0; i < length - 1; i++)
	{
		/*find the smallest number in unsorted array*/
		int min_pos = i;
		for (int j = i + 1; j < length; j++)
			if (a[j] < a[min_pos]) min_pos = j;

		if (min_pos != i)
		{
			 int temp = a[i];
			 a[i] = a[min_pos];
			 a[min_pos] = temp;
		}
	
	}

	for (int i = 0; i < length; i++)
		printf("a[%d] = %d\n", i, a[i]);

	return (0);
}
