/*
 ============================================================================
 Name        : Ejercicio_clase_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Ejercicio: Pedir 5 numeros enteros y mostrar el promedio

int main(void)
{
	setbuf(stdout,NULL);

	int numero;
	float promedio;
	int acumulador=0;
	int i;

	acumulador = 0;
	for (i = 0; i < 5; ++i)
	{
		printf("Ingrese un numero %d: ", numero);
		scanf("%d", &numero);
		acumulador += numero;
	}
	promedio = (float)acumulador / i; // Casting - Necesito que una de las dos variables actúe como float para obtener el promedio como decimal.
	printf("\nEl promedio es: %.2f", promedio);
}
