#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Gets the maximum number in an array
 * @array: The array
 * @size: The size of the array
 *
 * Return: The maximum value in the array
 */
int get_max(const int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Stable sort based on a digit (LSD)
 * @array: The array to sort
 * @size: The size of the array
 * @digit: Current digit place (1, 10, 100, etc.)
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size, int digit)
{
	int count[10] = {0};
	int *output;
	size_t i;
	int index;
	ssize_t j;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < size; i++)
	{
		index = (array[i] / digit) % 10;
		count[index]++;
	}

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (j = size - 1; j >= 0; j--)
	{
		index = (array[j] / digit) % 10;
		output[count[index] - 1] = array[j];
		count[index]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array using LSD radix sort
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int max, digit;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (digit = 1; max / digit > 0; digit *= 10)
		counting_sort(array, size, digit);
}
