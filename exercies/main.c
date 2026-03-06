#include <stdio.h>
#include "nodo.h"

int main() {
    printf("===== Repo de ejercicios de nodos =====\n");

    // Ejercicio 1
    Nodo* n1 = crearNodo(10);
    if (n1 != NULL) printf("Nodo creado con dato: %d\n", n1->dato);

    // Ejercicio 2
    Nodo* arreglo = crearArregloNodos(5);
    printf("\nArreglo de 5 nodos creado (usando calloc)\n");
    for(int i = 0; i < 5; i++) {
        printf(" arreglo[%d].dato = %d\n", i, (arreglo + i)->dato);
    }

    // Ejercicio 3
    int tam = 5;
    arreglo = agregarNodo(arreglo, &tam, 99);
    printf("\nArreglo actualizado con nuevo nodo(realloc):\n");
    for(int i = 0; i < tam; i++) {
        printf(" arreglo[%d].dato = %d\n", i, (arreglo + i)->dato);
    }

    // Ejercicio 4
    liberarNodos(arreglo, tam);
    liberarNodos(n1, 1);

    // Ejercicio 5
    Nodo* inicio = construirTresNodos();
    printf("\nNodos enlazados manualmente:\n");
    Nodo* n = inicio;
    while(n != NULL) {
        printf("Dato: %d\n", n->dato);
        n = n->siguiente;
    }

    // Ejercicio 6
    int total = contarNodos(inicio);
    printf("Total de nodos: %d\n", total);

    // Ejercicio 7
    Nodo *desdeEntrada = crearNodosPorEntrada();
    printf("Lista de numeros desde entrada:\n");
    Nodo *recorredorNodo = desdeEntrada;
    while(recorredorNodo != NULL) {
        printf("Nodo -> dato: %d\n", recorredorNodo->dato);
        recorredorNodo = recorredorNodo->siguiente;
    }

    return 0;
}
