#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "nodo.h"

/* Función auxiliar para imprimir resultado de test */
void mostrarResultado(const char* ejercicio, bool correcto, int* puntos, int valor){
    if(correcto){
        printf("[✓] %s correcto (+%d puntos)\n", ejercicio, valor);
        *puntos += valor;
    }else{
        printf("[X] %s incorrecto (+0 puntos)\n", ejercicio);
    }
}

/* Función auxiliar para contar nodos de un arreglo */
bool compararArreglo(Nodo* arreglo, int n, int* valores){
    for(int i = 0; i < n; i++){
        if(arreglo[i].dato != valores[i]) return false;
    }
    return true;
}

/* Función auxiliar para liberar lista enlazada */
void liberarLista(Nodo* inicio){
    Nodo* temp;
    while(inicio){
        temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }
}

int main(){
    int puntaje = 0;

    printf("=== Test autocorrectivo de ejercicios de nodos ===\n\n");

    /* ------------------ Ejercicio 1 ------------------ */
    Nodo* n1 = crearNodo(10);
    mostrarResultado("Ejercicio 1: crearNodo", n1 && n1->dato==10 && n1->siguiente==NULL, &puntaje, 10);

    /* ------------------ Ejercicio 2 ------------------ */
    int valores2[5] = {0,1,2,3,4};
    Nodo* arreglo = crearArregloNodos(5);
    mostrarResultado("Ejercicio 2: crearArregloNodos", arreglo != NULL && compararArreglo(arreglo,5,valores2), &puntaje, 10);
    /*
     cuando compara el arreglo con los valores del arreglo inicializado con calloc,
     calloc se inicializa en 0, entonces seria falsa la condicion
     if(arreglo[i].dato != valores[i]) return false;
     como los datos de calloc son 0, el primer elemento cumple y devuelve true,
     pero los demas al ser diferentes de 0, devuelve false, por eso el resultado es incorrecto
     aunque calloc este bien implementado
    */

    /* ------------------ Ejercicio 3 ------------------ */
    int tam = 5;
    arreglo = agregarNodo(arreglo,&tam,99);
    int valores3[6] = {0,1,2,3,4,99};
    mostrarResultado("Ejercicio 3: agregarNodo", arreglo!=NULL && tam==6 && compararArreglo(arreglo,6,valores3), &puntaje, 10);
   
    /* ------------------ Ejercicio 4 ------------------ */
    liberarNodos(arreglo, tam);
    liberarNodos(n1, 1);
    mostrarResultado("Ejercicio 4: liberarNodos (manual ver visual)", true, &puntaje, 5);

    /* ------------------ Ejercicio 5 ------------------ */
    Nodo* inicio = construirTresNodos();
    bool correcto5 = inicio && inicio->dato == 10 && inicio->siguiente && inicio->siguiente->dato==20 && inicio->siguiente->siguiente && inicio->siguiente->siguiente->dato==30;
    mostrarResultado("Ejercicio 5: construirTresNodos", correcto5, &puntaje, 10);

    /* ------------------ Ejercicio 6 ------------------ */
    int total = contarNodos(inicio);
    mostrarResultado("Ejercicio 7: contarNodos", total == 3, &puntaje, 5); //mostrarResultado("Ejercicio 7: contarNodos", total == 2, &puntaje, 5); mal
    /*
     Error en el test: la lista inicio tiene 3 nodos (10, 20, 30),
     por lo que contarNodos deberia devolver un 3 y no un 2,
     asi que seria error del test, no de la función contarNodos
    */

    /* ------------------ Ejercicio 7 ------------------ */
    // Aquí no podemos leer del usuario en test automático, simulamos entrada
    Nodo* desdeEntrada = crearNodo(1);
    Nodo* segundo = crearNodo(2);
    desdeEntrada->siguiente = segundo;
    bool correcto8 = desdeEntrada && desdeEntrada->siguiente && desdeEntrada->dato==1 && desdeEntrada->siguiente->dato==2;
    mostrarResultado("Ejercicio 8: crearNodosPorEntrada (simulado)", correcto8, &puntaje, 10);

    liberarLista(inicio);
    liberarLista(desdeEntrada);

    printf("\n=== Puntaje total: %d/70 ===\n", puntaje);

    return 0;
}
