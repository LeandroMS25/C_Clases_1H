/*
 * Alumno.c
 *
 *  Created on: 22 sept. 2020
 *      Author: leito
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#include "utn.h"

static int generarIdNuevo(void);
/**
 * \brief Realiza el alta de un alumno solo si el indice corresponde a un Empty.
 * \param Alumno* pArray, Es el puntero al array de alumnos.
 * \param int limite, es el limite de array.
 * \param int indice, es el indice donde se cargara el alumno.
 * \return (-1) Error / (0) Ok
 */
int alumno_alta(Alumno* pArray,int limite)
{
	int retorno = -1;
	Alumno auxiliarAlumno;
	int indice;

	if(pArray != NULL && limite > 0)
	{
		if(alumno_buscarLibre(pArray, limite, &indice) == 0 && indice < limite)
		{
			if( utn_getCadena(auxiliarAlumno.nombre, "Ingrese el nombre del alumno: ", "Nombre invalido.\n", 2, LONG_NOMBRE - 1) == 0 &&
				utn_getNumeroInt(&auxiliarAlumno.legajo, "Ingrese el legajo del alumno: ", "Legajo invalido.", 1, 1000, 2) == 0)
			{
				auxiliarAlumno.id = generarIdNuevo();
				auxiliarAlumno.isEmpty = 0;
				pArray[indice] = auxiliarAlumno;
				retorno = 0;
			}
			else
			{
				printf("Error al ingresar los datos.");
			}
		}
		else
		{
			printf("No hay espacios libres para dar de alta.");
		}
	}
	return retorno;
}
/**
 * \brief Modifica datos de un alumno si el indice no está vacio.
 * \param Alumno* pArray, Es el puntero al array de alumnos.
 * \param int limite, es el limite de array.
 * \param int indice, es el indice donde se cargara el alumno.
 * \return (-1) Error / (0) Ok
 */
int alumno_modificar(Alumno* pArray,int limite, int indice)
{
	int retorno = -1;
	Alumno auxiliarAlumno;

	if(pArray != NULL && limite > 0 && indice >= 0 && indice < limite && pArray[indice].isEmpty == 0)
	{
		if( utn_getCadena(auxiliarAlumno.nombre, "Ingrese el nombre del alumno: ", "Nombre invalido.\n", 2, LONG_NOMBRE - 1) == 0 &&
			utn_getNumeroInt(&auxiliarAlumno.legajo, "Ingrese el legajo del alumno: ", "Legajo invalido.", 1, 1000, 2) == 0)
		{
			auxiliarAlumno.id = pArray[indice].id;
			auxiliarAlumno.isEmpty = 0;
			pArray[indice] = auxiliarAlumno;
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief Modifica datos de un alumno si el indice no está vacio.
 * \param Alumno* pArray, Es el puntero al array de alumnos.
 * \param int limite, es el limite de array.
 * \param int indice, es el indice donde se cargara el alumno.
 * \return (-1) Error / (0) Ok
 */
int alumno_baja(Alumno* pArray,int limite, int indice)
{
	int retorno = -1;

	if(pArray != NULL && limite > 0 && indice >= 0 && indice < limite && pArray[indice].isEmpty == 0)
	{
		pArray[indice].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Imprime los alumnos cargados.
 * \param Alumno* pArray, Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int alumno_imprimirArray(Alumno* pArray, int limite)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && limite > 0)
	{
		for (i = 0; i < limite; i++)
		{
			if(pArray[i].isEmpty == 0)
			{
				printf("Id: %d - Nombre: %s - Legajo: %d.\n",pArray[i].id , pArray[i].nombre, pArray[i].legajo);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Inicializa el array de alumnos.
 * \param Alumno pArray, Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int alumno_init(Alumno* pArray, int limite)
{
	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0)
	{
		for (i = 0; i < limite; i++)
		{
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Busca un espacio libre en el array de alumnos.
 * \param Alumno pArrayAlumno, Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int alumno_buscarLibre(Alumno* pArray, int limite, int* pIndice)
{
	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0)
	{
		for (i = 0; i < limite; i++)
		{
			if(pArray[i].isEmpty == 1)
			{
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/*
 * \ brief - Ordena array de alumnos por nombre.
 * \ param - int array[], recibe el array a utilizar.
 * \ param - int lenghtArray, indica la longitud del array.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int alumno_ordenarPorNombre(Alumno* pArray, int limite)
{
	int retorno = -1;
	int i;
	Alumno aux;
	int flagArrayDesordenado = 1; // El array inicia desordenado.
	// 8 2 3 1 9 5 8 7 - Valores a utilizar
	if(pArray != NULL && limite > 0)
	{
		while(flagArrayDesordenado == 1) // Se itera hasta que se confirme que está ordenado.
		{
			flagArrayDesordenado = 0; // Se asume que ya está ordenado, pero si vuelve a entrar al for quiere decir que no lo está.
			for (i = 0; i < (limite - 1); i++)
			{
				if(strncmp(pArray[i].nombre, pArray[i+1].nombre,LONG_NOMBRE) > 0)
				{
					// Intercambiar (Swap)
					aux = pArray[i]; // 8 - Se guarda en el auxiliar para no perderlo.
					pArray[i] = pArray[i+1]; // 2 - Se guarda en el primer indice.
					pArray[i+1] = aux; // 8 - Se guarda el valor que se habia almacenado en el aux, en el segundo indice.
					flagArrayDesordenado = 1; // Se confirmo que estaba desordenado.
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Imprime un indice del array.
 * \param Alumno* pArray, Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int alumno_imprimirIndiceArray(Alumno* pArray, int limite, int indice)
{
	int retorno = -1;

	if(pArray != NULL && limite > 0)
	{
		if(pArray[indice].isEmpty == 0)
		{
			printf("Id: %d - Nombre: %s - Legajo: %d.\n",pArray[indice].id , pArray[indice].nombre, pArray[indice].legajo);
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Busca por id y retorna el espacio de memoria.
 * \param Alumno pArrayAlumno, Es el puntero al array de alumnos.
 * \param int limite, es el limite de array.
 * \param int id, id que será buscado.
 * \return Retorna el indice
 */
int alumno_buscarPorId(Alumno* pArray, int limite, int* pIndice, int id)
{
	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0 && id >= 0)
	{
		for (i = 0; i < limite; i++)
		{
			if(pArray[i].isEmpty == 0 && pArray[i].id == id)
			{
				*pIndice = i;
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
static int generarIdNuevo(void)
{
	static int id = 0;

	id++;
	return id;
}

