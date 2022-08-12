#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"


int getInt(char mensaje[])
{
	int retorno = -1;
	int esNumero;
	char auxiliar[30];

	getString(auxiliar,mensaje,30);

	while(esNumerica(auxiliar) < 1)
	{
	  getString(auxiliar,"ERROR, INGRESE UN NUMERO ENTERO: \n",30);
	}

	esNumero = atoi(auxiliar);

	retorno = esNumero;

 return retorno;
}

float getFloat(char mensaje[]){
	float retorno;
	float esNumero;
	char auxiliar[30];

	getString(auxiliar,mensaje,30);
	while (esFlotante(auxiliar)<1){
		getString(auxiliar,"ERROR, REINGRESE UN NUMERO DECIMAL VALIDO: \n",30);
	}
	esNumero=atof(auxiliar);
	retorno=esNumero;

	return retorno;
}

int esNumerica(char auxiliar[])
{
	int i;
	int largo;
	int retorno =-1;

	if(auxiliar != NULL)
	{
		retorno = 1;

		largo = strlen(auxiliar);

		for(i=0;i<largo;i++)
		{
			if(isdigit(auxiliar[i])==0)
			{
				retorno =0;
				break;

			}

		}
	}
	return retorno;

}

int esFlotante(char auxiliar[])
{
	int i;
	int largo;
	int retorno =-1;
	int contadorPuntos=0;

	if(auxiliar != NULL)
	{
		retorno = 1;

		largo = strlen(auxiliar);

		for(i=0;i<largo;i++)
		{
			if (auxiliar[i]=='.'){
				contadorPuntos++;
			}
		}

		if (contadorPuntos<2){
			for(i=0;i<largo;i++){
				if(isdigit(auxiliar[i])==0 && auxiliar[i]!='.'){
					retorno=0;
				}
			}
		}
		else{
			retorno=0;

		}

		if(contadorPuntos==1 && strlen(auxiliar)==1){ // VALIDO POR SI INGRESAN SOLAMETE UN PUNTO SOLO '.' QUE NO ES NUMERO NI NADA;
			retorno=0;
		}


	}
	return retorno;

}



void getString(char palabra[],char mensaje[],int tamanio)
{
	char auxilar[1024];
	int cantidadLetras;

	printf("%s",mensaje);
	fflush(stdin);
	gets(auxilar);

	cantidadLetras = strlen(auxilar);

	while(cantidadLetras > tamanio)
	{
		printf("%s","Error, vuelva a ingresar:\n");
		fflush(stdin);
		gets(auxilar);

	}

	strcpy(palabra,auxilar);
}
