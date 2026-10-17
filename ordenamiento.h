#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include "contenedor.h"

// Prototipos de los tres métodos de ordenamiento solicitados
void bubbleSort(Contenedor *arr, int n, int ascendente);
void selectionSort(Contenedor *arr, int n, int ascendente);
void insertionSort(Contenedor *arr, int n, int ascendente);

#endif