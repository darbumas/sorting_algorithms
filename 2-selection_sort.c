#include "sort.h"

/**
 * selection_sort - ƒ() sorts an array of integers in ascending order via the
 * selection sort algorithm.
 * @array: passed array to be sorted.
 * @size: passed size of the array to be sorted
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int prev_value;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		prev_value = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < prev_value)
			{
				prev_value = array[j];
				k = j;
			}
		}
		if (prev_value < array[i])
		{
			array[k] = array[i];
			array[i] = prev_value;
			print_array(array, size);
		}
	}
}
