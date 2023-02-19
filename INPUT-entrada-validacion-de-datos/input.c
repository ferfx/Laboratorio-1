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

int esNumerica(char cadena[])
{
	int retorno = -1;
	int i;
	int len=strlen(cadena);

	if(cadena != NULL && len > 0)
	{
		retorno = 1;

		for(i=0;i<len && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int esFlotante(char cadena[])
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++){
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
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
