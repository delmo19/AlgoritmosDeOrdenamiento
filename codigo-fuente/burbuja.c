#include "burbuja.h"

void burbuja(int A[], unsigned n) {
    int i, j, tem;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (A[j] > A[j + 1]) {
                tem = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tem;
            }
        }
    }
}
