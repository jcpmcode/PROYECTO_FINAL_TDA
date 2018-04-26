#include "tipos.h"
#include "topologia.h"

void Llenar_lista(EDIF **inicio, EDIF **aux)
{
  EDIF *nodo, *check;
  FILE *fp;
  char o, d;
  char line[255];
  int c, flag = 0;

  fp = fopen("topologia.txt", "rt");
  while(fgets(line, 255, fp) != NULL)//Se lee linea por linea dentro de un ciclo.
  {
    if (sscanf(line, "%c:%c:%d", &o, &d, &c) == 3)
    {
      flag = 0;
      check= nodo;
      while (check != NULL && flag == 0)
      {
        if (check-> nombre == o)
        {
          flag= 1;
          break;
        }
        check = check-> ant;
      }
      if (flag == 1)
      {
        // agregar_conexion(check, d);
        // despliega_conexiones(check);
        // limpia_conexiones(check);
      }
      else
      {
        nodo = malloc(sizeof(EDIF));
        if (nodo == NULL)
        {
          printf("No hay suficiente memoria.\n");
          exit(1);
        }
        nodo-> nombre= o;
        if (*inicio == NULL) //En el caso de que sea el primer elemento de la lista...
        {
          nodo->ant = NULL; //Su apuntador anterior apunta a NULL.
          *inicio = nodo; //El inicio de la lista ahora es el nuevo nodo.
        }
        else
        {
          nodo->ant= *aux; //El nodo nuevo que apunta a anterior apunta al último nodo que se había agregado.
          (*aux)->sig=nodo; //El nodo anterior al nuevo ahora apunta al nuevo.
        }
        nodo->sig=NULL; //Sea cual sea el caso, el último nodo que apunta a siguiente debe apuntar a NULL.
        *aux=nodo; //Se usa el aux para saber cual fue el ultimo nodo que se agregó.
        nodo-> conexiones = NULL;
      }
    }
  }
  fclose(fp);
}

void despliega_nodos(EDIF *inicio)
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
    nodo = nodo->sig; //Se pasa al siguiente nodo.
  }
}

void limpia_nodos(EDIF *inicio)
{
  EDIF *nodo;

  nodo = inicio; //Se iguala nodo a inicio para empezar a recorrer la lista desde ahí.
  while(nodo != NULL) //Se recorre la lista hasta llegar al último nodo en ella.
  {
    inicio = inicio -> sig;
    free (nodo); //Se libera el espacio de memoria del nodo en el que se encuentra la función en ese momento.
    nodo = inicio;
  }
}

void agregar_conexion(EDIF *principal, char d)
{
  EDIF *nodo, *aux;

  if (principal != NULL)//Se valida que el pointer principal no sea igual a NULL, indicando que la lista no está vacía.
  {
    nodo = malloc (sizeof (EDIF));//Se pide memoria para el nodo.
    if (nodo == NULL)//Se valida que exista memoria disponible.
    {
      printf("\nNo hay memoria disponible.\n");
      exit(1);
    }
    nodo-> nombre = d;
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

void limpia_conexiones(EDIF *principal)
{
  EDIF *nodo, *aux;

  aux=principal;//Se inicializa el valor de nodo con el primer elemento de la lista.
  while(aux != NULL)//Se recorre la lista completa.
  {
    nodo=aux;//Se utiliza un auxiliar para poder liberar el espacio de nodo.
    aux= aux->sig;//Se recorre el apuntador al siguiente elemento de la lista.
    free(nodo);//Se libera el espacio de memoria de nodo.
  }
}

void despliega_conexiones(EDIF *principal)
{
  EDIF *nodo;

  if (principal != NULL)//Si el principal contiene algo, se realiza la función.
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
      nodo= nodo->sig;//Se recorre el pointer de la lista.
    }
    printf("\n");
  }
}
