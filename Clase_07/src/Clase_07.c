/*
 ============================================================================
 Name        : Clase_07.c
 Author      : Leandro Sobrino
 Description : Seguimos con cadenas de caracteres.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesArray.h"
#include "utn.h"

#define LEN_NOMBRE 100

int main(void)
{
	setbuf(stdout,NULL);
	char nombre[LEN_NOMBRE];
	char edades[LEN_NOMBRE];
	int aVer;
	/*
	char nombre2[6] = "ABCZ";
	int resultadoCmp;
	int nombreLen;

	// Copiar un string en otro de forma segura. La otra forma es srtcpy pero no tiene en cuenta el tamaño
	strncpy(nombre,nombre2,sizeof(LEN_NOMBRE)); // nombre = nombre2 // MAL
	printf("%s\n",nombre);
	// Comparar strings.
	resultadoCmp = strncmp(nombre,nombre2,sizeof(nombre)-1);
	if(resultadoCmp == 0)
	{
		printf("Son iguales.\n");
	}
	else if(resultadoCmp > 0)
	{
		printf("El primer nombre es mas grande.\n");
	}
	else if(resultadoCmp < 0)
	{
		printf("El segundo nombre es mas grande.");
	}
	//	Indica la longitud del string, menos el ultimo lugar.
	nombreLen = strnlen(nombre,LEN_NOMBRE-1);
	printf("%d\n",nombreLen);
	// Guardar varias cosas en un array de Char.
	sprintf(nombre,"%.2f hola %d - %s",2.22,10,"HOLA");
	printf("%s\n",nombre);
	// Guardar varias cosas en un array de Char pero tenes que pasar la longitud del mismo.
	snprintf(nombre,LEN_NOMBRE-1,"%s %s","Mierda ","HOLA ");
	printf("%s",nombre);
	*/
	if(utn_getNombre(nombre, "Ingrese un nombre: ", "El nombre ingresado no es valido.\n", 2, LEN_NOMBRE-1) == 0)
	{
		printf("%s\n",nombre);
	}
	else
	{
		printf("Todo mal.");
	}
	if(utn_getNumero(edades, "Ingrese una edad: ", "El edad ingresada no es valida.\n", 2, LEN_NOMBRE - 1) == 0)
	{
		printf("%s",edades);
	}
	else
	{
		printf("Todo mal.");
	}
	return EXIT_SUCCESS;
}
