#define NEDIF 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

//Definicion de la estructura que conformará a cada nodo de la lista que representará la topologia.
typedef struct edificio{
  char nombre;
  struct edificio *sig;
  struct conexiones_edificio *conexiones;
}EDIF;

//Definición de la estructura que conformarán los nodos de la sublista en donde se almacenaran las conexiones.
typedef struct conexiones_edificio{
  char nombre;
  int costo;
  struct conexiones_edificio *sig;
}CON;
