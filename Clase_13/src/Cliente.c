/*
 * Cliente.c
 * Author: Leandro Sobrino
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <limits.h>
#include "Cliente.h"
#include "validaciones.h"

static int generateNewId(void);
static Cliente* cli_newConParametros(int id, char* name, char* lastName, char* cuit);
static void cli_delete(Cliente* pCliente);
/**
 * \brief Crea un nuevo cliente.
 * \param int id, id del cliente.
 * \param char* name, Puntero al espacio de memoria.
 * \param char* lastName, Puntero al espacio de memoria.
 * \param char* cuit, Puntero al espacio de memoria.
 * \return devuelve un puntero al espacio de memoria del cliente.
 */
static Cliente* cli_newConParametros(int id, char* name, char* lastName, char* cuit)
{
	Cliente* pNewClient = NULL;
	if(id > 0 && name != NULL && lastName != NULL && cuit != NULL)
	{
		pNewClient = (Cliente*) malloc(sizeof(Cliente));
		if(pNewClient != NULL)
		{
			pNewClient->id = id;
			strncpy(pNewClient->name,name, sizeof(pNewClient->name));
			strncpy(pNewClient->lastName,lastName, sizeof(pNewClient->lastName));
			strncpy(pNewClient->cuit,cuit, sizeof(pNewClient->cuit));
		}
	}
	return pNewClient;
}
/**
 * \brief Borra un cliente (libera el espacio de memoria).
 * \param Cliente* pCliente, Es el puntero al espacio de memoria del cliente.
 */
static void cli_delete(Cliente* pCliente)
{
	if(pCliente!=NULL)
	{
		free(pCliente);
	}
}
/**
 * \brief Inicializa el array.
 * \param Cliente* list[], Es el puntero al array.
 * \param int len, es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int cli_init(Cliente* list[], int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i] = NULL;
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Realiza el alta solo si el indice corresponde a un espacio vacio (isEmpty == 0).
 * \param Cliente* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param int id, indica el id del elemento.
 * \return (-1) Error / (0) Ok
 */
int cli_add(Cliente* list[], int len)
{
	int retorno = -1;
	int index;
	Cliente buffer;

	if(list != NULL && len > 0)
	{
		if(cli_findFree(list, len, &index) == 0)
		{
			if( index < len &&
				utn_getName(buffer.name, "Ingrese el nombre del cliente: ", "Nombre invalido.\n", 2, LONG_NAME - 1) == 0 &&
				utn_getName(buffer.lastName, "Ingrese el apellido del cliente: ", "Apellido invalido.\n", 2, LONG_NAME - 1) == 0 &&
				utn_getCuit(buffer.cuit, "Ingrese el cuit del cliente: ", "Cuit invalido.\n", 2, LONG_CUIT - 1) == 0)
			{
				buffer.id = generateNewId();
				list[index] = cli_newConParametros(buffer.id, buffer.name, buffer.lastName, buffer.cuit);
				cli_showClient(list[index]);
				retorno = 0;
			}
		}
		else
		{
			printf("No hay espacios libres.\n");
		}
	}
	return retorno;
}
/**
 * \brief Modifica datos si el indice no está vacio.
 * \param Cliente* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param Cliente aux, recibe un dato del tipo Cliente.
 * \param int index, es el indice donde se cargara el elemento.
 * \return (-1) Error / (0) Ok
 */
int cli_modify(Cliente* list[], int len)
{
	int retorno = -1;
	Cliente buffer;
	int idModify;
	int indexModify;

	if(list != NULL && len > 0)
	{
		cli_print(list, len);
		if( utn_getNumberInt(&idModify, "Ingrese el ID del cliente que desea modificar: ", "ID invalido.\n", 1, INT_MAX, 2) == 0 &&
			cli_findById(list, len, idModify, &indexModify) == 0 &&
			utn_getName(buffer.name, "Ingrese el nombre del cliente: ", "Nombre invalido.\n", 2, LONG_NAME - 1) == 0 &&
			utn_getName(buffer.lastName, "Ingrese el apellido del cliente: ", "Apellido invalido.\n", 2, LONG_NAME - 1) == 0 &&
			utn_getCuit(buffer.cuit, "Ingrese el cuit del cliente: ", "Cuit invalido.\n", 2, LONG_CUIT - 1) == 0)
		{
			buffer.id = list[indexModify]->id;
			list[indexModify] = cli_newConParametros(buffer.id, buffer.name, buffer.lastName, buffer.cuit);
			retorno = 0;
		}
		else
		{
			printf("El id seleccionado no existe.");
		}

	}
	return retorno;
}
/**
 * \brief Busca el elemento por id y se guarda su indice en un puntero.
 * \param Cliente list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param int id, es el limite de array.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return Retorna el indice
 */
int cli_findById(Cliente* list[], int len, int id, int* pIndex)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && pIndex != NULL && id > 0)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i] != NULL && list[i]->id == id)
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
 * \param Cliente* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param int id, es el id del elemento que se borrara.
 * \return (-1) Error / (0) Ok
 */
int cli_remove(Cliente* list[], int len, int id)
{
	int retorno = -1;
	int indexRemove;

	if(list != NULL && len > 0 && id >= 0)
	{
		if(cli_findById(list, len, id, &indexRemove) == 0)
		{
			cli_delete(list[indexRemove]);
			list[indexRemove] = NULL;
			retorno = 0;
		}
	}
	return retorno;
}
/*
 * \ brief - Ordena el array por nombre.
 * \ param - Cliente* list, recibe el array a utilizar.
 * \ param - int len, indica la longitud del array.
 * \ param - int order, indica el orden de los elementos. 1 en caso de ascendente y 0 en caso de descendente.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int cli_sortByName(Cliente* list[], int len, int order)
{
	int retorno = -1;
	int i;
	Cliente* aux;
	int flagSwap = 1;
	if(list != NULL && len > 0 && order >= 0 && order <= 1)
	{
		while(flagSwap)
		{
			flagSwap = 0;
			for (i = 0; i < (len - 1); i++)
			{
				if(	list[i] != NULL && list[i+1] != NULL && ((order == 1 &&
					strncmp(list[i]->name, list[i+1]->name,LONG_NAME) > 0)
						||
					(order == 0 &&
					strncmp(list[i]->name, list[i+1]->name,LONG_NAME) < 0)))
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
 * \param Cliente* list[], Es el puntero al array
 * \param int len, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int cli_print(Cliente* list[], int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			cli_showClient(list[i]);
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Busca un espacio libre en el array.
 * \param Cliente* list[], Es el puntero al array.
 * \param int len, es el limite de array.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int cli_findFree(Cliente* list[], int len, int* pIndex)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && pIndex!= NULL)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i] == NULL)
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
 * \param Cliente* list[], Es el puntero al array.
 * \param int len, es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int cli_findBusy(Cliente* list[], int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i] != NULL)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Muestra un cliente.
 * \param Cliente* pCliente, Es el puntero al cliente.
 * \param int index, indice del puntero al array.
 * \return (-1) Error / (0) Ok
 */
int cli_showClient(Cliente* pCliente)
{
    int retorno = -1;

    if(pCliente != NULL)
    {
		printf("ID del cliente: %d - Nombre: %s - Apellido: %s - Cuit: %s.\n",
				pCliente->id, pCliente->name, pCliente->lastName, pCliente->cuit);
		retorno = 0;
    }
    return retorno;
}
/**
 * \brief Realiza un alta forzada de un elemento.
 * \param Cliente* list, Es el puntero al array.
 * \param int len, es el limite de array
 * \param char* name, Puntero al espacio de memoria.
 * \param char* lastName, Puntero al espacio de memoria.
 * \param char* cuit, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int cli_altaForzada(Cliente* list[], int len, char* name, char* lastName, char* cuit)
{
    int retorno = -1;
    int index;
    Cliente* newClient;

    if(list != NULL && len > 0 && name != NULL && lastName != NULL && cuit != NULL)
    {
		if(cli_findFree(list, len, &index) == 0)
		{
			newClient = cli_newConParametros(generateNewId(), name, lastName, cuit);
			list[index] = newClient;
			retorno = 0;
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
