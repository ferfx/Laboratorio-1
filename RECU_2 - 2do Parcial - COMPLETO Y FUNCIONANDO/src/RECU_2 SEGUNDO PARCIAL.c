/*
 ============================================================================
 Name        : RECU_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"
#include "entidades.h"


int main(void) {
	setbuf(stdout, NULL);

	LinkedList* lista;
	//LinkedList* listaDos;
	lista = ll_newLinkedList();
	int opcion;
	char name[50];
	int flagMap=0;


	do{

			opcion=getInt("\n MENU PRINCIPAL\n1. Crea LL\n2. Ordena\n3. Imprime\n4. Mapeo\n5. Archivo nuevo filtrado\n6. Salir\n");

			switch (opcion){
			case 1:
				getString(name,"Ingrese nombre archivo: ", 50);
				if(!superHeroe_LeerArchivo(name,lista))
				{
					printf("\nSE CREO LA LISTA EXITOSAMENTE\n");
				}
				else
					printf("Error, no se encontro ese archivo, volviendo al menu..\n");

				break;

			case 2:
				if(!ll_isEmpty(lista))
				{
					if(!superHeroe_ordenarLista(lista))
					{
						printf("\nSE ORDENO LA LISTA EXITOSAMENTE\n");
					}
				}
				else
				{
					printf("\nLista vacia\n");
				}

				break;

			case 3:
				if(!ll_isEmpty(lista))
				{
					if(!superHeroe_imprimirPorPantalla(lista))
					{
						printf("\nSE IMPRIMIO EXITOSAMENTE\n");

					}
					else
					{
						printf("\n NO SE PUDO IMPRIMIR\n");
					}
					}
				else
					{
						printf("\nLista vacia\n");
					}

				break;

			case 4:
				if(!ll_isEmpty(lista))
				{
					ll_map(lista,superHeroe_mapearPorAtaque);
					if(lista != NULL)
						{
							printf("\nMAPEO EXITOSO\n");
							flagMap = 1;

						}
				}
				else
					printf("\n-----> Lista vacia <------\n");
				break;

			case 5:
				if(flagMap==1){
					if(!superHeroe_guardarEnArchivoTxt("mapeado.csv",lista))
					{
						printf("\nARCHIVO GENERADO EXITOSAMENTE\n");

					}
					else
					{
						printf("\n ERROR AL GENERAR ARCHIVO \n");
					}
				}
				else
					printf("PRIMERO LA LISTA DEBE FILTRARSE");

				break;

			case 6:
				printf("El programa finalizo. \n");
				break;

			default:
				printf("Opcion incorrecta, vuelva a elegir una opcion del 1 a 6 \n");
				break;

			}
	} while (opcion!=6);

	ll_deleteLinkedList(lista);
	//ll_deleteLinkedList(listaDos);

	return EXIT_SUCCESS;

}
