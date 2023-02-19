#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eParticipante.h"
#include "LinkedList.h"
#include "input.h"


void* participante_new(void)
{
	return (void*) malloc(sizeof(eParticipante));
}

eParticipante* participante_newParametrosTxt(char* id, char* nombre,char* edad, char* idDificultad, char* score){

	eParticipante* this = NULL;
	this = participante_new();
	if(this != NULL && id!=NULL && nombre!=NULL && edad!=NULL && idDificultad!=NULL && score!=NULL)
	{

			participante_setNombre(this, nombre);
			participante_setIdTxt(this, id);
			participante_setIdTipoTxt(this,  idDificultad);
			participante_setEdadTxt(this, edad);
			participante_setScoreTxt(this, score);

	}
	return this;
}

int participante_delete(eParticipante* this)

{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		free(this);
	}
	return retorno;
}

/////// GETTERS

int participante_getNombre(eParticipante* this, char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}
int participante_getId(eParticipante* this, int* id){

	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}
int participante_getIdDificultad(eParticipante* this, int* idDificultad){

	int retorno = -1;
	if(this != NULL && idDificultad != NULL)
	{
		*idDificultad = this->idDificultad;
		retorno = 0;
	}

	return retorno;
}
int participante_getIdTipoTxt(eParticipante* this, int idTipo, char* tipo){

	int retorno = -1;
	if(this != NULL && tipo != NULL)
	{
		retorno = 0;
		if(idTipo == 1)
		{
			strcpy(tipo, "FACIL");
		}
		else
		{
			if(idTipo == 2)
			{
				strcpy(tipo, "NORMAL");
			}
			else
				if(idTipo == 3)
			{
				strcpy(tipo, "DIFICIL");
			}
		}

	}

	return retorno;
}

int participante_getEdad(eParticipante* this, int* edad){

	int retorno = -1;
	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		retorno = 0;
	}

	return retorno;
}
int participante_getScore(eParticipante* this, int* score){

	int retorno = -1;
	if(this != NULL && score != NULL)
	{
		*score = this->score;
		retorno = 0;
	}

	return retorno;
}


//////////////////////////////////// FIN - GETTERS ////////////////
///////////////////////////////////////////////////////////////////


/////// SETTERS

int participante_setId(eParticipante* this, int id){

	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int participante_setIdTxt(eParticipante* this, char* id){

	int retorno = -1;

	if(this != NULL && id != NULL && esNumerica(id))
	{
		this->id = atoi(id);
		retorno = 0;
	}
	return retorno;
}
int participante_setEdad(eParticipante* this, int edad){

	int retorno = -1;
	if(this != NULL && edad > -1)
	{
		this->edad = edad;
		retorno = 0;
	}

	return retorno;
}

int participante_setEdadTxt(eParticipante* this, char* edad){

	int retorno = -1;
	if(this != NULL && edad != NULL && esFlotante(edad))
	{
		this->edad = atof(edad);
		retorno = 0;
	}

	return retorno;
}

int participante_setNombre(eParticipante* this, char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int participante_setIdTipoDificultad(eParticipante* this, int idTipo){

	int retorno = -1;

	if((this != NULL) && (idTipo == 1 || idTipo == 2 || idTipo == 3))
	{
		this->idDificultad = idTipo;
		retorno = 0;
	}
	return retorno;
}

int participante_setIdTipoTxt(eParticipante* this, char* idTipo){

	int retorno = -1;

	if(this != NULL && idTipo != NULL && esNumerica(idTipo))
	{
		this->idDificultad = atoi(idTipo);
		retorno = 0;
	}
	return retorno;
}

int participante_setScoreTxt(eParticipante* this, char* score){

	int retorno = -1;

	if(this != NULL && score != NULL && esNumerica(score))
	{
		this->score = atoi(score);
		retorno = 0;
	}
	return retorno;
}


////////////////////////////////// FIN - SETTERS ///////////////
////////////////////////////////////////////////////////////////


int participante_LeerArchivo(char* path , LinkedList* lista)
{
	int retorno = -1;
	int participantes;

	FILE* fpArchivo;
	if(path != NULL && lista != NULL)
	{

		fpArchivo = fopen(path, "r");
		if(fpArchivo != NULL)
		{

			participantes = parser_participanteFromText(fpArchivo,lista);
			printf("\nSe cargaron %d participantes", participantes);
			retorno = 0;
		}
		fclose(fpArchivo);

	}
	return retorno;
}

int parser_participanteFromText(FILE* pFile, LinkedList* lista){
	int retorno = -1;
	char bufferId[128];
	char bufferNombre[128];
	char bufferIdTipo[128];
	char bufferEdad[128];
	char bufferScore[128];

	char buffer[128];
	int contador = 0;
	eParticipante* aux;
	if(pFile != NULL && lista != NULL)
	{
		fscanf(pFile, "%[^\n]\n", buffer);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferEdad, bufferIdTipo, bufferScore) == 5)
			{
				aux = participante_newParametrosTxt(bufferId, bufferNombre, bufferEdad, bufferIdTipo, bufferScore);
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


///////////////////////////////////////////////////////////////////
///////////////////////////// 2 ///////////////////////////////////

int participante_ordenarLista(LinkedList* lista)
{
	int retorno = -1;
	if(lista != NULL)
	{
		if(!ll_sort(lista, participante_compararPorNombre, 0))
		{
			retorno = 0;
		}

	}
	return retorno;
}

int participante_compararPorNombre(void* e1, void* e2)
{
	int retorno = -2;
	eParticipante* p1;
	eParticipante* p2;
	char name1[100], name2[100];

	if(e1 != NULL &&  e2 != NULL)
	{
		p1 = (eParticipante*)e1;
		p2 = (eParticipante*)e2;
		participante_getNombre(p1, name1);
		participante_getNombre(p2, name2);

		if(stricmp(name1,name2)>0)
		{
			retorno = 1;
		}
		else
		{
			if(stricmp(name1,name2)<0)
			{
				retorno = -1;
			}
			else
			{
				retorno = 0;
			}
		}
	}
	return retorno;


}

/////////////////////////// 2 - FIN ///////////////////////////////
///////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////
//////////////////////////// 3 ////////////////////////////////////

int participante_imprimirPorPantalla(LinkedList* lista){
	int retorno = -1;
	eParticipante* aux;
	int len;
	int i;
	if(lista != NULL)
	{
		printf("\n");
		printf(" Id:     Nombre:           Edad:     idDificultad:     Score:");
		printf("\n");
		len = ll_len(lista);
		for(i=0;i<len;i++)
		{
			aux = ll_get(lista, i);
			if(aux != NULL)
			{
				participante_imprimirUno(aux);
			}
		}
		printf("\n");
		retorno = 0;
	}
	return retorno;
}

int participante_imprimirUno(eParticipante* this){

	int retorno = -1;
	int bufferEdad;
	char bufferNombre[128];
	char bufferTipo[128];
	int bufferScore;
	int bufferIdTipo;
	int bufferId;

	if(this != NULL)
	{
		participante_getId(this, &bufferId);
		participante_getNombre(this, bufferNombre);
		participante_getEdad(this, &bufferEdad);
		participante_getIdDificultad(this, &bufferIdTipo);
		participante_getIdTipoTxt(this, bufferIdTipo, bufferTipo);
		participante_getScore(this, &bufferScore);

		printf("\n %-5d   %-20s   %-10d   %-11s   %-5d  ", bufferId, bufferNombre ,bufferEdad, bufferTipo, bufferScore);
	}
	return retorno;
}

/////////////////////////////// 3 - Fin //////////////////////////////
//////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
////////////////////////////// 4 //////////////////////////////////////

LinkedList* participante_filtrar(LinkedList* lista)
{
	LinkedList* nuevaLista = NULL;
	int opcion;

	if(lista != NULL)
	{
		opcion=getInt("Ingrese dificultad a filtrar entre 1 - 2 - 3");
		while(opcion!=1 && opcion!=2 && opcion!=3)
			opcion=getInt("Ingrese dificultad a filtrar entre 1 - 2 - 3");

		switch(opcion){
		case 1:
			nuevaLista = ll_filter(lista,participante_filtrarPorDificultad);
			break;
		case 2:
			nuevaLista = ll_filter(lista,participante_filtrarPorDificultad2);
			break;
		case 3:
			nuevaLista = ll_filter(lista,participante_filtrarPorDificultad3);
			break;
		}


	}
	return nuevaLista;
}

int participante_filtrarPorDificultad(void* elemento)
{
	int retorno = -1;
	eParticipante* p = NULL;
	int dificultad;

	if(elemento != NULL)
	{
		p=(eParticipante*)elemento;
		if(p!=NULL){
		participante_getIdDificultad(p,&dificultad);
		if(dificultad==1)
			retorno=1;
		}
	}
	return retorno;
}

int participante_filtrarPorDificultad2(void* elemento)
{
	int retorno = -1;
	eParticipante* p = NULL;
	int dificultad;

	if(elemento != NULL)
	{
		p=(eParticipante*)elemento;
		if(p!=NULL){
		participante_getIdDificultad(p,&dificultad);
		if(dificultad==2)
			retorno=1;
		}
	}
	return retorno;
}

int participante_filtrarPorDificultad3(void* elemento)
{
	int retorno = -1;
	eParticipante* p = NULL;
	int dificultad;

	if(elemento != NULL)
	{
		p=(eParticipante*)elemento;
		if(p!=NULL){
		participante_getIdDificultad(p,&dificultad);
		if(dificultad==3)
			retorno=1;
		}
	}
	return retorno;
}

/////////////////////////////// 4 - Fin ////////////////////////////////
////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
///////////////////////////////// 5 ////////////////////////////////////

int participante_guardarEnArchivoTxt(char* path , LinkedList* lista)
{
	int retorno = -1;
	char bufferNombre[128];
	int bufferIdTipo;
	int bufferEdad;

	int bufferScore;
	int bufferId;

	int len, i;
	FILE* fpArchivo;
	eParticipante* aux;

	if(lista != NULL && path != NULL)
	{
		fpArchivo = fopen(path, "w");
		if(fpArchivo != NULL)
		{
			len = ll_len(lista);
			fprintf(fpArchivo, "id,nombre,edad,idTipo,score\n");
			for(i = 0; i < len; i++)
			{
				aux = (void*) ll_get(lista, i);
				if(aux != NULL)
				{
					if(!participante_getId(aux, &bufferId) &&
						!participante_getNombre(aux, bufferNombre) &&
						!participante_getEdad(aux, &bufferEdad) &&
						!participante_getIdDificultad(aux, &bufferIdTipo) &&
						!participante_getScore(aux, &bufferScore))

					{

						retorno = 0;
						fprintf(fpArchivo, "%d,%s,%d,%d,%d\n", bufferId, bufferNombre, bufferEdad, bufferIdTipo, bufferScore);
					}
				}
			}
		}
		fclose(fpArchivo);

	}
	return retorno;
}

