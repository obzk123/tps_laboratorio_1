#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ArrayEmployees.h"


int initEmployees(Employee* list, int len)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].id = -1;
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;

	if(list != NULL && len > 0 && name != NULL && lastName != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = 0;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].id == id)
			{
				list[i].isEmpty = 1;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	Employee auxEmpleados;


	if(list != NULL && len > 0 && order >= 0 && order <= 1)
	{
		for(int i = 0; i < len - 1; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if( (list[i].sector < list[j].sector) || (list[i].sector == list[j].sector && strcmpi(list[i].lastName, list[j].lastName) > order) )
				{
					auxEmpleados = list[i];
					list[i] = list[j];
					list[j] = auxEmpleados;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int printEmployees(Employee* list, int length)
{
	printf("ID  |   Name   |   Last Name  |   Salary   |  Sector\n");
	for(int i = 0; i < length; i++)
	{
		if(list[i].isEmpty == 0)
		{
			printf("%2d  |%9s |%9s     |   %5.2f  |     %d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
		}
	}

	return 0;
}

