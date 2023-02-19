#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "Pokemon.h"
#include "input.h"
#include "LinkedList.h"
#include "informe.h"
#include "Controller.h"

int main(void) {
	setbuf(stdout, NULL);
	LinkedList* lista;
	LinkedList* listaDos=NULL;
	char name[50];
	int opcion;

	lista = ll_newLinkedList();
	do{

		opcion=getInt("\n MENU PRINCIPAL\n1. Carga LL\n2. Eliminar PKM \n3. Imprime PKM\n4. Filtrar Water Shiny  \n5. Mapear Ataque Por Dia Soleado PKM\n6. Batalla PKM vs Giovanni PKM\n10. SALIR\n");

		switch(opcion){

		case 1:
			getString(name,"Ingrese el nombre del Archivo\n",50);
			if(!controller_loadFromText(name,lista)){
				printf("\nSE CREO LA LISTA EXITOSAMENTE;\n");
			}else
				printf("No se encontro ese archivo, volviendo al menu principal...\n");
			break;

		case 2:
			if(!ll_isEmpty(lista)){
				controller_List(lista);
				controller_eliminarPokemon(lista);
			}
			else
				printf("\nPRIMERO DEBE CARGAR LA LISTA\n");
			break;

		case 3:
			if(!ll_isEmpty(lista)){
				controller_List(lista);
			}
			else
				printf("\nPRIMERO DEBE CARGAR LA LISTA\n");
			break;

		case 4:
			if(!ll_isEmpty(lista)){
				listaDos=ll_filter(lista,filtrarPorAgua);
				if(listaDos!=NULL)
					controller_List(listaDos);
			}
			else
				printf("PRIMERO DEBE CARGAR LA LISTA");

			break;

		case 5:
			if(!ll_isEmpty(lista)){
				if(!ll_map(lista,mapearPorDiaDespejado)){
					printf("\nMAPEO EXITOSO\n");
				}
			}
			else
				printf("PRIMERO DE CARGAR LA LISTA\n");

			break;

		case 6:
			if(!ll_isEmpty(lista)){
				if(!batalla_pokemon(lista)){
					printf("\n BATALLA POKEMON GANADA - FELICIDADES!!!\n");
				}
				else
					printf("\n BATALLA PERDIDA, ANIMOS PARA LA PROXIMA\n");
			}
			else
				printf("PRIMERO DEBE CARGAR LA LISTA\n");
			break;

		case 10:
			printf("EL PROGRAMA FINALIZO.\n");
			break;

		default:
			printf("Opcion incorrecta, vuelva a elegir\n.");
			break;
		}


	}while(opcion!=10);

	ll_deleteLinkedList(lista);
	ll_deleteLinkedList(listaDos);







	return EXIT_SUCCESS;
}
