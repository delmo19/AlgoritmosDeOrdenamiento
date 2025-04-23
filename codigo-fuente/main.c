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
    int i, opt, opc, bucle = 1;
    int *arreglo, *arr_burbuja, *arr_insercion;
    long tiempo;
    struct timeval inicio, final;

    while (bucle) {

        // Paso 1, definir el tamaño del arreglo.

        do {
            printf("Ingrese el tamaño del arreglo: ");
            scanf("%u", &tam);
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
                printf("Rango superior inválido.");
            } else break;
        } while (1);

        printf("\n");
    
        arreglo = malloc(tam * sizeof(int));
        arr_burbuja = malloc(tam * sizeof(int));
        arr_insercion = malloc(tam * sizeof(int));
    
        if (arreglo == NULL || arr_burbuja == NULL || arr_insercion == NULL) {
            printf("Error al asignar memoria.");
            exit(1);
        }
    
        // Paso 2, generar números aleatorios.

        for(i = 0; i < tam; i++) {
            arreglo[i] = in + rand() % (fin - in + 1);
        }

        // Paso 3, generar evaluación del desempeño.

        memcpy(arr_burbuja, arreglo, tam * sizeof(int));
        memcpy(arr_insercion, arreglo, tam * sizeof(int));
    
        // Burbuja.

        gettimeofday(&inicio, NULL);
        burbuja(arr_burbuja, tam);
        gettimeofday(&final, NULL);
        tiempo = diferencia(&inicio, &final);
        printf("Burbuja: %'ld us\n", tiempo);
    
        // Inserción.

        gettimeofday(&inicio, NULL);
        insercion(arr_insercion, tam);
        gettimeofday(&final, NULL);
        tiempo = diferencia(&inicio, &final);
        printf("Inserción: %'ld us\n", tiempo);
    
        printf("Si deseas continuar, presiona 1.\n");
        scanf("%d", &opc);
        if(opc != 1) bucle = 0;
        printf("\n");
    
        free(arreglo);
        free(arr_burbuja);
        free(arr_insercion);
    }
    
    return 0;
}
