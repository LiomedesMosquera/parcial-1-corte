#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#define MAX_CODIGO 20
#define MAX_TIPO 30
#define MAX_BAY 10

// Estructura para el manejo de carga en el puerto
typedef struct {
    char codigo[MAX_CODIGO];
    float peso; // en toneladas
    char tipo_mercancia[MAX_TIPO];
    char bahia[MAX_BAY];
} Contenedor;

// Prototipos de funciones usando apuntadores
void registrarContenedor(Contenedor *c);
void mostrarContenedor(const Contenedor *c);
void mostrarListaContenedores(const Contenedor *arr, int n);

#endif