/*
 * menu.h
 * Author: Leandro Sobrino
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Envio.h"
#include "validaciones.h"
#include "menu.h"
#include "LinkedList.h"
/**
 * \brief	Muestra el menu principal.
 * \param	int* pOption, puntero a un espacio de memoria.
 * \return	Retorna 0 (exito)y -1 (error).
 */
int utn_showMenu(int* pOption, LinkedList* pArrayListEnvio)
{
	int retorno = -1;
	int option;

	if(pOption != NULL)
	{
		if(utn_getNumberInt(&option, "***Menu de opciones***\n\n"
									 "1- Cargar los datos de los envios desde el archivo data.csv (modo texto).\n"
									 "2- Imprimir lista de envios.\n"
									 "3- Calcular costos de envíos.\n"
									 "4- Generar archivos de costos por zonas.\n"
									 "5- Imprimir lista de zonas.\n"
									 "6- Salir.\n\n"
									 "Ingrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTIONS, 2) == 0 &&
		ll_isEmpty(pArrayListEnvio) && option > 1 && option < OPTIONS)
		{
			printf("Primero se debe cargar la lista.\n");
		}
		else
		{
			if(ll_isEmpty(pArrayListEnvio) == 0 && option == 1)
			{
				printf("La lista ya fue cargada.\n");
			}
			else
			{
				*pOption = option;
				retorno = 0;
			}
		}
	}
	return retorno;
}
