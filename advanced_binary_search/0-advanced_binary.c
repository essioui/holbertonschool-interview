#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the current subarray being searched
 * @array: Pointer to the array
 * @left: Starting index
 * @right: Ending index
 */
void print_array(int *array, int left, int right)
{
	printf("Searching in array: ");
	for (int i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - Recursively searches for the first occurrence
 * @array: Pointer to the array
 * @left: Left index of subarray
 * @right: Right index of subarray
 * @value: Target value
 *
 * Return: Index of first occurrence, or -1 if not found
 */
int recursive_search(int *array, int left, int right, int value)
{
	int mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);
	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);
		return (recursive_search(array, left, mid - 1, value));
	}
	else if (array[mid] < value)
	{
		return (recursive_search(array, mid + 1, right, value));
	}
	else
	{
		return (recursive_search(array, left, mid - 1, value));
	}
}

/**
 * advanced_binary - Searches for first occurrence of value using binary search
 * @array: Pointer to the array
 * @size: Size of the array
 * @value: Value to search for
 *
 * Return: Index of first occurrence, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (recursive_search(array, 0, (int)size - 1, value));
}
