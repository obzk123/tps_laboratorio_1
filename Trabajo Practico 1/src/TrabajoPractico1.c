/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      : Bill Zito Octavio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "operaciones.h"
#include "utn.h"
#include <string.h>

int menu(int a, int b, int flagOperador);
int calcular(int a, int b, int* resultadoSuma, int* resultadoResta, float* resultadoDivision,int* retornoDivision, int* resultadoMultiplicacion, long long int* resultadoFactorialA, long long int* resultadoFactorialB);
void mostrar(int resultadoSuma, int resultadoResta, float resultadoDivision,int retornoDivision , int resultadoMultiplicacion, long long int  resultadoFactorialA, long long int resultadoFactorialB);


int main(void)
{
	setbuf(stdout, NULL);

	int a;
	int b;
	int operacion;
	int resultadoSuma;
	int resultadoResta;
	float resultadoDivision;
	int resultadoMultiplicacion;
	long long int resultadoFactorialA;
	long long int resultadoFactorialB;
	int retornoDivision;
	int flagCalcular = 0;
	int flagOperando = 0;

	do
	{
		system("cls");
		operacion = menu(a,b, flagOperando);

		switch (operacion)
		{
			case 1:
				getInt("Ingrese el 1er operando: ", &a);
				flagOperando = 1;
				flagCalcular = 0;
			break;

			case 2:
				if(flagOperando)
				{
					getInt("Ingrese el 2do operando: ", &b);
					flagOperando = 2;
					flagCalcular = 0;
				}
				else
				{
					printf("Primero cargue el primer operando\n");
					system("pause");
				}
			break;

			case 3:
				if(flagOperando == 2)
				{
					calcular(a,b,&resultadoSuma,&resultadoResta,&resultadoDivision,&retornoDivision,&resultadoMultiplicacion,&resultadoFactorialA,&resultadoFactorialB);
					flagCalcular = 1;
				}
				else
				{
					printf("Primero cargue los dos operandos antes de calcular\n");
					system("pause");
				}
			break;

			case 4:
				if (flagCalcular)
				{
					mostrar(resultadoSuma, resultadoResta, resultadoDivision, retornoDivision, resultadoMultiplicacion, resultadoFactorialA, resultadoFactorialB);
					flagCalcular = 0;
					flagOperando = 0;
				}
				else
				{
					printf("No es posible informar sin antes calcular\n");
					system("pause");
				}
			break;

			case 5:
			break;

			default:
				printf("Opcion incorrecta\n");
				system("pause");
			break;
		}

	}while(operacion != 5);

	return 0;
}


int menu(int a, int b, int flagOperando)
{
	int operacion;

	printf("Menu de opciones\n");
	switch(flagOperando)
	{
	case 0:
		printf("1.Ingresar 1er operando (A = X)\n");
		printf("2.Ingresar 2do operando (B = Y)\n");
		break;
	case 1:
		printf("1.Ingresar 1er operando (A = %d)\n", a);
		printf("2.Ingresar 2do operando (B = Y)\n");
		break;
	case 2:
		printf("1.Ingresar 1er operando (A = %d)\n", a);
		printf("2.Ingresar 2do operando (B = %d)\n", b);
		break;
	}
	printf("3.Calcular todas las operaciones\n");
	printf("4.Informar resultados\n");
	printf("5.Salir\n");
	fflush(stdin);
	scanf("%d", &operacion);

	return operacion;
}

int calcular(int a, int b, int* resultadoSuma, int* resultadoResta, float* resultadoDivision,int* retornoDivision, int* resultadoMultiplicacion, long long int* resultadoFactorialA, long long int* resultadoFactorialB)
{
	int retorno = -1;

	if(resultadoSuma != NULL && resultadoResta != NULL && resultadoDivision != NULL && resultadoMultiplicacion != NULL && resultadoFactorialA != NULL && resultadoFactorialB != NULL)
	{
		*resultadoSuma = suma(a, b);
		*resultadoResta = resta(a, b);
		*retornoDivision = division(a,b, resultadoDivision);
		*resultadoMultiplicacion = multiplicacion(a, b);

		//Validacion para que no falle la cuenta del factorial
		if(a < 33 && a > -1)
		{
			*resultadoFactorialA = factorial(a);
		}
		else
		{
			*resultadoFactorialA = -1;
		}

		if(b < 33 && b > -1)
		{
			*resultadoFactorialB = factorial(b);
		}else
		{
			*resultadoFactorialB = -1;
		}

		printf("Se calculo correctamente\n");
		retorno = 0;

		system("pause");
	}
	else
	{
		printf("Ocurrio un error al calcular\n");
	}

	return retorno;
}

void mostrar(int resultadoSuma, int resultadoResta, float resultadoDivision,int retornoDivision, int resultadoMultiplicacion, long long int resultadoFactorialA, long long int resultadoFactorialB)
{

	printf("A) El resultado de A+B es: %d\n", resultadoSuma);
	printf("B) El resultado de A-B es: %d\n", resultadoResta);

	if(!retornoDivision)
	{
		printf("C) El resultado de A/B es: %.3f\n",resultadoDivision);
	}
	else
	{
		printf("C) No se puede divir por cero\n");
	}
	printf("D) El resultado de A*B es: %d\n",resultadoMultiplicacion);

	if(resultadoFactorialA == -1 && resultadoFactorialB == -1)
	{
		printf("E) No se puede resolver el factorial de A y el factorial de B no se puede resolver\n");
	}else
	{
		if(resultadoFactorialA == -1)
		{
			printf("E) No se puede resolver el factorial de A y el factorial de B es: %I64u\n", resultadoFactorialB);
		}
		else
		{
			if(resultadoFactorialB == -1)
			{
				printf("E) El factorial de A es: %I64u y el factorial de B no se puede resolver\n", resultadoFactorialA);
			}
			else
			{
				printf("E) El factorial de A es: %I64u y el factorial de B es: %I64u\n",resultadoFactorialA, resultadoFactorialB);
			}
		}
	}

	system("pause");
}
