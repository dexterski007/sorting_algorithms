#include "sort.h"

void vexel(int *array, size_t size, int *pos1, int *pos2);
ssize_t lomuto(int *array, size_t size, ssize_t down, ssize_t up);
void sort_alg(int *array, size_t size, ssize_t down, ssize_t up);

/**
 * vexel - exchange values
 *
 * @array: array
 * @size: size
 * @pos1: position 1
 * @pos2: position 2
 */

void vexel(int *array, size_t size, int *pos1, int *pos2)
{
	int temp = *pos1;

	if (*pos1 != *pos2)
	{
		temp = *pos1;
		*pos1 = *pos2;
		*pos2 = temp;
		print_array(array, size);
	}
}

/**
 * lomuto - partitioning by lomuto
 *
 * @array: array
 * @size: size
 * @down: down posit
 * @up: up position
 *
 * Return: new size
 */

ssize_t lomuto(int *array, size_t size, ssize_t down, ssize_t up)
{
	int i, j, piv = array[up];

	for (i = j = down; j < up; j++)
		if (array[j] < piv)
		{
			vexel(array, size, &array[j], &array[i]);
			i++;
		}
	vexel(array, size, &array[i], &array[up]);
	return (i);
}

/**
 * sort_alg - sorting algorithm
 *
 * @array: array
 * @size: size
 * @down: down posit
 * @up: up position
 */

void sort_alg(int *array, size_t size, ssize_t down, ssize_t up)
{
	if (down < up)
	{
		ssize_t piv = lomuto(array, size, down, up);

		sort_alg(array, size, down, piv - 1);
		sort_alg(array, size, piv + 1, up);
	}
}

/**
 * quick_sort - quick sort
 *
 * @array: array
 * @size: size
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;
	sort_alg(array, size, 0, size - 1);
}
