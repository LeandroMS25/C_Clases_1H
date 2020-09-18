/*
 ============================================================================
 Name        : Clase_08_Ejercicio06.c
 Author      : Leandro Sobrino
 Description : 6) Realizar un programa para probar la funcion del punto 5, permitiendo que el usuario ingrese un texto y
  	  	  	  	  luego validando si lo ingresado es un nombre válido. Usar scanf para tomar el texto.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int validarNombreArray(char pArray[]);
#define LEN 100

int main(void)
{
	setbuf(stdout,NULL);
	char nombre[LEN];

	printf("Ingrese un nombre: ");
	fflush(stdin);
	scanf("%s",nombre);
	if(validarLetraArray(nombre) == 0)
	{
		printf("Es un nombre valido.");
	}
	else
	{
		printf("No es un nombre valido.");
	}
}

int validarNombreArray(char pArray[])
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
