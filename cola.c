#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

// CREAR UNA COLA VACÍA
int colaCreaVacia(Cola *c) {
    c->frente = NULL;
    c->fondo = NULL;
    return 0; // Éxito
}

// VERIFICAR SI LA COLA ESTÁ VACÍA
int colaVacia(Cola *c) {
    return (c->frente == NULL); // Verdadero si el frente es NULL
}

// INSERTAR ELEMENTO EN LA COLA
int colaInsertaC(Cola *c, tipoElemento elemento) {
    // Crear un nuevo nodo
    tipoCelda *nuevoNodo = (tipoCelda *)malloc(sizeof(tipoCelda));
    if (nuevoNodo == NULL) {
        return -1; // Fallo en la asignación de memoria
    }
    // Asignar el elemento y ajustar los punteros
    nuevoNodo->elemento = elemento;
    nuevoNodo->sig = NULL;

    if (colaVacia(c)) {
        // Si la cola está vacía, el nuevo nodo es el frente y el fondo
        c->frente = nuevoNodo;
        c->fondo = nuevoNodo;
    } else {
        // Si no está vacía, añadir el nodo al final y actualizar el fondo
        c->fondo->sig = nuevoNodo;
        c->fondo = nuevoNodo;
    }
    return 0; // Éxito
}

// SUPRIMIR ELEMENTO DE LA COLA
tipoElemento colaSuprime(Cola *c) {
    if (colaVacia(c)) {
        fprintf(stderr, "Error: Intento de suprimir en una cola vacía.\n");
        exit(EXIT_FAILURE); // Terminar programa en caso de error
    }
    // Obtener el nodo del frente
    tipoCelda *nodoEliminar = c->frente;
    tipoElemento elemento = nodoEliminar->elemento; // Guardar el elemento
    c->frente = nodoEliminar->sig;                  // Actualizar el frente

    // Si la cola queda vacía, también actualizar el fondo
    if (c->frente == NULL) {
        c->fondo = NULL;
    }
    free(nodoEliminar); // Liberar memoria del nodo eliminado
    return elemento;    // Retornar el elemento suprimido
}
