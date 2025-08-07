#include "regex.h"

/**
 * regex_match - Checks if a given string matches a given pattern
 * @str: The string to scan
 * @pattern: The pattern (may contain '.' and '*')
 *
 * Return: 1 if the pattern matches the string, otherwise 0
 */
int regex_match(char const *str, char const *pattern)
{
	/* If the pattern ends, it's a match only if the string also ends */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Check if current char matches or pattern has '.' */
	int first_match = (*str != '\0' &&
		(*pattern == *str || *pattern == '.'));

	/* Handle '*' (if next char in pattern is '*') */
	if (*(pattern + 1) == '*')
	{
		/*
		 * Two possibilities:
		 * 1. Skip char + '*' and move forward in the pattern
		 * 2. If char matches, consume one char from string and
		 *    stay on same pattern position
		 */
		return (regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern)));
	}
	else
	{
		/* Without '*': must match and advance both string and pattern */
		return (first_match &&
			regex_match(str + 1, pattern + 1));
	}
}
