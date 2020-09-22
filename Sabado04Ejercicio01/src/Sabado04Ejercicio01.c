/*
 ============================================================================
 Name        : Sabado04Ejercicio01.c
 Author      : Leandro Sobrino
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Mascotas.h"
#include "funcionesArray.h"

#define LEN 2

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int i;
	int edad;
	Mascota ArrayMascotas[LEN];

	do
	{
		utn_mostrarMenu(&opcion, "1- Ingresar nombres.\n2- Mostrar listado.\n3- Ordenar por edad.\n4- Salir.\n\nIndicar opcion: ", "Opción ingresada invalida.", 1, 3, 2);
		system("cls");
		switch (opcion) {
			case 1:
				for (i = 0; i < LEN; i++)
				{
					utn_getNombre(ArrayMascotas[i].nombreMascotas, "Ingrese el nombre de la mascota: ", "Nombre invalido.\n", 2, 10);
					utn_getNumeroInt(&edad, "Ingrese la edad de la mascota: ", "Edad invalida.\n", 1, 20, 2);
					ArrayMascotas[i].edad = edad;
				}
				break;
			case 2:
				imprimirArrayMascotas(ArrayMascotas, LEN);
				break;
		}
	}while(opcion != 4);
}
