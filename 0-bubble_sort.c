#include "sort.h"
/**
 * bubble_sort - function that sorts an array using bubble sort algorithm
 * @array: array to be sorted
 * @size: size of array to be sorted
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i;
	unsigned int j;
	int temp;

	if (size < 2)
		return;
	/* outer loop to control no of swaps*/
	for (i = 0; i < size; i++)
	{
		/*inner loop to do the swaps*/
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
