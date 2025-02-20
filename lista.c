#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// Inicializa una lista vacía
int creaVacia(Lista *l) {
    l->raiz = (tipoCelda *)malloc(sizeof(tipoCelda));
    if (l->raiz == NULL) return -1;

    l->raiz->sig = NULL;
    l->ultimo = l->raiz;
    return 0;
}

// Devuelve si la lista está vacía
int vacia(Lista *l) {
    return l->raiz->sig == NULL;
}

// Inserta un elemento en la lista
int inserta(tipoElemento x, tipoPosicion p, Lista *l) {
    tipoCelda *nuevo = (tipoCelda *)malloc(sizeof(tipoCelda));
    if (nuevo == NULL) return -1;

    nuevo->elemento = x;
    nuevo->sig = p->sig;
    p->sig = nuevo;

    if (p == l->ultimo) {
        l->ultimo = nuevo;
    }

    return 0;
}

// Suprime un elemento de la lista
int suprime(tipoPosicion p, Lista *l) {
    if (p->sig == NULL) return -1;

    tipoCelda *aEliminar = p->sig;
    p->sig = aEliminar->sig;

    if (aEliminar == l->ultimo) {
        l->ultimo = p;
    }

    free(aEliminar);
    return 0;
}

// Recupera el elemento en una posición dada
tipoElemento recupera(tipoPosicion p, Lista *l) {
    if (p->sig == NULL) return -1; // Error
    return p->sig->elemento;
}

// Devuelve la primera posición de la lista
tipoPosicion primero(Lista *l) {
    return l->raiz;
}

// Devuelve la siguiente posición
tipoPosicion siguiente(tipoPosicion p, Lista *l) {
    return p->sig;
}

// Devuelve la posición final (nodo ficticio)
tipoPosicion fin(Lista *l) {
    return l->ultimo;
}

// Recupera el último elemento de la lista
tipoElemento recuperaUltimo(Lista *l) {
    if (vacia(l)) return -1; // Error
    return l->ultimo->elemento;
}

// Divide una lista en dos en la posición p
int dividirLista(Lista *lOrigen, tipoPosicion p, Lista *lNueva) {
    if (creaVacia(lNueva) != 0) return -1;

    lNueva->raiz->sig = p->sig;
    lNueva->ultimo = lOrigen->ultimo;

    p->sig = NULL;
    lOrigen->ultimo = p;

    return 0;
}

// Transfiere un nodo de una lista a otra
int traspasarNodo(tipoPosicion p, Lista *la, tipoPosicion q, Lista *lb) {
    if (p->sig == NULL) return -1;

    tipoCelda *aMover = p->sig;
    p->sig = aMover->sig;

    if (aMover == la->ultimo) {
        la->ultimo = p;
    }

    aMover->sig = q->sig;
    q->sig = aMover;

    if (q == lb->ultimo) {
        lb->ultimo = aMover;
    }

    return 0;
}

// Imprime la lista
void imprime(Lista *l) {
    tipoPosicion p = primero(l);
    while (p->sig != NULL) {
        printf("%d ", recupera(p, l));
        p = siguiente(p, l);
    }
    printf("\n");
}

// Anula la lista
int anula(Lista *l) {
    tipoPosicion p = l->raiz;
    while (p->sig != NULL) {
        suprime(p, l);
    }
    l->ultimo = l->raiz;
    return 0;
}

// Destruye la lista
int destruye(Lista *l) {
    anula(l);
    free(l->raiz);
    l->raiz = NULL;
    l->ultimo = NULL;
    return 0;
}