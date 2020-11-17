/*
 * menu.h
 * Author: Leandro Sobrino
 */
#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Envio.h"
#include "LinkedList.h"
#include "menu.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;

    LinkedList* listaEnvios = ll_newLinkedList();
    do
    {
    	option = 0;
    	utn_showMenu(&option, listaEnvios);
        switch(option)
        {
            case 1:
                if(!(controller_loadFromText("data.csv",listaEnvios)))
				{
                	printf("Los datos se cargaron correctamente.\n");
				}
                break;
            case 2:
				if(!(controller_imprimir(listaEnvios)))
				{
					printf("Los datos se mostraton correctamente.\n");
				}
				break;
            case 3:
				if(!(controller_calcularCosto(listaEnvios)))
				{
					ll_map(listaEnvios, envio_imprimir);
					printf("Los datos se mostraton correctamente.\n");
				}
				break;
            case 4:
				if(!(controller_generateFileZone(listaEnvios)))
				{
					printf("Se genero el archivo.\n");
				}
				break;
            case 5:
            	zona_imprimir(listaEnvios);
            	break;
            case 6:
            	printf("Adios.\n");
            	break;
        }
    }while(option != OPTIONS);
    return 0;
}

