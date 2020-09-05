/*
 * utn.h
 *
 *  Created on: 3 sept. 2020
 *      Author: leito
 */

#ifndef UTN_H_
#define UTN_H_

int sumarFloat(float operadorA, float operadorB,float *pResultado);
int restarFloat(float operadorA, float operadorB,float *pResultado);
int multiplicarFloat(float operadorA, float operadorB,float *pResultado);
int dividirFloat(float operadorA, float operadorB,float *pResultado);
int getFloat(float *pResultado, char *mensaje, char *mensajeError, char *mensajeReintentos, float minimo, float maximo, int reintentos);
int getInt(int *pResultado, char *mensaje, char *mensajeError, char *mensajeReintentos, int minimo, int maximo, int reintentos);
int getChar(char *pResultado, char *mensaje, char *mensajeError, char *mensajeReintentos, char minimo, char maximo, int reintentos);

#endif /* UTN_H_ */
