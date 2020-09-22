/*
 * Mascotas.c
 *
 *  Created on: 19 sept. 2020
 *      Author: leito
 */
#include <stdio.h>
#include <stdlib.h>
#include "Mascotas.h"

int imprimirArrayMascotas(Mascota* pArray, int limite)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && limite > 0)
	{
		for (i = 0; i < limite; i++)
		{
			printf("Nombre: %s. Edad: %d\n",pArray[i].nombreMascotas, pArray[i].edad);
		}
		printf("\n");
		retorno = 0;
	}
	return retorno;
}
