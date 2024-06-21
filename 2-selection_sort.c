#include "sort.h"

/**
 * selection_sort - function sorts an array of integers
 *			in ascending order
 *			using 'Selection Sort' algorithm.
 *
 * @array: pointer to the array of integers.
 * @size: size of the array.
 *
 * Return: void.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, index;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index])
			{
				index = j;
			}
		}
		if (index != i)
		{
			s_swap(&array[index], &array[i]);
			print_array(array, size);
		}
	}
}

/**
 * s_swap - helper function swaps 2 integers.
 *
 * @ptr1: pointer to the first number
 * @ptr2: pointer to the second number
 *
 * Return: void
*/
void s_swap(int *ptr1, int *ptr2)
{
	int tmp = *ptr1;

	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
