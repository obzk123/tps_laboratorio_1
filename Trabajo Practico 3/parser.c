#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int cant;
    Employee* auxNewEmployee = NULL;
    char buffer[4][30];
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        //Lectura del encabezado
        fscanf(pFile, "%[^,], %[^,], %[^,], %[^,\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,], %[^,], %[^,], %[^,\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant < 4)
            {
                    break;
            }

                auxNewEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(auxNewEmployee != NULL)
                {
                    ll_add(pArrayListEmployee, auxNewEmployee);
                    auxNewEmployee = NULL;
                }
                else
                {
                    printf("Error al cargar el empleado.\n");
                    break;
                }
                todoOk = 1;
       }
    }
    return todoOk;
}



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = NULL;
    int todoOk = 0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        do
        {
            auxEmployee = employee_new();
            if(auxEmployee != NULL)
            {
              if(fread(auxEmployee, sizeof(Employee), 1, pFile) == 1)
              {
                  ll_add(pArrayListEmployee, auxEmployee);
                  auxEmployee = NULL;
                  todoOk = 1;
              }
            }
        }while(!feof(pFile));
    }

    return todoOk;
}
