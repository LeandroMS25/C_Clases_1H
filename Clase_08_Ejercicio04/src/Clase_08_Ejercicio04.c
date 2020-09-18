/*
 ============================================================================
 Name        : Clase_08_Ejercicio04.c
 Author      : Leandro Sobrino
 Description : 4) Dada la siguiente cadena de caracteres:
				  char nombre[8]={'p','e','p','e','1','2','3','\0'};
​				  Hacer una funcion que reciba el array y su tamaño, y cuente cuantas veces aparece la letra 'e'.
				  Al terminar de contar, la funcion deberá imprimir por pantalla el valor contado. Escribir un programa para probar la funcion.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "funcionesArray.h"

#define LEN 8

int main(void)
{
	char caracteres[LEN]={'p','e','p','e','1','2','3','\0'};
	int cantidadLetraE;

	if (contarCharArray(&cantidadLetraE, caracteres, 'e', LEN) == 0)
	{
		printf("La letra 'e' se repite %d veces.\n",cantidadLetraE);
	}
	else
	{
		printf("Algo salió mal.");
	}
}
