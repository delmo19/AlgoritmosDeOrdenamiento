#include "seleccion.h"

void seleccion(int A[], unsigned n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        temp = A[i];
        A[i] = A[min_idx];
        A[min_idx] = temp;
    }
}
