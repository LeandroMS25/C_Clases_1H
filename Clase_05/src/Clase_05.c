/*
 ============================================================================
 Name        : Clase_05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculosArray.h"

#define LEN 5

int main(void)
{
	setbuf(stdout,NULL);
	int variableInt;
	char aMensaje[200];
	int arrayInt[LEN];
	int maximo;
	int minimo;
	float promedio;
	int i;
	int flagCargaCorrecta = 0;
	for(i=0; i < LEN ; i++)
	{
		sprintf(aMensaje,"Numero %d: ",i+1);
		if(getInt(&variableInt, aMensaje,"Fuera de rango [0-1000]\n",5,0,1000) != 0)
		{
			printf("GAME OVER");
			flagCargaCorrecta = -1;
			break;
		}
		else
		{
			arrayInt[i] = variableInt;
		}
	}
	if(flagCargaCorrecta == 0)
	{
		calcularMaxIntArray(&maximo, arrayInt, LEN);
		calcularMinIntArray(&minimo, arrayInt, LEN);
		promediarArrayInt(&promedio, arrayInt, LEN);
		printf("\nEl número máximo ingresado fue: %d",maximo);
		printf("\nEl número mínimo ingresado fue: %d",minimo);
		printf("\nEl promedio da: %.2f",promedio);
	}
	return EXIT_SUCCESS;
}

