/*
 ============================================================================
 Name        : Ejercicio02Sabado.c
 Author      : Leandro
 Description : Ejercicio 02:
Al ejercicio anterior :
Ademas de la edad ingresar el estado civil de la persona ( 's' para soltera , 'c' para casada, 'd' divorciada)
ademas de informar lo anterior ....informar:
la persona mas joven de las casadas
a persona mas Vieja de las solteras
de los estados civiles , cual fue el mas ingresado
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

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
