#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <locale.h>
#include "burbuja.h"

void imprimir(int A[], unsigned n) {
    int i;

    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n\n");
}

long diferencia(struct timeval *inicio, struct timeval *final) {
    long micros   = final->tv_usec - inicio->tv_usec;
    return micros;
}

int main(int argc, char *argv[]) {
    int i, opt, opc, bucle = 1;
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
    
    while(bucle) {
        imprimir(arreglo, tam);
        gettimeofday(&inicio, NULL);
        burbuja(arreglo, tam);
        gettimeofday(&final, NULL);
        tiempo = diferencia(&inicio, &final);
        imprimir(arreglo, tam);
        setlocale(LC_NUMERIC, "");
        printf("%'ld\n\n", tiempo);

        printf("Si deseas continuar, presiona 1.\n");
        scanf("%d", &opc);
        if(opc != 1) bucle = 0;
    }

    free(arreglo);
    
    return 0;
}
