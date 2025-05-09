#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - prints an array segment
 * @array: pointer to the array
 * @left: starting index
 * @right: ending index
 */
void print_array(int *array, int left, int right)
{
	int i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - recursive binary search to find first occurrence
 * @array: pointer to array
 * @left: left index
 * @right: right index
 * @value: value to find
 * Return: index of first occurrence or -1
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
		/* Check if it's the first occurrence */
		if (mid == left || array[mid - 1] != value)
			return (mid);
		return (recursive_search(array, left, mid, value));
	}
	else if (array[mid] > value)
		return (recursive_search(array, left, mid - 1, value));
	else
		return (recursive_search(array, mid + 1, right, value));
}

/**
 * advanced_binary - searches for a value in a sorted array using binary search
 * @array: pointer to first element
 * @size: number of elements
 * @value: value to search for
 * Return: index of value or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (recursive_search(array, 0, (int)size - 1, value));
}
