/*
 ============================================================================
 Name        : Clase_12.c
 Author      : Leandro Sobrino
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nat.h"
#include "validaciones.h"

#define QTY_NAT 200
#define OPTIONS 6

int main(void)
{
	setbuf(stdout,NULL);
	Nationality listNationality[QTY_NAT];
	int opcion;

	nat_init(listNationality, QTY_NAT);
	nat_hardcode(listNationality);
	do
	{
		utn_getNumberInt(&opcion, "***Menu de opciones***\n\n"
								  "1- Alta de nacionalidad.\n"
								  "2- Imprimir el listado de nacionalidad.\n"
								  "3- Modificar datos de la nacionalidad.\n"
								  "4- Baja de nacionalidad.\n"
								  "5- Ordenar.\n"
								  "6- Salir.\n\n"
								  "Ingrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTIONS, 2);
		switch (opcion)
		{
			case 1:
				if(nat_add(listNationality, QTY_NAT) == 0)
				{
					printf("El empleado se cargo correctamente");
				}
				break;
			case 2:
				nat_print(listNationality, QTY_NAT);
				break;
			case 3:
				if(nat_modify(listNationality, QTY_NAT) == 0)
				{
					printf("El empleado se modifico correctamente");
				}
				break;
			case 4:
				if(nat_remove(listNationality, QTY_NAT) == 0)
				{
					printf("El empleado se borro correctamente");
				}
				break;
			case 5:
				nat_sortByName(listNationality, QTY_NAT, 1);
				break;
		}
	}while(opcion != OPTIONS);
}

