#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// CREAR UNA PILA VACÍA
int pilaCreaVacia(Pila *p) {
    *p = NULL; // Una pila vacía es un puntero nulo
    return 0;  // Retorna 0 como éxito
}

// VERIFICAR SI LA PILA ESTÁ VACÍA
int pilaVacia(Pila *p) {
    return (*p == NULL); // Verdadero si el puntero es NULL
}

// INSERTAR ELEMENTO EN LA PILA
int pilaInserta(Pila *p, tipoElemento elemento) {
    // Crear un nuevo nodo
    tipoCelda *nuevoNodo = (tipoCelda *)malloc(sizeof(tipoCelda));
    if (nuevoNodo == NULL) {
        return -1; // Fallo en la asignación de memoria
    }
    // Asignar el elemento y ajustar el puntero
    nuevoNodo->elemento = elemento;
    nuevoNodo->sig = *p; // El nuevo nodo apunta al antiguo tope
    *p = nuevoNodo;      // Actualizar el tope de la pila
    return 0;            // Éxito
}

// SUPRIMIR ELEMENTO DE LA PILA
tipoElemento pilaSuprime(Pila *p) {
    if (pilaVacia(p)) {
        exit(EXIT_FAILURE); // Terminar programa en caso de error
    }
    // Obtener el nodo a suprimir
    tipoCelda *nodoEliminar = *p;
    tipoElemento elemento = nodoEliminar->elemento; // Guardar el elemento
    *p = nodoEliminar->sig;                         // Actualizar el tope
    free(nodoEliminar);                             // Liberar memoria
    return elemento;                                // Retornar el elemento suprimido
}
