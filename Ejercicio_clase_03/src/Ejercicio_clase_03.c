/*
 ============================================================================
 Name        : Ejercicio_clase_03.c
 Author      : Leandro Sobrino
 Description :
 Pedir al usuario dos numeros float.
 - Funcion sumar.
 - Funcion restar.
 - Funcion multiplicar.
 - Funcion dividir.
 Todas las funciones en caso de exito return 0 y en caso de error return -1.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);
	char operacion;
	float op1;
	float op2;
	float suma;
	float resta;
	float multiplicacion;
	float division;

	printf("Bienvenido a la calculadora de mierda.\n");
	printf("\nIngrese la operaci�n que desea realizar. Opciones: +|-|/|*. Respuesta: ");
	scanf("%c",&operacion);
	while(operacion != '+' && operacion != '-' && operacion != '/' && operacion != '*')
	{
		printf("La operaci�n ingresada no es v�lida. Ingrese otra: ");
		fflush(stdin);
		scanf("%c",&operacion);
	}
	printf("Usted eligi� la operaci�n: %c",operacion);
	if(getFloat("\nIngrese el primer n�mero: ", "ERROR! Reingrese el n�mero: ", "\nSuper� la cantidad intentos.", 3, &op1) == 0)
	{
		if(getFloat("Ingrese el segundo n�mero: ", "ERROR! Reingrese el n�mero: ", "\nSuper� la cantidad intentos.", 3, &op2) == 0)
		{
			switch (operacion)
			{
				case '+':
					sumarFloat(op1, op2, &suma);
					printf("\nLa suma dio: %.2f",suma);
					break;
				case '-':
					restarFloat(op1, op2, &resta);
					printf("\nLa resta dio: %.2f",resta);
					break;
				case '*':
					multiplicarFloat(op1, op2, &multiplicacion);
					printf("\nLa multiplicaci�n dio: %.2f",multiplicacion);
					break;
				case '/':
					dividirFloat(op1, op2, &division);
					printf("\nLa divisi�n dio: %.2f",division);
					break;
			}
		}
	}
}
