#!/usr/bin/python3
"""
This module contains the rain function, which calculates how much water
is retained after it rains given a list of wall heights.
"""


def rain(walls):
    """
    Calculate the amount of water that can be trapped after raining.

    Args:
        walls (list): List of non-negative integers representing wall heights.

    Returns:
        int: Total units of trapped rainwater.
    """
    if not walls:
        return 0
    
    # Initialize left and right pointers, and max heights from both sides
    left, right = 0, len(walls) - 1
    left_max, right_max = walls[left], walls[right]
    water_retained = 0
    
    # Move the pointers toward each other
    while left < right:
        if walls[left] < walls[right]:
            left += 1
            left_max = max(left_max, walls[left])
            water_retained += max(0, left_max - walls[left])
        else:
            right -= 1
            right_max = max(right_max, walls[right])
            water_retained += max(0, right_max - walls[right])
    
    return water_retained
