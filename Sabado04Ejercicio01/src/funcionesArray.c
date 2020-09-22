/*
 * funcionesArray.c
 *
 *  Created on: 8 sept. 2020
 *      Author: Leandro Sobrino
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
		retorno = 0;
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
		retorno = 0;
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
		retorno = 0;
	}
	return retorno;
}
/*
 * \ brief - Ordena cada valor del array, de menor a mayor en este caso.
 * \ param - int array[], recibe el array a utilizar.
 * \ param - int lenghtArray, indica la longitud del array.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int ordenarArray(int pArray[], int arrayLength)
{
	int retorno = -1;
	int i;
	int aux;
	int flagArrayDesordenado = 1; // El array inicia desordenado.
	// 8 2 3 1 9 5 8 7 - Valores a utilizar
	if(pArray != NULL && arrayLength > 0)
	{
		while(flagArrayDesordenado == 1) // Se itera hasta que se confirme que está ordenado.
		{
			flagArrayDesordenado = 0; // Se asume que ya está ordenado, pero si vuelve a entrar al for quiere decir que no lo está.
			for (i = 0; i < (arrayLength - 1); i++)
			{
				if(pArray[i] > pArray[i+1])
				{
					// Intercambiar (Swap)
					aux = pArray[i]; // 8 - Se guarda en el auxiliar para no perderlo.
					pArray[i] = pArray[i+1]; // 2 - Se guarda en el primer indice.
					pArray[i+1] = aux; // 8 - Se guarda el valor que se habia almacenado en el aux, en el segundo indice.
					flagArrayDesordenado = 1; // Se confirmo que estaba desordenado.
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * \ brief - Imprime cada valor del array uno al lado del otro.
 * \ param - int array[], recibe el array a utilizar.
 * \ param - int lenghtArray, indica la longitud del array.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int imprimirArray(float* pArray, int limite)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && limite > 0)
	{
		for (i = 0; i < limite; i++)
		{
			printf("%f ",pArray[i]);
		}
		printf("\n");
		retorno = 0;
	}
	return retorno;
}
/*
 * \ brief - Cuenta la cantidad de un determinado numero.
 * \ param - int* pContador, puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int array[], recibe el array a utilizar.
 * \ param - int numero, numero que se contara.
 * \ param - int limite, indica la longitud del array.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int contarNumArray(int* pContador,int pArray[],int numero, int limite)
{
	int retorno = -1;
	int i;
	int contador=0;

	if(pArray != NULL && pContador != NULL && limite > 0)
	{
		for (i = 0; i < limite; i++)
		{
			if(pArray[i] == numero)
			{
				contador++;
			}
		}
		*pContador = contador;
		retorno = 0;
	}
	return retorno;
}
/*
 * \ brief - Cuenta la cantidad de un determinado caracter.
 * \ param - int* pContador, puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int array[], recibe el array a utilizar.
 * \ param - int caracter, caracter que se contara.
 * \ param - int limite, indica la longitud del array.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int contarCharArray(int* pContador,char pArray[],char caracter)
{
	int retorno = -1;
	int i=0;
	int contador=0;

	if(pArray != NULL && pContador != NULL)
	{
		while(pArray[i] != '\0')
		{
			if(pArray[i] == caracter)
			{
				contador++;
			}
			i++;
		}
		*pContador = contador;
		retorno = 0;
	}
	return retorno;
}
