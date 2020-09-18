/*
 ============================================================================
 Name        : Clase_09_Ejercicio03.c
 Author      : Leandro Sobrino
 Description : 3) Modificar la funcion del punto 2 para que NO imprima el valor contado, sino que lo devuelva por referencia
 	 	 	 	 (recibiendo la direccion de memoria de una variable donde escribirá el valor contado).
  	  	  	  	  Escribir un programa para probar la funcion.
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
	int	numeros[LEN] = {3,7,4,5,2,3,7,1,7,3,2,7};
	int contador;

	if(contarNumArray(&contador, numeros, NUMERO_CONTADO, LEN) == 0)
	{
		printf("El número 7 se repite %d veces.",contador);
	}
	else
	{
		printf("Algo salió mal.");
	}
}
