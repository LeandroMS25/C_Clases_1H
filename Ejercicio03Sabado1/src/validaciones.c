/*
 * validaciones.c
 *
 *  Created on: 5 sept. 2020
 *      Author: leito
 */

#include <stdio.h>
#include <stdlib.h>

int validarSexo(char sexoParametro)
{
	setbuf(stdout,NULL);
	int retorno = -1;
	if(sexoParametro == 'f' || sexoParametro == 'm')
	{
		retorno = 0;
	}
	return retorno;
}
