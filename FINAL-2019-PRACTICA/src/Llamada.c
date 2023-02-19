#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Llamada.h"
#include "LinkedList.h"
#include "input.h"
#include "parser.h"


int opcionGlobal;


void* llamada_new(void){
	return (void*) malloc(sizeof(eLlamada));
}

eLlamada* llamada_newParametrosTxt(char* id, char* fecha,char* nCliente, char* idP, char* solucionado){


	eLlamada* this = NULL;
	this = llamada_new();
	if(this != NULL && id!=NULL && fecha!=NULL && nCliente!=NULL && idP!=NULL && solucionado!=NULL)
	{

			llamada_setIdTxt(this, id);
			llamada_setFechaTxt(this, fecha);
			llamada_setNumClienteTxt(this, nCliente);
			llamada_setIdTipoTxt(this, idP);
			llamada_setSolucionadoTxt(this, solucionado);

	}
	return this;
}

int llamada_LeerArchivo(char* path, LinkedList* lista)
{
	int retorno = -1;
	int cantLlamadas;

	FILE* fpArchivo;
	if(path != NULL && lista != NULL)
	{

		fpArchivo = fopen(path, "r");
		if(fpArchivo != NULL)
		{

			cantLlamadas = parser_llamadaFromText(fpArchivo,lista);
			printf("\nSe cargaron %d llamadas", cantLlamadas);
			retorno = 0;
		}
		fclose(fpArchivo);

	}
	return retorno;
}


///////////////////////////// SETTERS TXTS ----------------->

int llamada_setIdTxt(eLlamada* this, char* id){
	int retorno=-1;
	if(this!=NULL && id!=NULL && esNumerica(id)==1){
		this->id=atoi(id);
		retorno=0;
	}
	return retorno;
}

int llamada_setFechaTxt(eLlamada* this, char* fecha){
	int retorno=-1;
	if(this!=NULL && fecha!=NULL){
		strcpy(this->fecha,fecha);
		retorno=0;
	}
	return retorno;
}

int llamada_setNumClienteTxt(eLlamada* this, char* nCliente){
	int retorno=-1;
	if(this!=NULL && nCliente!=NULL && esNumerica(nCliente)==1){
		this->nCliente=atoi(nCliente);
		retorno=0;
	}
	return retorno;
}

int llamada_setIdTipoTxt(eLlamada* this,char* idP){
	int retorno=-1;
	if(this!=NULL && idP!=NULL && esNumerica(idP)==1){
		this->idProblema=atoi(idP);
		retorno=0;
	}
	return retorno;
}

int llamada_setSolucionadoTxt(eLlamada* this, char* solucionado){
	int retorno=-1;
	if(this!=NULL && solucionado!=NULL){
		strcpy(this->solucionado,solucionado);
		retorno=0;
	}
	return retorno;
}

///////////////////// GETTERS ---------------- >

int llamada_getId(eLlamada* this,int* id){
	int retorno=-1;
	if(this!=NULL){
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int llamada_getIdTipo(eLlamada* this, int* id){
	int retorno=-1;
	if(this!=NULL){
		*id=this->idProblema;
		retorno=0;
	}
	return retorno;
}

int llamada_getFecha(eLlamada* this, char* palabra){
	int retorno=-1;
	if(this!=NULL){
		strcpy(palabra,this->fecha);
		retorno=0;
	}
	return retorno;
}

int llamada_getNumCliente(eLlamada* this, int* n){
	int retorno=-1;
	if(this!=NULL){
		*n=this->nCliente;
		retorno=0;
	}
	return retorno;
}

int llamada_getSolucionado(eLlamada* this, char* palabra){
	int retorno=-1;
	if(this!=NULL){
		strcpy(palabra,this->solucionado);
		retorno=0;
	}
	return retorno;
}

void llamada_getIdTipoTxt(int id, char* palabra){
	switch(id){
	case 1:
		strcpy(palabra,"No enciende PC");
		break;
	case 2:
		strcpy(palabra,"No funciona Mouse");
		break;
	case 3:
		strcpy(palabra,"No funciona teclado");
		break;
	case 4:
		strcpy(palabra,"No hay internet");
		break;
	case 5:
		strcpy(palabra,"No funciona telefono");
		break;
	}

}

///////////////////////////////////////---->
///

//////////////// INCISO 3 ----------------->
///

LinkedList* llamada_filtrar(LinkedList* lista){
	LinkedList* nuevaLista=NULL;

	opcionGlobal=getInt("Ingrese una opcion del problema 1 - 5\n");
	while(opcionGlobal!=1&&opcionGlobal!=2&&opcionGlobal!=3&&opcionGlobal!=4&&opcionGlobal!=5)
		opcionGlobal=getInt("Ingrese una opcion del problema 1 - 5\n");

	nuevaLista = ll_filter(lista,filtrarPorProblema);
	return nuevaLista;
}

int filtrarPorProblema(void* elemento){
	int retorno=0;
	eLlamada* aux;
	int id;

	aux=(eLlamada*) elemento;
	if(aux!=NULL){
		llamada_getIdTipo(aux,&id);
		if(id==opcionGlobal){
			retorno=1;
		}
	}
	return retorno;
}

int llamada_guardarEnArchivoTxt(char* path , LinkedList* lista){
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
}








