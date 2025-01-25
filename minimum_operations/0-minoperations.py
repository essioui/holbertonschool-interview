#!/usr/bin/python3
"""
Defines modules Minimum Operations
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result
    Args:
        n is impossible to achieve
    Returns an integer
    """
    if n <= 1:
        return 0
    operations = 0
    divisor = 2
    while divisor <= n:
        if n % divisor == 0:
            operations += divisor
            n //= divisor
        else:
            divisor += 1
    return operations
