/*
 * utn.h
 *
 *  Created on: 8 sept. 2020
 *      Author: leito
 */

#ifndef UTN_H_
#define UTN_H_

int getInt(int *pResultado, char *mensaje, char *mensajeError, int reintentos, int minimo, int maximo);
int getFloat(float *pResultado, char *mensaje, char *mensajeError, float reintentos, float minimo, int maximo);
int getChar(char *pResultado, char *mensaje, char *mensajeError, char reintentos, char minimo, int maximo);

#endif /* UTN_H_ */
