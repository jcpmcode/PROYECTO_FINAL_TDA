#include "tipos.h"
#include "direccionamiento.h"
#include "topologia.h"
#include "ruteo.h"

int main(void)
{
  EDIF *inicio, *aux;
  inicio = NULL;

  Llenar_lista(&inicio, &aux);
  despliega_nodos(inicio);
  limpia_nodos(inicio);
  return 0;
}
