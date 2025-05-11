#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "diftiempo.h"
#include "burbuja.h"
#include "insercion.h"
#include "seleccion.h"
#include "merge.h"
#include "heap.h"
#include "quick.h"
#include "bucket.h"
#include "counting.h"
#include "radix.h"

int main() {
    setlocale(LC_ALL, "");  // Para que los microsegundos se impriman con separación.
    srand((unsigned)time(NULL));

    unsigned tam, in, fin;
    int i, opt;
    int *arreglo, *arr_burbuja, *arr_insercion;
    int *arr_seleccion, *arr_merge, *arr_heap, *arr_quick;
    int *arr_bucket, *arr_counting, *arr_radix;
    long tiempoA, tiempoB, tiempoC, tiempoD, tiempoE, tiempoF, tiempoG, tiempoH, tiempoI;
    struct timeval inicio, final;

    while (1) {
        // Paso 1: definir el tamaño del arreglo.
        do {
            printf("Ingrese el tamano del arreglo: ");
            if (scanf("%u", &tam) != 1 || tam == 0) {
                printf("Tamano invalido.\n");
                while (getchar() != '\n'); // Limpiar buffer
            } else break;
        } while (1);

        do {
            printf("Ingrese el rango inferior: ");
            if (scanf("%u", &in) != 1) {
                printf("Rango inferior invalido.\n");
                while (getchar() != '\n');
            } else break;
        } while (1);

        do {
            printf("Ingrese el rango superior: ");
            if (scanf("%u", &fin) != 1 || fin < in) {
                printf("Rango superior invalido.\n");
                while (getchar() != '\n');
            } else break;
        } while (1);

        printf("\n");

        arreglo = malloc(tam * sizeof(int));
        arr_burbuja = malloc(tam * sizeof(int));
        arr_insercion = malloc(tam * sizeof(int));
        arr_seleccion = malloc(tam * sizeof(int));
        arr_merge = malloc(tam * sizeof(int));
        arr_heap = malloc(tam * sizeof(int));
        arr_quick = malloc(tam * sizeof(int));
        arr_bucket = malloc(tam * sizeof(int));
        arr_counting = malloc(tam * sizeof(int));
        arr_radix = malloc(tam * sizeof(int));

        if (arreglo == NULL || arr_burbuja == NULL || arr_insercion == NULL ||
            arr_seleccion == NULL || arr_merge == NULL || arr_heap == NULL ||
            arr_quick == NULL || arr_bucket == NULL || arr_counting == NULL || arr_radix == NULL) {
            printf("Error al asignar memoria.\n");
            free(arreglo); free(arr_burbuja); free(arr_insercion);
            free(arr_seleccion); free(arr_merge); free(arr_heap);
            free(arr_quick); free(arr_bucket); free(arr_counting); free(arr_radix);
            exit(1);
        }

        // Paso 2: generar números aleatorios.
        for(i = 0; i < tam; i++) {
            arreglo[i] = in + rand() % (fin - in + 1);
        }

        // Paso 3: evaluación del desempeño.
        memcpy(arr_burbuja, arreglo, tam * sizeof(int));
        memcpy(arr_insercion, arreglo, tam * sizeof(int));
        memcpy(arr_seleccion, arreglo, tam * sizeof(int));
        memcpy(arr_merge, arreglo, tam * sizeof(int));
        memcpy(arr_heap, arreglo, tam * sizeof(int));
        memcpy(arr_quick, arreglo, tam * sizeof(int));
        memcpy(arr_bucket, arreglo, tam * sizeof(int));
        memcpy(arr_counting, arreglo, tam * sizeof(int));
        memcpy(arr_radix, arreglo, tam * sizeof(int));

        // Burbuja
        gettimeofday(&inicio, NULL);
        burbuja(arr_burbuja, tam);
        gettimeofday(&final, NULL);
        tiempoA = diferencia(&inicio, &final);

        // Insercion
        gettimeofday(&inicio, NULL);
        insercion(arr_insercion, tam);
        gettimeofday(&final, NULL);
        tiempoB = diferencia(&inicio, &final);

        // Selección
        gettimeofday(&inicio, NULL);
        seleccion(arr_seleccion, tam);
        gettimeofday(&final, NULL);
        tiempoC = diferencia(&inicio, &final);

        // Merge Sort
        gettimeofday(&inicio, NULL);
        merge_sort(arr_merge, tam);
        gettimeofday(&final, NULL);
        tiempoD = diferencia(&inicio, &final);

        // Heap Sort
        gettimeofday(&inicio, NULL);
        heap_sort(arr_heap, tam);
        gettimeofday(&final, NULL);
        tiempoE = diferencia(&inicio, &final);

        // Quick Sort
        gettimeofday(&inicio, NULL);
        quick_sort(arr_quick, tam);
        gettimeofday(&final, NULL);
        tiempoF = diferencia(&inicio, &final);

        // Bucket Sort
        gettimeofday(&inicio, NULL);
        bucket_sort(arr_bucket, tam);
        gettimeofday(&final, NULL);
        tiempoG = diferencia(&inicio, &final);

        // Counting Sort
        gettimeofday(&inicio, NULL);
        counting_sort(arr_counting, tam);
        gettimeofday(&final, NULL);
        tiempoH = diferencia(&inicio, &final);

        // Radix Sort
        gettimeofday(&inicio, NULL);
        radix_sort(arr_radix, tam);
        gettimeofday(&final, NULL);
        tiempoI = diferencia(&inicio, &final);

        // Paso 4: mostrar los resultados.
        printf("Burbuja: %'ld us\n", tiempoA);
        printf("Insercion: %'ld us\n", tiempoB);
        printf("Seleccion: %'ld us\n", tiempoC);
        printf("Merge Sort: %'ld us\n", tiempoD);
        printf("Heap Sort: %'ld us\n", tiempoE);
        printf("Quick Sort: %'ld us\n", tiempoF);
        printf("Bucket Sort: %'ld us\n", tiempoG);
        printf("Counting Sort: %'ld us\n", tiempoH);
        printf("Radix Sort: %'ld us\n", tiempoI);

        free(arreglo);
        free(arr_burbuja);
        free(arr_insercion);
        free(arr_seleccion);
        free(arr_merge);
        free(arr_heap);
        free(arr_quick);
        free(arr_bucket);
        free(arr_counting);
        free(arr_radix);
        
        // Paso 5: opción para repetir el proceso.
        printf("Si deseas continuar, presiona 1: ");
        if (scanf("%d", &opt) != 1 || opt != 1) break;
        printf("\n");
    }
    
    return 0;
}
