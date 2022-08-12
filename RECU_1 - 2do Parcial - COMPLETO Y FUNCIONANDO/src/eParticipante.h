/*
 * eParticipante.h
 *
 *  Created on: 4 ago. 2022
 *      Author: fx
 */

#ifndef EPARTICIPANTE_H_
#define EPARTICIPANTE_H_


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct{

	int id;
	char nombre[100];
	int edad;
	int idDificultad;
	int score;

}eParticipante;




int participante_LeerArchivo(char* path , LinkedList* lista);
int parser_participanteFromText(FILE* pFile, LinkedList* lista);
int participante_delete(eParticipante* this);



int participante_getNombre(eParticipante* this, char* nombre);
int participante_getId(eParticipante* this, int* id);
int participante_getIdDificultad(eParticipante* this, int* idDificultad);
int participante_getIdTipoTxt(eParticipante* this, int idTipo, char* tipo);
int participante_getEdad(eParticipante* this, int* edad);
int participante_getScore(eParticipante* this, int* score);


int participante_setId(eParticipante* this, int id);
int participante_setIdTxt(eParticipante* this, char* id);
int participante_setEdad(eParticipante* this, int edad);
int participante_setEdadTxt(eParticipante* this, char* edad);
int participante_setNombre(eParticipante* this, char* nombre);
int participante_setIdTipoDificultad(eParticipante* this, int idTipo);
int participante_setIdTipoTxt(eParticipante* this, char* idTipo);
int participante_setScoreTxt(eParticipante* this, char* score);


int participante_ordenarLista(LinkedList* listaComputadoras);
int participante_compararPorNombre(void* e1, void* e2);

int participante_imprimirPorPantalla(LinkedList* lista);
int participante_imprimirUno(eParticipante* this);

LinkedList* participante_filtrar(LinkedList* lista);
int participante_filtrarPorDificultad(void* elemento);
int participante_filtrarPorDificultad2(void* elemento);
int participante_filtrarPorDificultad3(void* elemento);

int participante_guardarEnArchivoTxt(char* path , LinkedList* lista);






#endif /* EPARTICIPANTE_H_ */
