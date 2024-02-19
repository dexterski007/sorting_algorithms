#include "sort.h"
#define UP 0
#define DOWN 1

/**
 * vexel - exchange values
 *
 * @pos1: position 1
 * @pos2: position 2
 */

void vexel(int *pos1, int *pos2)
{
	int temp = *pos1;
		*pos1 = *pos2;
		*pos2 = temp;
}


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
 * merge - bitonci merger
 * @array: array
 * @size: size
 * @begin: begin index
 * @block: block size
 * @direc: sequence direction
 */

void merge(int *array, size_t size, size_t begin, size_t block, char direc)
{
	size_t j, skip = block / 2;

	if (block > 1)
	{
		for (j = begin; j < begin + skip; j++)
		{
			if ((direc == UP && array[j] > array[j + skip]) ||
				(direc == DOWN && array[j + skip]))
				vexel(array + j, array + j + skip);
		}
		merge(array, size, begin, skip, direc);
		merge(array, size, begin + skip, skip, direc);
	}
	
}

/**
 * sequence - bitonci converter
 * @array: array
 * @size: size
 * @begin: begin index
 * @block: block size
 * @direc: sequence direction
 */

void sequence(int *array, size_t size, size_t begin, size_t block, char direc)
{
	size_t split = block / 2;
	char *str;

	if (direc == UP)
		str = "UP";
	else
		str = "DOWN";

	if (block > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", block, size, str);
		print_array(array + begin, block);
		sequence(array, size, begin, split, UP);
		sequence(array, size, begin + split, split, DOWN);
		merge(array, size, begin, block, direc);
		printf("Result [%lu/%lu] (%s):\n", block, size, str);
		print_array(array + begin, block);
	}
	
}

/**
 * radix_sort - radix
 * @array: array
 * @size: size
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sequence(array, size, 0, size, UP);
}
