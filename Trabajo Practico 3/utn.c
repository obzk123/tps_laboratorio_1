#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getInt(char* mensaje, int* pResultado)
{
    int retorno = -1;
    int retornoScanf;
    int auxInt;
    if(mensaje != NULL && pResultado != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        retornoScanf = scanf("%d", &auxInt);
        while(retornoScanf == 0)
        {
            printf("Error. Ingrese solo numeros: ");
            fflush(stdin);
            retornoScanf = scanf("%d", &auxInt);
        }

        *pResultado = auxInt;

        retorno = 0;
    }

    return retorno;
}

int getFloat(char* mensaje, float* pResultado)
{
    int retorno = -1;
    int retornoScanf;
    float auxFloat;
    if(mensaje != NULL && pResultado != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        retornoScanf = scanf("%f", &auxFloat);
        while(retornoScanf == 0)
        {
            printf("Error. Ingrese solo numeros: ");
            fflush(stdin);
            retornoScanf = scanf("%f", &auxFloat);
        }
        *pResultado = auxFloat;

        retorno = 0;
    }
    return retorno;
}

int getString(char* mensaje, char pResultado[])
{
    int retorno = -1;
    char auxCad[100];
    if(mensaje != NULL && pResultado != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(auxCad);

        while(strlen(auxCad) > 50 || strlen(auxCad) < 1)
        {
            printf("Error. Ingrese solo caracteres: ");
            fflush(stdin);
            gets(auxCad);
        }

        strcpy(pResultado, auxCad);

        retorno = 0;
    }

    return retorno;
}
