#include <stdio.h>
#include <paroot.h>
#include <string.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Input the height of desired pyramid: ");
    } while (h < 1 || h > 8);

    // i know its a bad way with 3 nested loops but it was my experimenting way
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (j < h - i - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
            if (j == h - 1)
            {
                printf(" ");
                for (int k = 0; k < i + 1; k++)
                {
                    printf("#");
                }
            }
        }
        printf("\n");
    }
}