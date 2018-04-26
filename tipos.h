#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

//Definicion de la estructura que conformará a cada nodo de la lista que representará la topologia.
typedef struct edificio{
  char nombre;
  struct edificio *sig;
  struct edificio *ant;
  struct edificio *conexiones;
}EDIF;
