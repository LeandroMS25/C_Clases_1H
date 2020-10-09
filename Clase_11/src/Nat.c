/*
 * nac.c
 *
 *  Created on: 29 sept. 2020
 *      Author: leito
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nat.h"
#include "validaciones.h"

static int generateNewId(void);
/**
 * \brief Inicializa el array .
 * \param Nationality list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int nat_init(Nationality* list, int len)
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
 * \brief Solicita los datos al usuario.
 * \param Nationality* auxNationality, Es el puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int nat_requestData(Nationality* auxNationality)
{
	int retorno = -1;
	Nationality aux;

	if(auxNationality != NULL)
	{
		if( utn_getString(aux.name, "Ingrese el nombre de la nacionalidad: ", "Nombre invalido.\n", 2, LONG_NAME - 1) == 0)
		{
			*auxNationality = aux;
			retorno = 0;
		}
		else
		{
			printf("Error al ingresar los datos.");
		}
	}
	return retorno;
}
/**
 * \brief Realiza el alta solo si el indice corresponde a un espacio vacio (isEmpty == 0)
 * \param Nationality* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param int id, indica el id del elemento.
 * \param char* name, indica el nombre del elemento.
 * \return (-1) Error / (0) Ok
 */
int nat_add(Nationality* list, int len, char* name)
{
	int retorno = -1;
	int index;

	if(list != NULL && len > 0 && name != NULL)
	{
		if(nat_searchFreePlace(list, len, &index) == 0 && index < len)
		{
			list[index].isEmpty = 0;
			list[index].id = generateNewId();
			strncpy(list[index].name, name, LONG_NAME);
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
 * \param Nationality* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param Nationality aux, recibe un dato del tipo Nationality.
 * \param int index, es el indice donde se cargara el elemento.
 * \param int field, indica el campo que se va a modificar.
 * \return (-1) Error / (0) Ok
 */
int nat_modify(Nationality* list, int len, Nationality aux, int index, int field)
{
	int retorno = -1;

	if(list != NULL && len > 0 && index >= 0 && list[index].isEmpty == 0)
	{
		if( field == 1 && utn_getString(aux.name, "Ingrese el nombre de la nacionalidad: ", "Nombre invalido.\n", 2, LONG_NAME - 1) == 0)
		{
			aux.id = list[index].id;
			aux.isEmpty = 0;
			list[index] = aux;
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief Busca el elemento por id y se guarda su indice en un puntero.
 * \param Nationality list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param int id, id que será buscado.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return Retorna el indice
 */
int nat_findById(Nationality* list, int len, int id, int* pIndex)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && id > 0 && pIndex != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == id)
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
 * \brief Modifica datos los datos si el indice no está vacio.
 * \param Nationality* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param int index, es el indice donde se cargara el elemento.
 * \return (-1) Error / (0) Ok
 */
int nat_remove(Nationality* list, int len, int index)
{
	int retorno = -1;

	if(list != NULL && len > 0 && index >= 0 && index < len && list[index].isEmpty == 0)
	{
		list[index].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}
/*
 * \ brief - Ordena el array por nombre.
 * \ param - Nationality* list, recibe el array a utilizar.
 * \ param - int len, indica la longitud del array.
 * \ param - int order, indica el orden de los elementos. 1 en caso de ascendente y 0 en caso de descendente.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int nat_sortByName(Nationality* list, int len, int order)
{
	int retorno = -1;
	int i;
	Nationality aux;
	int flagSwap = 1;
	if(list != NULL && len > 0)
	{
		while(flagSwap)
		{
			flagSwap = 0;
			for (i = 0; i < (len - 1); i++)
			{
				if(	(order == 1 &&
					strncmp(list[i].name, list[i+1].name,LONG_NAME) > 0) ||
					(order == 0 &&
					strncmp(list[i].name, list[i+1].name,LONG_NAME) < 0))

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
 * \param Nationality* list, Es el puntero al array
 * \param int len, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int nat_print(Nationality* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				printf( "Id: %d - Nombre: %s\n",list[i].id , list[i].name);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Ingresa datos hardcodeados al array.
 * \param Nationality* list, Es el puntero al array
 * \param int len, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int nat_hardcode(Nationality* list)
{
	int retorno = -1;

	if(list != NULL)
	{
		list[0] = (Nationality){1, "Argentina", 0};
 		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Busca un espacio libre en el array.
 * \param Nationality* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int nat_searchFreePlace(Nationality* list, int len, int* pIndex)
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
 * \param Nationality* list, Es el puntero al array.
 * \param int len, es el limite de array.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int nat_searchOccupiedPlace(Nationality* list, int len)
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
 * \brief Incrementa el id y lo retorna.
 * \return Retorna el id
 */
static int generateNewId(void)
{
	static int id = 0;

	id++;
	return id;
}
