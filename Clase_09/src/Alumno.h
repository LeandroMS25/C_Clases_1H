/*
 * Alumno.h
 *
 *  Created on: 22 sept. 2020
 *      Author: leito
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#define LONG_NOMBRE 50

typedef struct
{
	char nombre[LONG_NOMBRE];
	int legajo;
	int isEmpty;
}Alumno;

int alumno_imprimirArray(Alumno* pArray, int limite);
int alumno_alta(Alumno* pArray,int limite, int indice);
int alumno_modificar(Alumno* pArray,int limite, int indice);
int alumno_baja(Alumno* pArray,int limite, int indice);
int alumno_init(Alumno* pArray, int limite);
int alumno_buscarLibre(Alumno* pArray, int limite, int indice);
int alumno_ordenarPorNombre(Alumno* pArray, int limite);

#endif /* ALUMNO_H_ */
