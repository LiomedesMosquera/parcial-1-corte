#include <stdio.h>
#include <string.h>
#include "contenedor.h"

void registrarContenedor(Contenedor *c) {
    printf("Ingrese codigo alfanumerico (ej. CNT-101): ");
    scanf("%19s", c->codigo);
    printf("Ingrese peso en toneladas (t): ");
    scanf("%f", &(c->peso));
    printf("Ingrese tipo de mercancia (ej. Refrigerado): ");
    scanf("%29s", c->tipo_mercancia);
    printf("Ingrese bahia de asignacion (ej. B-3): ");
    scanf("%9s", c->bahia);
}

void mostrarContenedor(const Contenedor *c) {
    printf("Codigo: %-10s | Peso: %6.2f t | Mercancia: %-15s | Bahia: %-5s\n", 
           c->codigo, c->peso, c->tipo_mercancia, c->bahia);
}

void mostrarListaContenedores(const Contenedor *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d] ", i + 1);
        mostrarContenedor(&arr[i]);
    }
}