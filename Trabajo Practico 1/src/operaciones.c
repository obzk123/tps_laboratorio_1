/*
 * operaciones.c
 *
 *  Created on: 27 mar. 2021
 *      Author: Octavio Bill Zito
 */

#include "operaciones.h"

int suma(float a, float b)
{
	return (float) a + b;
}

int resta(float a, float b)
{
	return (float) a - b;
}

int division(float a, float b, float* resultado)
{
	int retorno = -1;

	if(b != 0)
	{
		*resultado =  (a / b);
		retorno = 0;
	}

	return retorno;
}

int multiplicacion(float a, float b)
{
	return (float) a * b;
}

int factorial(int a)
{
	int fact = 1;

	for(int i=1; i <= a; i++)
	{
		fact *= i;
	}

	return fact;
}

