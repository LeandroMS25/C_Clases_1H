/*
 * Envio.c
 * Author: Leandro Sobrino
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "validaciones.h"
#include "LinkedList.h"
#include "Envio.h"

typedef struct
{
	char nombre[SIZE_STR];
}Zona;

static int zona_getZonaDestino(Zona* this,char* nombre);
static int zona_setZonaDestino(Zona* this,char* nombre);
static void zona_generarLista(LinkedList* pArrayZona, LinkedList* pArrayEnvio);
static int zona_estaEnMiLista(LinkedList* pArrayZona, char* zonaNombre);
/**
 * \brief Crea un nuevo envío.
 * \return devuelve un puntero al espacio de memoria del cliente.
 */
Envio* envio_new(void)
{
	return (Envio*)malloc(sizeof(Envio));
}
/**
 * \brief Crea un nuevo envío.
 * \param char* idEnvio, id del producto.
 * \param char* nombreProducto, recibe el nombre del producto.
 * \param char* idCamion, id del camion.
 * \param char* zonaDestino, recibe la zona de destino del producto.
 * \param char* kmRecorridos, recibe lo km del envio.
 * \param char* tipoEntrega, recibe el tipo de entrega del envío.
 * \return devuelve un puntero al espacio de memoria del cliente.
 */
Envio* envio_newParam(char* idEnvio, char* nombreProducto, char* idCamion, char* zonaDestino, char* kmRecorridos, char* tipoEntrega)
{
	Envio* this = envio_new();
	if( this != NULL && idEnvio != NULL && nombreProducto != NULL && idCamion != NULL && zonaDestino != NULL &&
		kmRecorridos != NULL && tipoEntrega != NULL && isNumberInt(idEnvio, INT_MAX) && isNumberInt(idCamion, INT_MAX) &&
		isNumberInt(kmRecorridos, INT_MAX) && isNumberInt(tipoEntrega, INT_MAX) )
	{
		if(envio_allSets(this, atoi(idEnvio), atoi(idCamion), nombreProducto, zonaDestino, atoi(kmRecorridos), atoi(tipoEntrega), 0) == 0)
		{
			return this;
		}
	}
	return this;
}
/*
 * \brief Borra un envio (libera el espacio de memoria).
 * \param Envio* this, Es el puntero al espacio de memoria del envio.
 */
void envio_delete(Envio* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}
/**
 * \brief Lee el id del envio.
 * \param Envio* this, Es el puntero al array.
 * \param int* idEnvio, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_getIdProducto(Envio* this,int* idEnvio)
{
	int retorno = -1;

	if(this != NULL)
    {
        *idEnvio = this->idEnvio;
        retorno = 0;
    }
	return retorno;
}
/**
 * \brief Escribe el id del envio.
 * \param Envio* this, Es el puntero al array.
 * \param int idEnvio, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_setIdProducto(Envio* this,int idEnvio)
{
    int retorno = -1;

    if(this != NULL && idEnvio > 0)
    {
        this->idEnvio = idEnvio;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Lee un id de camion.
 * \param Envio* this, Es el puntero al array.
 * \param int* idCamion, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_getIdCamion(Envio* this,int* idCamion)
{
	int retorno = -1;

	if(this != NULL)
    {
        *idCamion = this->idCamion;
        retorno = 0;
    }
	return retorno;
}
/**
 * \brief Escribe un id de camion.
 * \param Envio* this, Es el puntero al array.
 * \param int idCamion, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_setIdCamion(Envio* this,int idCamion)
{
    int retorno = -1;

    if(this != NULL && idCamion > 0)
    {
        this->idCamion = idCamion;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Escribe un nombre de producto.
 * \param Envio* this, Es el puntero al array.
 * \param char* nombreProducto, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_setNombreProducto(Envio* this,char* nombreProducto)
{
    int retorno = -1;

    if(this != NULL && nombreProducto != NULL && isName(nombreProducto, SIZE_STR) == 1)
    {
        strncpy(this->nombreProducto,nombreProducto,sizeof(this->nombreProducto));
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Lee un nombre de producto.
 * \param Envio* this, Es el puntero al array.
 * \param char* nombreProducto, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_getNombreProducto(Envio* this,char* nombreProducto)
{
	int retorno = -1;

	if(this != NULL)
    {
        strncpy(nombreProducto, this->nombreProducto,(int)sizeof(this->nombreProducto));
        retorno = 0;
    }
	return retorno;
}
/**
 * \brief Escribe la zona de destino.
 * \param Envio* this, Es el puntero al array.
 * \param char* zonaDestino, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_setZonaDestino(Envio* this,char* zonaDestino)
{
    int retorno = -1;

    if(this != NULL && zonaDestino != NULL && isName(zonaDestino, SIZE_STR) == 1)
    {
        strncpy(this->zonaDestino,zonaDestino,sizeof(this->zonaDestino));
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Lee la zona de destino.
 * \param Envio* this, Es el puntero al array.
 * \param char* zonaDestino, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_getZonaDestino(Envio* this,char* zonaDestino)
{
	int retorno = -1;

	if(this != NULL)
    {
        strncpy(zonaDestino, this->zonaDestino,(int)sizeof(this->zonaDestino));
        retorno = 0;
    }
	return retorno;
}
/**
 * \brief Lee los km recorridos.
 * \param Envio* this, Es el puntero al array.
 * \param int kmRecorridos, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_setKmRecorridos(Envio* this,int kmRecorridos)
{
	int retorno = -1;

    if(this != NULL && kmRecorridos > 0)
    {
        this->kmRecorridos = kmRecorridos;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Escribe los km recorridos.
 * \param Envio* this, Es el puntero al array.
 * \param int* kmRecorridos, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_getKmRecorridos(Envio* this,int* kmRecorridos)
{
	int retorno = -1;

	if(this != NULL)
    {
        *kmRecorridos = this->kmRecorridos;
        retorno = 0;
    }
	return retorno;
}
/**
 * \brief Lee el tipo de entrega.
 * \param Envio* this, Es el puntero al array.
 * \param int tipoEntrega, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_setTipoEntrega(Envio* this,int tipoEntrega)
{
	int retorno = -1;

    if(this != NULL && tipoEntrega > 0)
    {
        this->tipoEntrega = tipoEntrega;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Escribe el tipo de entrega.
 * \param Envio* this, Es el puntero al array.
 * \param int* tipoEntrega, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_getTipoEntrega(Envio* this,int* tipoEntrega)
{
	int retorno = -1;

	if(this != NULL)
    {
        *tipoEntrega = this->tipoEntrega;
        retorno = 0;
    }
	return retorno;
}
/**
 * \brief Lee el costo de envío.
 * \param Envio* this, Es el puntero al array.
 * \param int tipoEntrega, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_setCostoEnvio(Envio* this,int costoEnvio)
{
	int retorno = -1;

    if(this != NULL && costoEnvio >= 0)
    {
        this->costoEnvio = costoEnvio;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Escribe el costo de envío.
 * \param Envio* this, Es el puntero al array.
 * \param int* tipoEntrega, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_getCostoEnvio(Envio* this,int* costoEnvio)
{
	int retorno = -1;

	if(this != NULL)
    {
        *costoEnvio = this->costoEnvio;
        retorno = 0;
    }
	return retorno;
}
/**
 * \brief Escribe los datos recibidos.
 * \param Envio* this, Es el puntero al array.
 * \param int idEnvio, recibe el id.
 * \param int idCamion, recibe el id.
 * \param char* nombreProducto, recibe un nombre.
 * \param char* zonaDestino, recibe la zona de destino.
 * \param int kmRecorridos, recibe los km recorridos.
 * \param int tipoEntrega, recibe el tipo de entrega.
 * \return (-1) Error / (0) Ok
 */
int envio_allSets(Envio* this, int idEnvio, int idCamion, char* nombreProducto, char* zonaDestino, int kmRecorridos, int tipoEntrega, int costoEnvio)
{
	int retorno = -1;

	if(this != NULL)
	{
		envio_setIdProducto(this, idEnvio);
		envio_setIdCamion(this, idCamion);
		envio_setNombreProducto(this, nombreProducto);
		envio_setKmRecorridos(this, kmRecorridos);
		envio_setZonaDestino(this, zonaDestino);
		envio_setTipoEntrega(this, tipoEntrega);
		envio_setCostoEnvio(this, costoEnvio);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Lee los datos.
 * \param Envio* this, Es el puntero al array.
 * \param int* idEnvio, Puntero al espacio de memoria.
 * \param int* idCamion, Puntero al espacio de memoria.
 * \param char* nombreProducto, Puntero al espacio de memoria.
 * \param char* zonaDestino, Puntero al espacio de memoria.
 * \param int* kmRecorridos, Puntero al espacio de memoria.
 * \param int* tipoEntrega, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int envio_allGets(Envio* this, int* idEnvio, int* idCamion, char* nombreProducto, char* zonaDestino, int* kmRecorridos, int* tipoEntrega, int* costoEnvio)
{
	int retorno = -1;

	if(this != NULL)
	{
		envio_getIdProducto(this, idEnvio);
		envio_getIdCamion(this, idCamion);
		envio_getNombreProducto(this, nombreProducto);
		envio_getKmRecorridos(this, kmRecorridos);
		envio_getZonaDestino(this, zonaDestino);
		envio_getTipoEntrega(this, tipoEntrega);
		envio_getCostoEnvio(this, costoEnvio);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Busca el elemento por id y se guarda su indice en un puntero.
 * \param LinkedList* pArrayListEmployee, Es el puntero al array.
 * \param int idEnvio, recibe el id del producto.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return Retorna el indice
 */
int envio_findByIdProducto(LinkedList* pArrayListEnvio, int idEnvio, int* pIndex)
{
	int retorno = -1;
	int i;
	int auxId;
	int len;
	Envio* auxEnvio = envio_new();

	len = ll_len(pArrayListEnvio);
	if (pArrayListEnvio != NULL && pIndex != NULL && idEnvio > 0)
	{
		for (i = 0; i < len; i++)
		{
			auxEnvio = ll_get(pArrayListEnvio, i);
			if(auxEnvio != NULL && !(envio_getIdProducto(auxEnvio, &auxId)) && auxId == idEnvio)
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
 * \brief Encuentra el id maximo de la linkedlist.
 * \param LinkedList* pArrayListEmployee, Es el puntero al array.
 * \param int* pMaxId, puntero al espacio de memmoria donde se encuentra el id maximo.
 * \return (-1) Error / (0) Ok
 */
int envio_findMaxIdProducto(LinkedList* pArrayListEnvio, int* pMaxId)
{
	int retorno = -1;
	Envio* auxEnvio = envio_new();
	int len = ll_len(pArrayListEnvio);
	int bufferId;
	int i;

	if(pArrayListEnvio != NULL && pMaxId != NULL && auxEnvio != NULL)
	{
		for (i = 0; i < len; i++)
		{
			auxEnvio = ll_get(pArrayListEnvio, i);
			envio_getIdProducto(auxEnvio, &bufferId);
			if(i == 0 || bufferId >= *pMaxId)
			{
				*pMaxId = bufferId+1;
			}
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief Incrementa el id y lo retorna.
 * \return Retorna el id
 */
int envio_generateNewId(void)
{
	static int id = 0;

	id++;
	return id;
}
/**
 * \brief Función criterio para imprimir cada elemento de la lista.
 * \param void* pElement, Es el puntero al elemento.
 * \return (-1) Error / (0) Ok
 */
void envio_imprimir(void* pElement)
{
	int bufferIdProducto;
	int bufferIdCamion;
	int bufferKmRecorridos;
	int bufferTipoEntrega;
	int bufferCosto;
	char tipoEntrega[SIZE_STR];
	char bufferNombreProducto[SIZE_STR];
	char bufferZonaDestino[SIZE_STR];
	Envio* auxEnvio = (Envio*)pElement;
	if(envio_allGets(auxEnvio, &bufferIdProducto, &bufferIdCamion, bufferNombreProducto,
			bufferZonaDestino, &bufferKmRecorridos, &bufferTipoEntrega, & bufferCosto) == 0)
	{
		if(bufferTipoEntrega == 0)
		{
			snprintf(tipoEntrega,SIZE_STR,"NORMAL");
		}
		else
		{
			if(bufferTipoEntrega == 1)
			{
				snprintf(tipoEntrega,SIZE_STR,"EXPRESS");
			}
			else
			{
				snprintf(tipoEntrega,SIZE_STR,"SEGUN DISPONIBILIDAD");
			}
		}
		printf("ID Producto: %-3d | Producto: %-10s | ID Camion: %-1d | Destino: %-10s | Kms: %-3d | Tipo entrega: %-20s | Costo: %d\n",
				bufferIdProducto,bufferNombreProducto,bufferIdCamion,bufferZonaDestino,bufferKmRecorridos,tipoEntrega, bufferCosto);
	}
}

void envio_calcularCostoCriterio(void* pElement)
{
	Envio* auxEnvio = (Envio*)pElement;
	int costoVariable;
	int costoFijo;
	int km;
	int tipoEntrega;
	int total;

	if(envio_getKmRecorridos(auxEnvio, &km) == 0)
	{
		if(km < 50)
		{
			costoVariable = km * 150;
		}
		else
		{
			costoVariable = km * 100;
		}
	}
	if(envio_getTipoEntrega(auxEnvio, &tipoEntrega) == 0)
	{
		if(tipoEntrega == 0)
		{
			costoFijo = 350;
		}
		else
		{
			if(tipoEntrega == 1)
			{
				costoFijo = 420;
			}
			else
			{
				costoFijo = 275;
			}
		}
	}
	total = costoFijo + costoVariable;
	envio_setCostoEnvio(auxEnvio, total);
}

int envio_filtrarZona(void* thisA, char* zona)
{
	int retorno = -1;
	Envio* auxEnvio = thisA;
	char bufferZona[SIZE_STR];

	if(thisA != NULL && envio_getZonaDestino(auxEnvio, bufferZona) == 0 && strncmp(bufferZona, zona, SIZE_STR) != 0)
	{
		retorno = 1;
	}
	return retorno;
}
/**
 * \brief Crea una nuevo zona.
 * \return devuelve un puntero al espacio de memoria.
 */
Zona* zona_new(void)
{
	return (Zona*)malloc(sizeof(Zona));
}
/**
 * \brief Crea una nueva zona.
 * \param char* nombre, nombre de la zona.
 * \return devuelve un puntero al espacio de memoria.
 */
Zona* zona_newParam(char* nombre)
{
	Zona* this = zona_new();

	if(this != NULL && nombre != NULL && zona_setZonaDestino(this, nombre) == 0)
	{
		return this;
	}
	return this;
}
/**
 * \brief Escribe la zona de destino.
 * \param Envio* this, Es el puntero al array.
 * \param char* nombre, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
static int zona_setZonaDestino(Zona* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL && isName(nombre, SIZE_STR) == 1)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Lee la zona de destino.
 * \param Envio* this, Es el puntero al array.
 * \param char* nombre, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
static int zona_getZonaDestino(Zona* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL)
    {
        strncpy(nombre, this->nombre,(int)sizeof(this->nombre));
        retorno = 0;
    }
	return retorno;
}
/**
 * \brief Genera la lista de zonas
 * \param LinkedList* pArrayZona, Es el puntero al array.
 * \param LinkedList* pArrayEnvio, Es el puntero al array.
 */
static void zona_generarLista(LinkedList* pArrayZona, LinkedList* pArrayEnvio)
{
	char zona[SIZE_STR];

	if(pArrayZona != NULL && pArrayEnvio != NULL)
	{
		for (int i = 0; i < ll_len(pArrayEnvio); i++)
		{
			envio_getZonaDestino(ll_get(pArrayEnvio, i), zona);
			if(zona_estaEnMiLista(pArrayZona, zona) != 1)
			{
				ll_add(pArrayZona, zona_newParam(zona));
			}
		}
	}
}
/**
 * \brief Se chequea si la zona comparada ya se encuentra en la lista de zonas.
 * \param LinkedList* pArrayZona, Es el puntero al array.
 * \param int zonaNombre, es el limite de array.
 * \return (1) Ya esta en la lista / (0) No esta en la lista
 */
static int zona_estaEnMiLista(LinkedList* pArrayZona, char* zonaNombre)
{
	int retorno = 0;
	Zona* auxZona;
	char nombreZona[SIZE_STR];

	if(pArrayZona != NULL && zonaNombre != NULL)
	{
		for (int i = 0;  i < ll_len(pArrayZona); i++)
		{
			auxZona = ll_get(pArrayZona, i);
			zona_getZonaDestino(auxZona, nombreZona);
			if(strncmp(nombreZona,zonaNombre,SIZE_STR) == 0)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

void zona_imprimir(LinkedList* pArrayEnvio)
{
	LinkedList* listaZonas = ll_newLinkedList();
	char nombre[SIZE_STR];
	Zona* auxZona;

	if(pArrayEnvio != NULL)
	{
		zona_generarLista(listaZonas, pArrayEnvio);
		for (int i = 0; i < ll_len(listaZonas); i++)
		{
			auxZona = ll_get(listaZonas, i);
			if(zona_getZonaDestino(auxZona, nombre) == 0)
			{
				printf("%s\n",nombre);
			}
		}
	}
}
