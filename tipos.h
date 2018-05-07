/****************************************************
*                   TOPOLOGIA.H                     *
*                                                   *
* Materia:Taller de Desarrollo de Apliaciones.      *
*                                                   *
* Descripción: Contiene las estructuras que se      *
* utilizarán en el modulo de topología.h            *
*                                                   *
* El programa se realizó el 17 de abril del 2018.   *
*                                                   *          *
* José Carlos Paniagua Mendoza                      *
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

struct tablas{
  char nodo, confirmado, sigSalto;
  int costo;
};typedef struct tablas rtabla;

struct nodos{
  char valor;
  int nCon;
  struct nodos *sig;
  struct tablas *tablaR;
  struct nodos **conexion;
};typedef struct nodos nodo;
