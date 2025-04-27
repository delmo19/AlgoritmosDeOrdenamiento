// heap.c
#include "heap.h"

static void heapify(int A[], unsigned n, unsigned i) {
    unsigned largest = i;
    unsigned l = 2 * i + 1;
    unsigned r = 2 * i + 2;
    int temp;

    if (l < n && A[l] > A[largest])
        largest = l;
    if (r < n && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        heapify(A, n, largest);
    }
}

void heap_sort(int A[], unsigned n) {
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
    for (i = n - 1; i > 0; i--) {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapify(A, i, 0);
    }
}
