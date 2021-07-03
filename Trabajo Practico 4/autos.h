#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char marca[20];
    char modelo[20];
    int anio;
}eAuto;

#endif // AUTOS_H_INCLUDED


eAuto* nuevoAuto();

eAuto* nuevoAutoParametros(int id, char* marca, char* modelo, int anio);

int mostrarAutos(LinkedList* lista);
int mostrarAuto(eAuto autos);

int autoSetterId(eAuto* this, int id);
int autoSetterMarca(eAuto* this, char* marca);
int autoSetterModelo(eAuto* this, char* modelo);
int autoSetterAnio(eAuto* this, int anio);

int autoGetterId(eAuto* this, int* id);
int autoGetterMarca(eAuto* this, char* marca);
int autoGetterModelo(eAuto* this, char* modelo);
int autoGetterAnio(eAuto* this, int* anio);

int ordenarPorAnio(void* pElement1, void* pElement2);
