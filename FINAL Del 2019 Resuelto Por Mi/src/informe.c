#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Llamada.h"
#include "LinkedList.h"
#include "parser.h"
#include "informe.h"



void imprimir_llamadas(LinkedList* lista){
	int cant=ll_len(lista);
	int i;
	eLlamada* aux;
	int bufferId;
	int bufferIdTipo;
	int bufferNumCliente;
	char bufferFecha[128];
	char bufferSolucionado[128];
	char bufferProblema[128];

	printf("ID:     FECHA:      N° CLIENTE:     PROBLEMA:      SOLUCIONADO:");
	for(i=0;i<cant;i++){
		aux=ll_get(lista,i);
		if(aux!=NULL && !llamada_getId(aux,&bufferId) && !llamada_getIdTipo(aux,&bufferIdTipo) &&
				!llamada_getFecha(aux,bufferFecha) && !llamada_getNumCliente(aux,&bufferNumCliente)
				&& !llamada_getSolucionado(aux,bufferSolucionado)){

			llamada_getIdTipoTxt(bufferIdTipo,bufferProblema);
			printf("\n %-5d   %-12s   %-5d   %-20s   %-2s  ",bufferId,bufferFecha,bufferNumCliente,bufferProblema,bufferSolucionado);

		}
	}
}


