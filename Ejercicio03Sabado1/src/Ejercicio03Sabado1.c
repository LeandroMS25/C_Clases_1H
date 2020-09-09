/*
 ============================================================================
 Name        : Ejercicio03Sabado1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Bibliotecas:
función
//retorna 1 si el sexo es correcto 'f' o 'm'
int validarSexo(char sexoParametro)
en la biblioteca "validacion.h", hacer el ".c"
función
//retorna un sexo valido ('f' o 'm'), pide el dato por "scanf" y lo //validad usando la funcion "validarSexo"
char pedirSexo()
en la bilioteca "funciones.h", hacer el ".c"
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	setbuf(stdout,NULL);
	char sexo;
	sexo = pedirSexo();
	if(sexo != ' ')
	{
		printf("El sexo ingresado es: %c",sexo);
	}
	return 0;
}
