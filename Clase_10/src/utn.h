/*
 * utn.h
 *
 *  Created on: 8 sept. 2020
 *      Author: Leandro Sobrino
 */

#ifndef UTN_H_
#define UTN_H_

#define LEN_BUFFER_STRING 4096
int utn_getCadena(char *pResultado, char *mensaje, char *mensajeError, int reintentos, int limite);
int utn_getNumeroInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);
int initArrayFlotante(float* pArray, int longitud, float valorInicial);
int utn_mostrarMenu(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

#endif /* UTN_H_ */
