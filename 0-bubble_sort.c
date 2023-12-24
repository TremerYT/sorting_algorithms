#include "sort.h"

/**
 * integer_swap - This swaps integers
 * @a: This is the first int
 * @b: This is is the second int
 */

void integer_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * bubble_sort - This sorts an array of integers in ascending
 * @array: This is the array of int
 * @size: This is the size
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, extent = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (a = 0; a < extent - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				integer_swap(array + a, array + a + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		extent--;
	}
}
