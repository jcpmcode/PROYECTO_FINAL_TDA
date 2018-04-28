#include "tipos.h"
#include "topologia.h"


void Llenar_matriz_adyacencia(int **mat)
{
  FILE *fp;
  char o, d;
  char line[255];
  int c, flag = 0, i, j;

  fp = fopen("topologia.txt", "rt");
  while(fgets(line, 255, fp) != NULL)//Se lee linea por linea dentro de un ciclo.
  {
    if (sscanf(line, "%c:%c:%d", &o, &d, &c) == 3)// Se obtienen el origen (o), destino (d) y el costo(c).
    {
      mat[o-65][d-65] = c; //Se alamcena el costo en la matriz de adyacencia.
    }
  }
  printf("matriz de adyacencia.\n");
  for (i=0; i<NEDIF; i++) // Despliegue de matriz.
  {
    for (j=0; j<NEDIF; j++)
    {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  fclose(fp);
}

void Llenar_lista(EDIF **inicio, EDIF **aux, int **mat)
{
  EDIF *nodo, *check;
  char o, d;
  int c, flag = 0, i=0, j;

  while(i<NEDIF)
  {
    flag = 0;
    nodo = malloc(sizeof(EDIF));
    if (nodo == NULL)
    {
      printf("No hay suficiente memoria.\n");
      exit(1);
    }
    nodo-> nombre= i+65; //Se guarda el nombre del nodo.
    if (*inicio == NULL) //En el caso de que sea el primer elemento de la lista.
    {
      *inicio = nodo; //El inicio de la lista ahora es el nuevo nodo.
    }
    else
    {
      (*aux)->sig=nodo; //El nodo anterior al nuevo ahora apunta al nuevo.
    }
    nodo->sig=NULL; //Sea cual sea el caso, el último nodo que apunta a siguiente debe apuntar a NULL.
    *aux=nodo; //Se usa el aux para saber cual fue el ultimo nodo que se agregó.
    nodo-> conexiones = NULL;
    for (j= 0; j<NEDIF; j++)
    {
      agrega_conexiones(nodo, mat, i, j);
    }
    i++;
  }
}

void despliega_lista(EDIF *inicio)
{
  EDIF *nodo;

  nodo = inicio; //Se iguala nodo a inicio para empezar a recorrer la lista desde ahí.
  if (nodo == NULL) //Se valida primero si la lista está vacía o no.
  {
    printf("No hay nada que desplegar.\n");
    return; //Se termina la función.
  }
  while(nodo != NULL) //Se recorre la lista hasta llegar al último nodo en ella.
  {
    printf("Nombre: %c\n", nodo->nombre);
    despliega_conexiones(nodo);
    nodo = nodo->sig; //Se pasa al siguiente nodo.
  }
}

void limpia_lista(EDIF *inicio)
{
  EDIF *nodo;

  nodo = inicio; //Se iguala nodo a inicio para empezar a recorrer la lista desde ahí.
  while(nodo != NULL) //Se recorre la lista hasta llegar al último nodo en ella.
  {
    limpia_conexiones(nodo->conexiones);
    inicio = inicio -> sig;
    free (nodo); //Se libera el espacio de memoria del nodo en el que se encuentra la función en ese momento.
    nodo = inicio;
  }
}

void agrega_conexiones(EDIF *principal, int **mat, int i, int j)
{
  CON *nodo, *aux;

  if (mat[i][j] != 0)
  {
    if (principal != NULL)//Se valida que el pointer principal no sea igual a NULL, indicando que la lista no está vacía.
    {
      nodo = malloc (sizeof (EDIF));//Se pide memoria para el nodo.
      if (nodo == NULL)//Se valida que exista memoria disponible.
      {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
      }
      nodo-> nombre = j+65;
      nodo->costo = mat[i][j];
      if(principal->conexiones == NULL)//Si es la primera vez que se agrega un dato.
      {
        principal->conexiones=nodo;//El inicio apunta al nodo nuevo.
        nodo->sig = NULL;//Se encadena apuntando a NULL.
      }
      else
      {
        aux= principal->conexiones;//Si no es la primera vez que se agrega una conexion, se utiliza un auxiliar para encadenamiento.
        while(aux->sig != NULL)//Se recorre la lista en busca del último elemento.
        {
          aux= aux->sig;//Se recorre el pointer.
        }
        aux->sig=nodo;//El auxiliar toma el valor del nodo actual.
        aux->sig->sig=NULL;//Se encadena al último a NULL.
      }
    }
  }
}

void limpia_conexiones(CON *principal)//Esta función libera el espacio de memoria de todas las conexiones una vez que se acaba el programa.
{
  CON *nodo, *aux;

  aux=principal;//Se inicializa el valor de nodo con el primer elemento de la lista.
  while(aux != NULL)//Se recorre la lista completa.
  {
    nodo=aux;//Se utiliza un auxiliar para poder liberar el espacio de nodo.
    aux= aux->sig;//Se recorre el apuntador al siguiente elemento de la lista.
    free(nodo);//Se libera el espacio de memoria de nodo.
  }
}

void despliega_conexiones(EDIF *principal)//Esta función las conexiones de cada nodo.
{
  CON *nodo;

  if (principal != NULL)//Si principal contiene algo, se ejecuta la función.
  {
    nodo= principal->conexiones;//Se inicializa el valor de nodo con el primer elemento de la lista.
    if (nodo == NULL)//Si no existe nada en la lista, se manda un mensaje indicándolo.
    {
      printf("\nNo hay conexiones.\n\n");
      return;//Se sale de la función.
    }
    printf("Conexiones:\n");//Se imprimen los datos.
    while (nodo != NULL)//Se recorre la lista imprimiendo cada nodo.
    {
      printf("\tNombre conexion: %c\n", nodo->nombre);
      printf("\tCosto: %d\n", nodo->costo);
      nodo= nodo->sig;//Se recorre el pointer de la lista.
    }
    printf("\n");
  }
}
