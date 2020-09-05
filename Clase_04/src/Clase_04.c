
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);
	int edad;
	int respuesta;

	respuesta = getInt(&edad, "Ingrese la edad del usuario: ", "Error. Debe ingresar un valor entre 0 y 100.\n", "Superó la cantidad de intentos.\n", 0, 100, 2);

	if(respuesta == 0)
	{
		printf("La edad del usuario es: %d",edad);
	}
	else
	{
		printf("La función no corrió.");
	}
}
