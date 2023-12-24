#include "sort.h"

/**
 * integer_swap - This swaps two integers of an array
 * @a: This is the first int
 * @b: This is the second int
 */

void integer_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * partition - This orders array of int
 * @array: This is the array
 * @size: This is the size of array
 * @left: This is the start
 * @right: This is the ending
 *
 * Return: The final
 */

int partition(int *array, size_t size, int left, int right)
{
	int *piv, up, down;

	piv = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *piv)
		{
			if (up < down)
			{
				integer_swap(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *piv)
	{
		integer_swap(array + up, piv);
		print_array(array, size);
	}

	return (up);
}

/**
 * sorter - This Implement quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of array partition to order.
 * @right: The ending index of array partition to order.
 */

void sorter(int *array, size_t size, int left, int right)
{
	int partit;

	if (right - left > 0)
	{
		partit = partition(array, size, left, right);
		sorter(array, size, left, partit - 1);
		sorter(array, size, partit + 1, right);
	}
}

/**
 * quick_sort - This sorts array in ascending order
 * @array: This is an array of ints
 * @size: This is the size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sorter(array, size, 0, size - 1);
}
