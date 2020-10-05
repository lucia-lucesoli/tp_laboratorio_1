#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesSistema.h"

#define TAM 1000



int main()
{
    char salir = 'n';
    int opcionIngresada;
    int opcionInformarPersonas;
    int opcionModificarPersona;
    int altaPersona;
    int flagAltaEmpelado;
    int legajoNuevoEmpleado = 30000;
    int AlertaBajaEmpleado;
    int AlertaModificacionEmpleado;
    int ePersona, lista[TAM];
    int persona;
    persona=ePersona;

    inicioDePersonas(lista, TAM);


    do
    {
        system("cls");
        opcionIngresada = menuPrincipal();


        switch(opcionIngresada)
        {
            case 1:
                if(altaPersona == 0)
                {
                    legajoNuevoEmpleado++;
                    printf("El alta se ha realizado con exito");
                    flagAltaEmpelado++;
                }else{

                    printf("Error al realizar el alta del empleado. Reintentar.");
                }
                break;
            case 2:
                if(opcionInformarPersonas == 0)
                {
                    AlertaModificacionEmpleado = modificarPersona(lista, TAM);

                    if(AlertaModificacionEmpleado == 0)
                    {
                        printf("Se modifico la informacion del empleado con exito");
                    }else{

                        printf("Error al modificar la informacion del empleado. Reintentar");
                    }
                }else{
                    printf("Error, primero debe realizar el alta de un empleado");
                    system("pause");
                }
                break;
            case 3:
                if(AlertaBajaEmpleado == 0)
                {
                    printf("Se realizo la baja del empleado con exito");
                }else{

                    printf("Error al dar de baja al empleado. Reintentar");
                }
                break;
            case 4:
                 if(flagAltaEmpelado == 0)
                {
                    printf("Error, primero debe realizar correctamente el alta de empleados.");
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf(" *** INFORMACION EMPLEADOS *** \n\n");
                    printf("1. Listar por orden alfabetico de Apellido\n");
                    printf("2. Listar por sector\n");
                    printf("Ingrese una opcion: ");
                    scanf("%d", &opcionInformarPersonas);

                    switch(opcionInformarPersonas)
                    {
                         case 1:
                        if(ordenPersonasApellido(lista, TAM) == 1  )
                        {
                            printf("Error al ordenar los empleados por apellidos. Reintentar.");
                        }
                        else
                        {
                            printf("Se ha realizado con exito el orden de los empleados por apellido.\n\n");
                            mostrarEmpleado(lista,TAM);
                            system("pause");
                        }
                        break;
                    case 2:
                        if(ordenPersonasSector(lista,TAM) == 1)
                        {
                            printf("Error al ordenar los empleados por sector. Reintentar.");
                        }
                        else
                        {
                            printf("\nSe ha realizado con exito el orden de los empleados por sector.\n\n");
                            mostrarEmpleados(lista,TAM);
                            system("pause");
                        }
                        break;
                    default:
                        system("cls");
                        printf("\n\¡Error, opcion incorrecta. Reingrese la opcion que desea realizar! \n\n");
                        system("pause");
                        break;
                    }
                break;
            case 5:
                system("cls");
                printf("Desea salir? (s/n) \n");
                fflush(stdin);
                scanf("%c",&salir);
                break;
            default:
                system("cls");
                printf("\n\¡Error, opcion incorrecta. Reingrese la opcion que desea realizar! \n\n");
                system("pause");
                break;
            }
        }

    }while(salir != 's');

    return 0;
}







