/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Trabajo Practico 2
 ============================================================================
 */


#include "inputs.h"
#include <stdlib.h>
#include <stdio.h>

int desplegarMenu() {
	int retorno = -1;
	int input;

	printf("***        ABM EMPLEADOS        ***\n\n"
			"1) Alta de empleados\n"
			"2) Modificar datos del empleado\n"
			"3) Dar de baja un empleado\n"
			"4) Informar empleados\n"
			"5) Salir\n");
	printf("Ingrese la opcion: ");
	scanf("%d", &input);
	if (input >= 1 && input <= 5) {
		retorno = input;
	}

	return retorno;
}



void cargaDatosEmpleado(char nombre[], char apellido[], float * salario, int * sector)
{
	printf("Ingrese el nombre del empleado: ");
	fflush(stdin);
	scanf("%s", nombre);

	printf("Ingrese el apellido del empleado: ");
	fflush(stdin);
	scanf("%s", apellido);

	printf("\nIngrese el Salario del empleado: ");
	scanf("%f", salario);

	printf("\nIngrese el Sector del empleado: ");
	scanf("%d", sector);

}

