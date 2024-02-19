#include "sort.h"
#define superp(x) (((x) - 1) / 2)
#define leftc(x) (((x) * 2) + 1)

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
 * sort_alg - sorting algorithm
 *
 * @array: array
 * @beg: beginning
 * @last: last
 * @size: size
 */

void sort_alg(int *array, size_t beg, size_t last, size_t size)
{
	size_t orig = beg, chng, inf;

	while (leftc(orig) <= last)
	{
		inf = leftc(orig);
		chng = orig;
		if (array[chng] < array[inf])
			chng = inf;
		if (inf + 1 <= last && array[chng] < array[inf + 1])
			chng = inf + 1;
		if (chng == orig)
			return;
		vexel(array, size, &array[orig], &array[chng]);
		orig = chng;
	}
}


/**
 * toheap - to heap
 *
 * @array: array
 * @size: size
 */

void toheap(int *array, size_t size)
{
	ssize_t beg;

	beg = superp(size - 1);
	while (beg >= 0)
	{
		sort_alg(array, beg, size - 1, size);
		beg--;
	}
}

/**
 * heap_sort - heap sort
 *
 * @array: array
 * @size: size
 */

void heap_sort(int *array, size_t size)
{
	size_t last;

	if (!array || size < 2)
		return;

	toheap(array, size);
	last = size - 1;
	while (last > 0)
	{
		vexel(array, size, &array[last], &array[0]);
		last--;
		sort_alg(array, 0, last, size);
	}

}
