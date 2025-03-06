#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p){
    if(p == NULL){
        perror("Pila nula");
        return -1;
    }
    *p=NULL;
    return 0;
}

int pilaVacia(Pila *p){
   if(p==NULL){
       perror("La pila no existe");
       return -1;
   }
    return *p==NULL;
}

int pilaInserta(Pila *p,tipoElemento elemento){
    if(p==NULL){
        perror("La pila no existe");
        return -1;
    }
    tipoCelda *nuevo;
    if(NULL==(nuevo=(tipoCelda *)malloc(sizeof(tipoCelda)))){
        perror("Error en la reserva de memoria");
        return -1;
    }
    nuevo->elemento=elemento;
    nuevo->sig=*p;
    *p=nuevo;
    return 0;
}

tipoElemento pilaSuprime(Pila *p){
   if(p==NULL){
       perror("La pila no existe");
       return NULL;
   }
    if(pilaVacia(p)){
        perror("La pila está vacía");
        return NULL;
    }
    tipoElemento elemento=(*p)->elemento;
    tipoCelda *aux=*p;
    *p=(*p)->sig;
    free(aux);
    return elemento;
}
