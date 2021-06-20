#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    FILE* archivo;
    archivo = fopen(path, "r");
    if(archivo != NULL && pArrayListEmployee != NULL && path != NULL)
    {
        parser_EmployeeFromText(archivo, pArrayListEmployee);
        todoOk = 1;
    }
    fclose(archivo);
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* p = NULL;
    p = fopen(path, "rb");
    if(p != NULL && pArrayListEmployee != NULL)
    {
        parser_EmployeeFromBinary(p, pArrayListEmployee);
        todoOk = 1;
    }
    fclose(p);
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = NULL;
    int tam;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int todoOk = 0;

    if(pArrayListEmployee != NULL)
    {
        tam = ll_len(pArrayListEmployee);
        auxEmployee = (Employee*) ll_get(pArrayListEmployee, tam-1);
        employee_getId(auxEmployee, &id);

        auxEmployee = NULL;
        auxEmployee = employee_new();
        if(auxEmployee != NULL)
        {
            id++;
            employee_setId(auxEmployee, id);
            system("cls");
            printf("Alta empleado\n");
            printf("ID: %d\n", id);
            getString("Ingrese el nombre: ", nombre);
            while(!employee_setNombre(auxEmployee, nombre))
            {
                getString("Error, reingrese el nombre: ", nombre);
            }

            getInt("Ingrese las horas trabajadas: ", &horasTrabajadas);
            while(!employee_setHorasTrabajadas(auxEmployee, horasTrabajadas))
            {
                getInt("Error, reingrese las horas trabajadas: ", &horasTrabajadas);
            }

            getInt("Ingrese el sueldo: ", &sueldo);
            while(!employee_setSueldo(auxEmployee,sueldo))
            {
                getInt("Error, reingrese el sueldo: ", &sueldo);
            }

            ll_add(pArrayListEmployee, auxEmployee);
            todoOk = 1;
        }
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int id;
    int indice = -1;
    int opcion;
    int newHoras;
    int newSueldo;
    char newNombre[30];

    Employee* auxEmpleado;
    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("Seleccione el ID a modificar: ");
        scanf("%d", &id);
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            if(auxEmpleado->id == id)
            {
                indice = i;
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
                todoOk = 1;
                break;
            }
        }

        if(indice > -1)
        {
            printf("Menu de modificaciones:\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\nIngrese su opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            while(opcion < 1 || opcion > 3)
            {
                printf("Error opcion incorrecta. Ingrese nuevamente: ");
                fflush(stdin);
                scanf("%d", &opcion);
            }

            switch(opcion)
            {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                gets(newNombre);
                employee_setNombre(auxEmpleado, newNombre);
                break;
            case 2:
                printf("Ingrese la nueva cantidad de horas: ");
                fflush(stdin);
                scanf("%d", &newHoras);
                employee_setHorasTrabajadas(auxEmpleado, newHoras);
                break;
            case 3:
                printf("Ingrese el nuevo sueldo: ");
                fflush(stdin);
                scanf("%d", &newSueldo);
                employee_setSueldo(auxEmpleado, newSueldo);
                break;
            }
            ll_set(pArrayListEmployee, indice, auxEmpleado);
        }else
        {
            printf("Error. No existe el empleado con ID: %d\n", id);
        }
    }

    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int id;
    int indice;
    Employee* auxEmpleado;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        controller_ListEmployee(pArrayListEmployee);
        printf("Seleccione el ID a borrar: ");
        scanf("%d", &id);
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            if(auxEmpleado->id == id)
            {
                indice = i;
                ll_remove(pArrayListEmployee, indice);
                todoOk = 1;
                break;
            }
        }

        if(todoOk == 0)
        {
            printf("Error. No existe el empleado con ID: %d\n", id);
        }else
        {
            printf("Empleado eliminado con exito\n");
        }
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* employee = NULL;
    int id;
    char nombre[30];
    int horasTrabajadas;
    int sueldo;
    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Lista de empleados\n");
        printf("  ID   Nombre     Horas Sueldo\n");
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            employee = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(employee, &id);
            employee_getNombre(employee, nombre);
            employee_getHorasTrabajadas(employee, &horasTrabajadas);
            employee_getSueldo(employee, &sueldo);

            printf("%4d%10s    %3d   %5d\n", id, nombre, horasTrabajadas, sueldo);
        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int opcion;
    int order;
    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Menu Ordenar:\n1.Por legajo.\n2.Por Nombre.\n3.Por horas.\n4.Por sueldo\nEscoja su opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        printf("Ordenar de manera:\n1 ascendente\n0 descendente: ");
        fflush(stdin);
        scanf("%d", &order);

        switch(opcion)
        {
        case 1:
            ll_sort(pArrayListEmployee, ordenarPorLegajo, order);
            break;
        case 2:
            ll_sort(pArrayListEmployee, ordenarPorNombre, order);
            break;
        case 3:
            ll_sort(pArrayListEmployee, ordenarPorHoras, order);
            break;
        case 4:
            ll_sort(pArrayListEmployee, ordenarPorSueldo, order);
            break;
        }

        controller_ListEmployee(pArrayListEmployee);
        todoOk = 1;
    }


    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int todoOk = 0;
    f = fopen(path, "w");
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    Employee* auxEmployee = NULL;
    if(pArrayListEmployee != NULL && f != NULL)
    {
        fprintf(f, "ID, Nombre, Horas trabjadas, Sueldo\n");
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            if(auxEmployee != NULL)
            {
                employee_getId(auxEmployee, &id);
                employee_getNombre(auxEmployee, nombre);
                employee_getHorasTrabajadas(auxEmployee, &horas);
                employee_getSueldo(auxEmployee, &sueldo);
                fprintf(f, "%d, %s, %d, %d\n", id, nombre, horas, sueldo);
                auxEmployee = NULL;
            }
        }
    }
    fclose(f);
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* auxEmployee = NULL;
    FILE* f = NULL;
    char encabezado[50] = "ID, Nombre, Horas trabajadas, Sueldo";
    f = fopen(path, "wb");
    if(f != NULL && pArrayListEmployee != NULL)
    {
        //fwrite(encabezado, 50, sizeof(char), f);
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            if(auxEmployee != NULL)
            {
               fwrite(auxEmployee, 1 ,sizeof(Employee), f);
            }
        }
    }

    fclose(f);
    return todoOk;
}

