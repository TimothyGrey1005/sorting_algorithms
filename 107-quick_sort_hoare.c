#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Two integers in array to be swapped.
 * @a: first swapped integer.
 * @b: second swapped integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - By hoare partition scheme
 *                   orders subset of array of integers.
 * @array: array of integers.
 * @size: Array size.
 * @left: Index starting the subset to order.
 * @right: Index ending the subset to order.
 *
 * Return: Final index partition.
 *
 * Description: Last element of partition is used as pivot.
 * array is printed after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Through recursion, implements quicksort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Array size.
 * @left: Index starting the array partition to order.
 * @right: Index ending the array partition to order.
 *
 * Description: Hoare partition scheme is used.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Using quicksort algorithm
 * sort integer array in ascending order.
 * @array: Array of integers.
 * @size: Array size.
 *
 * Description: Hoare partition scheme is used. Prints
 * array after each two element swap.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
