//
//  topologia.c
//
//  matriz dinámica
//
//
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct texto_topologia{
    char o, d;
    int c;
    struct texto_topologia *sig;
}VAL;

typedef struct destino{
    char nombre;
    int costo;
    struct edificio *des;
    struct destino *sig;
}CON;

typedef struct edificio{
    char nombre;
    struct edificio *sig;
    CON *conexiones;
}EDIF;

int llenar_matriz_adyacencia(int ***mat);
void leer_topologia(VAL **inicio, char str[60]);
void limpia_topologia(VAL **inicio);
void llenar_lista(EDIF **inicio, int **mat, int v);
void despliega_lista(EDIF *inicio);
void limpia_lista(EDIF **inicio);
void agrega_conexiones(EDIF **inicio, CON **inicio2, int **mat, int i, int j);
void limpia_conexiones(CON **inicio);
void despliega_conexiones(CON *inicio);

int main(void)
{
    int **mat;
    int v;
    EDIF *inicio = NULL;

    v = llenar_matriz_adyacencia(&mat);
    llenar_lista(&inicio, mat, v);
    despliega_lista(inicio);
    limpia_lista(&inicio);
}

int llenar_matriz_adyacencia(int ***mat)
{
    VAL *inicio, *aux;
    char c[60];
    int i, j, v;
    inicio = NULL;

    leer_topologia(&inicio, c);
    v = strlen(c);
    *mat = (int **) calloc (v, sizeof(int *));
    for (i = 0; i < v; i++) {
        (*mat)[i] = (int *) calloc (v, sizeof(int));
    }
    aux = inicio;
    while (aux != NULL) {
        (*mat)[(aux->o)-65][(aux->d)-65] = aux->c;
        (*mat)[(aux->d)-65][(aux->o)-65] = aux->c;
        aux = aux->sig;
    }
    limpia_topologia(&inicio);
    printf("Matriz de adyacencia.\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            printf("%d ", (*mat)[i][j]);
        }
        printf("\n");
    }
    return v;
}

void leer_topologia(VAL **inicio, char str[60])
{
    FILE *fp;
    VAL *nodo, *aux;
    char o, d;
    int c, i;
    char line[260];

    i = 0;
    fp = fopen("topologia.txt", "rt");
    if (fp != NULL) {
        while (fgets(line, 255, fp) != NULL) {
            if (sscanf(line, "%c:%c:%d", &o, &d, &c) == 3) {
                nodo = malloc(sizeof(VAL));
                if (nodo == NULL) {
                    printf("No hay suficiente memoria.\n");
                    limpia_topologia(inicio);
                    exit(2);
                }
                nodo->o = o;
                nodo->d = d;
                nodo->c = c;
                nodo->sig = NULL;
                if(*inicio == NULL) {
                    *inicio = nodo;
                } else {
                    aux->sig = nodo;
                }
                aux = nodo;
            }
        }
        fclose(fp);
        for (c = 0; c < 60; c++) {
            str[c] = '\0';
        }
        aux = *inicio;
        while (aux != NULL) {
            i = 0;
            for (c = 0; str[c] != '\0'; c++) {
                if (str[c] == aux->o) {
                    i = 1;
                }
            }
            if (i == 0) {
                str[c] = aux->o;
            }
            i = 0;
            for (c = 0; str[c] != '\0'; c++) {
                if (str[c] == aux->d) {
                    i = 1;
                }
            }
            if (i == 0) {
                str[c] = aux->d;
            }
            aux = aux->sig;
        }
    } else {
        printf("No existe topologia.\n");
        exit(1);
    }
}

void limpia_topologia(VAL **inicio)
{
    VAL *nodo;

    if (*inicio != NULL) {
        nodo = *inicio;
        while (nodo != NULL) {
            *inicio = nodo->sig;
            free(nodo);
            nodo = *inicio;
        }
    }
}

void llenar_lista(EDIF **inicio, int **mat, int v)
{
    EDIF *nodo, *aux;
    int i, j;

    for (i = 0; i < v; i++) {
        nodo = malloc(sizeof(EDIF));
        if (nodo == NULL) {
            printf("No hay suficiente memoria.\n");
            exit(2);
        }
        nodo->nombre = i+65;
        nodo->sig = NULL;
        nodo->conexiones = NULL;
        if (*inicio == NULL) {
            *inicio = nodo;
        } else {
            aux = *inicio;
            while (aux->sig != NULL) {
                aux = aux->sig;
            }
            aux->sig = nodo;
        }
    }
    i = 0;
    for (aux = *inicio; aux != NULL; aux = aux->sig) {
        for (j = 0; j < v; j++) {
            agrega_conexiones(inicio, &(aux->conexiones), mat, i, j);
        }
        i++;
    }
}

void despliega_lista(EDIF *inicio)
{
    EDIF *nodo;

    if (inicio != NULL) {
        nodo = inicio;
        while (nodo != NULL) {
            printf("Nombre: %c\n", nodo->nombre);
            despliega_conexiones(nodo->conexiones);
            nodo = nodo->sig;
        }
    } else {
        printf("No hay nada que desplegar.\n");
    }
}

void limpia_lista(EDIF **inicio)
{
    EDIF *nodo;

    if (*inicio != NULL) {
        nodo = *inicio;
        while (nodo != NULL) {
            *inicio = nodo->sig;
            limpia_conexiones(&(nodo->conexiones));
            free(nodo);
            nodo = *inicio;
        }
    }
}

void agrega_conexiones(EDIF **inicio1, CON **inicio, int **mat, int i, int j)
{
    EDIF *aux1;
    CON *nodo, *aux;

    if (mat[i][j] != 0) {
        nodo = malloc(sizeof(CON));
        if (nodo == NULL) {
            printf("No hay suficiente memoria.\n");
            limpia_conexiones(inicio);
            exit(2);
        }
        aux1 = *inicio1;
        while (aux1->nombre != j+65) {
            aux1 = aux1->sig;
        }
        nodo->des = aux1;
        nodo->costo = mat[i][j];
        nodo->sig = NULL;
        if (*inicio == NULL) {
            *inicio = nodo;
        } else {
            aux = *inicio;
            while (aux->sig != NULL) {
                aux = aux->sig;
            }
            aux->sig = nodo;
        }
    }
}

void limpia_conexiones(CON **inicio)
{
    CON *nodo;

    if (*inicio != NULL) {
        nodo = *inicio;
        while (nodo != NULL) {
            *inicio = nodo->sig;
            free(nodo);
            nodo = *inicio;
        }
    }
}

void despliega_conexiones(CON *inicio)
{
    CON *nodo;

    if (inicio != NULL) {
        nodo = inicio;
        while (nodo != NULL) {
            printf("\tNombre conexion: %c\n", nodo->des->nombre);
            printf("\tCosto: %d\n", nodo->costo);
            nodo = nodo->sig;
        }
        printf("\n");
    } else {
        printf("\nNo hay conexiones\n\n");
    }
}
