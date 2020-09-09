/*
 * funciones.c
 *
 *  Created on: 5 sept. 2020
 *      Author: leito
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

char pedirSexo()
{
	setbuf(stdout,NULL);
	char retorno;
	char sexoValido;

	printf("Ingrese un sexo: ");
	scanf("%c",&sexoValido);
	if(validarSexo(sexoValido) != 0)
	{
		printf("El sexo ingresado no es válido.\n");
	}
	else
	{
		retorno = sexoValido;
	}
	return retorno;
}
