/*
 ============================================================================
 Name        : Test_Clase_07.c
 Author      : Leandro Sobrino
 Description : Test
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);
	int num1;

	if(utn_getNumero(&num1, "Ingrese el primero numero: ", "El numero ingresado no es valido.\n", -100, 100, 3) == 0)
	{
		printf("El numero ingresado es: %d", num1);
	}
	else
	{
		printf("Algo salió mal.");
	}
	return EXIT_SUCCESS;
}
