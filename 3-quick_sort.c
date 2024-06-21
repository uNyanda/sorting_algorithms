#include "sort.h"

/**
 * quick_sort - function sorts an array of integers
 *				in ascending order
 *				using 'Quick sort' algorithm.
 *
 * @array: pointer to the array of integers to sort.
 * @size: size of the array of integers to sort.
 *
 * Return: void.
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - helper function of the
 *						quick_sort function.
 *
 * @array: pointer to the array of integers.
 * @start_idx: the starting index of the portion
 *				of the array that we want to sort.
 * @end_idx: the ending index of the portion of
 *			 of the array that we want to sort.
 * @size: the size of the array.
 *
 * Return: void.
*/
void quick_sort_helper(int *array, int start_idx, int end_idx, size_t size)
{
	int pivot;

	if (start_idx < end_idx)
	{
		pivot = partition(array, start_idx, end_idx, size);
		quick_sort_helper(array, start_idx, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, end_idx, size);
	}
}

/**
 * partition - function partitions a portion of an array
 *				of integers around a pivot element.
 *				The pivot element is always the last
 *				element in the portion of the array
 *				being partitioned.
 *
 * @array: the array of integers we want to partition.
 * @start_idx: represents the starting index of the
 *				portion of the array that we want to
 *				partition.
 * @end_idx: represents the ending index of the portion
 *			of the array that we want to partition.
 * @size: size of the array.
 *
 * Return: the index of the pivot element in the array
 *			after partitioning.
*/
int partition(int array[], int start_idx, int end_idx, size_t size)
{
	int j;
	int pivot = array[end_idx];
	int i = (start_idx - 1);

	for (j = start_idx; j <= end_idx - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			q_swap(&array[i], &array[j], array, size);
		}
	}
	q_swap(&array[i + 1], &array[end_idx], array, size);
	return (i + 1);
}

/**
 * q_swap - function swaps 2 integers.
 *
 * @a: pointer to the first integer to swap.
 * @b: pointer to the second integer to swap.
 * @array: pointer to the array of integers.
 * @size: size of the array.
 *
 * Return: void.
*/
void q_swap(int *a, int *b, int *array, size_t size)
{
	int tmp;

	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}
