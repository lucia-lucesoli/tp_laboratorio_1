#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int menuPrincipal()
{
    int retorno;

        system("cls");
        printf("*** SISTEMA DE ADMINITRACION DE EMPLEADOS ***\n\n\n");

        printf("1. Alta de usuario.\n");
        printf("2. Modificacion de usuario.\n");
        printf("3. Baja de usuario.\n");
        printf("4. Informes.\n");
        printf("5. Salir.\n\n");

        printf("Ingrese opcion: ");
        scanf("%d", &opcionIngresada);

        return retorno;
}



void mostrarEmpleado(ePersona unaPersona)
{
	printf("%5d    %10s    %10s    %d    %6f\n",unaPersona.legajo, unaPersona.apellido, unaPersona.nombre, unaPersona.sector, unaPersona.sueldo);
}

int mostrarEmpleado(ePersona gente[], int tam)
{
	system("cls");
	int flag = 0 ;

	printf("**  Legajo  |  Apellido  |  Nombre  |  Sector  |  Sueldo  **\n");
	printf("------------------------------------------------------------\n");

	if (gente != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam; i++)
		{
			if(gente[i].isEmpty == 0 )
			{
				mostrarEmpleado(gente[i]);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			printf("No se ingreso ningun empleado en el sistema");
		}

	}

	printf("\n\n");

	return 0;
}

int altaPersona(ePersona gente[], int tam, int legajo)
{
	int error = 1;
	int indiceEmpty;
	ePersona nuevoIngresante;

	if( gente != NULL && tam > 0 && legajo > 0)
	{
		indiceEmpty = buscarLibre(gente, tam);

		if(indiceEmpty == -1)
		{
			printf("\n\n** Se ocupo toda la capacidad de altas de empleados **");
		}
		else
		{
			nuevoIngresante.legajo = legajo;
			nuevoIngresante.isEmpty = 0;

			printf("** Alta de nuevo empleado **");

			printf("Ingrese el apellido del nuevo ingresante: \n");
			fflush(stdin);
			gets(nuevoIngresante.apellido);

			printf("Ingrese el nombre: \n");
			fflush(stdin);
			gets(nuevoIngresante.nombre);

            printf("Ingrese el sector a ubicar: \n");
			scanf("%d", &nuevoIngresante.sector);

			printf("Ingrese el sueldo: \n");
			scanf("%f", &nuevoIngresante.sueldo);

			gente[indiceEmpty] = nuevoIngresante;

			error = 0;
		}
	}
	return error;
}

int inicioDePersonas(ePersona gente[], int tam)
{
	int error = 1;

	if( gente != NULL && tam > 0 )
	{
		for(int i = 0 ; i < tam ; i++ )
		{
			gente[i].isEmpty = 1;
			gente[i].sueldo = 0;
		}
		error = 0;
	}
	return error;
}


int ordenPersonasSector(ePersona gente[], int tam)
{
    int error = 1;
	ePersona auxPersona;

	if (gente != NULL && tam > 0)
    {
        for( int i = 0 ; i < tam -1 ; i++)
        {
            for(int j = i+1 ; j < tam ; j++)
            {
                if( gente[i].sector > gente[j].sector )
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
            }
        }
        error = 0 ;
    }

	return error;
}


int buscarPersona(ePersona gente[], int tam, int legajo)
{
	int retorno = -1;

	if( gente != NULL && tam > 0)
	{
		for( int i = 0 ; i < tam ; i++ )
		{
			if(gente[i].legajo == legajo && gente[i].isEmpty == 0 )
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}




int ordenPersonasApellido(ePersonas gente[], int tam)
{
 	int error = 1;
 	ePersonas auxPersona;

 	if ( gente != NULL && tam > 0 )
 	{
	 	for( int i = 0 ; i < tam -1 ; i++)
		{
			for(int j = i+1 ; j < tam ; j++)
			{
				if(strcmp(gente[i].apellido, gente[j].apellido) > 0 )
				{
					auxPersona = gente[i];
					gente[i] = gente[j];
					gente[j] = auxPersona;
				}
			}
		}
		error = 0;
 	}

 	return error;
}

int modificarPersona(ePersona gente[], int tam)
{
	int legajo;
	int menu;
	int error = 1;
	char confirmar;
	int opcionModificarPersona;

	ePersona empleadoAux;

	if( gente != NULL && tam > 0)
	{
		system("cls");
		printf(" ***/// Modificar informacion del empleado \\\***\n\n");

		mostrarEmpleados(gente, tam);

		printf("Ingrese el numero de legajo: ");
		scanf("%d", &legajo);

		menu = buscarEmpleado(gente, tam, legajo);

		if(menu == -1)
		{
			printf("No existe un empleado con ese numero de legajo.\n");
			system("pause");
		}
		else
		{
			mostrarEmpleado(gente[menu]);

			printf("\n\nElija el dato a modificar: \n\n");
			printf("1. Apellido\n");
			printf("2. Nombre\n");
			printf("3. Sector\n");
			printf("4. Sueldo\n\n");
			printf("Ingrese opcion: ");
			scanf("%d", &opcionModificarPersona);

			switch(opcionModificarPersona)
			{
            case 1:
                printf("\n Apellido a modificar: ");
                scanf("%s", empleadoAux.apellido);

                printf("Confirmacion del apellido modificado - (s/n):  ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                printf("\n\n");

                if(confirma == 's')
                {
                    strcpy(gente[menu].apellido, empleadoAux.apellido);
                    mostrarEmpleado(gente[menu]);
                    system("pause");

                    error=0;
                }
                else
                {
                    error = 2 ;
                }
                break;
            case 2:
                printf("\n Nombre a modificar:");
                scanf("%s", empleadoAux.nombre);

                printf("Confirmacion del nombre modificado - (s/n): ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                printf("\n\n");

                if(confirma == 's')
                {
                    strcpy(gente[indice].nombre, empleadoAux.nombre );
                    mostrarEmpleado(gente[indice]);
                    system("pause");

                    error=0;
                }
                else
                {
                    error = 2 ;
                }
                break;

            case 3:
                printf("\n Sector a modificar: ");
                scanf("%d", &empleadoAux.sector);

                printf("Confirmacion del sector modificado - (s/n): ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                printf("\n\n");

                if(confirma == 's')
                {
                    gente[indice].sector = empleadoAux.sector;
                    mostrarEmpleado(gente[indice]);
                    system("pause");

                    error=0;
                }
                else
                {
                    error = 2 ;
                }
                break;
            case 4:
                printf("\n Modificacion de Sueldo: ");
                scanf("%f", &empleadoAux.sueldo);

                printf("Confirmacion del sueldo modificado - (s/n):");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                printf("\n\n");

                if(confirma == 's')
                {
                    gente[indice].sueldo = empleadoAux.sueldo;
                    mostrarEmpleado(gente[indice]);
                    system("pause");

                    error=0;
                }
                else
                {
                    error = 2 ;
                }
                break;
            default:
                printf("\nLa opcion ingresada es incorrecta. Por favor, reingrese una opcion\n");
			}
        }
	}

	return error;
}

int bajaPersona(ePersona gente[], int tam)
{

	int legajo;
	int menu;
	char confirma;
	int error = 1;

	if( gente != NULL && tam > 0)
	{
		system("cls");
		printf("\n\n** Baja de empleados **");

		mostrarEmpleados(gente, tam);

		printf("Ingrese el numero de legajo: ");
		scanf("%d", &legajo);

		menu = buscarEmpleado(gente, tam, legajo);

		if(menu == -1)
		{
			printf("Error, no existe empleado con ese numero de legajo.\n");
		}
		else
		{
			mostrarEmpleado(gente[menu]);
			printf("\nConfirma la baja del empleado ingresado? (s/n) ");
			fflush(stdin);
			scanf("%c", &confirma);

			if(confirma == 's')
			{
				gente[menu].isEmpty = 1;

				error=0;
			}
			else
			{
				error = 2 ;
			}
		}
	}

	return error;
}





