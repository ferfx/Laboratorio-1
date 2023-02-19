#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Llamada.h"
#include "LinkedList.h"
#include "parser.h"




int parser_llamadaFromText(FILE* pFile, LinkedList* lista){
	int retorno = -1;
	char bufferId[128];
	char bufferFecha[128];
	char bufferNumCliente[128];
	char bufferIdDos[128];
	char bufferSolucionado[128];

	char buffer[128];
	int contador = 0;
	eLlamada* aux;
	if(pFile != NULL && lista != NULL)
	{
		fscanf(pFile, "%[^\n]\n", buffer);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferFecha, bufferNumCliente, bufferIdDos, bufferSolucionado) == 5)
			{
				aux = llamada_newParametrosTxt(bufferId, bufferFecha, bufferNumCliente, bufferIdDos, bufferSolucionado);
				if(aux != NULL)
				{
					if(!ll_add(lista, aux))
					{
						contador++;
					}
				}
			}

		}while(!feof(pFile));
	}
	retorno = contador;
	return retorno;
}
