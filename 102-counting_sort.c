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
 * counting_sort - counting
 * @array: array
 * @size: size
 */
void counting_sort(int *array, size_t size)
{
	int *arrayc, *arrays, mx, c;

	if (array == NULL || size < 2)
		return;

	arrays = malloc(sizeof(int) * size);

	if (arrays == NULL)
		return;

	mx = gmax(array, size);
	arrayc = malloc(sizeof(int) * (mx + 1));

	if (arrayc == NULL)
	{
		free(arrays);
		return;
	}
	for (c = 0; c < (mx + 1); c++)
		arrayc[c] = 0;
	for (c = 0; c < (int)size; c++)
		arrayc[array[c]] += 1;

	for (c = 0; c < (mx + 1); c++)
		arrayc[c] += arrayc[c - 1];

	print_array(arrayc, mx + 1);

	for (c = 0; c < (int)size; c++)
	{
		arrays[arrayc[array[c]] - 1] = array[c];
		arrayc[array[c]] -= 1;
	}

	for (c = 0; c < (int)size; c++)
		array[c] = arrays[c];

	free(arrays);
	free(arrayc);
}
