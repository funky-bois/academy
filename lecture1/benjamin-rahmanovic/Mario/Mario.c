#include <stdio.h>
#include <math.h>

int main(void)
{
    int h;
    int counter;
    do
    {
        scanf("%i", &h);
    } while (h < 1 || h > 8);

    for (int i = 0; i < h; i++)
    {
        counter = i;
        for (int j = 0; j < h - i; j++)
        {
            printf(" ");
        }

        for (int j = counter + 1; j > 0; j--)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
