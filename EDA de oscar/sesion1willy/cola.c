#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"



int colaCreaVacia(Cola *c)
{
    if (c == NULL) return -1;
    
    c->frente = NULL;
    c->fondo = NULL;
    return 0;
}

int colaVacia(Cola *c)
{
    if (c == NULL) return -1;

    if (c->frente == NULL && c->fondo == NULL)
        return 1;
    else
        return 0;
}

int colaInserta(Cola *c,tipoElemento elemento)
{
    if (c == NULL) 
        return -1;
    
    tipoCelda *aux;
    if (NULL == (aux = malloc(sizeof(tipoCelda))))
        return -1;
    aux->elemento = elemento;
    aux->sig == NULL;
    if (c->frente == NULL) {
        // No había elementos
        c->frente = aux;
    }
    else {
        // El que era el último apunta al insertado
        c->fondo->sig = aux;
    }
    c->fondo = aux;
    return 0;
}

tipoElemento colaSuprime(Cola *c)
{
    if (c == NULL || c->frente == NULL)
        return NULL;

    tipoCelda *aux = c->frente;
    tipoElemento x = aux->elemento;

    c->frente = aux->sig;
    if (c->frente == NULL) {
        // No había segundo elemento
        c->fondo = NULL; // Para dejar la cola vacía correctamente
    }
    free(aux);
    return x;
}
