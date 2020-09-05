/*
 * utn.c
 *
 *  Created on: 3 sept. 2020
 *      Author: leito
 */
#include <stdio.h>
#include <stdlib.h>

int getFloat(float *pResultado, char *mensaje, char *mensajeError, char *mensajeReintentos, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	int respuestaScanF;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeReintentos != NULL && minimo<=maximo && reintentos >= 0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		respuestaScanF = scanf("%f",&bufferFloat);
		while(respuestaScanF != 1 && reintentos > 0 && (bufferFloat<minimo || bufferFloat>maximo))
		{
			reintentos--;
			printf("%s",mensajeError);
			fflush(stdin);
			respuestaScanF = scanf("%f",&bufferFloat);
		}
		if(reintentos == 0)
		{
			printf("%s",mensajeReintentos);
		}
		else
		{
			*pResultado = bufferFloat;
			retorno = 0;
		}
	}
	return retorno;
}

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
			if(bufferInt>=minimo && bufferInt<maximo)
			{
				*pResultado = bufferInt;
				retorno=0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
		if(reintentos < 0)
		{
			printf("%s",mensajeReintentos);
		}
	}
	return retorno;
}

int getChar(char *pResultado, char *mensaje, char *mensajeError, char *mensajeReintentos, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	int respuestaScanF;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && mensajeReintentos != NULL && minimo<=maximo && reintentos >= 0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		respuestaScanF = scanf("%c",&bufferChar);
		while(respuestaScanF != 1 && reintentos > 0 && (bufferChar<minimo || bufferChar>maximo))
		{
			reintentos--;
			printf("%s",mensajeError);
			fflush(stdin);
			respuestaScanF = scanf("%c",&bufferChar);
		}
		if(reintentos == 0)
		{
			printf("%s",mensajeReintentos);
		}
		else
		{
			*pResultado = bufferChar;
			retorno = 0;
		}
	}
	return retorno;
}

int sumarFloat(float *pResultado, float operadorA, float operadorB)
{
	int retorno = -1;
	if(pResultado != NULL)
	{
		*pResultado = operadorA + operadorB;
		retorno = 0;
	}
	return retorno;
}

int restarFloat(float *pResultado, float operadorA, float operadorB)
{
	int retorno = -1;
		if(pResultado != NULL)
		{
			*pResultado = operadorA - operadorB;
			retorno = 0;
		}
		return retorno;
}

int multiplicarFloat(float *pResultado, float operadorA, float operadorB)
{
	int retorno = -1;
		if(pResultado != NULL)
		{
			*pResultado = operadorA * operadorB;
			retorno = 0;
		}
		return retorno;
}

int dividirFloat(float *pResultado, float operadorA, float operadorB)
{
	int retorno = -1;
		if(pResultado != NULL && operadorB != 0)
		{
			*pResultado = operadorA / operadorB; // Se declara en la funcion con asterisco.
			retorno = 0;
		}
		return retorno;
}
