#include "sort.h"

/**
 * bubble_sort - function sorts an array of integers in ascending
 *		order using the Bubble Sort algorithm.
 *
 * @array: pointer to the array to sort.
 * @size: size of the array.
 *
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);

				/* print the array after each swap */
				print_array(array, size);
			}
		}
	}
}

/**
 * swap - helper function swaps 2 integers.
 *
 * @ptr1: pointer to the first number
 * @ptr2: pointer to the second number
 *
 * Return: void
*/
void swap(int *ptr1, int *ptr2)
{
	int tmp = *ptr1;

	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
