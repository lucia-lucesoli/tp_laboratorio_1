/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Trabajo Practico 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "Empleados.h"

#define TAM 100
#define TAM_P 1000


int main(void) {
	int enEjecucion = 1;
	int nextEmpleadoId = 1001;
	char nombreTmp[20];
	char apellidoTmp[20];
	float salarioTmp;
	int sectorTmp;
	int idTmp;
	int indexEmpleado;
	int opcionInformes;
	eEmpleado empleados[TAM];

	if (!inicializarEmpleados(empleados, TAM)) {
		while (enEjecucion) {
			system("cls");
			fflush(stdin);
			switch(desplegarMenu()) {
				case 1:
					system("cls");
					cargaDatosEmpleado(nombreTmp, apellidoTmp, &salarioTmp, &sectorTmp);

					if (!altaEmpleado(empleados, TAM, nextEmpleadoId, nombreTmp, apellidoTmp, salarioTmp, sectorTmp)) {
						nextEmpleadoId++;
						printf("Se ha registrado el empleado con exito.\n\n");
					} else {
						printf("No se ha podido agregar el empleado porque el listado ya está lleno o no se han pasado los parámetros correctos.\n\n");
					}

					break;
				case 2:
					system("cls");
					printf("Ingrese el ID del Empleado: ");
					scanf("%d", &idTmp);

					indexEmpleado = buscarEmpleadoPorid(empleados, TAM, idTmp);

					if (indexEmpleado > -1) {
						if (!modificarEmpleado(empleados, indexEmpleado)) {
							printf("La modificacion del empleado ha sido exitosa.\n\n");
						} else {
							printf("Hubo un error al modificar los datos del empleado.\n\n");
						}
					} else {
						printf("No se encontro el empleado solicitado\n\n");
					}

					break;
				case 3:
					system("cls");
					printf("Ingrese el ID del empleado: ");
					scanf("%d", &idTmp);
					indexEmpleado = buscarEmpleadoPorid(empleados, TAM, idTmp);

					if (indexEmpleado > -1) {
						if (!bajaEmpleado(empleados, indexEmpleado)) {
							printf("La baja del empleado ha sido exitosa\n\n");
						} else {
							printf("Hubo un error al procesar la baja del empleado\n\n");
						}
					} else {
						printf("No se encontro el empleado solicitado\n\n");
					}
					break;
				case 4:
					printf("1)  Listado de Empleados.\n"
							"2) Informe de salarios.\n");
					scanf("%d", &opcionInformes);

					switch(opcionInformes)
					{
					case 1:
						ordenarEmpleados(empleados, TAM, 0);
						mostrarEmpleados(empleados, TAM);
						break;
					case 2:
						informarSalario(empleados, TAM);
						break;
					default:
						printf("Error al ingresar opcion. Ingrese una opcion valida\n\n");
						break;
					}



					break;
				case 5:
					enEjecucion = 0;
					break;
				default:
					printf("Error al ingresar opcion. Ingrese una opcion valida\n\n");
					break;
			}
			system("pause");
		}
	}

	return EXIT_SUCCESS;
}
