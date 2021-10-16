/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Trabajo Practico 2
 ============================================================================
 */


#include "Empleados.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int inicializarEmpleados(eEmpleado empleados[], int tam)
{
	int error = 1;

	if (empleados != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			empleados[i].isEmpty = 1;
		}
		error = 0;
	}
	return error;
}




int altaEmpleado(eEmpleado empleados[], int tam, int id, char nombre[], char apellido[], float salario, int sector)
{
	int error = 1;

	if (empleados != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if (empleados[i].isEmpty)
			{
				empleados[i].id = id;
				strcpy(empleados[i].nombre, nombre);
				strcpy(empleados[i].apellido, apellido);
				empleados[i].salario = salario;
				empleados[i].sector = sector;
				empleados[i].isEmpty = 0;
				error = 0;
				break;
			}
		}
	}
	return error;
}



void mostrarEmpleado(eEmpleado empleados)
{
	printf(" %5d     %15s      %15s         %5.2f    %5d\n", empleados.id, empleados.apellido, empleados.nombre, empleados.salario, empleados.sector);

}

void mostrarEmpleados(eEmpleado empleados[], int tam)
{
	printf("                       *** Lista de Empleados *** \n");
	printf("------------------------------------------------------------------------------\n");
	printf("   ID    |       Apellido       |       Nombre       |   Sueldo   |   Sector\n");
	printf("------------------------------------------------------------------------------\n");
		for (int i = 0; i < tam; i++) {
			if (!empleados[i].isEmpty) {
				mostrarEmpleado(empleados[i]);
			}
		}


}


int buscarEmpleadoPorid(eEmpleado empleados[], int tam, int id)
{
	int index = -1;

	if (empleados != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (empleados[i].id == id) {
				index = i;
				break;
			}
		}
	}
	return index;
}





int modificarEmpleado(eEmpleado empleados[], int indice)
{
	int error = 1;

	if (empleados != NULL && indice >=0)
	{
		printf("Datos del empleado: \n");
		mostrarEmpleado(empleados[indice]);
		printf("\nIngrese el nuevo Nombre: ");
		scanf("%s", empleados[indice].nombre);
		printf("\nIngrese el nuevo Apellido: ");
		scanf("%s", empleados[indice].apellido);
		printf("\nIngrese el nuevo Salario: ");
		scanf("%f", &empleados[indice].salario);
		printf("\nIngrese el nuevo Sector: ");
		scanf("%d", &empleados[indice].sector);

		error = 0;
	}
	return error;
}



int bajaEmpleado(eEmpleado empleados[], int indice)
{
	int error = 1;

	if (empleados != NULL && indice >= 0) {
		empleados[indice].isEmpty = 1;
		error = 0;
	}

	return error;
}



int ordenarEmpleados(eEmpleado empleados[], int tam, int orden)
{
	int error = 1;

	if (empleados != NULL && tam > 0)
	{
		eEmpleado empleadoTemporal;

		for (int i = 0; i < tam-1; i++)
		{
			for (int j = i+1; j < tam; j++)
			{
				if ((strcmp(empleados[i].apellido, empleados[j].apellido) < 0 && orden) || (strcmp(empleados[i].apellido, empleados[j].apellido) > 0 && !orden))
				{
					empleadoTemporal = empleados[i];
					empleados[i] = empleados[j];
					empleados[j] = empleadoTemporal;
				}else if((strcmp(empleados[i].apellido, empleados[j].apellido) == 0) && ((empleados[i].sector < empleados[j].sector && orden) || (empleados[i].sector > empleados[j].sector && !orden))){
					empleadoTemporal = empleados[i];
					empleados[i] = empleados[j];
					empleados[j] = empleadoTemporal;
				}

			}

		}
 	}


	return error;
}


float totalSalario(eEmpleado empleados[], int tam)
{
	float total = -1;
	if(empleados != NULL && tam > 0) {
		for(int i = 0; i < tam; i++) {
			if(!empleados[i].isEmpty) {
				total += empleados[i].salario;
			}
		}
	}
	if(total > -1) {
		total++;
	}
	return total;
}


float getSalarioPromedio(eEmpleado empleados[], int tam, float totalSalario)
{
	float promedio = -1;
	int cont = 0;
	if(empleados != NULL && tam > 0) {
		for(int i = 0; i < tam; i++) {
			if(!empleados[i].isEmpty) {
				cont++;
			}
		}
		if(cont > 0) {
			promedio = totalSalario / cont;
		}
	}
	return promedio;
}



int getEmpleadosSuperiorPromedio(eEmpleado empleados[], int tam, float salarioPromedio)
{
	int cont = 0;
	if(empleados != NULL && tam > 0 && salarioPromedio > -1) {
		for(int i = 0; i < tam; i++) {
			if(!empleados[i].isEmpty && empleados[i].salario >= salarioPromedio) {
				cont++;
			}
		}
	}
	return cont;
}
int informarSalario(eEmpleado empleados[], int tam)
{
	int error = -1;
	float salarioTotal;
	float salarioPromedio;
	int cont = -1;
	if(empleados != NULL && tam > 0) {
		salarioTotal = totalSalario(empleados, tam);
		if(salarioTotal > -1) {
			salarioPromedio = getSalarioPromedio(empleados, tam, salarioTotal);
			cont = getEmpleadosSuperiorPromedio(empleados, tam, salarioPromedio);
		} else {
			printf("\nError al calcular el total de salarios.\n\n");
		}

		if(cont > 0) {
			printf("\n\nEl salario total es de: %.2f\n", salarioTotal);
			printf("El salario promedio es de: %.2f\n", salarioPromedio);
			printf("Hay %d empleados que cobran por encima del salario promedio.\n\n", cont);
			error = 0;
		}
	}
	return error;
}















