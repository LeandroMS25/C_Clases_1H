/*
 ============================================================================
 Name        : Clase_08_Ejercicio05.c
 Author      : Leandro Sobrino
 Description : 5) Hacer una funcion que reciba el array del punto 4, y verifique que las letras dentro del mismo
 	 	 	 	  esten en el rango de 'a' a 'z' o de 'A' a 'Z'.
  	  	  	  	  Si estan dentro del rango la funcion deberá devolver por valor(usando el return) un 0, de lo contrario devolverá -1.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "funcionesArray.h"

int validarLetraArray(char pArray[]);
#define LEN 8

int main(void)
{
	char caracteres[LEN]={'p','e','p','e','1','2','3','\0'};

	if(validarLetraArray(caracteres) == 0)
	{
		printf("Estoy dentro del rango.");
	}
	else
	{
		printf("Estoy fuera del rango.");
	}
}

int validarLetraArray(char pArray[])
{
	int retorno = -1;
	int i=0;

	if(pArray != NULL)
	{
		while(pArray[i] != '\0')
		{
			if( (pArray[i] < 'a' || pArray[i] > 'z') &&
				(pArray[i] < 'A' || pArray[i] > 'Z'))
			{
				retorno = -1;
				break;
			}
			retorno = 0;
			i++;
		}
	}
	return retorno;
}
