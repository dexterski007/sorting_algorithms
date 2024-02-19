#include "sort.h"

/**
 * vexel - exchange values
 *
 * @pos1: position 1
 * @pos2: position 2
 */

void vexel(int *pos1, int *pos2)
{
	int temp = *pos1;
		temp = *pos1;
		*pos1 = *pos2;
		*pos2 = temp;
}

/**
 * hoare - partitioning by hoare
 *
 * @array: array
 * @size: size
 * @left: left posit
 * @right: right position
 *
 * Return: new size
 */

ssize_t hoare(int *array, size_t size, ssize_t left, ssize_t right)
{
	int up, down, piv = array[right];

	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < piv);
		do {
			down--;
		} while (array[down] > piv);

		if (up < down)
		{
			vexel(array + up, array + down);
			print_array(array, size);
		}
	}
	return (up);
}

/**
 * sort_alg - sorting algorithm
 *
 * @array: array
 * @size: size
 * @left: left posit
 * @right: right position
 */

void sort_alg(int *array, size_t size, ssize_t left, ssize_t right)
{
	if (right - left > 0)
	{
		ssize_t piv = hoare(array, size, left, right);

		sort_alg(array, size, left, piv - 1);
		sort_alg(array, size, piv, right);
	}
}

/**
 * quick_sort_hoare - quick sort hoare
 *
 * @array: array
 * @size: size
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort_alg(array, size, 0, size - 1);
}
