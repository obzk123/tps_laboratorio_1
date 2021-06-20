#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int menu();

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int isLoad = 0;

    if(listaEmpleados == NULL)
    {
        exit(1);
    }

    do{
        system("cls");
        option = menu();
        switch(option)
        {
            case 1:
                if(!isLoad)
                {
                    controller_loadFromText("data.csv", listaEmpleados);
                    printf("Cargado el archivo de texto con exito\n");
                    isLoad = 1;
                }

                system("pause");
                break;

            case 2:
                if(!isLoad)
                {
                    controller_loadFromBinary("data.bin", listaEmpleados);
                    printf("Cargado el archivo binario con exito\n");
                    isLoad = 1;
                }
                system("pause");
                break;

            case 3:
                if(isLoad)
                {
                    controller_addEmployee(listaEmpleados);
                }else
                {
                    printf("Primero cargue los empleados de un archivos\n");
                }
                system("pause");
                break;

            case 4:
                if(isLoad)
                {
                    controller_editEmployee(listaEmpleados);
                }else
                {
                    printf("Primero cargue los empleados de un archivos\n");
                }
                system("pause");
                break;

            case 5:
                if(isLoad)
                {
                    controller_removeEmployee(listaEmpleados);
                }else
                {
                    printf("Primero cargue los empleados de un archivos\n");
                }
                system("pause");
                break;

            case 6:
                if(isLoad)
                {
                    controller_ListEmployee(listaEmpleados);
                }else
                {
                    printf("Primero cargue los empleados de un archivos\n");
                }
                system("pause");
                break;

            case 7:
                if(isLoad)
                {
                    controller_sortEmployee(listaEmpleados);
                }else
                {
                    printf("Primero cargue los empleados de un archivos\n");
                }
                system("pause");
                break;
            case 8:
                if(isLoad)
                {
                    controller_saveAsText("data.csv", listaEmpleados);
                    isLoad = 0;
                }else
                {
                    printf("Primero cargue un archivo antes de guardar\n");
                }
                system("pause");
                break;
            case 9:
                if(isLoad)
                {
                    controller_saveAsBinary("data.bin", listaEmpleados);
                    isLoad = 0;
                }else
                {
                    printf("Primero cargue un archivo antes de guardar\n");
                }
                system("pause");
                break;
            case 10:
                break;
        }
    }while(option != 10);
    return 0;
}

int menu()
{
    int opcion;
    printf("Menu\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    printf("Escoja su opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    while(opcion < 1 || opcion > 10)
    {
        printf("Error. Opcion Incorrecta: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    return opcion;
}

