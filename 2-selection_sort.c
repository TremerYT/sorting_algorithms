#include "sort.h"

/**
 * integer_swap- This swaps two integers
 * @a: This is the first
 * @b: This is the second
 */

void integer_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * selection_sort - This sorts an array of integers
 * @array: This is an array of integers
 * @size: This is the size of the array
 */

void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minimum = array + i;
		for (j = i + 1; j < size; j++)
			minimum = (array[j] < *minimum) ? (array + j) : minimum;

		if ((array + i) != minimum)
		{
			integer_swap(array + i, minimum);
			print_array(array, size);
		}
	}
}
