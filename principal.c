/****************************************************
*         PROGRAMA DE PRESENTACIÓN Y MENÚ           *
*                                                   *
* Materia:Taller de Desarrollo de Apliaciones.      *
*                                                   *
* Descripción: Este modulo es la presentación de    *
*los desarrolladores y menú, se mencionarán las     *
*opciones que puede solicitar el usuario.           *
*                                                   *
* El programa se realizó el 9 de mayo del 2018.     *
* Autores: Daniela Ontiveros Arroyo                 *
*Zurita Escobar Fernanda                            *
* José Carlos Paniagua Mendoza                      *
****************************************************/

/*Bibliotecas que se utilizan para este programa*/
#include "tipos.h"
#include "direccionamiento.h"
#include "topologia.h"
#include "ruteo.h"

/*Funciones del programa.*/
void Presentacion();
void Menu();
void Ayuda();

int main(void)//Comienza main.
{
  //int **tabla;
  //nodo *inicio= NULL;

  //GenerarEdificios(&inicio); // Menu en Topologia
  //GenerarTabla(&tabla,inicio); // Menu en Topologia
  //GenerarConexiones(&inicio,tabla); // Menu en Topologia
  //imprimir(inicio); // Menu en Topologia
  //tablasRuteo(&inicio, tabla); // Menu en Ruteo
  //guardarR(inicio); // Menu en Ruteo
  //caminoCorto(inicio); // Menu en Direccionamiento
  Presentacion();
  Menu();
}//Fin main.

/****************************************************
*               FUNCIÓN PRESENTACIÓN                *
* Esta función se encarga de imprimir mensajes en   *
*pantalla de los desarrolladores.                   *
*                                                   *
* La función se realizó el 17 de abril del 2018.    *
*                                                   *
* Autores:Zurita Escobar Fernanda                   *
* Daniela Ontiveros Arroyo                          *
* José Carlos Paniagua Mendoza                      *
****************************************************/
void Presentacion(){
  char Enter;
  printf("\n    ¡BIENVENIDO A LA APLICACIÓN ...!");
  printf("\n Esta aplicación mostrará cual es el camino más eficiente");
  printf("\n para llegar de un destino a otro en la Universidad Iberoamericana");
  printf("\nIntegrantes:");
  printf("\n--------------------------------");
  printf("\n  Ontiveros Arroyo Daniela.");
  printf("\n  Paniagua Mendoza José Carlos.");
  printf("\n  Zurita Escobar Fernanda.");
  printf("\n---------------------------------\n\n");
  printf("                 Presiona enter...");
  while((Enter=getchar()) != '\n');//Presionar enter para limpiar pantalla.
  system("clear");
}

/****************************************************
*                   FUNCIÓN MENÚ                    *
* Esta función trata de seleccionar una de las      *                             *
*  cuatro opciones (ayuda, generar topología,       *
*  tablas de ruteo, direccionamiento y salir        *
* La función se realizó el 9 de mayo del 2018.    *
*                                                   *
* Autores:Ontiveros Arroyo Daniela                  *
****************************************************/
void Menu(){
  int opcion, v;//Variable entero para seleccionar número.
  int **tabla;
  nodo *inicio= NULL;
  do {
    printf(" _______________________________\n");
    printf("|_____________MENU______________|\n");
    printf("| 0. Ayuda                      |\n");
    printf("| 1. Generar topologia          |\n");
    printf("| 2. Tablas de Ruteo            |\n");
    printf("| 3. Direccionamiento           |\n");
    printf("| 4. Salir                      |\n");
    printf("|_______________________________|\n");
    do {
      printf("Opción seleccionada -> ");
      v = scanf("%d",&opcion);
      if (v != 1) /*Validación para evitar que entre letras o caracteres*/
        printf("Favor de escribir el número de la opción deseada.\n\n");
      while (getchar() != '\n');
    } while (v != 1);
    switch (opcion) {
      case 0:
        Ayuda();
        break;
      case 1:
        GenerarEdificios(&inicio);
        GenerarTabla(&tabla,inicio);
        GenerarConexiones(&inicio,tabla);
        imprimir(inicio);
        break;
      case 2:
        tablasRuteo(&inicio, tabla);
        guardarR(inicio);
        break;
      case 3:
        caminoCorto(inicio);
        while (getchar() != '\n');
        break;
      case 4:
        printf("Adiós.\n");
        break;
      default:
        printf("Opción no válida.\n");
        break;
    }
    if (opcion != 4) {
      printf("    Presiona enter...");
      while (getchar() != '\n');
    }
  } while (opcion != 4);
}
/*Se describe la ayuda que puede necesitar el usuario*/
void Ayuda()
{
    printf("\n\nLa Universidad Iberoamericana cuenta con \n");
    printf("20 edificios, y el nombre de cada uno de ellos \n");
    printf("corresponde a una letra (sin virgulilla). \n");
    printf("Para conocer la forma más eficiente de desplazarse,\n");
    printf("sólo debe ingresar el origen y el destino cuando\n");
    printf("se lo pidan. \n");
}
