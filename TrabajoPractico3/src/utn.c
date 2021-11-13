/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Trabajo Practico 3
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

int esPar(int numero)
{
	int siEs = 0;
	if(numero%2 == 0)
	{
		siEs = 1;
	}
	return siEs;
}

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%c",&buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}
int getString(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
	  do
	  {
	    printf("%s",pMensaje);
	    fpurge(stdin);
	    fgets(buffer,sizeof(buffer),stdin);
	    buffer[strlen(buffer)-1] = '\0';
	    if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
	    {

		strncpy(pResultado,buffer,maximo+1);
		modificarMayus(pResultado);
		    retorno = 0;
		    break;
	    }
	    printf("%s",pMensajeError);
	    reintentos--;
	  }while(reintentos >= 0);
	}
	return retorno;
}

int sumar(int* resultado, int x, int y)
{
	int retorno = -1;
		if(x >= -99 && y <= 99)
		{
			*resultado = x + y;
			retorno= 0;
		}
	return retorno;
}

int restar(int* resultado, int x, int y)
{
	int retorno = -1;
		if(x >= -99 && y <= 99)
		{
			*resultado = x - y;
			retorno= 0;
		}
	return retorno;
}

int dividir(int* resultado, int x, int y)
{
	int retorno = -1;
		if(x == 0 || y == 0)
		{
			retorno = 1;
		}else if(x >= -99 && y <= 99){
			*resultado = x / y;
			retorno= 0;
		}
	return retorno;
}

int multiplicar(int* resultado, int x, int y)
{
	int retorno = -1;
		if(x >= -99 && y <= 99)
		{
			*resultado = x * y;
			retorno= 0;
		}
	return retorno;
}
long int factorizarA(int* resultadoA, int x)
{
	int retorno = -1;
	int i;
	long int fA = 1;
	if(x >= 0)
	{
		for(i=x;1<=i;i--)
		{
			fA =fA*i;
			*resultadoA = fA;
		}
		retorno = 0;
	}
	return retorno;
}
long int factorizarB(int* resultadoB, int y)
{
	int retorno = -1;
	int i;
	long int fB = 1;
	if(y >= 0)
	{
		for(i=y;1<=i;i--)
		{
			fB =fB*i;
			*resultadoB = fB;
		}
		retorno = 0;
	}
	return retorno;
}
void MostrarArray(int pArray[],int cantidad)
{
	for(int i = 0;i<cantidad;i++)
		{
			printf("\nel numero: %d %d",i,pArray[i]);
		}
}

void InicializarArray(int pArray[],int cantidad)
{
	int i;
	for(i = 0;i<cantidad;i++)
	{
		pArray[i]=-1;
	}
}
int SacarLaSuma(int pArray[], int cantidad)
{
	int acumulador=0;

	int i;

	for(i=0;i<cantidad;i++)
	{
		if(pArray[i] != -1)
		{
		acumulador=acumulador+pArray[i];
		}
	}
	return acumulador;
}

int SacarCantidadCargada(int pArray[], int cantidad)
{
	int i;
	int valorDeRetorno=0;
	for(i=0;i<cantidad;i++)
	{
		if(pArray[i]!=-1)
		{
			valorDeRetorno=valorDeRetorno+1;
		}
	}
	return valorDeRetorno;
}
float SacarPromedio(int pArray[],int cantidad)
{
	int cantidadDeElementos;
	int sumaDeElemetos;
	float valorDeRetorno;

	cantidadDeElementos=SacarCantidadCargada(pArray,cantidad);
	sumaDeElemetos=SacarLaSuma(pArray,cantidad);

	valorDeRetorno=(float)sumaDeElemetos/cantidadDeElementos;

	return valorDeRetorno;
}

int menu()
{
  int opcion = 0;
  printf("----------------------------------------------\n"
		  "                 ABM EMPLEADOS               \n"
		  "----------------------------------------------\n\n"
		  "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
		  "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
		  "3. Alta de empleado\n"
		  "4. Modificar datos de empleado\n"
		  "5. Baja de empleado\n"
		  "6. Listar empleados\n"
		  "7. Ordenar empleados\n"
		  "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
		  "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
		  "10. Salir\n\n");
  utn_getNumero(&opcion,"\nIngrese un opcion: ","Opcion invalida",1,10,3);
  return opcion;
}
int menuEdit()
{
  int opcion = 0;
  printf("1.Modificar Nombre.\n2.Modificar horas trabajadas.\n3.Modificar sueldo.\n4.Salir");
  utn_getNumero(&opcion,"\nIngrese un opcion: ","Opcion invalida",1,4,3);
  return opcion;
}
int menuOrdenamiento()
{
  int opcion = 0;
  printf("1.Ordenar por Nombre.\n2.Ordenar por horas trabajadas.\n3.Ordenar por sueldo.\n4.Ordenar por Id\n5.Salir");
  utn_getNumero(&opcion,"\nIngrese un opcion: ","Opcion invalida",1,5,3);
  return opcion;
}
void get_string(char* mensaje,char* string)
{
  printf("%s",mensaje);
  fpurge(stdin);
  gets(string);
}
int numero_valido(char* mensaje,char* mensaje_error,int min, int max,int intentos)
{
  int numero;
  char auxNumero[20];

    if(mensaje!=NULL || min>0 && max>=min)
    {
    	do
    	{
    		get_string(mensaje,auxNumero);

	  if(esNumero(auxNumero))
	    {
	      if(atoi(auxNumero)<=max && atoi(auxNumero)>=min)
		{
		  numero=atoi(auxNumero);
		  break;
		}
	      else
		{
		  printf("error, introduzca un numero entre %d y %d",min,max);
		}
	    }
	  else
	    {
	      printf("%s",mensaje_error);
	      intentos--;
	    }
	  }while(intentos>0);
      }
    return numero;
}

void debug()
{
  printf("debug");
}

void text(char* text)
{
  printf("%s",text);
}

int esNumero(char* string)
{
  int ok=-1;
  int i = 0;

  while(string[i]!='\0')
    {
      if(string[i]<'0' || string[i]>'9')
	{
	  ok=0;
	}
      i++;
    }
  return ok;
}
void modificarMayus(char *s){
	int indice = 1;
	s[0]=toupper(s[0]);
	while(s[indice]!= '\0'){
		s[indice] = tolower(s[indice]);
		if(s[indice] == ' '){
			s[indice+1]=toupper(s[indice+1]);
			indice++;
		}
		indice++;
	}

}


