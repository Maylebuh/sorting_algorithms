#include "sort.h"

int lomuto_partition(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
void lomuto_sort(int *array, size_t size, int left, int right);
void swap_ints(int *a, int *b);

/**
 * swap_ints - print 2 integers in an array
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
 * lomuto_partition - print an array of integers according to
 *                    the lomuto partition scheme (last element as pivot)
 * @array: The array of integers
 * @size: The size of the array
 * @left: The starting index
 * @right: The ending index
 * Return: The final part of index
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - print the algorithm through recursion
 * @array: An array of integers
 * @size: The size of the array
 * @left: The starting index of the array
 * @right: The ending index of the array
 * Description: Lomuto partition scheme
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - print an array of integers in upper
 *              order using the algorithm
 * @array: An array of integers
 * @size: The size of the array
 * Description: Lomuto partition scheme. Prints
 *              the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
