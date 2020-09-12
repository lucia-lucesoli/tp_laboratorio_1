#include <stdio.h>
#include <stdlib.h>
#include "FuncionesCalculadora.h"

int main()
{
    int opcion;
    int opcionOperaciones;
    float numero1, numero2;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int flag4 = 0;
    int flag5 = 0;
    char salir = 'n';

    do
    {
        system("cls");
        printf("++++ CALCULADORA ++++\n\n");
        printf("1. Ingresar el primer operando.");
        if(flag1 == 0)
        {
            printf("\n");
            flag1 = 1;
        }
        else
        {
            printf(" = %.2f \n",numero1);
        }
        printf("2. Ingresar el segundo operando.");
        if(flag2 == 0)
        {
            printf("\n");
            flag2 = 1;
        }
        else
        {
            printf(" = %2.f \n",numero2);
        }
        printf("3. Calcular todas las operaciones.\n");
        printf("4. Informar los resultados de las operaciones.\n");
        printf("5. Salir.\n\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("Ingrese el primer operando: ");
                scanf("%f",&numero1);
                flag3 = 1;
                break;
            case 2:
                system("cls");
                printf("Ingrese el segundo operando: ");
                scanf("%f",&numero2);
                flag4 = 1;
                break;
            case 3:
                if(flag3 == 1 && flag4 == 1)
                {
                    system("cls");
                    printf("*** OPERACIONES CON LOS OPERANDO ***\n\n");
                    printf("1) Calcular la suma (A+B).\n");
                    printf("2) Calcular la resta (A-B).\n");
                    printf("3) Calcular la division (A/B).\n");
                    printf("4) Calcular la multiplicacion (A*B).\n");
                    printf("5) Calcular el factorial (A! y B!).\n\n");
                    printf("Ingrese opcion: ");
                    scanf("%d", &opcionOperaciones);
                    flag5 = 1;
                }else
                {
                    printf("Error, primero debe ingresar los dos operandos\n");
                    system("pause");
                }



                    switch(opcionOperaciones)
                    {
                    case 1:
                        system("cls");
                        printf("*** RESULTADO DE LA SUMA ***\n\n");
                        printf("Suma entre los operandos: %.2f + %.2f = %.2f\n",numero1,numero2,suma(numero1,numero2));
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        printf("*** RESULTADO DE LA RESTA ***\n\n");
                        printf("Resta entre los operandos: %.2f - %.2f = %.2f\n",numero1,numero2,resta(numero1,numero2));
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        printf("*** RESULTADO DE LA DIVISION ***\n\n");
                        if(numero2 == 0)
                        {
                            printf("Error, no es posible dividir por cero.");
                        }else
                        {
                            printf("Division entre los operandos: %.2f / %.2f = %.2f\n",numero1,numero2,division(numero1,numero2));
                        }
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        printf("*** RESULTADO DE LA MULTIPLICACION ***\n\n");
                        printf("Multiplicacion entre los operandos: %.2f * %.2f = %.2f\n",numero1,numero2,multiplicacion(numero1,numero2));
                        system("pause");
                        break;
                    case 5:
                        system("cls");
                        printf("*** RESULTADO DEL FACTOREO  ***\n\n");
                        printf("El factoreo de %.2f es = %d\n",numero1,factoreo(numero1));
                        printf("El factoreo de %.2f es = %d\n",numero2,factoreo(numero2));
                        system("pause");
                        break;

                    default:
                        printf("Error, indique la opcion que desea realizar.");
                        break;
                    }
                    break;

            case 4:
                if(flag5 == 1)
                {
                    system("cls");
                    printf("*** RESULTADO DE TODAS LAS OPERACIONES CON LOS OPERANDOS ***\n\n\n");
                    printf("Suma entre los operandos = %.2f \n\n",suma(numero1,numero2));
                    printf("Resta entre los operandos = %.2f \n\n",resta(numero1,numero2));
                    if(numero2 == 0)
                    {
                        printf("Division entre los operandos = Error, no es posible dividir por cero.\n\n");
                    }else
                    {
                        printf("Division entre los operandos = %.2f \n\n",division(numero1,numero2));
                    }
                    printf("Multiplicacion entre los operandos = %.2f \n\n",multiplicacion(numero1,numero2));
                    printf("Factoreo de los opreandos:\n");
                    printf("El factoreo del primero = %d\n",factoreo(numero1));
                    printf("El factoreo del segundo = %d\n\n",factoreo(numero2));
                    system("pause");
                }else
                {
                    printf("Error, primero debe calcular los dos operandos\n");
                    system("pause");
                }
                break;

            case 5:
                system("cls");
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
