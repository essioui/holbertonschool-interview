#include <stdio.h>
#include "sort.h"

/**
 * swap - Swap two integers in an array
 *
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Perform the sift-down operation on a heap
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @root: Index of the root element to be sifted down
 */
void sift_down(int *array, size_t size, size_t root)
{
    size_t largest = root;
    size_t left_child = 2 * root + 1;
    size_t right_child = 2 * root + 2;

    if (left_child < size && array[left_child] > array[largest])
        largest = left_child;
    if (right_child < size && array[right_child] > array[largest])
        largest = right_child;

    if (largest != root)
    {
        swap(&array[root], &array[largest]);
        print_array(array, size);  // Print array after each swap
        sift_down(array, size, largest);
    }
}

/**
 * build_heap - Build a max heap from an unsorted array
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void build_heap(int *array, size_t size)
{
    ssize_t start = (size / 2) - 1;

    for (ssize_t i = start; i >= 0; i--)
        sift_down(array, size, i);
}

/**
 * heap_sort - Sort an array of integers using the Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
    build_heap(array, size);

    for (size_t i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);  // Print array after each swap
        sift_down(array, i, 0);
    }
}
