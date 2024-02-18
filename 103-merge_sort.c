#include "sort.h"

/**
 * merge_cmp - merge compare
 *
 * @array: size
 * @beg: begin
 * @end: end
 * @dupl: dupliarray
 */

void merge_cmp(int *array, size_t beg, size_t end, int *dupl)
{
	size_t mi, i = beg, j, o;

	j = mi = (beg + end) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + beg, mi - beg);
	printf("[right]: ");
	print_array(array + mi, end - mi);
	for (o = beg; o < end; o++)
	{
		if (i < mi && (j >= end || array[i] <= array[j]))
			dupl[o] = array[i++];
		else
			dupl[o] = array[j++];
	}
	printf("[Done]: ");
	print_array(dupl + beg, end - beg);
}

/**
 * merge_s - merge treatment
 *
 * @array: size
 * @beg: begin
 * @end: end
 * @dupl: dupliarray
 */

void merge_s(int *array, size_t beg, size_t end, int *dupl)
{
	size_t mi;

	mi = (beg + end) / 2;
	if (end - beg < 2)
		return;
	merge_s(dupl, 0, mi, array);
	merge_s(dupl, mi, end, array);
	merge_cmp(array, beg, end, dupl);
}


/**
 * merge_sort - merge sort
 *
 * @array: array
 * @size: size
 */

void merge_sort(int *array, size_t size)
{
	int *dupl;
	size_t i = 0;

	if (array == NULL || size < 2)
		return;

	dupl = malloc(sizeof(int) * size);
	if (dupl == NULL)
		return;

	for (i = 0; i < size; i++)
		dupl[i] = array[i];

	merge_s(dupl, 0, size, array);


	free(dupl);
}
