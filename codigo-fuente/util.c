#include <stdio.h>

void imprimir(int A[], unsigned n) {
    int i;

    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n\n");
}
