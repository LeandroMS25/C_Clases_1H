/*
 ============================================================================
 Name        : Ejercicio_clase_03.c
 Author      : Leandro Sobrino
 Description :
 Pedir al usuario dos metros float.
 - Funcion sumar.
 - Funcion restar.
 - Funcion multiplicar.
 - Funcion dividir.
 Todas las funciones en caso de exito return 0 y en caso de error return -1.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumarFloat(float operadorA, float operadorB,float *resultado);
int restarFloat(float operadorA, float operadorB,float *resultado);
int multiplicarFloat(float operadorA, float operadorB,float *resultado);
int dividirFloat(float operadorA, float operadorB,float *resultado);
float getFloat(char *mensaje, char *mensajeError, char *mensajeReintentos,int reintentos,float *pResultado);

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
	printf("\nIngrese la operación que desea realizar. Opciones: +|-|/|*. Respuesta: ");
	scanf("%c",&operacion);
	while(operacion != '+' && operacion != '-' &&operacion != '/' && operacion != '*')
	{
		printf("La operación ingresada no es válida. Ingrese otra: ");
		fflush(stdin);
		scanf("%c",&operacion);
	}
	printf("Usted eligió la operación: %c",operacion);
	if(getFloat("\nIngrese el primer número: ", "ERROR! Reingrese el número: ", "\nSuperó la cantidad intentos.", 3, &op1) == 0)
	{
		if(getFloat("Ingrese el segundo número: ", "ERROR! Reingrese el número: ", "\nSuperó la cantidad intentos.", 3, &op2) == 0)
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
					printf("\nLa multiplicación dio: %.2f",multiplicacion);
					break;
				case '/':
					dividirFloat(op1, op2, &division);
					printf("\nLa división dio: %.2f",division);
					break;
			}
		}
	}
}

float getFloat(char *mensaje, char *mensajeError, char *mensajeReintentos,int reintentos,float *pResultado)
{
	int retorno = -1;
	float bufferFloat;
	int respuestaScanF;
	printf("%s",mensaje);
	fflush(stdin);
	respuestaScanF = scanf("%f",&bufferFloat);
	while(respuestaScanF != 1 && reintentos > 0)
	{
		reintentos--;
		printf("%s",mensajeError);
		fflush(stdin);
		respuestaScanF = scanf("%f",&bufferFloat);
	}
	if(respuestaScanF != 0)
	{
		*pResultado = bufferFloat;
		retorno = 0;
	}
	else
	{
		printf("%s",mensajeReintentos);
	}
	return retorno;
}

int sumarFloat(float operadorA, float operadorB,float *resultado)
{
	*resultado = operadorA + operadorB;
	return 0;
}

int restarFloat(float operadorA, float operadorB,float *resultado)
{
	*resultado = operadorA - operadorB;
	return 0;
}

int multiplicarFloat(float operadorA, float operadorB,float *resultado)
{
	*resultado = operadorA * operadorB;
	return 0;
}

int dividirFloat(float operadorA, float operadorB,float *resultado)
{
	int retorno;
		if(operadorB != 0)
		{
			*resultado = operadorA / operadorB; // Se declara en la funcion con asterisco.
			retorno = 0;
		}
		else
		{
			retorno = -1;
		}
		return retorno;
}
