#ifndef NODO_H
#define NODO_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Estructura Nodo */
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

/* Ejercicio 1: Crear un nodo dinámicamente */
Nodo* crearNodo(int valor);

/* Ejercicio 2: Crear varios nodos con calloc */
Nodo* crearArregloNodos(int n);

/* Ejercicio 3: Agregar un nodo usando realloc */
Nodo* agregarNodo(Nodo* arreglo, int* n, int valor);

/* Ejercicio 4: Liberar memoria de nodos */
void liberarNodos(Nodo* arreglo, int n);

/* Ejercicio 5: Construir nodos enlazados manualmente */
Nodo* construirTresNodos();

/* Ejercicio 6: Contar nodos */
int contarNodos(Nodo* inicio);

/* Ejercicio 7: Crear nodos leyendo números */
Nodo* crearNodosPorEntrada();

#endif
