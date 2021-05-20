#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

#define TAM 5
#define TAMSTRING 51


int menu(int* respuesta);

int submenu();

int modificarEmpleado(Employee* list, int tamList);
int agregarEmpleado(Employee* list, int tamList, int* id);
int eliminarEmpleado(Employee* list, int tamList);
int informarPromedios(Employee* list,int tamList);


int main(void) {
	setbuf(stdout, NULL);
	Employee arrayEmployes[TAM];
	int id = 0;
	int order;
	int respuesta;
	int contadorEmpleados = 0;

	initEmployees(arrayEmployes, TAM);
	do
	{
		system("cls");
		menu(&respuesta);
		switch(respuesta)
		{
			case 1:
				if(contadorEmpleados < TAM){
					system("cls");
					agregarEmpleado(arrayEmployes, TAM, &id);
					contadorEmpleados++;
				}else{
					printf("No hay lugar\n");
				}
				break;

			case 2:
				if(contadorEmpleados > 0){
					system("cls");
					modificarEmpleado(arrayEmployes, TAM);
				}else{
					printf("No hay empleados en la lista\n");
				}
				break;

			case 3:
				if(contadorEmpleados > 0){
					system("cls");
					printEmployees(arrayEmployes,TAM);
					respuesta = eliminarEmpleado(arrayEmployes, TAM);
					if(!respuesta){
						contadorEmpleados--;
					}
				}else
				{
					printf("No hay empleados para eliminar\n");
				}
				break;

			case 4:
				do
				{
					system("cls");
					switch(submenu())
					{
					case 1:
						if(contadorEmpleados > 0)
						{
							system("cls");
							getInt("Ingrese 1 para ordenar apellido de forma Descendente o 0 para Ascendente: ", &order);
							while(order < 0 || order > 1)
							{
								getInt("Error. Ingrese 1 para ordenar Descendente o 0 para Ascendente: ", &order);
							}
							sortEmployees(arrayEmployes, TAM, order);
							printEmployees(arrayEmployes, TAM);
							system("pause");
						}else
						{
							printf("No hay empleados para mostrar\n");
						}
						break;
					case 2:
						informarPromedios(arrayEmployes, TAM);
						system("pause");
						break;

					case 3:
						respuesta = 3;
						break;
					}
				}while(respuesta != 3);

				break;
		}
		system("PAUSE");
	}while(respuesta != 5);
	return EXIT_SUCCESS;
}

int menu(int* respuesta)
{
	int retorno = -1;
	int r;

	if(respuesta != NULL)
	{
		printf("1.ALTAS\n");
		printf("2.MODIFICAR\n");
		printf("3.BAJA\n");
		printf("4.INFORMAR\n");
		printf("5.Salir\n");

		r = scanf("%d", respuesta);
		while(r == 0 || *respuesta > 5)
		{
			printf("Opcion Incorrecta. Ingrese nuevamente: ");
			fflush(stdin);
			r = scanf("%d", respuesta);
		}
		retorno = 0;
	}

	return retorno;
}

int modificarEmpleado(Employee* list, int tamList)
{
	int retorno = -1;
	int id;
	Employee nuevoEmpleado;
	int modificar;
	int i = -1;


	if(list != NULL && tamList > 0)
	{
		printEmployees(list, tamList);
		getInt("Escriba el ID del empleado que desea modificar: ", &id);

		i = findEmployeeById(list, tamList, id);

			if(i != -1)
			{
				nuevoEmpleado = list[i];
				getInt("Que desea modificar:\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector:", &modificar);
				while(modificar > 4 || modificar < 1){
					getInt("Error. Que desea modificar:\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector:", &modificar);
				}
				switch(modificar)
				{
				case 1:
					getString("Escriba el nuevo nombre: ", nuevoEmpleado.name, 51);
					//getString("Escriba el nuevo nombre: ", nombre, 51);
					break;
				case 2:
					getString("Escriba el nuevo apellido: ", nuevoEmpleado.lastName, 51);
					//getString("Escriba el nuevo apellido: ", apellido, 51);
					break;
				case 3:
					getFloat("Escriba el nuevo salario: ", &nuevoEmpleado.salary);
					//getFloat("Escriba el nuevo salario: ", &salario);
					break;
				case 4:
					getInt("Escriba el nuevo sector: ", &nuevoEmpleado.sector);
					//getInt("Escriba el nuevo sector: ", &sector);
					break;
				}
				list[i] = nuevoEmpleado;
				retorno = 0;
				printf("Se modifico con exito\n");
			}
			else
			{
				printf("No existe el ID\n");
			}
		}

	return retorno;
}



int agregarEmpleado(Employee* list, int tamList, int* id)
{
	int retorno = -1;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	if(list != NULL && tamList > 0 && id != NULL)
	{
		printf("ID: %d\n", *id);
		getString("Escriba el nombre: ", nombre, 51);
		getString("Escriba el apellido: ", apellido, 51);
		getFloat("Escriba el salario: ", &salario);
		getInt("Escriba el sector: ", &sector);
		addEmployee(list, tamList, *id, nombre, apellido, salario, sector);
		*id = *id + 1;
		printf("Se creo exitosamente\n");
		retorno = 0;
	}

	return retorno;
}

int eliminarEmpleado(Employee* list, int tamList)
{
	int retorno = -1;
	int id;

	if(list != NULL && tamList > 0)
	{
		getInt("Escriba el ID del empleado que desea eliminar: ", &id);
		removeEmployee(list, tamList, id);
		if(removeEmployee(list, tamList, id) == -1)
		{
			printf("El id no existe\n");
		}
		else
		{
			printf("Se elimino con exito\n");
			retorno = 0;
		}
	}
	return retorno;
}

int submenu()
{
	int respuesta = -1;

		printf("1.Mostrar empleados ordenador\n");
		printf("2.Informar promedio de sueldo\n");
		printf("3.Volver\n");
		scanf("%d", &respuesta);
		while(respuesta < 1 || respuesta > 3)
		{
			printf("Opcion Incorrecta. Ingrese nuevamente: ");
			fflush(stdin);
			scanf("%d", &respuesta);
		}

	return respuesta;
}

int informarPromedios(Employee* list,int tamList)
{
	int retorno = -1;
	float salarioTotal = 0;
	int contadorEmpleados = 0;
	int superanPromedio = 0;
	float promedio;
	if(list != NULL && tamList > 0)
	{
		for(int i = 0; i < tamList; i++)
		{
			if(list[i].isEmpty == 0)
			{
				salarioTotal += list[i].salary;
				contadorEmpleados++;
			}
		}

		promedio = salarioTotal / contadorEmpleados;
		printf("Salario total: %.2f\n", salarioTotal);
		printf("El promedio de sueldo es %.2f\n", promedio);
		for(int i = 0; i < tamList; i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary > promedio)
			{
				superanPromedio++;
			}
		}
		printf("La cantidad de empleados que superan el promedio son: %d\n", superanPromedio);
		retorno = 0;
	}
	return retorno;
}
