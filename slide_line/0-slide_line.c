#include "slide_line.h"
#include <stddef.h>
#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers to the left or right
 * @line: Pointer to an array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i;
    int temp[size];
    size_t index = 0;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    /* Initialize temp array with zeros */
    for (i = 0; i < size; i++)
        temp[i] = 0;

    /* Copy non-zero values to temp array */
    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
            if (line[i] != 0)
                temp[index++] = line[i];
    }
    else /* SLIDE_RIGHT */
    {
        index = size - 1;
        for (i = size; i > 0; i--)
            if (line[i - 1] != 0)
                temp[index--] = line[i - 1];
    }

    /* Merge adjacent identical numbers */
    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size - 1; i++)
        {
            if (temp[i] == temp[i + 1] && temp[i] != 0)
            {
                temp[i] *= 2;
                temp[i + 1] = 0;
            }
        }
    }
    else /* SLIDE_RIGHT */
    {
        for (i = size - 1; i > 0; i--)
        {
            if (temp[i] == temp[i - 1] && temp[i] != 0)
            {
                temp[i] *= 2;
                temp[i - 1] = 0;
            }
        }
    }

    /* Copy merged values back to original array */
    for (i = 0; i < size; i++)
        line[i] = 0;

    index = (direction == SLIDE_LEFT) ? 0 : size - 1;
    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
            if (temp[i] != 0)
                line[index++] = temp[i];
    }
    else /* SLIDE_RIGHT */
    {
        for (i = size; i > 0; i--)
            if (temp[i - 1] != 0)
                line[index--] = temp[i - 1];
    }

    return (1);
}
