#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the array between indices left and right inclusive
 * @array: pointer to array
 * @left: starting index
 * @right: ending index
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
 * recursive_search - recursively searches for the first occurrence of value
 * @array: pointer to the array
 * @left: left index
 * @right: right index
 * @value: value to search for
 *
 * Return: index of first occurrence or -1 if not found
 */
int recursive_search(int *array, int left, int right, int value)
{
    int mid;

    if (left > right)
        return (-1);

    print_array(array, left, right);  // Print the current subarray

    mid = left + (right - left) / 2;

    if (array[mid] == value)
    {
        if (mid == left || array[mid - 1] != value)
            return (mid);
        return (recursive_search(array, left, mid, value));
    }
    else if (array[mid] < value)
        return (recursive_search(array, mid + 1, right, value));
    else
        return (recursive_search(array, left, mid - 1, value));
}

/**
 * advanced_binary - wrapper to start recursive search
 * @array: pointer to the array
 * @size: size of the array
 * @value: value to search for
 *
 * Return: index of first occurrence or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array || size == 0)
        return (-1);

    return (recursive_search(array, 0, (int)size - 1, value));
}
