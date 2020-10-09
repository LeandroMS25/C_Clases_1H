/*
 ============================================================================
 Name        : Clase_11.c
 Author      : Leandro Sobrino
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Nat.h"
#include "validaciones.h"

#define QTY_NAT 200
#define OPTIONS 6

int main(void)
{
	setbuf(stdout,NULL);
	Nationality listNationality[QTY_NAT];
	Nationality aux;
	int opcion;
	int idModificar;
	int idBaja;
	int indiceModificar;
	int indiceBaja;

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
				if(nat_requestData(&aux) == 0)
				{
					nat_add(listNationality, QTY_NAT, aux.name);
				}
				break;
			case 2:
				nat_print(listNationality, QTY_NAT);
				break;
			case 3:
				nat_print(listNationality, QTY_NAT);
				if( utn_getNumberInt(&idModificar, "\nIngrese el id de la nacionalidad que quiere modificar: ", "Error.\n", 1, INT_MAX, 2) == 0 &&
					nat_findById(listNationality, QTY_NAT, idModificar, &indiceModificar) == 0)
				{
					nat_modify(listNationality, QTY_NAT, aux, indiceModificar, 1);
				}
				break;
			case 4:
				nat_print(listNationality, QTY_NAT);
				if( utn_getNumberInt(&idBaja, "\nIngrese el id de la nacionalidad que quiere dar de baja: ", "Error.\n", 1, INT_MAX, 2) == 0 &&
					nat_findById(listNationality, QTY_NAT, idBaja, &indiceBaja) == 0)
				{
					nat_remove(listNationality, QTY_NAT, indiceBaja);
				}
				break;
			case 5:
				nat_sortByName(listNationality, QTY_NAT, 1);
				break;
		}
	}while(opcion != OPTIONS);
}
