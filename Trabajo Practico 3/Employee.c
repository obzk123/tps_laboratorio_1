#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
    return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
     Employee* newEmployee = employee_new();

     int idAux;
     int horasTrabajadasAux;
     int sueldoAux;

     if(newEmployee != NULL)
     {
         idAux = atoi(idStr);
         horasTrabajadasAux = atoi(horasTrabajadasStr);
         sueldoAux = atoi(sueldo);

         employee_setId(newEmployee, idAux);
         employee_setNombre(newEmployee, nombreStr);
         employee_setHorasTrabajadas(newEmployee, horasTrabajadasAux);
         employee_setSueldo(newEmployee, sueldoAux);
     }

     return newEmployee;
}

void employee_delete(Employee* this)
{
    free(this);
}


int employee_setId(Employee* this,int id)
{
    int todoOk = -1;
    if(this != NULL)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = -1;
    if(this != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = -1;
    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = -1;
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = -1;
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = -1;
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = -1;
    if(this != NULL)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = -1;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int ordenarPorLegajo(void* a, void* b)
{
    int todoOk = 0;

    Employee* emp1 = NULL;
    Employee* emp2 = NULL;

    if(a != NULL && b != NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        if(emp1->id > emp2->id)
        {
           todoOk = 1;

        }

        else if(emp1->id < emp2->id)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int ordenarPorNombre(void* a, void* b)
{

    int todoOk = 0;
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;
    if(a != NULL && b != NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        if(strcmp(emp1->nombre, emp2->nombre) > 0)
        {
           todoOk = 1;
        }else if(strcmp(emp1->nombre, emp2->nombre) < 0)
        {
            todoOk = -1;
        }
    }

    return todoOk;
}

int ordenarPorHoras(void* a, void* b)
{
    int todoOk = 0;

    Employee* emp1 = NULL;
    Employee* emp2 = NULL;

    if(a != NULL && b != NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        if(emp1->horasTrabajadas > emp2->horasTrabajadas)
        {
           todoOk = 1;

        }

        else if(emp1->horasTrabajadas < emp2->horasTrabajadas)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int ordenarPorSueldo(void* a, void* b)
{
    int todoOk = 0;

    Employee* emp1 = NULL;
    Employee* emp2 = NULL;

    if(a != NULL && b != NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        if(emp1->sueldo > emp2->sueldo)
        {
           todoOk = 1;

        }

        else if(emp1->sueldo < emp2->sueldo)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

