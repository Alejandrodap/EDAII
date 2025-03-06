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
    if(raiz==NULL){
        return -1;
    }
    int altIzq=altura(raiz->izq);
    int altDer=altura(raiz->der);
    if(altIzq>altDer){
        return altIzq+1;
    }else{
        return altDer+1;
    }
}
int numNodos(Arbol raiz){
    if(raiz==NULL){
        return 0;
    }
    return 1+numNodos(raiz->izq)+numNodos(raiz->der);
}

Arbol anula(Arbol raiz){
    if(raiz!=NULL){
        raiz->izq=anula(raiz->izq);
        raiz->der=anula(raiz->der);
        free(raiz);
    }
    return NULL;
}

int sustiuye(Arbol raiz, tipoInfo x, tipoInfo y){
    if(raiz==NULL){
        return 0;
    }
    if(raiz->info==x){
        raiz->info=y;
        return 1;
    }
    return sustiuye(raiz->izq,x,y)+sustiuye(raiz->der,x,y);
}

int numNodosHoja(Arbol raiz){
    if(raiz==NULL){
        return 0;
    }
    if(raiz->izq==NULL && raiz->der==NULL){
        return 1;
    }
    return numNodosHoja(raiz->izq)+numNodosHoja(raiz->der);
}

int numNodosInternos(Arbol raiz){
    if(raiz==NULL){
        return 0;
    }
    if(raiz->izq!=NULL || raiz->der!=NULL){
        return 1+numNodosInternos(raiz->izq)+numNodosInternos(raiz->der);
    }
    return numNodosInternos(raiz->izq)+numNodosInternos(raiz->der);
}
int numHijoUnico(Arbol raiz){
    if(raiz==NULL){
        return 0;
    }
    if(raiz->izq!=NULL && raiz->der==NULL){
        return 1+numHijoUnico(raiz->izq);
    }
    if(raiz->izq==NULL && raiz->der!=NULL){
        return 1+numHijoUnico(raiz->der);
    }
    return numHijoUnico(raiz->izq)+numHijoUnico(raiz->der);
}

Arbol buscarMax(Arbol raiz){
    if(raiz==NULL){
        return NULL;
    }
    Arbol maxIzq=buscarMax(raiz->izq);
    Arbol maxDer=buscarMax(raiz->der);
    if(maxIzq==NULL && maxDer==NULL){
        return raiz;
    }
    if(maxIzq!=NULL && maxDer==NULL){
        if(raiz->info>maxIzq->info){
            return raiz;
        }else{
            return maxIzq;
        }
    }
    if(maxIzq==NULL && maxDer!=NULL){
        if(raiz->info>maxDer->info){
            return raiz;
        }else{
            return maxDer;
        }
    }
    if(raiz->info>maxIzq->info && raiz->info>maxDer->info){
        return raiz;
    }
    if(maxIzq->info>maxDer->info){
        return maxIzq;
    }else{
        return maxDer;
    }
}

Arbol buscarMin(Arbol raiz){
    if(raiz==NULL){
        return NULL;
    }
    Arbol minIzq=buscarMin(raiz->izq);
    Arbol minDer=buscarMin(raiz->der);
    if(minIzq==NULL && minDer==NULL){
        return raiz;
    }
    if(minIzq!=NULL && minDer==NULL){
        if(raiz->info<minIzq->info){
            return raiz;
        }else{
            return minIzq;
        }
    }
    if(minIzq==NULL && minDer!=NULL){
        if(raiz->info<minDer->info){
            return raiz;
        }else{
            return minDer;
        }
    }
    if(raiz->info<minIzq->info && raiz->info<minDer->info){
        return raiz;
    }
    if(minIzq->info<minDer->info){
        return minIzq;
    }else{
        return minDer;
    }
}

int similares(Arbol r1,Arbol r2){
    if(r1==NULL && r2==NULL){
        return 1;
    }
    if(r1==NULL || r2==NULL){
        return 0;
    }
    return similares(r1->izq,r2->izq) && similares(r1->der,r2->der);
}

int equivalentes(Arbol r1,Arbol r2){
    if(r1==NULL && r2==NULL){
        return 1;
    }
    if(r1==NULL || r2==NULL){
        return 0;
    }
    return r1->info==r2->info && equivalentes(r1->izq,r2->izq) && equivalentes(r1->der,r2->der);
}

Arbol especular(Arbol raiz){
    if(raiz==NULL){
        return NULL;
    }
    Arbol aux=raiz->izq;
    raiz->izq=especular(raiz->der);
    raiz->der=especular(aux);
    return raiz;
}

int evaluar(Arbol a){
    if(a==NULL){
        return 0;
    }
    if(a->izq==NULL && a->der==NULL){
        return a->info-'0';
    }
    int op1=evaluar(a->izq);
    int op2=evaluar(a->der);
    switch(a->info){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
    }
    return 0;
}

int buscar(int *enOrden, int inicio, int fin, int dato){
    for(int i=inicio;i<=fin;i++){
        if(enOrden[i]==dato){
            return i;
        }
    }
    return -1;
}

Arbol construirArbol(int *enOrden, int *preOrden, int inicio, int fin){
    if(inicio>fin){
        return NULL;
    }
    static int preIndex=0;
    Arbol nuevo=creaNodo(preOrden[preIndex]);
    preIndex++;
    if(inicio==fin){
        return nuevo;
    }
    int inIndex=buscar(enOrden,inicio,fin,nuevo->info);
    nuevo->izq=construirArbol(enOrden,preOrden,inicio,inIndex-1);
    nuevo->der=construirArbol(enOrden,preOrden,inIndex+1,fin);
    return nuevo;
}
