#include "sort.h"

/**
 * gmax - get max
 * @array: array
 * @size: size
 *
 * Return: maxval
 */
int gmax(int *array, int size)
{
	int mx, c;

	for (mx = array[0], c = 1; c < size; c++)
	{
		if (array[c] > mx)
			mx = array[c];
	}
	return (mx);
}

/**
 * sort_alg - alg radix
 * @array: array
 * @size: size
 * @dig: digit
 * @buffer: buffer
 */

void sort_alg(int *array, size_t size, int dig, int *buffer)
{
	int arrayc[10], i;
	size_t j;

	for (i = 0; i < 10; i++)
		arrayc[i] = 0;

	for (j = 0; j < size; j++)
		arrayc[(array[j] / dig) % 10] += 1;

	for (j = 0; j < 10; j++)
		arrayc[j] += arrayc[j - 1];

	for (j = size - 1; (int)j >= 0; j--)
	{
		buffer[arrayc[(array[j] / dig) % 10] - 1] = array[j];
		arrayc[(array[j] / dig) % 10] -= 1;
	}
	for (j = 0; j < size; j++)
		array[j] = buffer[j];
}

/**
 * radix_sort - radix
 * @array: array
 * @size: size
 */
void radix_sort(int *array, size_t size)
{
	int mx, *buffer, dig;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	mx = gmax(array, size);
	for (dig = 1; mx / dig > 0; dig *= 10)
	{
		sort_alg(array, size, dig, buffer);
		print_array(array, size);
	}

	free(buffer);
}
