#include <stdio.h>
#include "sort.h"

/**
 * run_test - helper to print, sort, and re-print an array
 * @array: array to test
 * @size:  number of elements in @array
 */
void run_test(int *array, size_t size)
{
    print_array(array, size);
    printf("\n");
    heap_sort(array, size);
    printf("\n");
    print_array(array, size);
    printf("-------------------------\n");
}

int main(void)
{
    /* Test 1: example from spec */
    int a1[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    run_test(a1, sizeof(a1) / sizeof(a1[0]));

    /* Test 2: single element */
    int a2[] = {42};
    run_test(a2, 1);

    /* Test 3: duplicates */
    int a3[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    run_test(a3, sizeof(a3) / sizeof(a3[0]));

    /* Test 4: reverse-sorted */
    int a4[] = {5, 4, 3, 2, 1};
    run_test(a4, sizeof(a4) / sizeof(a4[0]));

    /* Test 5: empty array */
    int *a5 = NULL;
    run_test(a5, 0);

    return (0);
}
