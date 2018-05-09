#include "tipos.h"
#include "direccionamiento.h"
#include "topologia.h"

void caminoCorto(nodo *inicio)
{
    nodo *indice=inicio;
    int i=0, j;
    char o, d;
    printf("Origen: ");
    scanf(" %c",&o);
    printf("Destino: ");
    scanf(" %c",&d);
    while ((indice != NULL) && (indice->valor != o)) {
        indice = indice->sig;
    }
    if (indice == NULL) {
        printf("No se encontro el origen.\n");
        exit(1);
    }
    while (indice->tablaR[i].nodo!=d && i<conNodos(inicio)) {
        i++;
    }
    if (i == conNodos(inicio)) {
        printf("No se encontro el destino.\n");
        exit(1);
    }
    printf("Costo de %c a %c: %d\n", o, d, (indice->tablaR[i]).costo);
    while(indice->valor != d){
        j = 0;
        printf("%c -> ", indice->valor);
        while (indice->tablaR[i].sigSalto != (indice->conexion[j])->valor) {
            j++;
        }
        indice = indice->conexion[j];
    }
    printf("%c\n", indice->valor);
}
