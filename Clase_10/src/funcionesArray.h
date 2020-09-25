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
int imprimirArray(float* pArray, int limite);
int contarNumArray(int* pContador,int pArray[],int numero, int limite);
int sumarParesArray(int* pResultado,int pArray[], int arrayLength);
int contarCharArray(int* pContador,char pArray[],char caracter);

#endif /* FUNCIONESARRAY_H_ */
