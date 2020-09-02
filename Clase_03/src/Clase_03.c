#include <stdio.h>
#include <stdlib.h>

int sumarEnteros(int operadorA, int operadorB);
int dividirEnteros(int operadorA, int operadorB, float *resultado);
/*
int sumar(int a, int b, int *resultado); Prueba 2
*/
int main(void)
{
	float resultadoDiv;
	if(dividirEnteros(14,0,&resultadoDiv) == 0)
	{
		printf("El resultado es: %.2f",resultadoDiv); // Se usa en despues con &.
	}
	else
	{
		printf("No se puede dividir por 0.");
	}
	return EXIT_SUCCESS;
}

int sumarEnteros(int operadorA, int operadorB)
{
	int resultado;
	resultado = operadorA + operadorB;
	return resultado;
}

int dividirEnteros(int operadorA, int operadorB, float *resultadoDiv)
{
	int retorno;
	if(operadorB != 0)
	{
		*resultadoDiv = (float)operadorA / operadorB; // Se declara en la funcion con asterisco.
		retorno = 0;
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}

/*	Prueba 2
int main(void)
{
	int numero = 22;
	sumar(14,11,&numero);
}

int sumar(int a, int b, int *resultado)
{
	*resultado = a + b;
	return 0;
}
*/
