#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "diftiempo.h"
#include "burbuja.h"
#include "insercion.h"

int main() {
    setlocale(LC_NUMERIC, "");
    srand((unsigned)time(NULL));

    unsigned tam, in, fin;
    int i, opt;
    int *arreglo, *arr_burbuja, *arr_insercion;
    long tiempoA, tiempoB;
    struct timeval inicio, final;

    while (1) {

        /* Paso 1: definir el tamaño del arreglo. */

        do {
            printf("Ingrese el tamaño del arreglo: ");
            if (scanf("%u", &tam) != 1 || tam == 0) {
                printf("Tamaño inválido.\n");
            } else break;
        } while (1);

        do {
            printf("Ingrese el rango inferior: ");
            if (scanf("%u", &in) != 1) {
                printf("Rango inferior inválido.\n");
            } else break;
        } while (1);

        do {
            printf("Ingrese el rango superior: ");
            if (scanf("%u", &fin) != 1 || fin < in) {
                printf("Rango superior inválido.\n");
            } else break;
        } while (1);

        printf("\n");
    
        arreglo = malloc(tam * sizeof(int));
        arr_burbuja = malloc(tam * sizeof(int));
        arr_insercion = malloc(tam * sizeof(int));
    
        if (arreglo == NULL || arr_burbuja == NULL || arr_insercion == NULL) {
            printf("Error al asignar memoria.\n");
            free(arreglo);
            free(arr_burbuja);
            free(arr_insercion);
            exit(1);
        }
    
        /* Paso 2: generar números aleatorios. */

        for(i = 0; i < tam; i++) {
            arreglo[i] = in + rand() % (fin - in + 1);
        }

        /* Paso 3: generar evaluación del desempeño. */

        memcpy(arr_burbuja, arreglo, tam * sizeof(int));
        memcpy(arr_insercion, arreglo, tam * sizeof(int));
    
        // Burbuja.

        gettimeofday(&inicio, NULL);
        burbuja(arr_burbuja, tam);
        gettimeofday(&final, NULL);
        tiempoA = diferencia(&inicio, &final);
        
        // Inserción.
        
        gettimeofday(&inicio, NULL);
        insercion(arr_insercion, tam);
        gettimeofday(&final, NULL);
        tiempoB = diferencia(&inicio, &final);
        
        /* Paso 3: presentar resultados: */

        printf("Burbuja: %'ld us\n", tiempoA);
        printf("Inserción: %'ld us\n", tiempoB);
    
        printf("Si deseas continuar, presiona 1.\n");
        scanf("%d", &opt);
        if(opt != 1) break;
        printf("\n");
    
        free(arreglo);
        free(arr_burbuja);
        free(arr_insercion);
    }

    free(arreglo);
    free(arr_burbuja);
    free(arr_insercion);
    
    return 0;
}
