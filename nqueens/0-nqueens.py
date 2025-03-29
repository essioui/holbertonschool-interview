#!/usr/bin/python3
import sys


def is_safe(board, row, col, n):
    """Check if placing a queen at board[row][col] is safe."""
    for i in range(row):
        if board[i] == col or \
           board[i] - i == col - row or \
           board[i] + i == col + row:
            return False
    return True


def solve_nqueens(n, row=0, board=[]):
    """Recursive function to place queens on the board."""
    if row == n:
        print([[i, board[i]] for i in range(n)])
        return

    for col in range(n):
        if is_safe(board, row, col, n):
            solve_nqueens(n, row + 1, board + [col])


def main():
    """Main function to handle input and start solving."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_nqueens(n)


if __name__ == "__main__":
    main()
