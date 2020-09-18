/*
 ============================================================================
 Name        : Clase_08_Ejercicio02.c
 Author      : Leandro Sobrino
 Description : 2) Hacer una funcion que reciba el array del punto 1 y su tamaño, y cuente cuantas veces aparece el numero 7.
  	  	  	  	  Al terminar de contar, la funcion deberá imprimir por pantalla el valor contado.
  	  	  	  	  Escribir un programa para probar la funcion
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "funcionesArray.h"

#define LEN 12
#define NUMERO_CONTADO 7

int main(void)
{
	setbuf(stdout,NULL);
	int	numeros[LEN] = {3,7,4,5,2,3,7,1,7,3,2,7}; // Si se define asi no es necesario poner el tamaño del array.

	contarNumArray(numeros, NUMERO_CONTADO, LEN);
}
