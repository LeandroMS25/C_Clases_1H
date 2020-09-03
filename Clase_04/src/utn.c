/*
 * utn.c
 *
 *  Created on: 3 sept. 2020
 *      Author: leito
 */
#include <stdio.h>
#include <stdlib.h>

int getInt(char *mensaje, char *mensajeError, char *mensajeReintentos,  int reintentos, int maximo, int minimo, int *pResultado)
{
	int retorno = -1;
	int bufferInt;
	int respuestaScanF;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeReintentos != NULL && minimo<=maximo && reintentos >= 0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		respuestaScanF = scanf("%d",&bufferInt);
		while(respuestaScanF != 1 && reintentos > 0 && (bufferInt<minimo || bufferInt>maximo))
		{
			reintentos--;
			printf("%s",mensajeError);
			fflush(stdin);
			respuestaScanF = scanf("%d",&bufferInt);
		}
		if(respuestaScanF != 0)
		{
			*pResultado = bufferInt;
			retorno = 0;
		}
		else
		{
			printf("%s",mensajeReintentos);
		}
	}
	return retorno;
}

int getInt(char *mensaje, char *mensajeError, char *mensajeReintentos,  int reintentos, int maximo, int minimo, int *pResultado)
{
	int retorno = -1;
	int bufferInt;
	int respuestaScanF;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeReintentos != NULL && minimo<=maximo && reintentos >= 0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		respuestaScanF = scanf("%d",&bufferInt);
		while(respuestaScanF != 1 && reintentos > 0 && (bufferInt<minimo || bufferInt>maximo))
		{
			reintentos--;
			printf("%s",mensajeError);
			fflush(stdin);
			respuestaScanF = scanf("%d",&bufferInt);
		}
		if(respuestaScanF != 0)
		{
			*pResultado = bufferInt;
			retorno = 0;
		}
		else
		{
			printf("%s",mensajeReintentos);
		}
	}
	return retorno;
}

int sumarFloat(float operadorA, float operadorB,float *pResultado)
{
	int retorno = -1;
	if(pResultado != NULL)
	{
		*pResultado = operadorA + operadorB;
		retorno = 0;
	}
	return retorno;
}

int restarFloat(float operadorA, float operadorB,float *pResultado)
{
	int retorno = -1;
		if(pResultado != NULL)
		{
			*pResultado = operadorA - operadorB;
			retorno = 0;
		}
		return retorno;
}

int multiplicarFloat(float operadorA, float operadorB,float *pResultado)
{
	int retorno = -1;
		if(pResultado != NULL)
		{
			*pResultado = operadorA * operadorB;
			retorno = 0;
		}
		return retorno;
}

int dividirFloat(float operadorA, float operadorB,float *pResultado)
{
	int retorno = -1;
		if(pResultado != NULL && operadorB != 0)
		{
			*pResultado = operadorA / operadorB; // Se declara en la funcion con asterisco.
			retorno = 0;
		}
		return retorno;
}
