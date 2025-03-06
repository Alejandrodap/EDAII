#include "monticulo.h"
#include <stdlib.h>


void iniciaMonticulo(Monticulo *m){
    m->tamanno=0;
}
int vacioMonticulo(Monticulo m){
    return m.tamanno==0;
}
int insertar(tipoElemento x, Monticulo *m){
    if(m->tamanno==MAXIMO){
        return 0;
    }
    m->tamanno++;
    m->elemento[m->tamanno]=x;
    filtradoAscendente(m,m->tamanno);
    return 1;
}
int eliminarMinimo(Monticulo *m, tipoElemento *minimo){
    if(vacioMonticulo(*m)){
        return 0;
    }
    *minimo=m->elemento[1];
    m->elemento[1]=m->elemento[m->tamanno];
    m->tamanno--;
    filtradoDescendente(m,1);
    return 1;
}
void decrementarClave(int pos, tipoClave cantidad, Monticulo *m){
    m->elemento[pos].clave-=cantidad;
    filtradoAscendente(m,pos);
}
void incrementarClave(int pos, tipoClave cantidad, Monticulo *m){
    m->elemento[pos].clave+=cantidad;
    filtradoDescendente(m,pos);
}
int esMonticulo(Monticulo m){
    int i;
    for(i=2;i<=m.tamanno;i++){
        if(m.elemento[i].clave<m.elemento[i/2].clave){
            return 0;
        }
    }
    return 1;
}

/* Funciones auxiliares que conviene implementar: las dos estrategias de filtrado en las 
   que se basan todos los algoritmos que manejan montículos */

  void filtradoDescendente(Monticulo *m, int i){
    int h;
    tipoElemento x;
    x=m->elemento[i];
    while(2*i<=m->tamanno){
        h=2*i;
        if(h<m->tamanno && m->elemento[h+1].clave<m->elemento[h].clave){
            h++;
        }
        if(m->elemento[h].clave>=x.clave){
            break;
        }
        m->elemento[i]=m->elemento[h];
        i=h;
    }
    m->elemento[i]=x;
  }
  void filtradoAscendente(Monticulo *m, int i){
    tipoElemento x;
    x=m->elemento[i];
    while(i>1 && m->elemento[i/2].clave>x.clave){
        m->elemento[i]=m->elemento[i/2];
        i=i/2;
    }
    m->elemento[i]=x;
  }

/* Operación crearMonticulo la utilizaremos en ejercicio 2 y en tema de grafos */ 

  void crearMonticulo(Monticulo *m){
    int i;
    for(i=m->tamanno/2;i>=1;i--){
        filtradoDescendente(m,i);
    }
  }

  void heapsort(Monticulo *m)
{ 
  int i;
  tipoElemento x;
  int originalTamanno = m->tamanno; // Guardar el tamaño original
  for (i=m->tamanno/2;i>=1;i--)
    filtradoDescendente(m,i);
  for (i=m->tamanno;i>1;i--)
  { 
    x=m->elemento[1];
    m->elemento[1]=m->elemento[m->tamanno];
    m->elemento[m->tamanno]=x;
    m->tamanno--;
    filtradoDescendente(m,1);
  }
  m->tamanno = originalTamanno; // Restaurar el tamaño original
}