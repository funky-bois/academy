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
        }
        printf("\n");
    }
}