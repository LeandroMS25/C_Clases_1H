/*
 ============================================================================
 Name        : Clase_10.c
 Author      : Leandro Sobrino
 Description : Estructuras
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utn.h"
#include "Alumno.h"

#define CANT_ALUMNOS 200
#define OPTIONS 6

int main(void)
{
	setbuf(stdout,NULL);
	Alumno arrayAlumnos[CANT_ALUMNOS];
	int opcion;
	int idModificar;
	int idBaja;
	int indiceModificar;
	int indiceBaja;

	alumno_init(arrayAlumnos, CANT_ALUMNOS);
	do
	{
		utn_getNumeroInt(&opcion, "***Menu de opciones***\n\n"
								  "1- Alta de alumno.\n"
								  "2- Imprimir el listado de alumnos.\n"
								  "3- Modificar datos del alumno.\n"
								  "4- Baja de alumno.\n"
								  "5- Ordenar.\n"
								  "6- Salir.\n\n"
								  "Ingrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTIONS, 2);
		switch (opcion)
		{
			case 1:
				alumno_alta(arrayAlumnos, CANT_ALUMNOS);
				break;
			case 2:
				alumno_imprimirArray(arrayAlumnos, CANT_ALUMNOS);
				break;
			case 3:
				alumno_imprimirArray(arrayAlumnos, CANT_ALUMNOS);
				if( utn_getNumeroInt(&idModificar, "\nIngrese el id del alumno que quiere modificar: ", "Error.\n", 1, INT_MAX, 2) == 0 &&
					alumno_buscarPorId(arrayAlumnos, CANT_ALUMNOS, &indiceModificar, idModificar) == 0)
				{
						alumno_modificar(arrayAlumnos, CANT_ALUMNOS, indiceModificar);
				}
				break;
			case 4:
				alumno_imprimirArray(arrayAlumnos, CANT_ALUMNOS);
				if( utn_getNumeroInt(&idBaja, "\nIngrese el id del alumno que quiere dar de baja: ", "Error.\n", 1, INT_MAX, 2) == 0 &&
					alumno_buscarPorId(arrayAlumnos, CANT_ALUMNOS, &indiceBaja, idBaja) == 0)
				{
						alumno_baja(arrayAlumnos, CANT_ALUMNOS, indiceBaja);
				}
				break;
			case 5:
				alumno_ordenarPorNombre(arrayAlumnos, CANT_ALUMNOS, 1);
				break;
		}
	}while(opcion != 6);
}
