/*
 ============================================================================
 Name        : Clase_14.c
 Author      : Leandro Sobrino
 Description : Archivos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[8];
	int edad;
}Empleado;

int main(void)
{
	setbuf(stdout,NULL);

	// char variable[50] = "Puto el que lee";
	// int numeros[4]={12,115,32,65};
	// Empleado empleado1;
	char cadena[50] = "Leandro 9";

	// empleado1.edad = 20;
	// strncpy(empleado1.name,"Juan",8);

	// fprintf(); - fscanf(); - SOLO TEXTO.

	FILE* fp = fopen("archivo.programacion","w");
	if(fp != NULL)
	{
		printf("%s",cadena);
		fprintf(fp,"%s",cadena);
		fclose(fp);
	}

	/* // fwrite(); - fread(); - Variables: BINARIO SEGUNDA PRUEBA
	FILE* fp = fopen("archivo.programacion","rb");
	if(fp != NULL)
	{
		// fread();
		// fscanf();
		fread(&empleado1,sizeof(empleado1),1,fp);

		printf("Datos escritos.\n");
		printf("Empleado edad: %d y nombre: %s.\n",empleado1.edad,empleado1.name);

		fclose(fp);
	}
	*/


	/* PRIMERA PRUEBA
	FILE* fp = fopen("archivo.programacion","w");
	if(fp != NULL)
	{
		// uso de funciones para leer y escribir
		// ...
		// fprintf(); escribo archivo
		// fwrite(); escribo archivo
		// fwrite(variable,sizeof(variable),1,fp);
		// fwrite(numeros,sizeof(numeros),5,fp);
		fwrite(&empleado1,sizeof(empleado1),1,fp);
		fclose(fp);
	}
	*/
}
