
#include <stdio.h>
#include <stdlib.h>
/*
Solicitar al usuario que ingrese una serie de n�meros la cual finaliza al introducir el 999 (el 999 no debe ser tenido en cuenta para dicho c�lculo).
 Una vez finalizado el ingreso de n�meros el programa deber� mostrar el promedio de dichos n�meros por pantalla.
*/
int main(void)
{
	setbuf(stdout,NULL);
	int numero;
	int acumulador=0;
	int contador=0;
	float promedio;

	while(numero != 999)
	{
		printf("Ingrese un n�mero: ");
		scanf("%d", &numero);
		if (numero != 999)
		{
			acumulador += numero;
			contador++;
		}
	}
	promedio = (float)acumulador / contador;
	printf("\nEl promedio de los n�meros ingresados es %.2f", promedio);

	return 0;
}
