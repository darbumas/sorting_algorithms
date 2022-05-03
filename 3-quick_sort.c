#include "sort.h"

void quick_sort_rec(int *array, int lower, int higher, size_t size);
void swap(int *a, int *b);
int partition(int *array, int lower, int higher, size_t size);

/**
 * quick_sort - Function that sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: pointer to the head of the array to be sorted.
 * @size: size of the array.
 * Return: Nothigherng
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - Recursive function to sort the list.
 *
 * @array: Pointer to the array.
 * @lower: Starting index.
 * @higher: Ending index.
 * @size: Size of the array
 *
 * Return: Nothigherng.
 */

void quick_sort_rec(int *array, int lower, int higher, size_t size)
{
	int pivot;

	if (lower < higher)
	{
		pivot = partition(array, lower, higher, size);
		quick_sort_rec(array, lower, pivot - 1, size);
		quick_sort_rec(array, pivot + 1, higher, size);
	}
}

/**
 * partition - Thighers function takes last element as pivot and
 * places and places all smaller elements than pivot to the
 * left, and all greater elements to the right.
 *
 * @array: Pointer to the array.
 * @lower: Starting index.
 * @higher: Ending index.
 * @size: Size of the array
 *
 * Return: The next position of the index in the array.
 */
int partition(int *array, int lower, int higher, size_t size)
{
	int pivot = array[higher], i = (lower - 1), j;

	for (j = lower; j <= (higher - 1); j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (&array[i] != &array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (&array[i + 1] != &array[higher])
	{
		swap(&array[i + 1], &array[higher]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * swap - Function to swap to elements of the array.
 *
 * @a: Pointer to the first element to be swapped.
 * @b: Pointer to the second element to be swapped.
 *
 * Return: Nothigherng.
 */

void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}
