/*
 * utn.c
 *
 *  Created on: 8 sept. 2020
 *      Author: Leandro Sobrino
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int myGets(char* cadena, int longitud);
static int esNumerica(char* cadena, int limite);
static int getInt(int *pResultado);
/**
 * \brief	Lee el stdin hasta que encuentra un '\0' o hasta que haya copiado en cadena
 * 			un maximo de 'longitud - 1' caracteres.
 * \param	char* cadena, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param	char longitud, Define el tama�o de la cadena.
 * \return	Retorna 0 (exito) si se obtiene una cadena y -1 (error) si no se obtiene.
 */
int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[LEN_BUFFER_STRING];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		// file get string.
		if(fgets(bufferString,sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString,longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/*
 * \ brief - Obtiene un numero entero.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
static int getInt(int* pResultado)
{
	int retorno	= -1;
	char bufferString[LEN_BUFFER_STRING];

	if(pResultado != NULL)
	{
		if( myGets(bufferString, sizeof(bufferString)) == 0 &&
			esNumerica(bufferString, LEN_BUFFER_STRING)  == 1)
		{
			retorno = 0;
			*pResultado = atoi(bufferString);
		}
	}
	return retorno;
}
/*
 * \ brief - Verifica una cadena recibida como parametro para determinar
 * 	         si es un nombre valido.
 * \ param - char* cadena, cadena a analizar.
 * \ param - int limite, indica la cantidad de letras maximas de la cadena.
 * \ return - (1) Indica que es un nombre valido / (0) Indica que no es un nombre valido.
 */
int esUnNombreValido(char cadena[],int limite)
{
	int respuesta = 1; // Todo bien.

	for (int i = 0; i <= limite && cadena[i] != '\0'; i++)
	{
		if(	(cadena[i] < 'A' || cadena[i] > 'Z' ) &&
			(cadena[i] < 'a' || cadena[i] > 'z' ) &&
			cadena[i] != ' ')
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}
/*
 * \ brief - Verifica una cadena recibida como parametro para determinar
 * 	         si es un numero valido.
 * \ param - char* cadena, cadena a analizar.
 * \ param - int limite, indica la cantidad de numeros maximas de la cadena.
 * \ return - (1) Indica que es un nombre valido / (0) Indica que no es un nombre valido.
 */
static int esNumerica(char* cadena, int limite)
{
	int respuesta = 1; // Todo bien.
	int i = 0;

	if(cadena[0] == '-')
	{
		i = 1;
	}
	for ( ; i <= limite && cadena[i] != '\0'; i++)
	{
		if(cadena[i] < '0' || cadena[i] > '9' )
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}
/*
 * \ brief - Solicita un nombre al usuario.
 * \ param - char* mensaje, Mensaje a ser mostrado al usuario para solicitarle el dato.
 * \ param - char* mensajeError, Mensaje a ser mostrado al usuario para indicarle que el valor ingresado no es correcto.
 * \ param - char* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int reintentos, Cantidad de oportunidades para ingresar el dato.
 * \ param - int limite, indica la cantidad de letras maxima del nombre.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError, int reintentos, int limite)
{
	int retorno = -1;
	char bufferString[LEN_BUFFER_STRING];

	if( 	pResultado != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos >= 0 &&
			limite > 1)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			if(	myGets(bufferString, LEN_BUFFER_STRING) == 0 &&
				strnlen(bufferString, sizeof(bufferString)-1) <= limite &&
				esUnNombreValido(bufferString, limite) != 0)
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
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
 * \ brief - Solicita un numero al usuario y, luego de verificarlo, devuelve el resultado.
 * \ param - char* mensaje, Mensaje a ser mostrado al usuario para solicitarle el dato.
 * \ param - char* mensajeError, Mensaje a ser mostrado al usuario para indicarle que el valor ingresado no es correcto.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int reintentos, Cantidad de oportunidades para ingresar el dato.
 * \ param - int minimo, valor minimo admitido.
 * \ param - int maximo, valor maximo admitido.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 *
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if( 	pResultado != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			if(	getInt(&bufferInt) == 0 &&
				bufferInt >= minimo &&
				bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
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
