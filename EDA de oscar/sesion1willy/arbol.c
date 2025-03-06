#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "cola.h"

//
// Reserva de memoria para un nuevo nodo de árbol binario
//
Arbol creaNodo(tipoInfo info)
{ tipoNodo * nuevo;

  //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));
  if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL)
	return NULL;
  else
  { 	nuevo->info=info;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	return nuevo;
   }
}

//
// Recorrido en amplitud o por niveles: necesita una cola de punteros a nodos de árbol binario!!!
//

void amplitud(Arbol raiz)
{ Cola c;
  tipoNodo *nodo;
  colaCreaVacia(&c);
  nodo = raiz;
  if (raiz!=NULL) colaInserta(&c,nodo);
  while (!colaVacia(&c))
  { nodo = (Arbol) colaSuprime(&c);
    printf("%c ", nodo->info);
    if (nodo->izq!=NULL) colaInserta(&c,nodo->izq);
    if (nodo->der!=NULL) colaInserta(&c,nodo->der);
  }
}
// 
// Recorridos en profundidad "recursivos"
//
void preOrden(Arbol raiz)
{ if (raiz!=NULL)
  { printf("%c ",raiz->info);
    preOrden(raiz->izq);
    preOrden(raiz->der);
  }
}
void enOrden(Arbol raiz)
{ if (raiz!=NULL)
  { enOrden(raiz->izq);
    printf("%c ",raiz->info);
    enOrden(raiz->der);
  }
}
void postOrden(Arbol raiz)
{ if (raiz!=NULL)
  { postOrden(raiz->izq);
    postOrden(raiz->der);
    printf("%c ",raiz->info);
  }
}

int altura(Arbol raiz){
  if (raiz == NULL) return -1; //No hay nodos
  // Si es una hoja, caso base
  if (raiz->der == NULL && raiz->izq == NULL) {
    return 0;
  }
  else {
    //Se elige la mayor de las dos alturas recursivamente
    int altIzq = 1 + altura(raiz->izq);
    int altDer = 1 + altura(raiz->der);
    if (altIzq >= altDer) return altIzq;
    else return altDer;
  }
}

int numNodos(Arbol raiz) {
  int num = 0;
  if (raiz != NULL) {
    num++;
    num += numNodos(raiz->izq);
    num += numNodos (raiz->der); 
    return num;
  }
  else return 0;
}

Arbol anula(Arbol raiz) {
  if (raiz != NULL) {
    anula(raiz->izq);
    anula(raiz->der);
    free(raiz);
  }
  return NULL;
}




