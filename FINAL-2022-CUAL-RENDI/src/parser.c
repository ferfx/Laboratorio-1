#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pokemon.h"
#include "LinkedList.h"
#include "parser.h"



int parser_pokemonFromText(FILE* pFile, LinkedList* lista){
	int retorno = -1;
		char bufferNumero[128];
		char bufferNombre[128];
		char bufferTipo[128];
		char bufferTamanio[128];
		char bufferAtaqueCargado[128];
		char bufferValorAtaque[128];
		char bufferEsVarioColor[128];

		char buffer[128];
		int contador = 0;
		ePokemon* aux;
		if(pFile != NULL && lista != NULL)
		{
			fscanf(pFile, "%[^\n]\n", buffer);
			do
			{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferNumero, bufferNombre, bufferTipo, bufferTamanio, bufferAtaqueCargado, bufferValorAtaque, bufferEsVarioColor) == 7)
				{
					aux = pokemon_newParametrosTxt(bufferNumero, bufferNombre, bufferTipo, bufferTamanio, bufferAtaqueCargado, bufferValorAtaque, bufferEsVarioColor);
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




/*

int parserFeo_pokemonFromText(FILE* pFile, LinkedList* lista){
		int retorno = -1;
		char bufferNumero[128];
		char bufferNombre[128];
		char bufferTipo[128];
		char bufferTamanio[128];
		char bufferAtaqueCargado[128];
		char bufferValorAtaque[128];
		char bufferEsVarioColor[128];

		char buffer[128];
		int contador = 0;
		ePokemon* aux;
		if(pFile != NULL && lista != NULL)
		{

			do
			{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n\n", bufferNumero, bufferNombre, bufferTipo, bufferTamanio, bufferAtaqueCargado, bufferValorAtaque, bufferEsVarioColor) == 7)
				{
					aux = pokemon_newParametrosTxt(bufferNumero, bufferNombre, bufferTipo, bufferTamanio, bufferAtaqueCargado, bufferValorAtaque, bufferEsVarioColor);
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


*/
