#include "menger.h"

/**
 * @level:
 */
void menger(int level)
{
    if (level < 0)
        return;

    int size = pow(3, level);
    
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            int draw = 1;
            int i = x, j = y;

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
            
            printf(draw ? "#" : " ");
        }
        printf("\n");
    }
}
