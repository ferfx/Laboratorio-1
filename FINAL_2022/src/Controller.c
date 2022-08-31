#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "input.h"
#include "Pokemon.h"
#include "parser.h"
#include "informe.h"
//

int controller_loadFromText(char* path , LinkedList* lista)
{
	int retorno = -1;
	int cantPokemon;

	FILE* pArchivo = NULL;

	if(lista != NULL && path != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			cantPokemon=parser_pokemonFromText(pArchivo, lista);
			printf("\nCarga exitosa\n");
			printf("\nSe cargaron %d Pokemones\n",cantPokemon);
			retorno = 0;
		}
		else
		{
			printf("\nError con la carga\n");
		}

		fclose(pArchivo);
	}

	return retorno;
}


int controller_List(LinkedList* lista)
{
	int retorno = -1;
	int i;
	ePokemon* aux = NULL;
	int tam;

	printf("\n===================================================================================================\n");
	printf("Numero:    Nombre:    Tipo:    Tamanio:    AtaqueCargado:    ValorAtaque:    EsVarioColor:\n");
	printf("===================================================================================================\n");
	if(lista != NULL)
	{
		tam = ll_len(lista);

		for(i=0;i<tam;i++)
		{
			aux = (ePokemon*)ll_get(lista, i);
			pokemon_mostrar(aux);

		}
	}
	else
	{
		printf("\nError\n");
	}


	return retorno;
}



int controller_eliminarPokemon(LinkedList* lista)
{
    int retorno=-1;

    if(lista!=NULL)
    {
        if(pokemon_bajaPokemon(lista)==0)
        {
            retorno=0;
        }
        else
        {
            printf("ERROR, NO SE PUDO ELIMINAR EL POKEMON!\n");
        }
    }

    return retorno;
}
