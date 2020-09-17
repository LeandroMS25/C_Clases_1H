/*
 * utn.h
 *
 *  Created on: 8 sept. 2020
 *      Author: Leandro Sobrino
 */

#ifndef UTN_H_
#define UTN_H_

#define LEN_BUFFER_STRING 4096
int esUnNombreValido(char cadena[],int limite);
int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError, int reintentos, int limite);
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

#endif /* UTN_H_ */
