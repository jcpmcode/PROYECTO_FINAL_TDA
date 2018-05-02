/****************************************************
*               MODULO DE TOPOLOGIA                 *
*                                                   *
* Materia:Taller de Desarrollo de Apliaciones.      *
*                                                   *
* Descripción: Este modulo se desarrolla la         *
*topología de la red, es decir, se construyen los   *
*nodos y las conexiones entre cada uno de los nodos *
*                                                   *
* El programa se realizó el 17 de abril del 2018.   *
*                                                   *
* Autor:Zurita Escobar Fernanda.                    *
****************************************************/
/*Bibliotecas que se utilizaran en el programa*/
#include<stdio.h>
#include<stdlib.h>
#include "topologia.h"
#include "tipos.h"

/*Funciones que componen el programa.*/
void GenerarEdificios(nodo **inicio);
void imprimir(nodo *inicio);

int main(void){//Inicia main.
  nodo *inicio=NULL;
  GenerarEdificios(&inicio);
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

/****************************************************
*                  FUNCIÓN IMPRIMIR                 *
* Esta función se encarga de imprimir los edificios *
*                                                   *
* La función se realizó el 17 de abril del 2018.    *
*                                                   *
* Autor:Zurita Escobar Fernanda.                    *
****************************************************/
void imprimir(nodo *inicio){//Inicia función imprimir.
    nodo *indice=inicio;//Apuntador.
    conexion *indice2;//Apuntador.
    while(indice!=NULL){//Se recorre la lista dinamica.
        printf("Edificio: %c\n",indice->valor);
        indice=indice->sig;
        printf("----------------------\n");
    }
}//Fin imprimir.
