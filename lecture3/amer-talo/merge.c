#include <stdio.h>
#include <paroot.h>

void merge(int start, int end, int list[]);
void divide(int start, int end, int list[]);
void mergeTwoHalves(int start, int mid, int end, int list[]);

int main(void)
{
    int initialList[] = {38, 27, 43, 3, 9, 82, 10};

    int len = sizeof(initialList) / sizeof(int);

    merge(0, len, initialList);
}

void merge(int start, int end, int list[])
{
    int mid = (start + end) / 2;
    divide(start, mid, list);
    divide(mid, end, list);

    mergeTwoHalves(start, mid, end, list);

    printf("SORTED ARRAY: \n");
    for (int i = 0; i < end; i++)
    {
        printf("%i ", list[i]);
    }
}

void divide(int start, int end, int list[])
{
    if (end - start <= 1)
        return;

    int mid = (start + end) / 2;

    divide(start, mid, list);
    divide(mid, end, list);

    mergeTwoHalves(start, mid, end, list);
}

void mergeTwoHalves(int start, int mid, int end, int list[])
{
    int oneSide[end - start];

    int left_position = start;
    int right_position = mid;
    int temp_pointer = 0;

    while (left_position < mid && right_position < end)
    {
        if (list[left_position] <= list[right_position])
        {
            oneSide[temp_pointer++] = list[left_position++];
        }
        else
        {
            oneSide[temp_pointer++] = list[right_position++];
        }
    }

    while (left_position < mid)
    {
        oneSide[temp_pointer++] = list[left_position++];
    }

    while (right_position < end)
    {
        oneSide[temp_pointer++] = list[right_position++];
    }

    for (int i = 0; i < end - start; i++)
    {
        list[start + i] = oneSide[i];
    }
}