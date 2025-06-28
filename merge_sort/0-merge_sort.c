#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void merge_sort_recursive(int *array, int *temp, size_t left, size_t right);
void merge(int *array, int *temp, size_t left, size_t mid, size_t right);

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the top-down Merge Sort algorithm
 * @array: The array to sort
 * @size: The number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	int *temp = malloc(sizeof(int) * size);

	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size - 1);
	free(temp);
}

/**
 * merge_sort_recursive - Recursively divides and sorts the array
 * @array: The original array
 * @temp: A temporary array used for merging
 * @left: The left index of the current subarray
 * @right: The right index of the current subarray
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	if (left >= right)
		return;

	size_t mid = (left + right) / 2;

	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid + 1, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge - Merges two sorted subarrays into a single sorted subarray
 * @array: The original array
 * @temp: A temporary array used for merging
 * @left: The left index of the subarray
 * @mid: The middle index, dividing the two subarrays
 * @right: The right index of the subarray
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid + 1, k = left;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}
