/*
 * calculosArray.c
 *
 *  Created on: 8 sept. 2020
 *      Author: leito
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * \ brief - Calcula el número maximo del array recibido como parametro.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int array[], recibe el array a utilizar.
 * \ param - int lenghtArray, indica la longitud del array.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int calcularMaxIntArray(int* pResultado, int pArray[], int lengthArray)
{
	int retorno = -1;
	int i;
	int maximo;

	if(pArray != NULL && pResultado != NULL && lengthArray > 0)
	{
		for (i = 0; i < lengthArray; i++)
		{
			if(i == 0 || pArray[i] > maximo)
			{
				maximo = pArray[i];
			}
		}
		*pResultado = maximo;
	}
	return retorno;
}
/*
 * \ brief - Calcula el número minimo del array recibido como parametro.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int array[], recibe el array a utilizar.
 * \ param - int lenghtArray, indica la longitud del array.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int calcularMinIntArray(int* pResultado, int pArray[], int lengthArray)
{
	int retorno = -1;
	int i;
	int minimo;

	if(pArray != NULL && pResultado != NULL && lengthArray > 0)
	{
		for (i = 0; i < lengthArray; i++)
		{
			if(i == 0 || pArray[i] < minimo)
			{
				minimo = pArray[i];
			}
		}
		*pResultado = minimo;
	}
	return retorno;
}
/*
 * \ brief - Calcula el promedio de los numeros del array recibido como parametro.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int array[], recibe el array a utilizar.
 * \ param - int lenghtArray, indica la longitud del array.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
float promediarArrayInt(float* pResultado, int pArray[], int lengthArray)
{
	int retorno = -1;
	int acumuladorNumeros = 0;
	int i;
	if(pArray != NULL && pResultado != NULL && lengthArray > 0)
	{
		for (i = 0; i < lengthArray; i++)
		{
			acumuladorNumeros += pArray[i];
		}
		*pResultado = ((float)acumuladorNumeros) / lengthArray;
	}
	return retorno;
}
