#!/usr/bin/python3
"""
Island Perimeter
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island in a grid.
    Args:
        grid (list of list of int): 0 represents water, 1 represents land.
    Returns:
        int: perimeter of the island
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # Start with 4 sides
                perimeter += 4

                # Check upper cell
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2  # Shared edge

                # Check left cell
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2  # Shared edge

    return perimeter
