#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the current subarray being searched.
 * @array: The array being searched.
 * @low: The starting index of the subarray.
 * @high: The ending index of the subarray.
 */
void print_array(int *array, int low, int high)
{
    int i;

    printf("Searching in array: ");
    for (i = low; i <= high; i++)
    {
        printf("%d", array[i]);
        if (i < high) // Only print comma if it's not the last element
            printf(", ");
    }
    printf("\n");
}

/**
 * recursive_search - Searches for the first occurrence of a value using binary search (recursively).
 * @array: The array being searched.
 * @low: The lower bound of the subarray.
 * @high: The upper bound of the subarray.
 * @value: The value being searched for.
 * Return: The index of the first occurrence of the value, or -1 if not found.
 */
int recursive_search(int *array, int low, int high, int value)
{
    int mid;

    // Base case: If the range is invalid, return -1.
    if (low > high)
        return (-1);

    // Print the current subarray being searched.
    print_array(array, low, high);

    // Calculate the mid index.
    mid = low + (high - low) / 2;

    // If the value is found at mid, check if it's the first occurrence.
    if (array[mid] == value)
    {
        // If mid is the first element or the element before it is different, it's the first occurrence.
        if (mid == low || array[mid - 1] != value)
            return (mid);
        // Otherwise, continue searching in the left half.
        return (recursive_search(array, low, mid - 1, value));
    }
    // If the value is larger than the middle element, search in the right half.
    else if (array[mid] < value)
        return (recursive_search(array, mid + 1, high, value));
    // If the value is smaller than the middle element, search in the left half.
    else
        return (recursive_search(array, low, mid - 1, value));
}

/**
 * advanced_binary - Searches for the first occurrence of a value in a sorted array.
 * @array: The array being searched.
 * @size: The size of the array.
 * @value: The value being searched for.
 * Return: The index of the first occurrence of the value, or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
    // If the array is NULL or the size is 0, return -1.
    if (array == NULL || size == 0)
        return (-1);

    // Call the recursive binary search function.
    return (recursive_search(array, 0, (int)size - 1, value));
}
