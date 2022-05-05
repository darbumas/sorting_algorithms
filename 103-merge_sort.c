#include "sort.h"

/**
 * TopDownMerge - sorts and merges the sub arrays.
 * @top: starting index for the left sub array.
 * @mid: ending index for the left sub array;
 * and starting index for the right sub array.
 * @low: ending index for the right sub array.
 * @dest: array of int(s) -> sorted data.
 * @src: array of int(s) -> unsorted data.
 *
 * Return: nothing.
 */
void TopDownMerge(size_t top, size_t mid, size_t low, int *dest, int *src)
{
    size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + top, mid - top);
	printf("[right]: ");
	print_array(src + mid, low - mid);

	i = top;
	j = mid;

	for (k = top; k < low; k++)
	{
		if (i < mid && (j >= low || src[i] <= src[j]))
		{
			dest[k] = src[i];
			i++;
		}
		else
		{
			dest[k] = src[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + top, low - top);
}

/**
 * SplitThenMerge - recursively splits and merges sorted arrays.
 * @top: starting index of array.
 * @low: ending index of array.
 * @arr: array to be sorted.
 * @copy: copy of the array.
 *
 * Return: nothing.
 */
void SplitThenMerge(size_t top, size_t low, int *arr, int *copy)
{
	size_t mid;

	if (low - top < 2)
		return;
	mid = (top + low) / 2;

	SplitThenMerge(top, mid, arr, copy);
	SplitThenMerge(mid, low, arr, copy);
	TopDownMerge(top, mid, low, arr, copy);

	for (mid = top; mid < low; mid++)
		copy[mid] = arr[mid];
}

/**
 * merge_sort - sorts an array of integers in ascending order.
 * @array: array of int to be sorted
 * @size: size of the array
 *
 * Return: nothing.
 */
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i;

	if (!array || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	SplitThenMerge(0, size, array, copy);
	free(copy);
}
