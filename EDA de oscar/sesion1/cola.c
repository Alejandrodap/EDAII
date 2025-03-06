#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"

int colaCreaVacia(Cola *c){
    if(c == NULL){
        perror("Cola nula");
        return -1;
    }

    c->fondo=c->frente=NULL;
    return 0;
}

int colaVacia(Cola *c){
    if(c==NULL){
       perror("La cola no existe");
       return -1;
   }
    return (c->frente==NULL&&c->fondo==NULL);
    
}

int colaInserta(Cola *c,tipoElemento elemento){
    if(c==NULL){
        perror("La cola no existe");
        return -1;
    }
    tipoCelda *nuevo;
    if(NULL==(nuevo=(tipoCelda *)malloc(sizeof(tipoCelda)))){
        perror("Error en la reserva de memoria");
        return -1;
    }
    nuevo->elemento=elemento;
    nuevo->sig=NULL;
    if(colaVacia(c)){
        c->frente=c->fondo=nuevo;
    }else{
        c->fondo->sig=nuevo;
    }
    c->fondo=nuevo;
    return 0;
}

tipoElemento colaSuprime(Cola *c){
    if(c==NULL){
       perror("La cola no existe");
       return NULL;
   }
    if(colaVacia(c)){
        perror("La cola está vacía");
        return NULL;
    }
    tipoElemento elemento=c->frente->elemento;
    tipoCelda *aux=c->frente;
    if(aux->sig==NULL){
        c->fondo=c->frente=NULL;
    } else {
        c->frente=c->frente->sig;
    }
    free(aux);
    return elemento;
    
}
