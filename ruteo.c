/****************************************************
*                MODULO DE RUTEO                    *
*                                                   *
* Materia:Taller de Desarrollo de Apliaciones.      *
*                                                   *
* Descripción: Este modulo se generan las tablas    *
*de ruteo en cada nodo, de acuerdo al algoritmo     *
*de Dijkstra.                                       *
*                                                   *
* El programa se realizó el 7 de mayo del 2018.     *
*                                                   *
* Autor:Zurita Escobar Fernanda. .                    *
****************************************************/
#include "tipos.h"
#include "ruteo.h"
#include "topologia.h"
#define MENOR 1000000

/*****************************************************
*                FUNCIÓN TABLASRUTEO                 *
*                                                    *
* Esta función se encarga de crear las tablas de     *
*con base de en las tablas de adyacencia.            *
*                                                    *
* La función se realizó el 7 de mayo del 2018.       *
*                                                    *
* Autores:Zurita Escobar Fernanda                    *
*****************************************************/
void tablasRuteo(nodo **inicio, int **tabla){//Inicia función tablasRuteo.
  nodo *aux=*inicio, *aux2;//Variables.
  rtabla *tablaF, *tablaAu;//Declaración de variables.
  int nNodos=conNodos(*inicio), i, costAnt=0, j, menor, nmen, bandera, k;
  char nAnt;
  tablaAu=(rtabla*)malloc(sizeof(rtabla)*nNodos);//Se crea tabla auxiliar.
  for(i=0;i<nNodos;i++){
    aux2=*inicio; /*Línea agregada por Daniela Ontiveros para el destino en direccionamiento*/
    tablaF=(rtabla*)malloc(sizeof(rtabla)*nNodos);//Se crea tabla final.
    iniciarTablas(tablaAu,tabla[i],nNodos,*inicio);//Se inicializa la tabla auxiliar.
    for(j=0;j<nNodos;j++){//Se inicializa la tabla final con valores nulos;
      tablaF[j].nodo=aux2->valor; /*Línea agregada por Daniela Ontiveros para el destino en direccionamiento*/
      tablaF[j].confirmado='N';
      tablaF[j].costo=-1;
      tablaF[j].sigSalto='\n';
      aux2=aux2->sig;/*Línea agregada por Daniela Ontiveros para el destino en direccionamiento*/
    }
    costAnt=0;//Se inicializa la variable en 0.
    nAnt=obtenervalor(*inicio, i);//Se obtiene el valor del nodo donde esta la tabla.
    while(Comprobado(tablaF,nNodos)){
      menor=MENOR;//Se inicia variable en valor.
      for(j=0;j<nNodos;j++){//Se recorre buscando si hay una mejor ruta que la que se planteo.
        if(tablaAu[j].costo!=-1){
          if((tablaF[j].costo>tablaAu[j].costo+costAnt||tablaF[j].costo==-1)&&tablaF[j].confirmado=='N'){
            tablaF[j].costo=tablaAu[j].costo+costAnt;
            tablaF[j].sigSalto=nAnt;
          }
        }
      }
      for(j=0;j<nNodos;j++){//Se recorre buscando el costo mas bajo.
        if(tablaF[j].costo<=menor&&tablaF[j].costo!=-1&&tablaF[j].confirmado=='N'){
          menor=tablaF[j].costo;
          nmen=j;
        }
      }
      tablaF[nmen].confirmado='S';//Se confirma el nodo de costo más bajo.
      iniciarTablas(tablaAu,tabla[nmen],nNodos,*inicio);//Se inicializa la tabla de nuevo
      costAnt=tablaF[nmen].costo;//Se aumenta el costo anterior
      nAnt=obtenervalor(*inicio,nmen);//Se obtiene el valor anterior
    }
    for(j=0;j<nNodos;j++){//Se comprueban las rutas de donde salieron
      while(tabla[i][obtenervalor2(*inicio,tablaF[j].sigSalto)]==-1){
        tablaF[j].sigSalto=tablaF[obtenervalor2(*inicio,tablaF[j].sigSalto)].sigSalto;
      }
    }
    for(j=0;j<nNodos;j++){
      if(tabla[i][obtenervalor2(*inicio,tablaF[j].sigSalto)]!=-1&&tablaF[j].sigSalto==obtenervalor(*inicio,i)){
        tablaF[j].sigSalto=obtenervalor(*inicio,j);
      }
    }
    aux->tablaR=tablaF;//Se le asigna a cada nodo su tabla Final
    aux=aux->sig;
  }
}//Fin tablasRuteo.

/*****************************************************
*                 FUNCIÓN COMPROBADO                 *
*                                                    *
* Esta función se encarga de comprobar que en esa    *
*tabla ya no existan valores que ya estan fijos.     *
*                                                    *
* La función se realizó el 7 de mayo del 2018.       *
*                                                    *
* Autores:Zurita Escobar Fernanda                    *
*****************************************************/
int Comprobado(rtabla tabla[], int nNodos){//Inicia función Comprobado.
  int i;//Declaración de variables.
  for(i=0;i<nNodos;i++){
    if(tabla[i].confirmado=='N')
      return 1;
  }
  return 0;
}//Fin función Comprobado.

/*****************************************************
*                FUNCIÓN OBTENERVALOR                *
*                                                    *
* Esta función se encarga de obtener el valor del    *
*nodo con respecto al valor de la tabla de adyacencia*
*                                                    *
* La función se realizó el 7 de mayo del 2018.       *
*                                                    *
* Autores:Zurita Escobar Fernanda                    *
*****************************************************/
char obtenervalor(nodo *nodoa, int hasta){
  int i;//Declaración de variables.
  nodo *aux=nodoa;
  for(i=0;i<hasta;i++){
    aux=aux->sig;
  }
  return aux->valor;
}//Fin Comprobado.

/*****************************************************
*               FUNCIÓN OBTENERVALOR2                *
*                                                    *
* Esta función se encarga de obtener el numero que   *
*corresponde al valor de la tabla de opciones.       *
*                                                    *
* La función se realizó el 7 de mayo del 2018.       *
*                                                    *
* Autores:Zurita Escobar Fernanda                    *
*****************************************************/
int obtenervalor2(nodo *nodoa, char hasta){//Inicia función obtenervalor2.
  int i=0;//Declaración de variables.
  nodo *aux=nodoa;
  while(aux->valor!=hasta){
    aux=aux->sig;
    i++;
  }
  return i;//Retorna el valor.
}//Fin función obtenervalor2.

/*****************************************************
*               FUNCIÓN INICIARTABLAS                *
*                                                    *
* Esta función se encarga de inicializar la tabla    *
*auxiliar, con el renglon de la tabla de adyacencia  *
*que le mandan.                                       *
*                                                    *
* La función se realizó el 7 de mayo del 2018.       *
*                                                    *
* Autores:Zurita Escobar Fernanda                    *
*****************************************************/
void iniciarTablas(rtabla tabla[], int tabla1[],int nNodos, nodo *inicio){//Inicia función iniciarTablas.
  int i;//Declaración de variables.
  for(i=0;i<nNodos;i++){
    tabla[i].confirmado='N';
    tabla[i].costo=tabla1[i];
    tabla[i].sigSalto=obtenervalor(inicio,i);
  }
}//Fin iniciarTablas.

/*****************************************************
*                  FUNCIÓN GUARDARR                  *
*                                                    *
* Esta función se encarga de guadar en el archivo    *
*llamado "TablasR.dat" las tablas de ruteo, que      *
*genera el programa*
*                                                    *
* La función se realizó el 7 de mayo del 2018.       *
*                                                    *
* Autores:Zurita Escobar Fernanda                    *
*****************************************************/
void guardarR(nodo *inicio){
    nodo *indice=inicio;//Inicialización de variables.
    int i, nNodos=conNodos(inicio),j;//Declaración de variables.
    FILE *fp;
    fp=fopen("TablasR.dat","wt");
    while(indice!=NULL){
        fprintf(fp,"----------Tablas de %c----------\n",indice->valor);
        for(j=0;j<nNodos;j++){
          fprintf(fp,"%d ",indice->tablaR[j].costo);
        }
        fprintf(fp,"\n");
        for(j=0;j<nNodos;j++){
          fprintf(fp,"%c ",indice->tablaR[j].sigSalto);
        }
        fprintf(fp,"\n");
        indice=indice->sig;
    }
    fclose(fp);
}//Fin Imprimir.
