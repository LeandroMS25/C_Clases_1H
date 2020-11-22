#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Envio.h"
#include "LinkedList.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"
#define LEN_TEXT 4096

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param Char* path, archivo que va a ser leído.
 * \param LinkedList* pArrayListEnvio, recibe el array.
 * \return (-1) Error / (0) Ok
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEnvio)
{
	int retorno = -1;

	FILE* pFile;
	if(path != NULL && pArrayListEnvio != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL && !(parser_envioFromText(pFile, pArrayListEnvio)))
		{
			retorno = 0;
			fclose(pFile);
		}
		else
		{
			printf("No se pudo abrir el archivo.\n");
		}
	}
    return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param Char* path, archivo que va a ser escrito.
 * \param LinkedList* pArrayListEnvio, recibe el array.
 * \return (-1) Error / (0) Ok
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEnvio)
{
	int retorno = -1;
	Envio* auxEnvio;
	int len = ll_len(pArrayListEnvio);
	int i;
	int bufferIdEnvio;
	int bufferIdCamion;
	int bufferKmRecorridos;
	int bufferTipoEntrega;
	int bufferCosto;
	char bufferNombreProducto[SIZE_STR];
	char bufferZonaDestino[SIZE_STR];
	FILE* pFile;

	if(path != NULL && pArrayListEnvio != NULL && len > 0)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			fprintf(pFile, "%s,%s,%s,%s,%s,%s,%s\n","id_envio","nombre_producto","id_camion","zona_destino","km_recorridos","tipo_entrega","costo_envio");
			for (i = 0; i < len; i++)
			{
				auxEnvio = ll_get(pArrayListEnvio, i);
				if(!(envio_allGets(auxEnvio, &bufferIdEnvio, &bufferIdCamion, bufferNombreProducto, bufferZonaDestino, &bufferKmRecorridos, &bufferTipoEntrega, &bufferCosto)))
				{
					fprintf(pFile, "%d,%d,%s,%s,%d,%d,%d\n",bufferIdEnvio,bufferIdCamion,bufferNombreProducto,bufferZonaDestino,bufferKmRecorridos,bufferTipoEntrega, bufferCosto);
					retorno = 0;
				}
			}
		}
		else
		{
			printf("No se pudo abrir el archivo.\n");
		}
	}
	fclose(pFile);
	return retorno;
}

int controller_imprimir(LinkedList* pArrayListEnvio)
{
	int retorno = -1;

	if(pArrayListEnvio != NULL)
	{
		printf("     ID ENVIO    |       PRODUCTO       |  ID CAMION   |     ZONA DESTINO    |"
				"    KM    |            TIPO ENTREGA           \n");
		ll_map(pArrayListEnvio, envio_imprimir);
		retorno = 0;
	}
	return retorno;
}

int controller_calcularCosto(LinkedList* pArrayListEnvio)
{
	int retorno = -1;

	if(pArrayListEnvio != NULL)
	{
		ll_map(pArrayListEnvio, envio_calcularCostoCriterio);
		ll_map(pArrayListEnvio, envio_imprimir);
		retorno = 0;
	}
	return retorno;
}

int controller_generateFileZone(LinkedList* pArrayListEnvio)
{
	int retorno = -1;
	LinkedList* newList;
	char zona[SIZE_STR];

	if(pArrayListEnvio != NULL)
	{
		if( utn_getName(zona, "Ingrese el nombre de la zona: ", "Zona invalida.\n", 3, SIZE_STR - 1) == 0)
		{
			newList = ll_filter(pArrayListEnvio, envio_filtrarZona, zona);
			ll_map(newList, envio_imprimir);
			controller_saveAsText(zona, newList);
			retorno = 0;
		}
	}
	return retorno;
}

