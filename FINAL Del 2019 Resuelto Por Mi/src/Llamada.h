

#ifndef LLAMADA_H_
#define LLAMADA_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


typedef struct{
	int id;
	char fecha[20];
	int nCliente;
	int idProblema;
	char solucionado[4];
}eLlamada;


void* llamada_new(void);
eLlamada* llamada_newParametrosTxt(char* id, char* fecha,char* nCliente, char* idP, char* solucionado);
int llamada_LeerArchivo(char* path, LinkedList* lista);

int llamada_setIdTxt(eLlamada* this, char* id);
int llamada_setFechaTxt(eLlamada* this, char* fecha);
int llamada_setNumClienteTxt(eLlamada* this, char* nCliente);
int llamada_setIdTipoTxt(eLlamada* this,char* idP);
int llamada_setSolucionadoTxt(eLlamada* this, char* solucionado);


int llamada_getId(eLlamada* this,int* id);
int llamada_getIdTipo(eLlamada* this, int* id);
int llamada_getFecha(eLlamada* this, char* palabra);
int llamada_getNumCliente(eLlamada* this, int* n);
int llamada_getSolucionado(eLlamada* this, char* palabra);
void llamada_getIdTipoTxt(int id, char* palabra);


LinkedList* llamada_filtrar(LinkedList* lista);
int filtrarPorProblema(void* elemento);

int llamada_guardarEnArchivoTxt(char* path , LinkedList* lista);




#endif /* LLAMADA_H_ */
