/*
 * funciones.c
 *
 *  Created on: 5 sept. 2020
 *      Author: leito
 */

#include <stdio.h>
#include <stdlib.h>

int getInt(int *pResultado, char *mensaje, char *mensajeError, char *mensajeReintentos, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	// int respuestaScanF;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeReintentos != NULL && minimo<=maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%d",&bufferInt);
			if(bufferInt < minimo || bufferInt > maximo)
			{
				printf("%s",mensajeError);
				reintentos--;
			}
			else
			{

				*pResultado = bufferInt;
				retorno=0;
				break;
			}
		}while(reintentos >= 0);
		if(reintentos < 0)
		{
			printf("%s",mensajeReintentos);
		}
	}
	return retorno;
}

int getFloat(float *pResultado, char *mensaje, char *mensajeError, char *mensajeReintentos, float minimo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	// int respuestaScanF;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeReintentos != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%f",&bufferFloat);
			if(bufferFloat < minimo)
			{
				printf("%s",mensajeError);
				reintentos--;
			}
			else
			{

				*pResultado = bufferFloat;
				retorno=0;
				break;
			}
		}while(reintentos >= 0);
		if(reintentos < 0)
		{
			printf("%s",mensajeReintentos);
		}
	}
	return retorno;
}
