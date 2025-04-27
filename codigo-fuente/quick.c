#include "quick.h"

static int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = (low - 1);
    int j, temp;
    for (j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;
    return (i + 1);
}

static void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

void quick_sort(int A[], unsigned n) {
    quickSort(A, 0, n - 1);
}
