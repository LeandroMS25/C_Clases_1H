#include <stdio.h>
#include <stdlib.h>
/*
Ejercicio 01:
Se pide una cantidad indeterminada de edades enteras,
informar:
el máximo ingresado
el mínimo ingresado
el promedio
la cantidad de edades ingresadas
*/
int main(void)
{
	char respuesta;
	int edad;
	int edadMaxima;
	int edadMinima;
	int contadorEdades=0;
	int acumEdades=0;
	float promedio;

	do
	{
		setbuf(stdout,NULL);
		printf("Ingrese una edad: ");
		scanf("%d",&edad);
		if(contadorEdades == 0 || edad>edadMaxima)
		{
			edadMaxima = edad;
		}
		if(contadorEdades == 0 || edad<edadMinima)
		{
			edadMinima = edad;
		}
		contadorEdades++;
		acumEdades+=edad;
		printf("¿Desea ingresar otra edad? s/n: ");
		fflush(stdin);
		scanf("%c",&respuesta);
	}while(respuesta == 's');
	promedio = (float)acumEdades / contadorEdades;

	printf("\nEl promedio de las edades ingresadas es: %.2f", promedio);
	printf("\nLa edad maxima ingresada es: %d", edadMaxima);
	printf("\nLa edad minima ingresada es: %d", edadMinima);
}
