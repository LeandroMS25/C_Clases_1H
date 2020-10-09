/*
 * Contrataciones.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <limits.h>
#include "Contratacion.h"
#include "validaciones.h"
#include "Screen.h"

static int generateNewId(void);
/**
 * \brief Inicializa el array .
 * \param Contratacion list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int con_init(Contratacion* list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Realiza el alta solo si el indice corresponde a un espacio vacio (isEmpty == 0)
 * \param Contratacion* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param Screen* listScreen, Es el puntero al array.
 * \param int lenScreen, es el limite de array.
 * \param int id, indica el id del elemento.
 * \return (-1) Error / (0) Ok
 */
int con_add(Contratacion* list, int len, Screen* listScreen, int lenScreen)
{
	int retorno = -1;
	int index;
	int idScreen;
	int indexScreen;
	Contratacion buffer;

	if(list != NULL && len > 0 && listScreen != NULL && lenScreen  > 0)
	{
		scr_print(listScreen, lenScreen);
		if( utn_getNumberInt(&idScreen, "Ingrese el id de la pantalla donde se quiere publicar: ", "\nError.", 1, INT_MAX, 2) == 0 &&
			scr_findById(listScreen, lenScreen, idScreen, &indexScreen) == 0 &&
			con_findFree(list, len, &index) == 0 && index < len &&
			utn_getString(buffer.nombreVideo, "Ingrese el nombre del video: ", "Nombre invalido.\n", 2, LONG_NAME - 1) == 0 &&
			utn_getNumberInt(&buffer.cantDias, "Ingrese la cantidad de días: ", "Cantidad invalida.\n", 0, QTY_DAYS, 2) == 0 &&
			utn_getCuit(buffer.cuitCliente, "Ingrese el cuit del cliente: ", "Cuit invalido.\n", 2, LONG_CUIT - 1) == 0)
		{
			buffer.isEmpty = 0;
			buffer.idContratacion = generateNewId();
			list[index] = buffer;
			list[index].idScreen = listScreen[indexScreen].id;
			retorno = 0;
		}
		else
		{
			printf("No hay espacios libres para dar de alta.");
		}
	}
	return retorno;
}
/**
 * \brief Modifica datos si el indice no está vacio.
 * \param Contratacion* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param Screen* listScreen, Es el puntero al array.
 * \param int lenScreen, es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int con_modify(Contratacion* list, int len, Screen* listScreen, int lenScreen)
{
	int retorno = -1;
	Contratacion buffer;
	int idModify;
	int indexModify;
	int cantDias;

	if(list != NULL && len > 0 && listScreen != NULL && lenScreen  > 0)
	{
		if( utn_getCuit(buffer.cuitCliente, "Ingrese el cuit del cliente: ", "Cuit invalido.\n", 2, LONG_CUIT - 1) == 0 &&
			con_printByCuit(list, len, buffer.cuitCliente) == 0 &&
			utn_getNumberInt(&idModify, "Ingrese el id de la publicidad que quiere modificar: ", "\nError.", 1, INT_MAX, 2) == 0 &&
			con_findById(list, len, idModify, &indexModify) == 0 &&
			utn_getNumberInt(&cantDias, "Ingrese la cantidad de días que desea mostrar la publicidad: ", "\nCantidad invalida.", 1, QTY_DAYS, 2) == 0)
		{
			list[indexModify].cantDias = cantDias;
			retorno = 0;
		}
		else
		{
			printf("El id ingresado no pertenece a una contratacion.\n");
		}
	}
	return retorno;
}
/**
 * \brief Busca el elemento por id y se guarda su indice en un puntero.
 * \param Contratacion list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param int id, es el limite de array.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return Retorna el indice
 */
int con_findById(Contratacion* list, int len, int id, int* pIndex)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && pIndex != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].idContratacion == id)
			{
				*pIndex = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Elimina el elemento que de encuentra en el indice recibido.
 * \param Contratacion* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param Screen* listScreen, Es el puntero al array.
 * \param int lenScreen, es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int con_remove(Contratacion* list, int len, Screen* listScreen, int lenScreen)
{
	int retorno = -1;
	Contratacion buffer;
	int idRemove;
	int indexRemove;

	if(list != NULL && len > 0 && listScreen != NULL && lenScreen  > 0)
	{
		if( utn_getCuit(buffer.cuitCliente, "Ingrese el cuit del cliente: ", "Cuit invalido.\n", 2, LONG_CUIT - 1) == 0 &&
			con_printByCuit(list, len, buffer.cuitCliente) == 0 &&
			utn_getNumberInt(&idRemove, "Ingrese el id de la publicidad que quiere modificar: ", "\nError.", 1, INT_MAX, 2) == 0 &&
			con_findById(list, len, idRemove, &indexRemove) == 0 )
		{
			list[indexRemove].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}
/*
 * \ brief - Ordena el array por nombre.
 * \ param - Contratacion* list, recibe el array a utilizar.
 * \ param - int len, indica la longitud del array.
 * \ param - int order, indica el orden de los elementos. 1 en caso de ascendente y 0 en caso de descendente.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int con_sortByName(Contratacion* list, int len, int order)
{
	int retorno = -1;
	int i;
	Contratacion aux;
	int flagSwap = 1;
	if(list != NULL && len > 0)
	{
		while(flagSwap)
		{
			flagSwap = 0;
			for (i = 0; i < (len - 1); i++)
			{
				if(	(order == 1 &&
					strncmp(list[i].nombreVideo, list[i+1].nombreVideo,LONG_NAME) > 0) ||
					(order == 0 &&
					strncmp(list[i].nombreVideo, list[i+1].nombreVideo,LONG_NAME) < 0))

				{
					aux = list[i];
					list[i] = list[i+1];
					list[i+1] = aux;
					flagSwap = 1;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Imprime los datos cargados.
 * \param Contratacion* list, Es el puntero al array
 * \param int len, es el limite de array
 * \param Screen* listScreen, Es el puntero al array.
 * \param int lenScreen, es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int con_print(Contratacion* list, int len, Screen* listScreen, int lenScreen)
{
	int retorno = -1;
	int auxIndex;
	int i;

	if(list != NULL && len > 0 && listScreen != NULL && lenScreen  > 0)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && scr_findById(listScreen, lenScreen, list[i].idScreen, &auxIndex) == 0)
			{
				printf( "Nombre de la pantalla: %s - Nombre del video: %s - Cantidad de dias: %d - Cuit del cliente: %s.\n"
						, listScreen[auxIndex].name, list[i].nombreVideo
						, list[i].cantDias, list[i].cuitCliente);
			}

		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Imprime los datos de un cliente.
 * \param Contratacion* list, Es el puntero al array
 * \param int len, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int con_printByCuit(Contratacion* list, int len, char* cuit)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && cuit != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if(strncmp(list[i].cuitCliente, cuit, LONG_CUIT) == 0)
			{
				printf( "Id: %d - Nombre del video: %s - Cantidad de dias: %d.\n",list[i].idContratacion, list[i].nombreVideo
						, list[i].cantDias);
				retorno = 0;
				break;
			}
			else
			{
				printf("El cuit ingresado no existe.\n");
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Busca un espacio libre en el array.
 * \param Contratacion* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int con_findFree(Contratacion* list, int len, int* pIndex)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && pIndex!= NULL)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				*pIndex = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Busca un espacio ocupado en el array.
 * \param Contratacion* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int con_findOccupied(Contratacion* list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Imprime los datos cargados.
 * \param Contratacion* list, Es el puntero al array
 * \param int len, es el limite de array
 * \param Screen* listScreen, Es el puntero al array.
 * \param int lenScreen, es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int con_checkAmountToPay(Contratacion* list, int len, Screen* listScreen, int lenScreen)
{
	int retorno = -1;
	char cuit[LONG_CUIT];
	int auxIndex;
	float importe;
	int i;

	if(list != NULL && len > 0 && listScreen != NULL && lenScreen  > 0)
	{
		for (i = 0; i < len; i++)
		{
			if( utn_getCuit(cuit, "Ingrese el cuit del cliente: ", "Cuit invalido.\n", 2, LONG_CUIT - 1) == 0 &&
				strncmp(list[i].cuitCliente, cuit, LONG_CUIT) == 0 &&
				scr_findById(listScreen, lenScreen, list[i].idScreen, &auxIndex) == 0)
			{
				importe = listScreen[auxIndex].price * (float)list[i].cantDias;
				printf( "Nombre del video: %s - Dias: %d - Valor por día: %.2f - Importe total: %.2f.\n",listScreen[auxIndex].name, list[i].cantDias
						, listScreen[i].price, importe);
				retorno = 0;
				break;
			}
			else
			{
				printf("El cuit ingresado no existe.\n");
				break;
			}
		}
	}
	return retorno;
}
int calculateContByClient(Contratacion* list, int len, cuit)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if(strncmp() == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Incrementa el id y lo retorna.
 * \return Retorna el id
 */
static int generateNewId(void)
{
	static int id = 0;

	id++;
	return id;
}
