/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Trabajo Practico 2
 ============================================================================
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

typedef struct {
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
} eEmpleado;



#endif /* EMPLEADOS_H_ */

int inicializarEmpleados(eEmpleado empleados[], int tam);
int altaEmpleado(eEmpleado empleados[], int tam, int id, char nombre[], char apellido[], float salario, int sector);
int modificarEmpleado(eEmpleado empleados[], int indice);
int bajaEmpleado(eEmpleado empleados[], int indice);

void mostrarEmpleado(eEmpleado empleados);
void mostrarEmpleados(eEmpleado empleados[], int tam);
int buscarEmpleadoPorid(eEmpleado empleados[], int tam, int id);

int ordenarEmpleados(eEmpleado empleados[], int tam, int orden);



float totalSalario(eEmpleado empleados[], int tam);
float getSalarioPromedio(eEmpleado empleados[], int tam, float totalSalario);
int getEmpleadosSuperiorPromedio(eEmpleado empleados[], int tam, float salarioPromedio);
int informarSalario(eEmpleado empleados[], int tam);



