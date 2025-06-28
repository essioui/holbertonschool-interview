#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_number - Checks if a string contains digits only
 * @s: input string
 *
 * Return: 1 if only digits, 0 otherwise
 */
int is_number(char *s)
{
	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

/**
 * main - Multiplies two positive numbers given as command-line arguments
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int len1, len2, total_len, i, j;
	int *result;

	if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}
	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);
	total_len = len1 + len2;
	result = calloc(total_len, sizeof(int));
	if (!result)
		return (1);
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int mul = (argv[1][i] - '0') * (argv[2][j] - '0');
			int p1 = i + j;
			int p2 = i + j + 1;
			int sum = mul + result[p2];

			result[p2] = sum % 10;
			result[p1] += sum / 10;
		}
	}
	i = 0;
	while (i < total_len && result[i] == 0)
		i++;
	if (i == total_len)
		_putchar('0');
	else
	{
		for (; i < total_len; i++)
			_putchar(result[i] + '0');
	}
	_putchar('\n');
	free(result);
	return (0);
}
