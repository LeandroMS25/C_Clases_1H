/*
 * Envio.h
 * Author: Leandro Sobrino
 */

#ifndef ENVIO_H_
#define ENVIO_H_
#define SIZE_STR 4096
#include "LinkedList.h"

typedef struct
{
	int idEnvio;
	char nombreProducto[SIZE_STR];
	int idCamion;
	char zonaDestino[SIZE_STR];
	int kmRecorridos;
	int tipoEntrega;
	int costoEnvio;
}Envio;

Envio* envio_new(void);
Envio* envio_newParam(char* idEnvio, char* nombreProducto, char* idCamion, char* zonaDestino, char* kmRecorridos, char* tipoEntrega);
int envio_generateNewId(void);
void envio_delete(Envio* this);
int envio_setIdProducto(Envio* this, int idEnvio);
int envio_setNombreProducto(Envio* this, char* nombreProducto);
int envio_setIdCamion(Envio* this, int idCamion);
int envio_setZonaDestino(Envio* this, char* zonaDestino);
int envio_setKmRecorridos(Envio* this, int kmRecorridos);
int envio_setTipoEntrega(Envio* this, int tipoEntrega);
int envio_getIdProducto(Envio* this, int* idEnvio);
int envio_getNombreProducto(Envio* this, char* nombreProducto);
int envio_getIdCamion(Envio* this, int* idCamion);
int envio_getZonaDestino(Envio* this, char* kmRecorridos);
int envio_getKmRecorridos(Envio* this, int* kmRecorridos);
int envio_getTipoEntrega(Envio* this, int* tipoEntrega);
int envio_allSets(Envio* this, int idEnvio, int idCamion, char* nombreProducto, char* zonaDestino, int kmRecorridos, int tipoEntrega, int costoEnvio);
int envio_allGets(Envio* this, int* idEnvio, int* idCamion, char* nombreProducto, char* zonaDestino, int* kmRecorridos, int* tipoEntrega, int* costoEnvio);
int envio_findByIdProducto(LinkedList* pArrayListEnvio, int id, int* pIndex);
int envio_findMaxIdProducto(LinkedList* pArrayListEnvio, int* pMaxId);
void envio_imprimir(void* pElement);
void envio_calcularCostoCriterio(void* pElement);
int envio_filtrarZona(void* thisA, char* zona);
void zona_imprimir(LinkedList* pArrayEnvio);

#endif /* ENVIO_H_ */
