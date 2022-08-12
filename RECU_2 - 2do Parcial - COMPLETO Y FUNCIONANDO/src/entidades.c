#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidades.h"
#include "LinkedList.h"
#include "input.h"


void* superHeroe_new(void)
{
	return (void*) malloc(sizeof(eSuperHeroe));
}

eSuperHeroe* superHeroe_newParametrosTxt(char* id, char* nombre,char* idD, char* power, char* ataque){

	eSuperHeroe* this = NULL;
	this = superHeroe_new();
	if(this != NULL && id!=NULL && nombre!=NULL && power!=NULL && idD!=NULL && ataque!=NULL)
	{

			superHeroe_setNombre(this, nombre);
			superHeroe_setIdTxt(this, id);
			superHeroe_setIdTipoTxt(this,  idD);
			superHeroe_setPowerTxt(this, power);
			superHeroe_setAtaqueTxt(this, ataque);

	}
	return this;
}

int superHeroe_delete(eSuperHeroe* this)

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

int superHeroe_getNombre(eSuperHeroe* this, char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}
int superHeroe_getId(eSuperHeroe* this, int* id){

	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}
int superHeroe_getIdPropietario(eSuperHeroe* this, int* id){

	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->idProp;
		retorno = 0;
	}

	return retorno;
}
int superHeroe_getIdTipoTxt(eSuperHeroe* this, int idTipo, char* tipo){

	int retorno = -1;
	if(this != NULL && tipo != NULL)
	{
		retorno = 0;
		if(idTipo == 1)
		{
			strcpy(tipo,"DC");
		}
		else
		{
			if(idTipo == 2)
			{
				strcpy(tipo,"MARVEL");
			}

		}

	}

	return retorno;
}

int superHeroe_getPower(eSuperHeroe* this, int* power){

	int retorno = -1;
	if(this != NULL && power != NULL)
	{
		*power = this->power;
		retorno = 0;
	}

	return retorno;
}
int superHeroe_getAtaque(eSuperHeroe* this, int* ataque){

	int retorno = -1;
	if(this != NULL && ataque != NULL)
	{
		*ataque = this->ataque;
		retorno = 0;
	}

	return retorno;
}


//////////////////////////////////// FIN - GETTERS ////////////////
///////////////////////////////////////////////////////////////////


/////// SETTERS

int superHeroe_setId(eSuperHeroe* this, int id){

	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int superHeroe_setIdTxt(eSuperHeroe* this, char* id){

	int retorno = -1;

	if(this != NULL && id != NULL && esNumerica(id))
	{
		this->id = atoi(id);
		retorno = 0;
	}
	return retorno;
}
int superHeroe_setPower(eSuperHeroe* this, int power){

	int retorno = -1;
	if(this != NULL && power > -1)
	{
		this->power = power;
		retorno = 0;
	}

	return retorno;
}

int superHeroe_setPowerTxt(eSuperHeroe* this, char* power){

	int retorno = -1;
	if(this != NULL && power != NULL && esNumerica(power))
	{
		this->power = atoi(power);
		retorno = 0;
	}

	return retorno;
}

int superHeroe_setNombre(eSuperHeroe* this, char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int superHeroe_setIdTipoPropietario(eSuperHeroe* this, int idTipo){

	int retorno = -1;

	if((this != NULL) && (idTipo == 1 || idTipo == 2 ))
	{
		this->idProp = idTipo;
		retorno = 0;
	}
	return retorno;
}

int superHeroe_setIdTipoTxt(eSuperHeroe* this, char* idTipo){

	int retorno = -1;

	if(this != NULL && idTipo != NULL && esNumerica(idTipo))
	{
		this->idProp = atoi(idTipo);
		retorno = 0;
	}
	return retorno;
}

int superHeroe_setAtaqueTxt(eSuperHeroe* this, char* ataque){

	int retorno = -1;

	if(this != NULL && ataque != NULL && esNumerica(ataque))
	{
		this->ataque = atoi(ataque);
		retorno = 0;
	}
	return retorno;
}

int superHeroe_setAtaque(eSuperHeroe* this, int ataque)
{
	int retorno = -1;

	if(this != NULL && ataque > -1)
	{
		this->ataque = ataque;
		retorno = 0;
	}
	return retorno;
}


////////////////////////////////// FIN - SETTERS ///////////////
////////////////////////////////////////////////////////////////


int superHeroe_LeerArchivo(char* path , LinkedList* lista)
{
	int retorno = -1;
	int participantes;

	FILE* fpArchivo;
	if(path != NULL && lista != NULL)
	{

		fpArchivo = fopen(path, "r");
		if(fpArchivo != NULL)
		{

			participantes = parser_superHeroeFromText(fpArchivo,lista);
			printf("\nSe cargaron %d participantes", participantes);
			retorno = 0;
		}
		fclose(fpArchivo);

	}
	return retorno;
}

int parser_superHeroeFromText(FILE* pFile, LinkedList* lista){
	int retorno = -1;
	char bufferId[128];
	char bufferNombre[128];
	char bufferIdTipo[128];
	char bufferPower[128];
	char bufferAtaque[128];

	char buffer[128];
	int contador = 0;
	eSuperHeroe* aux;
	if(pFile != NULL && lista != NULL)
	{
		fscanf(pFile, "%[^\n]\n", buffer);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferIdTipo, bufferPower, bufferAtaque) == 5)
			{
				aux = superHeroe_newParametrosTxt(bufferId, bufferNombre, bufferIdTipo, bufferPower, bufferAtaque);
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

int superHeroe_ordenarLista(LinkedList* lista)
{
	int retorno = -1;
	if(lista != NULL)
	{
		if(!ll_sort(lista, superHeroe_compararPorPower, 0))
		{
			retorno = 0;
		}

	}
	return retorno;
}

int superHeroe_compararPorPower(void* e1, void* e2)
{
	int retorno = -2;
	eSuperHeroe* p1;
	eSuperHeroe* p2;
	int power1,power2;

	if(e1 != NULL &&  e2 != NULL)
	{
		p1 = (eSuperHeroe*)e1;
		p2 = (eSuperHeroe*)e2;
		superHeroe_getPower(p1, &power1);
		superHeroe_getPower(p2, &power2);

		if(power1>power2)
		{
			retorno = 1;
		}
		else
		{
			if(power1<power2)
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

int superHeroe_imprimirPorPantalla(LinkedList* lista){
	int retorno = -1;
	eSuperHeroe* aux;
	int len;
	int i;
	if(lista != NULL)
	{
		printf("\n");
		printf(" Id:     Nombre:    IdPropietario:     Power:     Atque:");
		printf("\n");
		len = ll_len(lista);
		for(i=0;i<len;i++)
		{
			aux = ll_get(lista, i);
			if(aux != NULL)
			{
				superHeroe_imprimirUno(aux);
			}
		}
		printf("\n");
		retorno = 0;
	}
	return retorno;
}

int superHeroe_imprimirUno(eSuperHeroe* this){

	int retorno = -1;
	int bufferPower;
	char bufferNombre[128];
	char bufferTipo[128];
	int bufferAtaque;
	int bufferIdTipo;
	int bufferId;

	if(this != NULL)
	{
		superHeroe_getId(this, &bufferId);
		superHeroe_getNombre(this, bufferNombre);
		superHeroe_getPower(this, &bufferPower);
		superHeroe_getIdPropietario(this, &bufferIdTipo);
		superHeroe_getIdTipoTxt(this, bufferIdTipo, bufferTipo);
		superHeroe_getAtaque(this, &bufferAtaque);

		printf("\n %-5d   %-20s   %-7s   %-5d   %-5d  ", bufferId, bufferNombre ,bufferTipo, bufferPower, bufferAtaque);
	}
	return retorno;
}

/////////////////////////////// 3 - Fin //////////////////////////////
//////////////////////////////////////////////////////////////////////

/*
///////////////////////////////////////////////////////////////////////
////////////////////////////// 4 //////////////////////////////////////

--------------------- FUNCIONES PARA FILTER ---------------------

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


*/



////////////////////// 4 *********************
/*
 * Funcion para Devolver una LL llamando a LL_MAP

LinkedList* superHeroe_mapear(LinkedList* lista)
{
	LinkedList* nuevaLista = NULL;

	if(lista != NULL)
	{
		nuevaLista = ll_map(lista,superHeroe_mapearPorAtaque);
	}
	return nuevaLista;
}*/

int superHeroe_mapearPorAtaque(void* elemento)
{
	int retorno = -1;
	eSuperHeroe* s = NULL;
	int ataque;
	int power;
	int incremento;
	if(elemento != NULL)
	{
		s = (eSuperHeroe*) elemento;
		superHeroe_getAtaque(s, &ataque);
		superHeroe_getPower(s, &power);
		incremento = (power*0.1);

		if(!superHeroe_setAtaque(s, incremento))
		{
			retorno = 1;
		}
	}
	return retorno;
}

/////////////////// 4 -Fin *********************



//////////////////// 5 ***********************
int superHeroe_guardarEnArchivoTxt(char* path , LinkedList* lista)
{
	int retorno = -1;
	char bufferNombre[128];
	int bufferIdTipo;
	int bufferPower;

	int bufferAtaque;
	int bufferId;

	int len, i;
	FILE* fpArchivo;
	eSuperHeroe* aux;

	if(lista != NULL && path != NULL)
	{
		fpArchivo = fopen(path, "w");
		if(fpArchivo != NULL)
		{
			len = ll_len(lista);
			fprintf(fpArchivo, "id,nombre,IdPropietario,power,ataque\n");
			for(i = 0; i < len; i++)
			{
				aux = (void*) ll_get(lista, i);
				if(aux != NULL)
				{
					if(!superHeroe_getId(aux, &bufferId) &&
						!superHeroe_getNombre(aux, bufferNombre) &&
						!superHeroe_getAtaque(aux, &bufferAtaque) &&
						!superHeroe_getIdPropietario(aux, &bufferIdTipo) &&
						!superHeroe_getPower(aux, &bufferPower))

					{

						retorno = 0;
						fprintf(fpArchivo, "%d,%s,%d,%d,%d\n", bufferId, bufferNombre, bufferIdTipo, bufferPower, bufferAtaque);
					}
				}
			}
		}
		fclose(fpArchivo);

	}
	return retorno;
}

















//////////////////// 5 - Fin ******************
