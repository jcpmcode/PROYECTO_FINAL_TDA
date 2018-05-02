/***************************************************
*               MODULO DE TOPOLOGIA                *
*                                                  *
* Materia:Taller de Desarrollo de Apliaciones.     *
*                                                  *
* Descripción: Este modulo se desarrolla la        *
*topología de la red, es decir, se construyen los  *
*nodos y las conexiones entre cada uno de los nodos*
*                                                  *
* El programa se realizó el 18 de abril del 2018.  *
*                                                  *
* Autor:Zurita Escobar Fernanda.                   *
***************************************************/
/*Bibliotecas que se utilizaran en el programa*/
#include<stdio.h>
#include<stdlib.h>
#include "topologia.h"
#include "tipos.h"

/*Funciones que componen el programa.*/
void GenerarEdificios(nodo **inicio);
void GenerarConexiones(nodo **inicio);
void GeneraConexion(conexion **indice2, int val, char val2);
void imprimir(nodo *inicio);

int main(void){//Inicia main.
  nodo *inicio=NULL;
  GenerarEdificios(&inicio);
  GenerarConexiones(&inicio);
  imprimir(inicio);
}//Final main.

/*****************************************************
*             FUNCIÓN GENERAREDIFICIOS               *
*                                                    *
* Esta función se encarga de generar una lista       *
*doblemente encadenada, la cual simula los edificios *
*de la escuela.                                      *
*                                                    *
* La función se realizó el 17 de abril del 2018.     *
*                                                    *
* Autor:Zurita Escobar Fernanda.                     *
*****************************************************/
void GenerarEdificios(nodo **inicio){//Inicia función GenerarEdificios.
  nodo *nuevo, *indice;//Declaración de variables.
  FILE *arch;
  char x, y;//Declaración de variables.
  int costo, bandera;//Declaración de variables.
  arch=fopen("ruta.dat","rt");//Se abre el archivo donde se encuentra la información.
  while(fscanf(arch,"%c:%c:%d\n",&x,&y,&costo)==3){
     indice=*inicio;
     nuevo=(nodo*)malloc(sizeof(nodo));//Se crea nuevo edificio.
     nuevo->valor=x;
     nuevo->abajo=NULL;
     if(*inicio==NULL){
        nuevo->sig=NULL;
        *inicio=nuevo;
     }
     else{//Se comprueba que el edificio no este creado.
        bandera=0;
        while(indice!=NULL){
            if(indice->valor==x)
                bandera=1;
            indice=indice->sig;
        }
        if(bandera==0){//Se inserta edificio sino esta creado.
            nuevo->sig=*inicio;
            *inicio=nuevo;
        }
     }
     indice=*inicio;
     nuevo=(nodo*)malloc(sizeof(nodo));//Se crea nuevo edificio.
     nuevo->valor=y;
     nuevo->abajo=NULL;
        bandera=0;
        while(indice!=NULL){//Se busca si el edificio ya esta creado.
            if(indice->valor==y)
                bandera=1;
            indice=indice->sig;
        }
        if(bandera==0){//Se inserta edificio sino esta creado.
            nuevo->sig=*inicio;
            *inicio=nuevo;
        }
  }
}//Fin GenerarEdificios.

/*****************************************************
*             FUNCIÓN GENERARCONEXIONES              *
*                                                    *
* Esta función se encarga de buscar en el archivo    *
*las conexiones que tiene cada uno de los edificos   *
*y obtener los parametros como el costo.             *
*                                                    *
* La función se realizó el 18 de abril del 2018.     *
*                                                    *
* Autor:Zurita Escobar Fernanda.                     *
*****************************************************/
void GenerarConexiones(nodo **inicio){//Inicia función GenerarConexiones.
  nodo *indice;
  FILE *arch;
  char x, y, auxl;
  int costo, bandera;
  arch=fopen("ruta.dat","rt");
  while(fscanf(arch,"%c:%c:%d\n",&x,&y,&costo)==3){//Recorre el archivo hasta el final.
    indice=*inicio;
    while(indice!=NULL){//Busca si el valor ya esta insertado.
        if(indice->valor==x){
            GeneraConexion(&(indice->abajo),costo, y);//Manda a llamar la función GeneraConexion
        }
        indice=indice->sig;
    }
    indice=*inicio;
    while(indice!=NULL){//Busca si el valor ya esta insertado.
        if(indice->valor==y){
            GeneraConexion(&(indice->abajo),costo, x);//Manda a llamar la función GeneraConexion
        }
        indice=indice->sig;
    }
  }
}//Fin GenerarConexiones.

/*****************************************************
*                 FUNCIÓN GENERACONEXION             *
*                                                    *
* Esta función genera la lista de conexiones dentro  *
*de cada uno de los edificios.                       *
*                                                    *
* La función se realizó el 18 de abril del 2018.     *
*                                                    *
* Autor:Zurita Escobar Fernanda.                     *
*****************************************************/
void GeneraConexion(conexion **indice2, int val, char val2){//Inicia función GenearConexion.
    conexion *nuevo, *aux;
    int bandera;
    nuevo=(conexion*)malloc(sizeof(conexion));//Genera nueva conexión
    nuevo->costo=val;
    nuevo->destino=val2;
    if(*indice2==NULL){
        nuevo->sig=NULL;
        *indice2=nuevo;
    }
    else{//Recorrepara buscar si la conexión ya esta insertada.
        bandera=0;
        aux=*indice2;
        while(aux!=NULL){
            if(aux->destino==val2)
                bandera=1;
            aux=aux->sig;
        }
        if(bandera==0){//Inserta si la conexión no existe.
            nuevo->sig=*indice2;
            *indice2=nuevo;
        }
    }
}//Inicia función GenearConexion.

/****************************************************
*                  FUNCIÓN IMPRIMIR                 *
* Esta función se encarga de imprimir los edificios *
*y conexiones .                                     *
*                                                   *
* La función se realizó el 18 de abril del 2018.    *
*                                                   *
* Autor:Zurita Escobar Fernanda.                    *
****************************************************/
void imprimir(nodo *inicio){//Inicia función imprimir.
    nodo *indice=inicio;
    conexion *indice2;
    while(indice!=NULL){//recorre la lista de edificios.
        printf("Edificio: %c\n",indice->valor);
        indice2=indice->abajo;
        indice=indice->sig;
        while(indice2!=NULL){//recorre la lista conexiones de cada edificio.
            printf("Conexion: %c\tCosto: %d\n",indice2->destino,indice2->costo);
            indice2=indice2->sig;
        }
        printf("----------------------\n");
    }
}//Fin imprimir.
