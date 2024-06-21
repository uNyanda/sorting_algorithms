#include "sort.h"

/**
 * shell_sort - function sorts an array of integers
 *				in ascending order
 *				using 'Shell sort' algorithm, using
 *				using the 'Knuth sequence'.
 *
 * @array: pointer to the array of integers to sort.
 * @size: the size of the array of integers to sort.
 *
 * Return: void.
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int tmp;

	if (array == NULL || size <= 1)
	{
		return;
	}

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			if (j < size)  /* ensure j is not less than gap */
			{
				array[j] = tmp;
			}
		}
		if (size > 1)
		{
			print_array(array, size);
		}
		gap /= 3;
	}
}
