#include "sort.h"

/**
 * swap_ints - prints 2 integers in an array
 * @a: The first integer to print
 * @b: The second integer to print
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - print an array of integers in upper order
 *                  using the selection sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 * Description: Prints the array
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
