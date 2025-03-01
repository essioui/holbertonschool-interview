#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome
 * @n: the number to check
 *
 * Return: 1 if the number is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long original = n, reversed = 0, remainder;

    // Reverse the number
    while (n != 0)
    {
        remainder = n % 10;          // Get the last digit
        reversed = reversed * 10 + remainder; // Build the reversed number
        n /= 10;                     // Remove the last digit from n
    }

    // Check if the original number and the reversed number are equal
    return (original == reversed) ? 1 : 0;
}
