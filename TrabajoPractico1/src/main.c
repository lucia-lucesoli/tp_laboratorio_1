/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1
 Descripcion: Trabajo Practico 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesCalculadora.h"

int main()
{
	setbuf(stdout,NULL);
    int opcion;
    float numero1;
    float numero2;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    char salir = 'n';

    do
    {
        system("clear");
        printf("++++ CALCULADORA ++++\n\n");
        printf("1. Ingresar el primer operando.");
        if(flag1 == 0)
        {
            printf("\n");
        }
        else
        {
            printf(" = %.2f \n",numero1);
        }
        printf("2. Ingresar el segundo operando.");
        if(flag2 == 0)
        {
        	printf("\n");
        }
        else
        {
        	printf(" = %.2f \n",numero2);
        }
        printf("3. Calcular todas las operaciones.\n");
        printf("4. Informar los resultados de las operaciones.\n");
        printf("5. Salir.\n\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("clear");
                printf("Ingrese el primer operando: ");
                scanf("%f",&numero1);
                flag1 = 1;
                break;
            case 2:
                system("clear");
                printf("Ingrese el segundo operando: ");
                scanf("%f",&numero2);
                flag2 = 1;
                break;
            case 3:
            	if(flag1 == 1 && flag2 == 1)
            	{
            		system("clear");
            	    printf("*** OPERACIONES CON LOS OPERANDO ***\n\n");
            	    printf("a) Calcular la suma (A+B).\n");
            	    printf("b) Calcular la resta (A-B).\n");
            	    printf("c) Calcular la division (A/B).\n");
            	    printf("d) Calcular la multiplicacion (A*B).\n");
            	    printf("e) Calcular el factorial (A! y B!).\n\n");
            	    flag3 = 1;
            	}else
            	{
            		printf("Error, primero debe ingresar los dos operandos\n");
            	}
                break;


            case 4:
                if(flag3 == 1)
                {
                    system("clear");
                    printf("*** RESULTADO DE TODAS LAS OPERACIONES CON LOS OPERANDOS ***\n\n\n");
                    printf("a) La suma entre los operandos es = %.2f \n\n",suma(numero1,numero2));
                    printf("b) La resta entre los operandos es = %.2f \n\n",resta(numero1,numero2));
                    if(numero2 == 0)
                    {
                        printf("La division entre los operandos es = Error, no es posible dividir por cero.\n\n");
                    }else
                    {
                        printf("La division entre los operandos es= %.2f \n\n",division(numero1,numero2));
                    }
                    printf("La multiplicacion entre los operandos es = %.2f \n\n",multiplicacion(numero1,numero2));
                    printf("El factoreo de los opreandos es:\n");
                    printf("Factoreo del primero = %d\n",factoreo(numero1));
                    printf("Factoreo del segundo = %d\n\n",factoreo(numero2));
                }else
                {
                    printf("Error, primero debe calcular los dos operandos\n");
                }
                break;

            case 5:
                system("clear");
                printf("Desea salir? (s/n) \n");
                fflush(stdin);
                scanf("%c",&salir);
                break;

            default:
                printf("Error, indique la opcion que desea realizar.");
                break;
        }




    }
    while(salir != 's');

    return 0;
}
