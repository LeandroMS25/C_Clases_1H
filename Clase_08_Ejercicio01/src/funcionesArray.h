/*
 * funcionesArray.h
 *
 *  Created on: 8 sept. 2020
 *      Author: Leandro Sobrino
 */

#ifndef FUNCIONESARRAY_H_
#define FUNCIONESARRAY_H_

int calcularMaxIntArray(int* pResultado, int pArray[], int lengthArray);
int calcularMinIntArray(int* pResultado, int pArray[], int lengthArray);
float promediarArrayInt(float* pResultado, int pArray[], int lengthArray);
void ordenarArray(int array[], int arrayLength);
int imprimirArray(int array[], int limite);
int contadorNumArray(int* pContador,int pArray[],int numero, int arrayLength);
int sumarParesArray(int* pResultado,int pArray[], int arrayLength);

#endif /* FUNCIONESARRAY_H_ */
