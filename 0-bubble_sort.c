#include <stdio.h>
/**
 * the way bubble sort works is if two items are not in order it swaps them to be in either ascending or descending order.
 */
int main(void)
{
	int a[] = {5, 1, 6, 8, 5};
	int length = 5;
	 /* outer loop control the number of passes */
	/* the inner loops will do the passes/swaps */
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < (length -1); j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	
	}
	for (int i = 0; i < length; i++)
		printf("a[%d] = %d\n", i, a[i]);


	return (0);
}
