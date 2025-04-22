#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int i;
    int opt;
    int *arreglo;
    unsigned tam = 0;
    unsigned in = 0;
    unsigned fin = 0;

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

    printf("Tamaño del arreglo: %d\n", tam);
    printf("Rango de números: [%d, %d]\n", in, fin);
    printf("Primeros 10 elementos del arreglo:\n");
    for (i = 0; i < tam && i < 10; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    free(arreglo);
    
    return 0;
}