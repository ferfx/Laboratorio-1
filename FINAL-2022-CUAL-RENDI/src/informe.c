#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "input.h"
#include "Pokemon.h"
#include "parser.h"
#include "informe.h"



void pokemon_mostrar(ePokemon* aux)
{
	int bufferNum;
	char bufferNombre[128];
	char bufferTipo[128];
	char bufferTamanio[128];
	char bufferAtaqueCargado[128];
	int bufferValorAtaque;
	int bufferEsVarioColor;
	char tipoVarioColor[2];



	if(aux!=NULL && !pkm_getNum(aux, &bufferNum)&&
		!pkm_getNombre(aux, bufferNombre)&&
		!pkm_getTipo(aux, bufferTipo)&&
		!pkm_getTamanio(aux, bufferTamanio)&&
		!pkm_getAtaqueCargado(aux,bufferAtaqueCargado)&&
		!pkm_getValorAtaque(aux,&bufferValorAtaque)&&
		!pkm_getEsVarioColor(aux,&bufferEsVarioColor)){

			pkm_getTipoVarioColor(bufferEsVarioColor,tipoVarioColor);
			printf("\n %-5d  %-15s  %-12s  %-5s  %-15s   %-15d   %-2s\n",bufferNum,bufferNombre,bufferTipo,bufferTamanio,bufferAtaqueCargado,bufferValorAtaque,tipoVarioColor);

	}

	else
	{
		printf("\nError\n");
	}

}
