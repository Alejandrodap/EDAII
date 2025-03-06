#ifndef __PILA_H
#define __PILA_H
#include "arbol.h"

#ifndef __TIPO_ELEMENTO
#define __TIPO_ELEMENTO
typedef Arbol tipoElemento;
#endif

#ifndef __TIPO_CELDA
#define __TIPO_CELDA
typedef struct tipoCelda {
	tipoElemento elemento;
	struct tipoCelda * sig;
	} tipoCelda;
#endif

typedef tipoCelda *Pila;

int creaVacia(Pila *p);
int vacia(Pila *p);
int inserta(Pila *p, tipoElemento x);
tipoElemento suprime(Pila *p);

#endif