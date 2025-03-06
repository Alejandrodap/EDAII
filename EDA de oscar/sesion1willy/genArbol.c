#include <stdlib.h>
#include <stdio.h>
#include "genArbol.h"
#include "pila.h"



Arbol genArbol(char *exPostfija)
{ Pila p=NULL;
  Arbol a=NULL;
  int i=0;
  char simbolo;
  tipoInfo info;
  simbolo = exPostfija[i];
  while (simbolo != '\0')
  { switch(esOperador(simbolo))
    { case 0: a = creaNodo(simbolo);
 	      inserta(&p,a);
	      break;
      case 1: a = creaNodo(simbolo);
  	      a->der = (Arbol) suprime(&p);
  	      a->izq = (Arbol) suprime(&p);
  	      inserta(&p,a);
      	      break;
      default: printf("\n\n¡¡Expresión incorrecta !!\n\n");
      		// anula(a); 
      		while (!vacia(&p)) suprime(&p);
      	       return NULL;		
    }
    i++;
    simbolo=exPostfija[i];
  }
  return suprime(&p);
}

int esOperador(char simbolo)
{ if ((simbolo=='+') || (simbolo=='-') || (simbolo=='*') || (simbolo=='/'))
	return 1;
  else  if ((simbolo>= 'A' && simbolo<= 'Z') ||
            (simbolo>= 'a' && simbolo<= 'z') ||
            (simbolo>= '0' && simbolo<= '9'))
  		return 0;
  	else return -1;
}

int evaluar(Arbol a) {
    if (a== NULL) return -999999;
    if (a->info == '+')
        return (evaluar(a->izq) + evaluar (a->der));
    
    if (a->info == '-')
        return (evaluar(a->izq) - evaluar (a->der));

    if (a->info == '*')
        return (evaluar(a->izq) * evaluar (a->der));

    return (atoi(&(a->info)));

    return (a->info - 48);
}
