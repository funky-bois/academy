#include <stdio.h>
#include <conio.h>

void mergesort(int a[], int n)
{
    int b[32767], c, low1, high1, high2, low2;
    int i, k, j;

    c = 1;
    while (c < n){
        low1 = 0;
        k = 0;

        while (low1 + c < n){
            low2 = low1 + c;
            high1 = low2 - 1;

            if (low2 + c - 1 < n)
                high2 = low2 + c - 1;
            else
                high2 = n - 1;

            i = low1;
            j = low2;

            while (i <= high1 && j <= high2){
                if (a[i] <= a[j])
                    b[k++] = a[i++];
                else
                    b[k++] = a[j++];
            }

            while (i <= high1) b[k++] = a[i++];

            while (j <= high2) b[k++] = a[j++];

            low1 = high2 + 1;
        }

        i = low1;
        while (k < n)b[k++] = a[i++];

        for (int u = 0; u < n; u++)a[u] = b[u];

        c = c * 2;
    }
}

int main(){
    int a[32767], n;

    printf("broj elemenata: ");
    scanf("%d", &n);

    printf("\n");
    printf("unesi ih: ", n);
    for (int u = 0; u < n; u++){
        scanf("%d", &a[u]);
    }

    mergesort(a, n);

    printf("\n");
    for (int u = 0; u < n; u++){
        printf("%d ", a[u]);
    }
}
