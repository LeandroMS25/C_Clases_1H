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
int getFloat(char *mensaje, char *mensajeError, char *mensajeReintentos,  int reintentos, float maximo, float minimo, float *pResultado);
int getInt(char *mensaje, char *mensajeError, char *mensajeReintentos,  int reintentos, int maximo, int minimo, int *pResultado);
int getChar(char *mensaje, char *mensajeError, char *mensajeReintentos, int reintentos, char maximo, char minimo, char *pResultado);

#endif /* UTN_H_ */
