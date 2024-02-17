#include "sort.h"

/**
 * selection_sort - selection sort
 *
 * @array: array
 * @size: size
 */

void selection_sort(int *array, size_t size)
{
	size_t i, k, index;
	int tmp;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (k = i + 1; k < size; k++)
		{
			if (array[k] < array[index])
				index = k;
		}
		if (index != i)
		{
			tmp = array[i];
			array[i] = array[index];
			array[index] = tmp;		
			print_array(array, size);
		}
	}
}
