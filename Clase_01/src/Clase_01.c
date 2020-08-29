/*
 ============================================================================
 Name        : Clase_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		setbuf(stdout,NULL);
		/*
	  	JS
	    var numero1; // let numero 1
	    var numero2; // let numero 2
	    var resultado;
	    */

	    /* C  TIPOS   int float char */
	    int numero1;
	    int numero2;
	    int resultado;
	    int respuestaScan;

	    /* JS
	    numero1 = parseInt(prompt("Numero 1? "));
	    numero2 = parseInt(prompt("Numero 2? "));
	    */

	    printf("Ingrese el numero 1: ");
	    fflush(stdin);
	    respuestaScan = scanf("%d", &numero1); /* C  TIPOS   int %d   -  float %f  - char %c */
	    printf("El resultado scanf es %d", respuestaScan);
	    while(respuestaScan == 0)
	    {
	        printf("Error - Reingrese numero 1 ");
	        fflush(stdin); // __fpurge(stdin)
	        respuestaScan = scanf("%d", &numero1);
	        printf("El resultado scanf es %d", respuestaScan);
	    }

	    printf("\nIngrese el numero 2: ");
	    fflush(stdin);
	    respuestaScan = scanf("%d", &numero2); /* C  TIPOS   int %d   -  float %f  - char %c */
	    printf("El resultado scanf es %d", respuestaScan);

	    resultado = numero1 + numero2;

	    /* Js
	    console.log("La suma es " + resultado);
	    */
	    printf("\nLa suma es %d", resultado);
	    return 0;
}
