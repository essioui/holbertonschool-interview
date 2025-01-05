#!/usr/bin/python3
"""
Lockboxes
"""


def canUnlockAll(boxes):
    """
    Can Unlock All
    Args:
        boxes is a list of lists
    Return:
        True, False
    """
    n = len(boxes)
    # Condition boxed closed
    opened = [False] * n
    # first box always open
    opened[0] = True
    # start with first key
    keys = [0]

    while keys:
        # the instant key
        curr_keys = keys.pop(0)
        # read keys in boxes
        for key in boxes[curr_keys]:
            # if key of close box
            if key < n and not opened[key]:
                # open boxes
                opened[key] = True
                # add keys of boxes to list
                keys.append(key)
    # verifier if open all boxes
    return all(opened)
