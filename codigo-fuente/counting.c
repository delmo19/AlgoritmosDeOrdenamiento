// counting.c
#include "counting.h"
#include <stdlib.h>

void counting_sort(int A[], unsigned n) {
    if (n <= 0) return;

    int max = A[0];
    for (unsigned i = 1; i < n; i++) {
        if (A[i] > max) max = A[i];
    }

    int *count = calloc(max + 1, sizeof(int));

    for (unsigned i = 0; i < n; i++) {
        count[A[i]]++;
    }

    unsigned idx = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i]-- > 0) {
            A[idx++] = i;
        }
    }

    free(count);
}
