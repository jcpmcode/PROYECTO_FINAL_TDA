/****************************************************
*                     RUTEO.H                       *
*                                                   *
* Materia:Taller de Desarrollo de Apliaciones.      *
*                                                   *
* Descripción: Contiene las funciones que se        *
* utilizarán en el modulo de ruteo.h                *
*                                                   *
* El programa se realizó el 7 de mayo del 2018.     *
*                                                   *
* Autor:Zurita Escobar Fernanda                     *
****************************************************/

/*Funciones que componen el programa.*/
void tablasRuteo(nodo **inicio, int **tablaA);
int conNodos(nodo *inicio);
int Comprobado(rtabla tabla[], int nNodos);
char obtenervalor(nodo *nodoa, int hasta);
int obtenervalor2(nodo *nodoa, char hasta);
void guardarR(nodo *inicio);
void iniciarTablas(rtabla tabla[], int tabla1[],int nNodos, nodo *inicio);
