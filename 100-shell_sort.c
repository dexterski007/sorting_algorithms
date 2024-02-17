#include "sort.h"

size_t gmax(size_t size);

/**
 * gmax - gap max
 *
 * @size: size
 *
 * Return: max gap
 */

size_t gmax(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = (gap * 3) + 1;
	return ((gap / 3) - 1);
}


/**
 * shell_sort - shell sort
 *
 * @array: array
 * @size: size
 */

void shell_sort(int *array, size_t size)
{
	size_t a, b, gap;
	int tmp;

	if (array == NULL || size == 0)
		return;

	for (gap = gmax(size); gap; gap = (gap - 1) / 3)
	{
		for (a = gap; a < size; a++)
		{
			tmp = array[a];
			for (b = a; b > gap - 1 && array[b - gap] > tmp; b -= gap)
				array[b] = array[b - gap];
			array[b] = tmp;
		}
		print_array(array, size);
	}

}
