#include <stdio.h>
#include <stdlib.h>
#include "Envio.h"
#include "LinkedList.h"

/** \brief Parsea los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int parser_envioFromText(FILE* pFile , LinkedList* pArrayListEnvio)
{
	int retorno = -1;
	Envio* auxEnvio;
	int r;
	char var1[4096], var2[4096], var3[4096], var4[4096], var5[4096], var6[4096];

	if(pFile != NULL && pArrayListEnvio != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
		do
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
			auxEnvio = envio_newParam(var1, var2, var3, var4, var5, var6);
			if(auxEnvio != NULL)
			{
				if(r == 6)
				{
					ll_add(pArrayListEnvio, auxEnvio);
					retorno = 0;
				}
				else
				{
					envio_delete(auxEnvio);
				}
			}
			else
			{
				printf("Envio NULL");
			}
		}while(!feof(pFile));
	}
    return retorno;
}
