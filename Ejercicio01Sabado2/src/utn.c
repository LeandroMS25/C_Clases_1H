/*
 * utn.c
 *
 *  Created on: 8 sept. 2020
 *      Author: Leandro Sobrino
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * \ brief - Solicita un entero al usuario.
 * \ param - char* mensaje, Mensaje a ser mostrado al usuario para solicitarle el dato.
 * \ param - char* mensajeError, Mensaje a ser mostrado al usuario para indicarle que el valor ingresado no es correcto.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int reintentos, Cantidad de oportunidades para ingresar el dato.
 * \ param - int minimo, valor minimo admitido.
 * \ param - int maximo, valor maximo admitido.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 *
 */
int getInt(int *pResultado, char *mensaje, char *mensajeError, int reintentos, int minimo, int maximo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%d",&bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
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
	}
	return retorno;
}

/*
 * \ brief - Solicita un float (número con decimal) al usuario.
 * \ param - char* mensaje, Mensaje a ser mostrado al usuario para solicitarle el dato.
 * \ param - char* mensajeError, Mensaje a ser mostrado al usuario para indicarle que el valor ingresado no es correcto.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int reintentos, Cantidad de oportunidades para ingresar el dato.
 * \ param - int minimo, valor minimo admitido.
 * \ param - int maximo, valor maximo admitido.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 *
 */
int getFloat(float *pResultado, char *mensaje, char *mensajeError, int reintentos, float minimo, float maximo)
{
	int retorno = -1;
	float bufferFloat;
	int resultadoScanf;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%f",&bufferFloat);
			if(resultadoScanf == 1 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
					*pResultado = bufferFloat;
					retorno=0;
					break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/*
 * \ brief - Solicita un caracter al usuario.
 * \ param - char* mensaje, Mensaje a ser mostrado al usuario para solicitarle el dato.
 * \ param - char* mensajeError, Mensaje a ser mostrado al usuario para indicarle que el valor ingresado no es correcto.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int reintentos, Cantidad de oportunidades para ingresar el dato.
 * \ param - int minimo, valor minimo admitido.
 * \ param - int maximo, valor maximo admitido.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 *
 */
int getChar(char *pResultado, char *mensaje, char *mensajeError, int reintentos, char minimo, char maximo)
{
	int retorno = -1;
	char bufferChar;
	int resultadoScanf;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%c",&bufferChar);
			if(resultadoScanf == 1 && bufferChar >= minimo && bufferChar <= maximo)
			{
					*pResultado = bufferChar;
					retorno=0;
					break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

