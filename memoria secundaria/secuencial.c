#include "secuencial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*int leeSecuencial(char *fichSecuencial)
que toma como entrada el nombre del fichero secuencial que se desea leer
(alumnos.dat) y muestra el contenido del mismo. La función devuelve el número de
registros que tiene el fichero y muestra todos los registros del mismo anteponiendo a
cada uno de ellos el número relativo del registro (NRR) en el fichero.*/
int leeSecuencial(char *fichero){
    FILE *fsecuencial;
    tipoAlumno reg;
    int num;
    fsecuencial=fopen(fichero,"r");
    if (fsecuencial==NULL)
    {
        printf("Error al abrir fichero");
        return -1;
    }
    while (fread(&reg,sizeof(tipoAlumno),1,fsecuencial)==1)
    {
        printf("%s %s %s %s %s\n ",reg.dni,reg.nombre,reg.ape1,reg.ape2,reg.provincia);
        num++;
    }
    fclose(fsecuencial);
    return num;
}


int buscaReg(FILE *fSecuencial, tipoAlumno *reg,char *dni){
    while (fread(&reg,sizeof(tipoAlumno),1,fSecuencial)==1)
    {
        if(strcmp(reg->dni,dni)==0){
            return 1;
        }
    }
    return 0;
}


int insertaReg(char *fSecuencial, tipoAlumno *reg){
    FILE *fsecuencial;
    fsecuencial=fopen(fSecuencial,"r");
    if (fsecuencial==NULL)
    {
        printf("Error al abrir fichero");
        return -1;
    }

    fwrite(reg,sizeof(tipoAlumno),1,fsecuencial);
    fclose(fsecuencial);
    return 0;
}

