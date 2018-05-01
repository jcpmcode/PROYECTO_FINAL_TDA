/****************************************************
*                     TIPOS.H                       *
*                                                   *
* Materia: Taller de Desarrollo de Aplicaciones.      *
*                                                   *
* Descripción: Este modulo contendrá las            *
*estructuras que utilizará el programa para un      *
*correcto funcionamiento.                           *
*                                                   *
* El programa se realizó el 17 de abril del 2018.   *
*                                                   *
* Autor: Zurita Escobar Fernanda.                    *
****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

struct tablas{
    char nodo, confirmado, sigSalto;
    int costo;
};//Estructura tablas.

struct nodos{
  char valor;
  int nCon;
  struct nodos *sig;
  struct tablas *tablaR;
  struct nodos **conexion;
};//Estructura nodos.
