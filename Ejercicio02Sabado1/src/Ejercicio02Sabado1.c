/*
 ============================================================================
 Name        : Ejercicio02Sabado1.c
 Author      : Leandro Sobrino
 Description : Una función:
Realizar una función que reciba el precio float y el porcentaje de descuento como entero  ,retornar el precio con el descuento al main
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	setbuf(stdout,NULL);
	float precio;
	int porcentaje;
	float descuento;
	float precioConDescuento;

	if(getFloat(&precio, "Ingrese un precio: ", "El precio no es válido.\n", "Superó la cantidad de intentos.", 0, 1) == 0)
	{
		if(getInt(&porcentaje, "Ingrese un porcentaje: ", "El porcentaje no es válido.\n", "Superó la cantidad de intentos.", 0, 100, 1) == 0)
		{
			descuento = precio * porcentaje / 100;
			precioConDescuento = precio - descuento;
		}
	}
	printf("\nEl precio con descuento es: %.2f",precioConDescuento);
}
