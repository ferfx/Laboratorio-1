#ifndef POKEMON_H_
#define POKEMON_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct{
	int numero;
	char nombre[20];
	char tipo[20];
	char tamanio[10];
	char ataqueCargado[20];
	int valorAtaque;
	int esVariocolor;
}ePokemon;

void* pokemon_new(void);
ePokemon* pokemon_newParametrosTxt(char* num, char* nom,char* tipo, char* tam, char* ataque, char* valorAtq, char* esVar);


int pkm_setNumeroTxt(ePokemon* this, char* num);
int pkm_setNombreTxt(ePokemon* this, char* nombre);
int pkm_setTipoTxt(ePokemon* this, char* tipo);
int pkm_setTamanioTxt(ePokemon* this,char* tam);
int pkm_setAtaqueTxt(ePokemon* this, char* ataque);
int pkm_setValorAtaqueTxt(ePokemon* this, char* num);
int pkm_setEsVarioColorTxt(ePokemon* this, char* num);



int pkm_getNum(ePokemon* this,int* id);
int pkm_getNombre(ePokemon* this, char* id);
int pkm_getTipo(ePokemon* this, char* palabra);
int pkm_getTamanio(ePokemon* this, char* n);
int pkm_getAtaqueCargado(ePokemon* this, char* palabra);
int pkm_getValorAtaque(ePokemon* this, int* n);
int pkm_getEsVarioColor(ePokemon* this, int* n);
void pkm_getTipoVarioColor(int id, char* palabra);


int pokemon_bajaPokemon(LinkedList* lista);
int pokemon_buscarNum(LinkedList* lista,int id);

int filtrarPorAgua(void* elemento);

int mapearPorDiaDespejado(void* elemento);

int batalla_pokemon(LinkedList* lista);






#endif /* POKEMON_H_ */
