/*
 ============================================================================
 Name        : Clase_08_Ejercicio01.c
 Author      : Leandro Sobrino
 Description : 1) Se tiene el siguiente array de variables del tipo int:
				  int numeros[12]={3,7,4,5,2,3,7,1,7,3,2,7};
			  	  Hacer una funcion que reciba el array y su tamaño, y lo imprima. Escribir un programa para probar la funcion.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "funcionesArray.h"

#define LEN 12

int main(void)
{

	int	numeros[LEN] = {3,7,4,5,2,3,7,1,7,3,2,7}; // Si se define asi no es necesario poner el tamaño del array.

	if(imprimirArray(numeros, LEN) == 0)
	{
		printf("Los numeros se imprimieron correctamente.");
	}
	else
	{
		printf("Algo salió mal.");
	}
}
