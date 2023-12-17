#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort algorithm
 * @array: array to be sorted
 * @size: size/length of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_pos;

	register int temp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_pos])
				min_pos = j;
		}
		temp = array[i];
		array[i] = array[min_pos];
		array[min_pos] = temp;
		if (i != min_pos)
			print_array(array, size);
	}
}
