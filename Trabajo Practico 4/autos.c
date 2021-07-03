#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "autos.h"


eAuto* nuevoAuto()
{
    eAuto* nuevoAuto = (eAuto*) malloc(sizeof(eAuto));
    return nuevoAuto;
}

eAuto* nuevoAutoParametros(int id, char* marca, char* modelo, int anio)
{
    eAuto* nuevoAutoParam = nuevoAuto();
    if(nuevoAutoParam != NULL)
    {
        if(!((autoSetterId(nuevoAutoParam, id)) &&
           (autoSetterMarca(nuevoAutoParam, marca)) &&
           (autoSetterModelo(nuevoAutoParam, modelo)) &&
           (autoSetterAnio(nuevoAutoParam, anio))))
        {
            free(nuevoAutoParam);
            nuevoAutoParam = NULL;
        }
    }
    return nuevoAutoParam;
}

int mostrarAuto(eAuto autos)
{
    int todoOk = 0;

    printf("%d %s %s %d\n", autos.id, autos.marca, autos.modelo, autos.anio);
    todoOk = 1;
    return todoOk;
}

int mostrarAutos(LinkedList* lista)
{
    int todoOk = 0;
    eAuto* auxAuto = NULL;
    if(lista != NULL)
    {
        for(int i = 0; i < ll_len(lista); i++)
        {
            auxAuto = (eAuto*) ll_get(lista, i);
            mostrarAuto(*auxAuto);
        }
        todoOk = 1;
    }
    return todoOk;
}



int autoSetterId(eAuto* this, int id)
{
    int todoOk = 0;
    if(this != NULL)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int autoSetterMarca(eAuto* this, char* marca)
{
    int todoOk = 0;
    if(this != NULL)
    {
        strcpy(this->marca, marca);
        todoOk = 1;
    }
    return todoOk;
}

int autoSetterModelo(eAuto* this, char* modelo)
{
    int todoOk = 0;
    if(this != NULL)
    {
        strcpy(this->modelo, modelo);
        todoOk = 1;
    }
    return todoOk;
}

int autoSetterAnio(eAuto* this, int anio)
{
    int todoOk = 0;
    if(this != NULL)
    {
        this->anio = anio;
        todoOk = 1;
    }

    return todoOk;
}

int ordenarPorAnio(void* pElement1, void* pElement2)
{
    int todoOk = 0;
    eAuto* Element1 = (eAuto*) pElement1;
    eAuto* Element2 = (eAuto*) pElement2;
    if(Element1 != NULL && Element2 != NULL)
    {
        if(Element1->anio > Element2->anio)
        {
            todoOk = 1;
        }
        else if(Element1->anio < Element2->anio)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int autoGetterId(eAuto* this, int* id)
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}
int autoGetterMarca(eAuto* this, char* marca)
{
    int todoOk = 0;
    if(this != NULL && marca != NULL)
    {
        strcpy(marca, this->marca);
        todoOk = 1;
    }
    return todoOk;
}

int autoGetterModelo(eAuto* this, char* modelo)
{
    int todoOk = 0;
    if(this != NULL && modelo != NULL)
    {
        strcpy(modelo, this->modelo);
        todoOk = 1;
    }
    return todoOk;
}

int autoGetterAnio(eAuto* this, int* anio)
{
    int todoOk = 0;
    if(this != NULL && anio != NULL)
    {
        *anio = this->anio;
        todoOk = 1;
    }
    return todoOk;
}
