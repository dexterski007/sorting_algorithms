#include "sort.h"

/**
 * bubble_sort - bubble sort
 *
 * @array: array
 * @size: size
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, k = 0;
	int tmp = 0;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (k = 0; k < size - i - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				tmp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
