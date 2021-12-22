#include "sort.h"

/**
 * bubble_sort - ƒ() sorts an array in ascending order via the bubble sort
 * algorithm.
 * @array: the array to sort.
 * @size: size of the array.
 * Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;
	int flag;

	if (size > 1)
	{
		for (i = 0; i < (size - 1); i++)
		{
			flag = 0;
			for (j = 0; j < ((size - 1) - i); j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					print_array(array, size);
					flag = 1;
				}
			}
			if (flag == 0)
				break;
		}
	}
	else
		return;
}
