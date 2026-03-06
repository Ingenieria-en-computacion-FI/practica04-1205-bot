#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>

/* Ejercicio 1 */
Nodo* crearNodo(int valor){
    Nodo *n = (Nodo*)malloc(sizeof(Nodo));
    if (n != NULL) {
        n->dato = valor;
        n->siguiente = NULL;
    }  
    return n;
}

/* Ejercicio 2 */
Nodo* crearArregloNodos(int n_elementos){
    Nodo *n = (Nodo*)calloc(n_elementos, sizeof(Nodo));
    return n;
}

/* Ejercicio 3 */
Nodo* agregarNodo(Nodo* arreglo, int *n, int valor){
    Nodo *nuevo_arreglo = (Nodo*)realloc(arreglo, (*n + 1) * sizeof(Nodo));
    if (nuevo_arreglo != NULL) { 
        (nuevo_arreglo + *n)->dato = valor;// -> caundo tienes nodo suelto o individual y [*n] cuando tienes un arreglo de nodos
        (nuevo_arreglo + *n)->siguiente = NULL;// (nuevo_arreglo + *n).dato = (nuevo_arreglo + *n)->dato
        (*n)++;
        return nuevo_arreglo;
    }

    return arreglo;
}

/* Ejercicio 4 */
void liberarNodos(Nodo* arreglo, int n){
    if(arreglo != NULL) free(arreglo);
}

/* Ejercicio 5 */
Nodo* construirTresNodos(){
    Nodo *n1 = crearNodo(1);
    Nodo *n2 = crearNodo(2);
    Nodo *n3 = crearNodo(3);
    if(n1 != NULL && n2 != NULL && n3 != NULL) {
        n1->siguiente = n2;
        n2->siguiente = n3;
    }
    return n1;
}

/* Ejercicio 6 */
int contarNodos(Nodo* inicio){
    int cont = 0;
    Nodo *n = inicio;
    while(n != NULL) {
        cont++;
        n = n->siguiente;
    }   

    return cont;
}

/* Ejercicio 7 */
Nodo* crearNodosPorEntrada(){
    int num;
    Nodo *n = NULL, *t = NULL;
    printf("Ingresa un numero entero (0 para terminar): ");
    scanf("%d", &num);

    while(num != 0) {
        if(n == NULL) {
            n = crearNodo(num);
            t = n;
        } else {
            t->siguiente = crearNodo(num);
            t = t->siguiente;
        }

        printf("Ingresa un numero entero (0 para terminar): ");
        scanf("%d", &num);
    }

    return n;
}
