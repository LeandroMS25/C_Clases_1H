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

int nat_requestData(Nationality* auxNationality);
int nat_init(Nationality* list, int len);
int nat_add(Nationality* list, int len, char* name);
int nat_findById(Nationality* list, int len, int id, int* pIndex);
int nat_remove(Nationality* list, int len, int id);
int nat_sortByName(Nationality* list, int len, int order);
int nat_modify(Nationality* list, int len, Nationality aux, int index, int field);
int nat_print(Nationality* list, int len);
int nat_searchFreePlace(Nationality* list, int len, int* pIndex);
int nat_searchOccupiedPlace(Nationality* list, int len);
int nat_hardcode(Nationality* list);

#endif /* NAT_H_ */
