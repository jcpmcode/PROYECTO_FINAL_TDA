#include "tipos.h"
#include "direccionamiento.h"
#include "topologia.h"
#include "ruteo.h"

int main(void)
{
  int **mat;
  int i, j;
  EDIF *inicio, *aux;
  inicio = NULL;

  mat = (int **) calloc (NEDIF, sizeof(int *)); // Se reserva una matriz dinamica.
  for (i=0; i<NEDIF; i++) // Se reserva renglon por renglon dinamicamente.
  {
    mat[i] = (int *) calloc (NEDIF, sizeof(int));
  }

  Llenar_matriz_adyacencia(mat);
  Llenar_lista(&inicio, &aux, mat);
  despliega_lista(inicio);
  limpia_lista(inicio);
}
