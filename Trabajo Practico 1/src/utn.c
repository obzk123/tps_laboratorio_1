/*
 * utn.c
 *
 *  Created on: 30 mar. 2021
 *      Author: octav
 */

#include "utn.h"
#include <stdio.h>
#include <stdlib.h>


int getInt(char mensaje[], int *pResultado)
{
	int RetornoScan;
	int retorno = -1;
	int resultado;

	if(pResultado != NULL)
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
