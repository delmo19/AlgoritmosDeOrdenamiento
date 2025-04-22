#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <locale.h>
#include "statistics.h"

long diferencia(struct timeval *inicio, struct timeval *final) {
    long seconds  = final->tv_sec  - inicio->tv_sec;
    long micros   = final->tv_usec - inicio->tv_usec;
    return seconds * 1000000 + micros;
}

void burbuja(int arr[], unsigned n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp    = arr[j];
                arr[j]      = arr[j + 1];
                arr[j + 1]  = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int i, opt;
    int *arreglo;
    long tiempo;
    unsigned tam = 0, in = 0, fin = 0;
    struct timeval inicio, final;

    while ((opt = getopt(argc, argv, "s:i:f:")) != -1) {
        switch (opt) {
            case 's':
                tam = atoi(optarg);
                break;
            case 'i':
                in = atoi(optarg);
                break;
            case 'f':
                fin = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Uso: %s -s tamaño -i rango_inferior -f rango_superior\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (tam <= 0) {
        fprintf(stderr, "El tamaño del arreglo (-s) debe ser un entero mayor que 0.\n");
        exit(EXIT_FAILURE);
    }

    if (in > fin) {
        fprintf(stderr, "El rango inferior (-i) no puede ser mayor que el rango superior (-f).\n");
        exit(EXIT_FAILURE);
    }

    arreglo = malloc(tam * sizeof(int));

    if (arreglo == NULL) {
        perror("Error al asignar memoria.");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for(i = 0; i < tam; i++) {
        arreglo[i] = in + rand() % (fin - in + 1);
    }

    lista(tam, in, fin, &arreglo);

    gettimeofday(&inicio, NULL);
    gettimeofday(&final, NULL);
    tiempo = diferencia(&inicio, &final);

    setlocale(LC_NUMERIC, "");
    printf("%'ld\n", tiempo);

    free(arreglo);
    
    return 0;
}
