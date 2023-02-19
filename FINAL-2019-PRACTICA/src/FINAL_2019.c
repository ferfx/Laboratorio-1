/*
 ============================================================================
 Name        : FINAL_2019.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "Llamada.h"
#include "input.h"
#include "LinkedList.h"
#include "informe.h"

int main(void) {
	setbuf(stdout, NULL);
	LinkedList* lista;
	LinkedList* listaDos=NULL;
	char name[50];
	int opcion;

	lista = ll_newLinkedList();
	do{

		opcion=getInt("\n MENU PRINCIPAL\n1. Crea LL\n2. Imprime\n3. Genera Archivo\n4. Salir\n");

		switch(opcion){
		case 1:
			getString(name,"Ingrese el nombre del Archivo\n",50);
			if(!llamada_LeerArchivo(name,lista)){
				printf("\nSE CREO LA LISTA EXITOSAMENTE;\n");
			}else
				printf("No se encontro ese archivo, volviendo al menu principal...\n");
			break;
		case 2:
			if(!ll_isEmpty(lista)){
				imprimir_llamadas(lista);
			}
			else
				printf("\nPRIMERO DEBE CARGAR LA LISTA\n");
			break;
		case 3:
			if(!ll_isEmpty(lista)){
				listaDos=llamada_filtrar(lista);
				if(listaDos!=NULL){
					printf("Lista Filtrada generada Exitosamente\n");
					if(!llamada_guardarEnArchivoTxt("filtrado.csv",listaDos))
						printf("Se genero el nuevo archivo.csv\n");
				}
				else
					printf("ERROR!\n");
			}else
				printf("La lista principal esta vacia!\n");
			break;
		case 4:
			printf("El programa finalizo.");
			break;
		default:
			printf("Opcion incorrecta, vuelva a elegir\n.");
			break;
		}



	}while(opcion!=4);







	return EXIT_SUCCESS;
}
