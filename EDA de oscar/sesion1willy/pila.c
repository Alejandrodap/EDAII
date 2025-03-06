#include <stdlib.h>
#include "pila.h"

int creaVacia(Pila *p) {
    if (p == NULL) {
        return -1;
    }
    else {
        *p = NULL;
        return 0;
    }
}

int vacia(Pila *p) {
    if (p == NULL)
        return -1;

    if (*p == NULL)
        return 1;
    else
        return 0;
}

int inserta(Pila *p, tipoElemento x) {
    if (p == NULL) 
        return -1;
    tipoCelda *aux = NULL;
    if (NULL == (aux = malloc(sizeof(tipoCelda))))
        return -1;
    else {
        aux->sig = NULL;    
        aux->elemento = x;
        if (*p == NULL) {
            *p = aux;
            return 0;
        }
        else {
            aux->sig = *p;
            *p = aux;
            return 0;
        }
    }
}

// Para solucionar la abstracción del código de error se puede cambiar el prototipo,
// devolviendo el valor suprimido por un parámetro y que el return sea un int
tipoElemento suprime(Pila *p) {
    if (p == NULL)
        return NULL;

    if (*p == NULL)
        return NULL;
    else {
        tipoCelda *aux;
        tipoElemento x;
        aux = *p;
        *p = (*p)->sig; //Si solo quedaba un elemento se queda a NULL
        x = aux->elemento;
        free(aux);
        return x;
    }
}

