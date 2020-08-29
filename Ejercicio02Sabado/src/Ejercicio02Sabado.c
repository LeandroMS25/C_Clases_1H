/*
 ============================================================================
 Name        : Ejercicio02Sabado.c
 Author      : Leandro
 Description : Ejercicio 02:
Al ejercicio anterior :
Ademas de la edad ingresar el estado civil de la persona ( 's' para soltera , 'c' para casada, 'd' divorciada)
ademas de informar lo anterior ....informar:
la persona mas joven de las casadas
la persona mas Vieja de las solteras
de los estados civiles , cual fue el mas ingresado
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int edad;
	int flagJovenCasado=0;
	int edadJovenCasado;
	int flagViejoSoltero=0;
	int edadViejoCasado;
	int contadorSolteros=0;
	int contadorCasados=0;
	int contadorDivorciados=0;
	char estadoCivil;
	char respuesta;

	do
	{
		setbuf(stdout,NULL);
		printf("Ingrese una edad: ");
		scanf("%d",&edad);
		printf("Ingrese el estado civil:\n(s para soltero - c para casado - d para divorciado): ");
		fflush(stdin);
		scanf("%c",&estadoCivil);
		switch (estadoCivil)
		{
			case 'c':
				contadorCasados++;
				if(flagJovenCasado == 0 || edad<edadJovenCasado)
				{
					edadJovenCasado = edad;
					flagJovenCasado = 1;
				}
				break;
			case 'd':
				contadorDivorciados++;
				break;
			case 's':
				contadorSolteros++;
				if(flagViejoSoltero == 0 || edad>edadViejoCasado)
				{
					edadViejoCasado = edad;
					flagViejoSoltero = 1;
				}
				break;
		}
		printf("¿Desea ingresar otra edad? s/n: ");
		fflush(stdin);
		scanf("%c",&respuesta);
	}while(respuesta == 's');

	printf("\nLa persona mas joven casada tiene %d años",edadJovenCasado);
	printf("\nLa persona mas vieja soltera tiene %d años",edadViejoCasado);
	if(contadorCasados>contadorSolteros && contadorCasados>contadorDivorciados)
	{
		printf("\nEl estado civil mas ingresado es: Casados");
	}
	else
	{
		if(contadorDivorciados>contadorSolteros)
		{
			printf("\nEl estado civil mas ingresado es: Divorciados");
		}
		else
		{
			printf("\nEl estado civil mas ingresado es: Solteros");
		}
	}
}
