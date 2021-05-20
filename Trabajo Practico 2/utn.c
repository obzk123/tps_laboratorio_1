/*
 * utn.c
 *
 *  Created on: 30 mar. 2021
 *      Author: octav
 */

#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getInt(char mensaje[], int *pResultado)
{
	int RetornoScan;
	int retorno = -1;
	int resultado;

	if(pResultado != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		RetornoScan = scanf("%d", &resultado);

		while(RetornoScan == 0)
		{
			printf("Error ingrese solo numeros: ");
			fflush(stdin);
			RetornoScan = scanf("%d", &resultado);
		}

		*pResultado = resultado;
		retorno = 0;
	}

	return retorno;
}

int getString(char mensaje[], char* pVariable, int tam)
{
	int retorno = -1;
	char auxCad[100];
	if(pVariable != NULL && tam > 0 && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(auxCad);
		while(strlen(auxCad) > (tam - 1) )
		{
			printf("Error cadena demasiado larga. Ingrese nuevamente: ");
			fflush(stdin);
			gets(auxCad);
		}

		strcpy(pVariable, auxCad);

		retorno = 0;
	}

	return retorno;
}

int getFloat(char mensaje[], float *pResultado)
{
	int RetornoScan;
	int retorno = -1;
	float resultado;

	if(pResultado != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		RetornoScan = scanf("%f", &resultado);

		while(RetornoScan == 0)
		{
			printf("Error ingrese solo numeros: ");
			fflush(stdin);
			RetornoScan = scanf("%f", &resultado);
		}

		*pResultado = resultado;
		retorno = 0;
	}

	return retorno;
}
