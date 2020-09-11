/*
 ============================================================================
 Name        : Clase_06.c
 Author      : Leandro Sobrino
 Description : Ordenar array.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesArray.h"
#include "utn.h"

#define LEN 8

int main(void)
{
	setbuf(stdout,NULL);
	int variableInt;
	int arrayInt[LEN];
	int i;
	for(i=0; i < LEN ; i++)
	{
		if(getInt(&variableInt, "Ingrese un número: ","Fuera de rango [0-1000]\n",5,0,1000) != 0)
		{
			printf("GAME OVER");
			break;
		}
		else
		{
			arrayInt[i] = variableInt;
		}
	}
	printf("Array sin ordenar: ");
	imprimirArray(arrayInt, LEN);
	ordenarArray(arrayInt, LEN);
	printf("\nArray ordenado: ");
	imprimirArray(arrayInt, LEN);
	// 8 2 3 1 9 5 8 7
	return EXIT_SUCCESS;
}
