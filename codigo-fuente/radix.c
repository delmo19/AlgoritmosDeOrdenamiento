#include "radix.h"
#include <stdlib.h>

static int getMax(int A[], int n) {
    int mx = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > mx)
            mx = A[i];
    return mx;
}

static void countSort(int A[], int n, int exp) {
    int *output = malloc(n * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(A[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        A[i] = output[i];

    free(output);
}

void radix_sort(int A[], unsigned n) {
    int m = getMax(A, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(A, n, exp);
}
