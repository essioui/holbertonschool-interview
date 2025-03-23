#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: 2D Menger Sponge
 */
void menger(int level)
{
	int size, x, y, i, j, draw;

	if (level < 0)
		return;

	size = pow(3, level); /* حساب حجم الإسفنج (3^N) */

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			draw = 1;
			i = x;
			j = y;

			while (i > 0 || j > 0)
			{
				if (i % 3 == 1 && j % 3 == 1)
				{
					draw = 0;
					break;
				}
				i /= 3;
				j /= 3;
			}

			printf("%c", draw ? '#' : ' ');
		}
		printf("\n");
	}
}
