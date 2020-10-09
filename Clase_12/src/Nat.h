/*
 * nac.h
 *
 *  Created on: 29 sept. 2020
 *      Author: leito
 */

#ifndef NAT_H_
#define NAT_H_

#define LONG_NAME 51
typedef struct
{
	int id;
	char name[50];
	int isEmpty;
}Nationality;

int nat_init(Nationality* list, int len);
int nat_add(Nationality* list, int len);
int nat_remove(Nationality* list, int len);
int nat_modify(Nationality* list, int len);
int nat_print(Nationality* list, int len);
int nat_findById(Nationality* list, int len, int id, int* pIndex);
int nat_findFree(Nationality* list, int len, int* pIndex);
int nat_findOccupied(Nationality* list, int len);
int nat_sortByName(Nationality* list, int len, int order);
int nat_hardcode(Nationality* list);

#endif /* NAT_H_ */
