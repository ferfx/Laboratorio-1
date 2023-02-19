

#ifndef EPARTICIPANTE_H_
#define EPARTICIPANTE_H_


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct{

	int id;
	char nombre[100];
	int idProp;
	int power;
	int ataque;

}eSuperHeroe;




int superHeroe_LeerArchivo(char* path , LinkedList* lista);
int parser_superHeroeFromText(FILE* pFile, LinkedList* lista);
int superHeroe_delete(eSuperHeroe* this);



int superHeroe_getNombre(eSuperHeroe* this, char* nombre);
int superHeroe_getId(eSuperHeroe* this, int* id);
int superHeroe_getIdPropietario(eSuperHeroe* this, int* id);
int superHeroe_getIdTipoTxt(eSuperHeroe* this, int idTipo, char* tipo);
int superHeroe_getPower(eSuperHeroe* this, int* power);
int superHeroe_getAtaque(eSuperHeroe* this, int* ataque);


int superHeroe_setId(eSuperHeroe* this, int id);
int superHeroe_setIdTxt(eSuperHeroe* this, char* id);
int superHeroe_setPower(eSuperHeroe* this, int power);
int superHeroe_setPowerTxt(eSuperHeroe* this, char* power);
int superHeroe_setNombre(eSuperHeroe* this, char* nombre);
int superHeroe_setIdTipoPropietario(eSuperHeroe* this, int idTipo);
int superHeroe_setIdTipoTxt(eSuperHeroe* this, char* idTipo);
int superHeroe_setAtaque(eSuperHeroe* this, int ataque);
int superHeroe_setAtaqueTxt(eSuperHeroe* this, char* ataque);


int superHeroe_ordenarLista(LinkedList* lista);
int superHeroe_compararPorPower(void* e1, void* e2);

int superHeroe_imprimirPorPantalla(LinkedList* lista);
int superHeroe_imprimirUno(eSuperHeroe* this);


//LinkedList* superHeroe_mapear(LinkedList* lista);

int superHeroe_mapearPorAtaque(void* elemento);



/*
int superHeroe_filtrarPorDificultad(void* elemento);
int superHeroe_filtrarPorDificultad2(void* elemento);
int superHeroe_filtrarPorDificultad3(void* elemento);*/

int superHeroe_guardarEnArchivoTxt(char* path , LinkedList* lista);








#endif /* EPARTICIPANTE_H_ */
