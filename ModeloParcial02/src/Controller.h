#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEnvio);
int controller_saveAsText(char* path , LinkedList* pArrayListEnvio);
int controller_imprimir(LinkedList* pArrayListEnvio);
int controller_calcularCosto(LinkedList* pArrayListEnvio);
int controller_generateFileZone(LinkedList* pArrayListEnvio);
LinkedList* controller_filtrarLista(LinkedList* pArrayListEnvio);


