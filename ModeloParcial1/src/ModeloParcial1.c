/*
 ============================================================================
 Name        : ModeloParcial1.c
 Author      : Leandro Sobrino
 Description : Modelo de parcial Publicidad
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Screen.h"
#include "Contratacion.h"
#include "validaciones.h"

#define QTY_SCR 200
#define QTY_CON 200
#define OPTIONS 10

int main(void)
{
	setbuf(stdout,NULL);
	Screen listScreen[QTY_SCR];
	Contratacion listContratacion[QTY_CON];
	int opcion;

	scr_init(listScreen, QTY_SCR);
	con_init(listContratacion, QTY_CON);
	do
	{
		utn_getNumberInt(&opcion, "***Menu de opciones***\n\n"
								  "1- Alta de pantalla.\n"
								  "2- Modificar datos de la pantalla.\n"
								  "3- Baja de pantalla.\n"
								  "4- Alta de contratacion.\n"
								  "5- Modificar contratacion.\n"
								  "6- Eliminar contratacion.\n"
								  "7- Consulta de facturacion\n"
				 	 	 	 	  "8- Imprimir listado de contrataciones.\n"
								  "9- Imprimir listado de pantallas.\n"
								  "10- Salir.\n\n"
								  "Ingrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTIONS, 2);
		switch (opcion)
		{
			case 1:
				if(scr_add(listScreen, QTY_SCR) == 0)
				{
					printf("La pantalla se cargo correctamente.\n");
				}
				break;
			case 2:
				if(scr_modify(listScreen, QTY_SCR) == 0)
				{
					printf("La pantalla se modifico correctamente.\n");
				}
				break;
			case 3:
				if(scr_remove(listScreen, QTY_SCR) == 0)
				{
					printf("La pantalla se borro correctamente.\n");
				}
				break;
			case 4:
				if(con_add(listContratacion, QTY_CON, listScreen, QTY_SCR) == 0)
				{
					printf("La contratación fue realizada correctamente.\n");
				}
				break;
			case 5:
				if(con_modify(listContratacion, QTY_CON, listScreen, QTY_SCR) == 0)
				{
					printf("La contratación fue modificada correctamente.\n");
				}
				break;
			case 6:
				if(con_remove(listContratacion, QTY_CON, listScreen, QTY_SCR) == 0)
				{
					printf("La contratación fue elimanada correctamente.\n");
				}
				break;
			case 7:
				con_checkAmountToPay(listContratacion, QTY_CON,listScreen, QTY_SCR);
				break;
			case 8:
				con_print(listContratacion, QTY_CON,listScreen, QTY_SCR);
				break;
			case 9:
				scr_print(listScreen, QTY_SCR);
				break;
		}
	}while(opcion != OPTIONS);
}
