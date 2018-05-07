/****************************************************
*                   TOPOLOGIA.H                     *
*                                                   *
* Materia:Taller de Desarrollo de Apliaciones.      *
*                                                   *
* Descripción: Contiene las estructuras que se      *
* utilizarán en el modulo de topología.h            *
*                                                   *
* El programa se realizó el 17 de abril del 2018.   *
*                                                   *
* Autores:Zurita Escobar Fernanda                   *
* José Carlos Paniagua Mendoza                      *
****************************************************/

/*Funciones que componen el programa.*/
void GenerarEdificios(nodo **inicio);
void GenerarTabla(int ***tablaA, nodo *inicio);
void GenerarConexiones(nodo **inicio, int **tabla);
int conNodos(nodo *inicio);
void imprimir(nodo *inicio);
