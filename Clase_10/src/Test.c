/*
 * Test.c
 *
 *  Created on: 24 sept. 2020
 *      Author: leito
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"

#define CANT_ALUMNOS 200
#define OPTIONS 3



	/*
	setbuf(stdout,NULL);
	Alumno arrayAlumnos[CANT_ALUMNOS];
	int opcion;
	int indiceLibre;

	alumno_init(arrayAlumnos, CANT_ALUMNOS);
	do
	{
		utn_getNumeroInt(&opcion, "***Menu de opciones***\n\n"
								  "1- Alta de alumno.\n"
								  "2- Imprimir el indice seleccionado.\n"
								  "3- Salir.\n\n"
								  "Ingrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTIONS, 2);
		switch (opcion)
		{
			case 1:
				if(alumno_buscarLibre(arrayAlumnos, CANT_ALUMNOS, &indiceLibre) == 0)
				{
					alumno_alta(arrayAlumnos, CANT_ALUMNOS, indiceLibre);
				}
				else
				{
					printf("No hay espacios libres para dar de alta un alumno.");
				}
				break;
			case 2:
				alumno_imprimirArray(arrayAlumnos, CANT_ALUMNOS);
				break;
		}
	}while(opcion != 3);
	*/
	/*
	setbuf(stdout,NULL);
	Alumno arrayAlumnos[CANT_ALUMNOS];
	int opcion;
	int indiceLibre;
	int indiceOcupado;

	alumno_init(arrayAlumnos, CANT_ALUMNOS);
	do
	{
		utn_getNumeroInt(&opcion, "***Menu de opciones***\n\n"
								  "1- Ingrese un alumno.\n"
								  "2- Modificar un alumno.\n"
								  "3- Borrar alumno.\n"
								  "4- Imprimir el indice seleccionado.\n"
								  "5- Ordenar listado por nombre.\n"
								  "6- Salir.\n\n"
								  "Ingrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTIONS, 2);
		switch (opcion)
		{
			case 1:
				if(alumno_buscarLibre(arrayAlumnos, CANT_ALUMNOS, &indiceLibre) == 0)
				{
					alumno_alta(arrayAlumnos, CANT_ALUMNOS, indiceLibre);
				}
				else
				{
					printf("No hay espacios libres para dar de alta un alumno.");
				}
				break;
			case 2:
				alumno_imprimirArray(arrayAlumnos, CANT_ALUMNOS);
				if( utn_getNumeroInt(&indiceOcupado, "\n\nSeleccione el indice del alumno que quiere modificar: ", "Error.\n", 0, CANT_ALUMNOS, 2) == 0)
				{
					alumno_modificar(arrayAlumnos, CANT_ALUMNOS, indiceOcupado);
				}
				break;
			case 3:
				alumno_imprimirArray(arrayAlumnos, CANT_ALUMNOS);
				if( utn_getNumeroInt(&indiceOcupado, "\n\nSeleccione el indice del alumno que quiere borrar: ", "Error.\n", 0, CANT_ALUMNOS, 2) == 0)
				{
					alumno_baja(arrayAlumnos, CANT_ALUMNOS, indiceOcupado);
				}
				break;
			case 4:

				if( utn_getNumeroInt(&indiceOcupado, "\n\nSeleccione el indice del alumno que quiere mostrar: ", "Error.\n", 0, CANT_ALUMNOS, 2) == 0)
				{
					alumno_imprimirIndiceArray(arrayAlumnos, CANT_ALUMNOS, indiceOcupado);
				}

				alumno_imprimirArray(arrayAlumnos, CANT_ALUMNOS);
				break;
			case 5:
				alumno_ordenarPorNombre(arrayAlumnos, CANT_ALUMNOS);
				break;
		}
	}while(opcion != 6);

*/

