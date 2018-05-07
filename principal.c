/****************************************************
*         PROGRAMA DE PRESENTACIÓN Y MENÚ           *
*                                                   *
* Materia:Taller de Desarrollo de Apliaciones.      *
*                                                    *
* Descripción: Este modulo es la presentación de    *
*los desarrolladores y menú, se mencionarán las     *
*opciones que puede solicitar el usuario.           *
*                                                   *
* El programa se realizó el 17 de abril del 2018.   *
* Autores:Zurita Escobar Fernanda                   *
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

int main(void)//Comienza main.
{
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
* José Carlos Paniagua Mendoza                      *
****************************************************/
void Presentacion(){
  char Enter;
  printf("\n    ¡BIENVENIDO A LA APLICACIÓN ...!");
  printf("\n Esta aplicación mostrará cual es el camino más eficiente");
  printf("\n para llegar de un destino a otro en la Universidad Iberoamericana");
  printf("\n pero si lo desea también le mostrará la ruta más larga.\n\n");
  printf("\nIntegrantes:");
  printf("\n--------------------------------");
  printf("\n  Ontiveros Arroyo Daniela.");
  printf("\n  Paniagua Mendoza José Carlos.");
  printf("\n  Zurita Escobar Fernanda.");
  printf("\n---------------------------------\n\n");
  printf("                 Presione enter...");
  while((Enter=getchar()) != '\n');//Presionar enter para limpiar pantalla.
  system("clear");
}

/****************************************************
*                   FUNCIÓN MENÚ                    *
* Esta función se encarga de imprimir mensajes en   *
*la pantalla de lo opciones que el usuario puede.   *
*seleccionar.                                       *
*                                                   *
* La función se realizó el 17 de abril del 2018.    *
*                                                   *
* Autores:Zurita Escobar Fernanda                   *
* José Carlos Paniagua Mendoza                      *
****************************************************/
void Menu(){
  int opcion;//Variable entero para seleccionar número.
  char origen, destino;//Variable char para origen(De donde esta) y destino(A donde quiere ir)
    printf(" _______________________________\n");
    printf("|_____________MENU______________|\n");
    printf("| 1. Mostrar la ruta más corta. |\n");
    printf("| 2. Mostrar la ruta más larga. |\n");
    printf("| 3. Salir.                     |\n");
    printf("|_______________________________|\n");
    printf("Opción seleccionada -> ");
    scanf("%d",&opcion);
    switch (opcion)
    {
      case 1:
        printf("\nIngrese lugar de origen: ");
        scanf("%s",&origen);
        printf("\nIngrese lugar de destino: ");
        scanf("%s",&destino);
        printf("\nCalculando ruta...\n");
        break;

        case 2:
        printf("\nIngrese lugar de origen: ");
        scanf("%s",&origen);
        printf("\nIngrese lugar de destino: ");
        scanf("%s",&destino);
        printf("\nCalculando ruta...\n");
        break;

        case 3:
        printf("\nHasta la proxima.\n");
        break;
      }
}
