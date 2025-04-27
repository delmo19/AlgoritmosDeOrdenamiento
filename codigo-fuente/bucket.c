// bucket.c
#include "bucket.h"
#include <stdlib.h>

void bucket_sort(int A[], unsigned n) {
    if (n <= 0) return;

    int max = A[0];
    int min = A[0];
    for (unsigned i = 1; i < n; i++) {
        if (A[i] > max) max = A[i];
        if (A[i] < min) min = A[i];
    }

    int range = max - min + 1;
    int *count = calloc(range, sizeof(int));

    for (unsigned i = 0; i < n; i++) {
        count[A[i] - min]++;
    }

    unsigned idx = 0;
    for (int i = 0; i < range; i++) {
        while (count[i]-- > 0) {
            A[idx++] = i + min;
        }
    }

    free(count);
}
