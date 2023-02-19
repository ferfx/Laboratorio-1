#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pokemon.h"
#include "LinkedList.h"
#include "input.h"
#include "parser.h"
#include "informe.h"


void* pokemon_new(void){
	return (void*) malloc(sizeof(ePokemon));
}

ePokemon* pokemon_newParametrosTxt(char* num, char* nom,char* tipo, char* tam, char* ataque, char* valorAtq, char* esVar){


	ePokemon* this = NULL;
	this = pokemon_new();
	if(this != NULL && num!=NULL && nom!=NULL && tipo!=NULL && tam!=NULL && ataque!=NULL)
	{

			pkm_setNumeroTxt(this,num);
			pkm_setNombreTxt(this,nom);
			pkm_setTipoTxt(this,tipo);
			pkm_setTamanioTxt(this,tam);
			pkm_setAtaqueTxt(this,ataque);
			pkm_setValorAtaqueTxt(this,valorAtq);
			pkm_setEsVarioColorTxt(this,esVar);

	}
	return this;
}

/////////////////////// SETTERS TXT ---------->


int pkm_setNumeroTxt(ePokemon* this, char* num){
	int retorno=-1;
	if(this!=NULL && num!=NULL && esNumerica(num)==1){
		this->numero=atoi(num);
		retorno=0;
	}
	return retorno;
}

int pkm_setNombreTxt(ePokemon* this, char* nombre){
	int retorno=-1;
	if(this!=NULL && nombre!=NULL){
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}

int pkm_setTipoTxt(ePokemon* this, char* tipo){
	int retorno=-1;
	if(this!=NULL && tipo!=NULL){
		strcpy(this->tipo,tipo);
		retorno=0;
	}
	return retorno;
}

int pkm_setTamanioTxt(ePokemon* this,char* tam){
	int retorno=-1;
	if(this!=NULL && tam!=NULL){
		strcpy(this->tamanio,tam);
		retorno=0;
	}
	return retorno;
}

int pkm_setAtaqueTxt(ePokemon* this, char* ataque){
	int retorno=-1;
	if(this!=NULL && ataque!=NULL){
		strcpy(this->ataqueCargado,ataque);
		retorno=0;
	}
	return retorno;
}

int pkm_setValorAtaqueTxt(ePokemon* this, char* num){
	int retorno=-1;
	if(this!=NULL && num!=NULL && esNumerica(num)==1){
		this->valorAtaque=atoi(num);
		retorno=0;
	}
	return retorno;
}

int pkm_setEsVarioColorTxt(ePokemon* this, char* num){
	int retorno=-1;
	if(this!=NULL && num!=NULL && esNumerica(num)==1){
		this->esVariocolor=atoi(num);
		retorno=0;
	}
	return retorno;
}


////////////// GETTERS ----------------->

int pkm_getNum(ePokemon* this,int* id){
	int retorno=-1;
	if(this!=NULL){
		*id=this->numero;
		retorno=0;
	}
	return retorno;
}

int pkm_getNombre(ePokemon* this, char* id){
	int retorno=-1;
	if(this!=NULL){
		strcpy(id,this->nombre);
		retorno=0;
	}
	return retorno;
}

int pkm_getTipo(ePokemon* this, char* palabra){
	int retorno=-1;
	if(this!=NULL){
		strcpy(palabra,this->tipo);
		retorno=0;
	}
	return retorno;
}

int pkm_getTamanio(ePokemon* this, char* n){
	int retorno=-1;
	if(this!=NULL){
		strcpy(n,this->tamanio);
		retorno=0;
	}
	return retorno;
}

int pkm_getAtaqueCargado(ePokemon* this, char* palabra){
	int retorno=-1;
	if(this!=NULL){
		strcpy(palabra,this->ataqueCargado);
		retorno=0;
	}
	return retorno;
}

int pkm_getValorAtaque(ePokemon* this, int* n){
	int retorno=-1;
	if(this!=NULL){
		*n=this->valorAtaque;
		retorno=0;
	}
	return retorno;
}

int pkm_getEsVarioColor(ePokemon* this, int* n){
	int retorno=-1;
	if(this!=NULL){
		*n=this->esVariocolor;
		retorno=0;
	}
	return retorno;
}


void pkm_getTipoVarioColor(int id, char* palabra){
	if(id==1)
		strcpy(palabra,"SI");
	else
		if(id==0)
			strcpy(palabra,"NO");
}

////////////////////////////////////////////////////////////////// FIN - GETTERS / SETTERS
///

int pokemon_bajaPokemon(LinkedList* lista)
{
    ePokemon* aux;
    int retorno=-1;
    int idBuscado;
    int validarId;

    if(lista!=NULL)
    {
        validarId=getInt("\nINGRESE EL NUMERO DEL POKEMON A ELIMINAR:\n");
        while(validarId<1||validarId>150)
        	validarId=getInt("\nINGRESE UN NUMERO VALIDO:\n");


        idBuscado=pokemon_buscarNum(lista,validarId);
        if(idBuscado != -1)
        {
            aux=(ePokemon*)ll_get(lista,idBuscado);
            if(aux!=NULL)
            {
                ll_remove(lista,idBuscado);
                printf("EL POKEMON ELIMINADO FUE:\n");
                printf("Numero:    Nombre:    Tipo:    Tamanio:    AtaqueCargado:    ValorAtaque:    EsVarioColor:\n");
                pokemon_mostrar(aux);
                retorno=0;
            }
        }
        else
        {
            printf("NO SE ENCONTRO EL POKEMON\n");
        }

    }
    return retorno;
}


int pokemon_buscarNum(LinkedList* lista,int id)
{
    ePokemon* aux;
    int retorno=-1;
    int limite;
    int i;
    int numero;

    if(lista!=NULL)
    {
        limite=ll_len(lista);

        for(i=0; i<limite; i++)//1
        {
            aux=(ePokemon*)ll_get(lista,i);
            pkm_getNum(aux,&numero);
            if(numero==id)
            {
            	retorno=i;
                break;
            }
        }
    }
    return retorno;
}


/////////////////////////////////////////////////////////////////

int filtrarPorAgua(void* elemento){
	int retorno=0;
	ePokemon* aux;
	int id;
	char bufferTipo[20];

	aux=(ePokemon*) elemento;
	if(aux!=NULL){
		pkm_getTipo(aux,bufferTipo);
		pkm_getEsVarioColor(aux,&id);
		if(stricmp(bufferTipo,"Water")==0 && id==1){
			retorno=1;
		}
	}
	return retorno;
}

/////////////////////////////////////////////////////////////

int mapearPorDiaDespejado(void* elemento){
	int retorno=0;
	ePokemon* aux;
	char bufferTipo[128];
	int incremento;
	char incrementoTxt[20];
	int valor;

	aux=(ePokemon*)elemento;
	pkm_getTipo(aux,bufferTipo);

	if(stricmp(bufferTipo,"Fire")==0 || stricmp(bufferTipo,"Grass")==0 || stricmp(bufferTipo,"Ground")==0){
		pkm_getValorAtaque(aux,&valor);
		incremento=valor+valor*0.1;
		sprintf(incrementoTxt,"%d",incremento);
		if(!pkm_setValorAtaqueTxt(aux,incrementoTxt)){
			retorno=1;
		}
	}
	return retorno;
}

/////////////////////////////////////////////////////////////////////


int batalla_pokemon(LinkedList* lista){
	int retorno=-1;
	ePokemon* aux;
	int contador=0;
	int i,len;

	int valorAtaque;
	char tipo[20];
	char tam[10];
	char ataque[20];

	len=ll_len(lista);

	for (i=0;i<len;i++){

		aux=(ePokemon*)ll_get(lista,i);

		if(aux!=NULL&&
		!pkm_getValorAtaque(aux,&valorAtaque)&&
		!pkm_getTipo(aux,tipo)&&
		!pkm_getTamanio(aux,tam)&&
		!pkm_getAtaqueCargado(aux,ataque)){

			if(stricmp(tipo,"Fire")==0 && stricmp(tam,"XL")==0 && stricmp(ataque,"Lanzallamas")==0 && valorAtaque>80){
				contador++;

			}
			else
				if(stricmp(tipo,"Water")==0 && stricmp(tam,"L")==0 && stricmp(ataque,"Hidrobomba")==0 && valorAtaque>80){
					contador++;
				}

		}


	}

	if(contador>2)
		retorno=0;


	return retorno;
}





















/////////////////////////////////////////////////////////////////////

/*
 * int llamada_guardarEnArchivoTxt(char* path , LinkedList* lista){
	int retorno=1;
	char bufferNombre[128];
	int bufferIdTipo;
	char bufferSolucionado[128];

	int bufferNumCliente;
	int bufferId;

	int len, i;
	FILE* fpArchivo;
	eLlamada* aux;

	if(lista != NULL && path != NULL)
	{
		fpArchivo = fopen(path, "w");
		if(fpArchivo != NULL)
		{
			len=ll_len(lista);
			fprintf(fpArchivo, "id,fecha,N°cliente,Problema,solcionado\n");
			for(i = 0; i < len; i++)
			{
				aux = ll_get(lista, i);
				if(aux != NULL)
				{
					if(!llamada_getId(aux, &bufferId) &&
						!llamada_getFecha(aux, bufferNombre) &&
						!llamada_getNumCliente(aux, &bufferNumCliente) &&
						!llamada_getIdTipo(aux, &bufferIdTipo) &&
						!llamada_getSolucionado(aux, bufferSolucionado))

					{

						retorno = 0;
						fprintf(fpArchivo, "%d,%s,%d,%d,%s\n", bufferId, bufferNombre,bufferNumCliente, bufferIdTipo, bufferSolucionado);
					}
				}
			}
		}
		fclose(fpArchivo);

	}
	return retorno;
}*/






/*
 * ///////////// DELETE //////////
int computer_delete(eComputer* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		free(this);
	}
	return retorno;
}*/




