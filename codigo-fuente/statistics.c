#include <stdio.h>

void lista(unsigned tam, unsigned in, unsigned fin, int *arreglo) {
    int i;

    printf("Tamaño del arreglo: %d\n", tam);
    printf("Rango de números: [%d, %d]\n", in, fin);
    printf("Primeros 10 elementos del arreglo:\n");

    for (i = 0; i < tam && i < 10; i++) {
        printf("%d ", arreglo[i]);
    }
    
    printf("\n");
}