/*
 ============================================================================
 Name        : Clase_09.c
 Author      : Leandro Sobrino
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"

#define CANT_ALUMNOS 10
#define OPTIONS 6

int main(void)
{
	setbuf(stdout,NULL);
	Alumno arrayAlumnos[CANT_ALUMNOS];
	int opcion;
	int indice;

	alumno_init(arrayAlumnos, CANT_ALUMNOS);
	do
	{
		utn_getNumeroInt(&opcion, "***Menu de opciones***\n\n"
								  "1- Ingrese un alumno.\n"
								  "2- Modificar un alumno.\n"
								  "3- Borrar alumno.\n"
								  "4- Imprimir listado de alumnos.\n"
								  "5- Ordenar listado por nombre.\n"
								  "6- Salir.\n\n"
								  "Ingrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTIONS, 2);
		switch (opcion)
		{
			case 1:
				if( utn_getNumeroInt(&indice, "Ingrese la posicion (0 - 9): ", "Error.\n", 0, CANT_ALUMNOS, 2) == 0)
				{
					if(alumno_buscarLibre(arrayAlumnos, CANT_ALUMNOS, indice) == 0)
					{
						alumno_alta(arrayAlumnos, CANT_ALUMNOS, indice);
					}
					else
					{
						printf("Ya fue dado de alta un alumno en ese indice.\n");
					}
				}
				break;
			case 2:
				alumno_imprimirArray(arrayAlumnos, CANT_ALUMNOS);
				if( utn_getNumeroInt(&indice, "\n\nSeleccione el indice del alumno que quiere modificar: ", "Error.\n", 0, CANT_ALUMNOS, 2) == 0)
				{
					if(alumno_buscarLibre(arrayAlumnos, CANT_ALUMNOS, indice) != 0)
					{
						alumno_modificar(arrayAlumnos, CANT_ALUMNOS, indice);
					}
					else
					{
						printf("El indice ingresado no pertenece a un alumno dado de alta.\n");
					}
				}
				break;
			case 3:
				alumno_imprimirArray(arrayAlumnos, CANT_ALUMNOS);
				if( utn_getNumeroInt(&indice, "\n\nSeleccione el indice del alumno que quiere borrar: ", "Error.\n", 0, CANT_ALUMNOS, 2) == 0)
				{
					alumno_baja(arrayAlumnos, CANT_ALUMNOS, indice);
				}
				break;
			case 4:
				alumno_imprimirArray(arrayAlumnos, CANT_ALUMNOS);
				break;
			case 5:
				alumno_ordenarPorNombre(arrayAlumnos, CANT_ALUMNOS);
				break;
		}
	}while(opcion != 6);
}
