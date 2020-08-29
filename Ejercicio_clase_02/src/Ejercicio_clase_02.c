
#include <stdio.h>
#include <stdlib.h>
/*
Solicitar al usuario que ingrese una serie de números la cual finaliza al introducir el 999 (el 999 no debe ser tenido en cuenta para dicho cálculo).
 Una vez finalizado el ingreso de números el programa deberá mostrar el promedio de dichos números por pantalla.
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
		printf("Ingrese un número: ");
		scanf("%d", &numero);
		if (numero != 999)
		{
			acumulador += numero;
			contador++;
		}
	}
	promedio = (float)acumulador / contador;
	printf("\nEl promedio de los números ingresados es %.2f", promedio);

	return 0;
}
