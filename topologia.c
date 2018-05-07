/****************************************************
*               MODULO DE TOPOLOGIA                 *
*                                                   *
* Materia:Taller de Desarrollo de Apliaciones.      *
*                                                   *
* Descripción: Este modulo se desarrolla la         *
*topología de la red, es decir, se construyen los   *
*nodos y las conexiones entre cada uno de los nodos *
*                                                   *
* El programa se realizó el 23 de abril del 2018.   *
*                                                   *
* Autores:Zurita Escobar Fernanda                   *
* José Carlos Paniagua Mendoza                      *
****************************************************/
/*Bibliotecas que se utilizaran en el programa*/

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

#include<stdio.h>
#include<stdlib.h>

/*Funciones que componen el programa.*/
void GenerarEdificios(nodo **inicio);
void GenerarTabla(int ***tablaA, nodo *inicio);
void GenerarConexiones(nodo **inicio, int **tabla);
int conNodos(nodo *inicio);
void imprimir(nodo *inicio);

int main(void){//Inicia main.
  int **tabla;
  nodo *inicio=NULL;
  GenerarEdificios(&inicio);
  GenerarTabla(&tabla,inicio);
  GenerarConexiones(&inicio,tabla);
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
  char x, y;
  int costo, bandera;
  arch=fopen("ruta.dat","rt");//Se abre el archivo donde se encuentra la información.
  while(fscanf(arch,"%c:%c:%d\n",&x,&y,&costo)==3){
     indice=*inicio;
     nuevo=(nodo*)malloc(sizeof(nodo));//Se crea nuevo edificio.
     nuevo->valor=x;
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
}

/*****************************************************
*               FUNCIÓN GENERARTABLA                 *
*                                                    *
* Esta función se encarga de generar la tabla de     *
*adyacencias.                                        *
*                                                    *
* La función se realizó el 20 de abril del 2018.     *
*                                                    *
* Autor:Zurita Escobar Fernanda.                     *
*****************************************************/
void GenerarTabla(int ***tablaA, nodo *inicio){//Inicia función GenerarTabla.
  nodo *aux1=inicio, *aux2=inicio;
  int i,j,c;
  char a,b,indice,buscar;
  FILE *arch;
  *tablaA = (int **)malloc(sizeof(int *)*conNodos(inicio));
  for (i=0; i < conNodos(inicio); i++) // Se genera arreglo bidimensional dinamicamente.
  {
      (*tablaA)[i] = (int *) malloc (sizeof(int)*conNodos(inicio));
  }
  for(i=0;i<conNodos(inicio);i++)
    for(j=0;j<conNodos(inicio);j++){//Se inicializa la tabla de adyacencias.
      if(i==j)
        (*tablaA)[i][j]=0;//Se pone 0 porque es una conexión consigo mismo.
      else
        (*tablaA)[i][j]=-1;//Se pone 1 porque no se conoce el costo.
      }
  i=0;
  j=0;
  while(aux1!=NULL){
    indice=aux1->valor;
    arch=fopen("ruta.dat","rt");
    while(fscanf(arch,"%c:%c:%d\n",&a,&b,&c)==3){//Se recorre el archivo.
      j=0;
      aux2=inicio;
      if(indice==a||indice==b){
        if(a==indice)
          buscar=b;
        else
          buscar=a;
        while(aux2!=NULL && aux2->valor!=buscar){
          j++;
          aux2=aux2->sig;
        }
        (*tablaA)[i][j]=c;
      }
    }
    aux1=aux1->sig;
    i++;
    fclose(arch);
  }
  for(i=0;i<conNodos(inicio);i++){//Se imprime la tabla de adyacencias.
    for(j=0;j<conNodos(inicio);j++)
      printf("%3d ",(*tablaA)[i][j]);
      printf("\n");
  }
}//Fin GenerarTabla.

/*****************************************************
*            FUNCIÓN GENERARCONEXIONES               *
*                                                    *
* Esta función se encarga de generar un arreglo      *
*dinamico de apuntadores para las conexiones.        *
*                                                    *
* La función se realizó el 23 de abril del 2018.     *
*                                                    *
* Autor:Zurita Escobar Fernanda.                     *
*****************************************************/
void GenerarConexiones(nodo **inicio, int **tablaA){//Inicia función GenerarConexiones.
  int nNodos=conNodos(*inicio),i=0,j=0, num=0, l;
  nodo *aux1=*inicio, *aux2=*inicio;
  while(aux1!=NULL){
    num=0;
    for(j=0;j<nNodos;j++){
      if(tablaA[i][j]!=-1 && tablaA[i][j]!=0)//Cuenta el numero de conexiones.
        num++;
    }
    aux1->nCon=num;
    aux1->conexion=(nodo**)malloc(sizeof(nodo*)*num);//Genera el arreglo dinamico.
    l=0;
    for(j=0;j<nNodos;j++){
      aux2=*inicio;
      if(tablaA[i][j]!=-1 && tablaA[i][j]!=0){
        num=0;
        while(j!=num){//Busca el apuntador donde debe generar la conexión.
          num++;
          aux2=aux2->sig;
        }
        aux1->conexion[l]=aux2;//Genera una conexión.
        l++;
      }
    }
    i++;
    aux1=aux1->sig;
  }
}//Fin GenerarConexiones.

/*****************************************************
*                   FUNCIÓN CONNODOS                 *
*                                                    *
* Esta función se encarga de contar el numero de     *
*nodos en la lista.                                  *
*                                                    *
* La función se realizó el 20 de abril del 2018.     *
*                                                    *
* Autor:Zurita Escobar Fernanda.                     *
*****************************************************/
int conNodos(nodo *inicio){//Inicia función conNodos.
    nodo *aux=inicio;
    int sum=0;
    while(aux!=NULL){
        sum=sum+1;
        aux=aux->sig;
    }
    return sum;
}//Fin conNodos.

/*****************************************************
*                   FUNCIÓN IMPRIMIR                 *
*                                                    *
* Esta función se encarga de imprimir la topologia.  *
*                                                    *
* La función se realizó el 20 de abril del 2018.     *
*                                                    *
* Autor:Zurita Escobar Fernanda.                     *
*****************************************************/
void imprimir(nodo *inicio){//Inicia función imprimir.
    nodo *indice=inicio;
    int i;
    while(indice!=NULL){
        printf("Edificio: %c\n",indice->valor);//Imprime el edficio.
        printf("Numero de conexiones: %d\n",indice->nCon);//Imprime el numero de conexiones.
        for(i=0;i<indice->nCon;i++){//Recorre el arreglo de pointers.
          printf("\t%c\n",indice->conexion[i]->valor);//Imprime el valor de la conexión.
        }
        indice=indice->sig;
        printf("----------------------\n");
    }
}//Fin imprimir.
