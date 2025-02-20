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


int altura(Arbol raiz)
{ 
  int alt = -1;
  int temp1, temp2;
  if (raiz==NULL) return 0;
  else
  { 
    temp1 = altura(raiz->izq);s
    temp2 = altura(raiz->der);
    if (temp1>temp2) alt = temp1+1;
    else alt = temp2+1;
    return alt;
  }
}


int numNodos(Arbol raiz)
{ 
  if (raiz!=NULL){
    return 1+numNodos(raiz->izq) + numNodos(raiz->der);
  } else return 0;
}


int numNodosHoja (Arbol raiz)
{ 
  if (raiz != NULL){
    if (raiz->izq == NULL && raiz->der == NULL){
      return 1;
    } else {
      return numNodosHoja(raiz->izq) + numNodosHoja(raiz->der);
    }
  }

}


int numNodosInternos (Arbol raiz)
{ 
  if (raiz != NULL){
    if (raiz->izq != NULL || raiz->der != NULL){
      return 1 + numNodosInternos(raiz->izq) + numNodosInternos(raiz->der);
    } else {
      return 0;
    }
  }
}


int sustituye(Arbol raiz, tipoInfo x, tipoInfo y)
{ 
  int numSustituciones = 0;

  if (raiz != NULL){
    numSustituciones = sustituye(raiz->izq, x, y) + sustituye(raiz->der, x, y);
    if (raiz->info == x){
      raiz->info = y;
      numSustituciones++;
    }
  }
  return numSustituciones;
}


Arbol buscarMax(Arbol raiz)
{ 
  Arbol maximo1, maximo2, maximoTotal;

  if (raiz != NULL){
    maximo1 = buscarMax(raiz->izq);
    maximo2 = buscarMax(raiz->der);
    maximoTotal = raiz;

    if (maximo1 != NULL){
      if (maximo1->info > maximoTotal->info){
        maximoTotal = maximo1;
      }
    }
    if (maximo2 != NULL){
      if (maximo2->info > maximoTotal->info){
        maximoTotal = maximo2;
      }
    }
    return maximoTotal;
  }
}


int similares (Arbol r1, Arbol r2){
  if (r1 != NULL && r2 != NULL){
    
    if( similares(r1->izq, r2->izq) && similares(r1->der, r2->der) ){
      return 1;
    } else {
      return 0;
    }
    if (r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL){
      return 0;
    }
  }
  return 1;
}


Arbol especular(Arbol raiz)
{ 
  Arbol temp;
  if (raiz != NULL){
    temp = creaNodo(raiz->info);
    raiz->izq = especular(raiz->der);
    raiz->der = especular(temp);
  }
  return temp;
}


int equivalentes (Arbol r1, Arbol r2){
  
}


int anula(Arbol raiz)
{ 
  if (raiz != NULL){
    anula(raiz->izq);
    anula(raiz->der);
    free(raiz);
  }
  return 1;
}


int numHijoUnico (Arbol raiz){

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
    printf(" %c ", nodo->info);
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



