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
struct nodos{
  char valor;
  struct nodos *sig;
  struct conexiones *abajo;
  struct tablas *tablaR;
};//Estructura nodos.

struct conexiones{
  int costo;
  char destino;
  struct conexiones *sig;
};//Estructura conexiones.
typedef struct nodos nodo;
typedef struct conexiones conexion;
