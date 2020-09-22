/*
 * Mascotas.h
 *
 *  Created on: 19 sept. 2020
 *      Author: leito
 */

#ifndef MASCOTAS_H_
#define MASCOTAS_H_

typedef struct Mascota
{
	char nombreMascotas[11];
	int edad;
	int isEmpty;
}Mascota;

int imprimirArrayMascotas(Mascota* pArray, int limite);

#endif /* MASCOTAS_H_ */
