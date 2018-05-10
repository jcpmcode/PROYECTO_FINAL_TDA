/****************************************************
*                MODULO DE DIRECCIONAMIENTO         *
*                                                   *
* Materia:Taller de Desarrollo de Apliaciones.      *
*                                                   *
* La intensión de este módulo es llevar a cabo,     *
* con base en las tablas de ruteo, el direcciona-   *
* miento. Se busca la ruta más corta con base en    *
* el algoritmo de Dijkstra y se imprime en pantalla *
* mostrando por donde se pasó.                      *
* El programa se realizó el 8 de mayo del 2018.     *
*                                                   *
* Autor: Daniela Ontiveros Arroyo                   *
****************************************************/

#include "tipos.h"
#include "direccionamiento.h"
#include "topologia.h"

void caminoCorto(nodo *inicio) /*Envío nodo de inicio a camino*/
{
    nodo *indice=inicio; /*Índice toma valor inicio*/
    int i=0, j;
    char o, d;
    printf("Origen: ");
    scanf(" %c",&o);
    printf("Destino: ");
    scanf(" %c",&d);
    while ((indice != NULL) && (indice->valor != o)) { /*Mientras índice tenga un valor diferente del origen se va a recorrer el siguiente nodo*/
        indice = indice->sig;
    }
    if (indice == NULL) {
        printf("No se encontro el origen.\n"); //En caso de que origen no exista
        exit(1);
    }
    while (indice->tablaR[i].nodo!=d && i<conNodos(inicio)) {//Mientras en mi tabla de ruteo el valor sea diferente del valor de destino y mientras i sea menor al número de nodos aumenta el contador
        i++;
    }
    if (i == conNodos(inicio)) {
        printf("No se encontro el destino.\n");
        exit(1);
    }
    printf("Costo de %c a %c: %d\n", o, d, (indice->tablaR[i]).costo);//Costo de tabla de ruteo
    while(indice->valor != d){
        j = 0;
        printf("%c -> ", indice->valor);
        while (indice->tablaR[i].sigSalto != (indice->conexion[j])->valor) {
            j++;//El valor de los que va pasando es índice
        }
        indice = indice->conexion[j];
    }
    printf("%c\n", indice->valor);
}
