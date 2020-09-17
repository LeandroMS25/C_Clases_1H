/*
 ============================================================================
 Name        : Ejercicio01Sabado2.c
 Author      : Leandro Sobrino
 Description : Vectores y cadenas.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "funcionesArray.h"

#define LEN 5

int main(void)
{
	setbuf(stdout,NULL);
	int numeros[LEN];
	int i;
	/*
	int contadorCero;
	int contadorSiete;
	int contadorCinco;
	int sumaPares;
	*/

	for (i = 0; i < LEN; i++)
	{
		getInt(&numeros[i], "Ingrese un numero: ", "Numero ingresado no valido.", 3, -100, 100);

	}
	/*
	contadorNumArray(&contadorCero, numeros, 0, LEN);
	contadorNumArray(&contadorSiete, numeros, 7, LEN);
	contadorNumArray(&contadorCinco, numeros, 5, LEN);
	sumarParesArray(&sumaPares, numeros, LEN);
	printf("\nLa cantidad de 0 es: %d.\n",contadorCero);
	printf("La cantidad de 7 es: %d.\n",contadorSiete);
	printf("La cantidad de 5 es: %d.\n",contadorCinco);
	printf("La suma de los numeros pares es: %d.\n",sumaPares);
	*/
}
