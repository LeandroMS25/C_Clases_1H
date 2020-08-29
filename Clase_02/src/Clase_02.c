#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
Ingresar 5 numeros enteros y pedir maximos y minimos.
*/
int main(void)
{
	setbuf(stdout,NULL);
	int maximo = INT_MIN;
	int minimo = INT_MAX;
	int i;
	int numero;
	// int flag = 1;
	for (i = 0; i < 5; ++i)
	{
		printf("Ingrese el numero %d: ", i+1);
		scanf("%d", &numero);
		if(numero > maximo) // if(flag == 1 || numero > maximo) - Tambien se puede usando i == 0.
		{
			maximo = numero;
		}
		if(numero < minimo) // if(flag == 1 || numero < minimo) - Tambien se puede usando i == 0.
		{
			minimo = numero;
		} // flag = 0;
	}
	printf("\nEl número máximo es %d y el mínimo es %d.", maximo, minimo);
}
