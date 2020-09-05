/*
 ============================================================================
 Name        : Ejercicio01Sabado1.c
 Author      : Leandro Sobrino
 Description : Sin funciones:
para realizar un pedido, solicitar tres datos ,(iterar 5 veces)
código de tipo int , validar entre 100 y 200
cantidad de tipo entero(int), validar entre 1 y 20
una talle de tipo char validad entre('S' , 'M' , 'L')
a-mostrar el código y el talle  del que mas cantidad solicito
b-el promedio del total  de cantidades de talle 'M' con decimales
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);
	int codigo;
	int cantidad;
	char tipo;
	int i;
	int acumuladorTalleM=0;
	int cantidadTalleM=0;
	float promedioTalleM;
	int cantidadMasSolicitado;
	int codigoMasSolicitado;
	char tipoMasSolicitado;

	for (i = 0; i < 5; i++)
	{
		if(getInt(&codigo, "Ingrese un codigo(100 a 200): ", "Codigo no válido.\n", "Superó la cantidad de intentos.", 100, 200, 1) == 0)
		{
			if(getInt(&cantidad, "Ingrese la cantidad(1 a 20): ", "Cantidad ingresada no válida.\n", "Superó la cantidad de intentos.", 1, 20, 1) == 0)
			{
				if(getChar(&tipo, "Ingrese el tipo(S-M-L): ", "Tipo no válido.\n", "Superó la cantidad de intentos.", 'L', 'S', 1) == 0)
				{
					if(tipo == 'M')
					{
						cantidadTalleM++;
						acumuladorTalleM+=cantidad;
					}
					if(i == 0 || cantidad > cantidadMasSolicitado)
					{
						cantidadMasSolicitado = cantidad;
						tipoMasSolicitado = tipo;
						codigoMasSolicitado = codigo;
					}
				}
			}
		}
		else
		{
			break;
		}
	}
	promedioTalleM = (float)acumuladorTalleM / cantidadTalleM;
	printf("\nEl codigo del talle mas solicitado es: %d.",codigoMasSolicitado);
	printf("\nEl tipo del talle mas solicitado es: %c.",tipoMasSolicitado);
	if(cantidadTalleM != 0)
	{
		printf("\nEl promedio de la cantidad del talle M es: %.2f",promedioTalleM);
	}
	else
	{
		printf("\nNo se ingresaron productos de talle M.");
	}
}
