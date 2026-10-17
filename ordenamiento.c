#include "ordenamiento.h"

// Función auxiliar para intercambiar dos estructuras usando apuntadores
static void intercambiar(Contenedor *a, Contenedor *b) {
    Contenedor temp = *a;
    *a = *b;
    *b = temp;
}

// a. Bubble Sort (Ordenamiento Burbuja)
void bubbleSort(Contenedor *arr, int n, int ascendente) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int condicion = ascendente ? (arr[j].peso > arr[j + 1].peso) : (arr[j].peso < arr[j + 1].peso);
            if (condicion) {
                intercambiar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// b. Selection Sort (Ordenamiento por Selección)
void selectionSort(Contenedor *arr, int n, int ascendente) {
    for (int i = 0; i < n - 1; i++) {
        int min_max_idx = i;
        for (int j = i + 1; j < n; j++) {
            int condicion = ascendente ? (arr[j].peso < arr[min_max_idx].peso) : (arr[j].peso > arr[min_max_idx].peso);
            if (condicion) {
                min_max_idx = j;
            }
        }
        if (min_max_idx != i) {
            intercambiar(&arr[min_max_idx], &arr[i]);
        }
    }
}

// c. Insertion Sort (Ordenamiento por Inserción)
void insertionSort(Contenedor *arr, int n, int ascendente) {
    for (int i = 1; i < n; i++) {
        Contenedor key = arr[i];
        int j = i - 1;
        while (j >= 0 && (ascendente ? (arr[j].peso > key.peso) : (arr[j].peso < key.peso))) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}