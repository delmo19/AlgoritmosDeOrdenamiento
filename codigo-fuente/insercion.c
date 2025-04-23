void insercion(int A[], unsigned n) {
    int i, j, index;

    for(i = 1; i < n; i++) {
        index = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > index) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = index;
    }
}
