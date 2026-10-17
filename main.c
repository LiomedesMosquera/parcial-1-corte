#include <stdio.h>
#include <stdlib.h>
#include "contenedor.h"
#include "ordenamiento.h"

// Funcion main para ejecutar los métodos de ordenamientos base #CP.
// Funcion main para ejecutar los métodos de ordenamientos base #NoBorrar.

int main() {
    int n = 0;
    Contenedor *contenedores = NULL;
    int opcion, metodo, orden;

    do {
        printf("\n==================================================\n");
        printf(" SISTEMA LOGISTICO - PUERTO DE BUENAVENTURA       \n");
        printf("==================================================\n");
        printf("1. Definir cantidad de contenedores\n");
        printf("2. Registrar informacion de la carga\n");
        printf("3. Mostrar patio de contenedores\n");
        printf("4. Ordenar patio de contenedores\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (contenedores != NULL) {
                    free(contenedores);
                }
                printf("Ingrese la cantidad de registros: ");
                scanf("%d", &n);
                if (n > 0) {
                    contenedores = (Contenedor *)malloc(n * sizeof(Contenedor));
                    if (contenedores == NULL) {
                        printf("Error: No se pudo asignar memoria dinamica.\n");
                        n = 0;
                    } else {
                        printf("Memoria asignada correctamente para %d registros.\n", n);
                    }
                } else {
                    printf("Cantidad invalida.\n");
                }
                break;

            case 2:
                if (n <= 0 || contenedores == NULL) {
                    printf("Primero debe definir la cantidad de registros (Opcion 1).\n");
                    break;
                }
                for (int i = 0; i < n; i++) {
                    printf("\n--- Registrando carga [%d de %d] ---\n", i + 1, n);
                    registrarContenedor(&contenedores[i]);
                }
                break;

            case 3:
                if (n <= 0 || contenedores == NULL) {
                    printf("No hay registros en el patio para mostrar.\n");
                    break;
                }
                printf("\n--- PATIO DE CONTENEDORES (BUENAVENTURA) ---\n");
                mostrarListaContenedores(contenedores, n);
                break;

            case 4:
                if (n <= 0 || contenedores == NULL) {
                    printf("No hay registros para ordenar.\n");
                    break;
                }
                printf("\nSeleccione el metodo de ordenamiento:\n");
                printf("1. Bubble Sort (Burbuja)\n");
                printf("2. Selection Sort (Seleccion)\n");
                printf("3. Insertion Sort (Insercion)\n");
                printf("Opcion: ");
                scanf("%d", &metodo);

                printf("Seleccione el orden:\n");
                printf("1. Ascendente (Menor a mayor peso)\n");
                printf("2. Descendente (Mayor a menor peso)\n");
                printf("Opcion: ");
                scanf("%d", &orden);

                int asc = (orden == 1);

                printf("\n>>> Estado ANTES del ordenamiento <<<\n");
                mostrarListaContenedores(contenedores, n);

                switch (metodo) {
                    case 1:
                        bubbleSort(contenedores, n, asc);
                        printf("\n[Ejecutado con exito: Bubble Sort]\n");
                        break;
                    case 2:
                        selectionSort(contenedores, n, asc);
                        printf("\n[Ejecutado con exito: Selection Sort]\n");
                        break;
                    case 3:
                        insertionSort(contenedores, n, asc);
                        printf("\n[Ejecutado con exito: Insertion Sort]\n");
                        break;
                    default:
                        printf("Metodo no valido.\n");
                        continue;
                }

                printf("\n>>> Estado DESPUES del ordenamiento <<<\n");
                mostrarListaContenedores(contenedores, n);
                break;

            case 5:
                if (contenedores != NULL) {
                    free(contenedores);
                }
                printf("Saliendo del sistema de gestion portuaria...\n");
                break;

            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}