/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Trabajo Practico 3
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
  int ok=-1;
  FILE* pFile;
  if(path!=NULL && pArrayListEmployee!=NULL)
    {
      pFile =fopen(path,"r");
	if(pFile!=NULL)
	  {
	      if(parser_EmployeeFromText(pFile,pArrayListEmployee)==1)
		{
		  printf("\nLeido\n");
		  ok = 1;
		}
	      else if(parser_EmployeeFromText(pFile,pArrayListEmployee)==0)
		{
		  printf("\nMal leido");
		}
	      else
		{
		  printf("\nError");
		}
	  }
    }

  return ok;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ok=-1;

	  FILE* pFile;
	  if(path!=NULL && pArrayListEmployee!=NULL)
	    {
	      pFile=fopen(path,"wb");

		if(pFile!=NULL)
		  {
		    parser_EmployeeFromBinary(pFile,pArrayListEmployee);
		    printf("Leido");
		    fclose(pFile);
		    ok=1;
		  }
		else
		  {
		    printf("Error al cargar");
		    ok=0;
		  }
	    }
    return ok;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ok=-1;
    int auxId;
    int auxSueldo;
    int auxHrTb;
    char nombre[20];


    if(pArrayListEmployee!=NULL)
      {
	//debug();
	Employee* nEmp = employee_new();
	auxId=auto_id(pArrayListEmployee);
	getString(nombre,"Nombre:","\nError",0,20,3);
	utn_getNumero(&auxSueldo,"Sueldo: ","\nError",0,900000,3);
	utn_getNumero(&auxHrTb,"Horas Trabajadas: ","\nError",1,900,3);
	fflush(stdin);

	//printf("%d",auxHrTb);
	 if(!employee_setNombre(nEmp,nombre)&&
	 !employee_setId(nEmp,auxId)&&
	 !employee_setSueldo(nEmp,auxSueldo)&&
	 !employee_setHorasTrabajadas(nEmp,auxHrTb))
	   {
	     //debug();
	     if(!ll_add(pArrayListEmployee,nEmp))
	    	   {
	    	     text("\nOk");
	    	   }
	   }


      }
    return ok;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ok = -1;
    Employee* Edit_Emp;
    char resp = ' ';
    char seguir = ' ';
    char n_nombre[21];
    int n_sueldo,n_HsTb,id_,id_m,i;
    int ll_tam = auto_id(pArrayListEmployee);


	controller_ListEmployee(pArrayListEmployee);
	utn_getNumero(&id_m,"\nIngrese el id a modificar","\nError",1,ll_tam-1,3);

	if(pArrayListEmployee!=NULL)
	  {
	    for(i=0;i<ll_tam;i++)
	      {
		Edit_Emp = (Employee*)ll_get(pArrayListEmployee,i);
		employee_getId(Edit_Emp,&id_);

		if(id_ == id_m)
		  {
		    while(seguir !='n')
		      {
		      switch(menuEdit())
		      {
			case 1:
			  getString(n_nombre,"\nNuevo nombre: ","Error",0,20,3);
			  if(employee_setNombre(Edit_Emp,n_nombre)==0){text("Modificado con exito");ok=1;}

			  break;
			case 2:
			  utn_getNumero(&n_HsTb,"Nuevas horas trabajadas: ","Error",0,1000,3);
			  if(employee_setHorasTrabajadas(Edit_Emp,n_HsTb)==0){text("Modificado con exito");ok=1;}

			  break;
			case 3:
			  utn_getNumero(&n_sueldo,"Nuevo sueldo: ","Error",0,900000,3);
			  if(employee_setSueldo(Edit_Emp,n_sueldo)==0){text("Modificado con exito");ok=1;}
			  break;
			case 4:
			  printf("Desea salir?\n");
			  fflush(stdin);
			  scanf("%c",&resp);
			  if(resp == 's'){
				  seguir = 'n';

			  }
			  break;
		      }
		    }
		  }

	      }

	  }


    return ok;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ok=-1;
    Employee* rEmp;
    int id_r,id_aux;
    int ll_tam;
    int i;
    ll_tam = auto_id(pArrayListEmployee);
    controller_ListEmployee(pArrayListEmployee);
    utn_getNumero(&id_r,"Ingrese el id a eliminar","\nError",1,ll_tam-1,3);

    if(pArrayListEmployee!=NULL)
      {
	for(i=0;i<ll_tam;i++)
	  {
	    rEmp = (Employee*)ll_get(pArrayListEmployee,i);
	    employee_getId(rEmp,&id_aux);
	    if(id_aux==id_r)
	      {
		ll_remove(pArrayListEmployee,i);
		text("Eliminado");
		ok=1;
		break;
	      }

	  }
	if(ok==-1)
	  {
	    text("Empleado no encontrado");
	  }
      }
    return ok;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ok=-1;
    int i;
    Employee* auxEmp;
    int tamList;
    if(pArrayListEmployee!=NULL)
      {
	tamList=ll_len(pArrayListEmployee);
	printf("-------------------------------------------------\n");
	printf("  ID  |  NOMBRE  |  HORAS TRABAJADAS  |  SUELDO  \n");
	printf("-------------------------------------------------\n");

	for(i=0;i<tamList;i++)
	  {
	    auxEmp = (Employee*)ll_get(pArrayListEmployee,i);
	    mostrarEmpleado(auxEmp);
	    ok=1;
	  }
      }
    return ok;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ok=-1;
    char resp=' ';
    char seguir = ' ';
    if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0)
      {
	while(seguir!='n')
	  {
	    switch(menuOrdenamiento())
	    {
	      case 1:
		ll_sort(pArrayListEmployee,emp_ord_nombre,1);
		break;
	      case 2:
		ll_sort(pArrayListEmployee,emp_ord_horas_trabajadas,1);
		break;
	      case 3:
		ll_sort(pArrayListEmployee,emp_ord_sueldo,1);
		break;
	      case 4:
		ll_sort(pArrayListEmployee,emp_ord_id,1);
		break;
	      case 5:
		printf("Desea salir?\n");
		fflush(stdin);
		scanf("%c",&resp);
		if(resp=='s')
		  {
		    seguir='n';
		  }

		break;

	    }
	  }
      }
    return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
  int ok=-1;
  FILE* pArch;
  Employee* Emp;
  int id,sueldo,hsTb,i;
  char nombre[20];
  int ll_tam=-1;


      if(path!=NULL && pArrayListEmployee!=NULL)
	{
	  ll_tam=ll_len(pArrayListEmployee);
	  //debug();
	  //printf("%d",ll_tam);
	  if(ll_tam>0)
	    {
	     pArch = fopen(path,"w");
	      if(pArch!=NULL)
		{
	    	 fprintf(pArch,"id,nombre,horas,trabajadas,sueldo");
		  for(i=0;i<ll_tam;i++)
		    {
		      Emp=(Employee*)ll_get(pArrayListEmployee,i);
		      employee_getHorasTrabajadas(Emp,&hsTb);
		      employee_getId(Emp,&id);
		      employee_getNombre(Emp,nombre);
		      employee_getSueldo(Emp,&sueldo);
		      fprintf(pArch,"%d,%s,%d,%d\n",id,nombre,hsTb,sueldo);
		    }
		  fclose(pArch);
		  if(i == ll_tam)
		    {
		      ok=1;
		    }

		}
	    }
	}
      if(ok==1)
	{
	  text("Guardado");

	}
      else
	{
	  text("Error al escribir");
	}

     return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ok=-1;
    FILE* bin;
    Employee* emp_b;
    int ll_tam=-1,i;

    if(path!=NULL && pArrayListEmployee!=NULL)
      {
	ll_tam=ll_len(pArrayListEmployee);
	if(ll_tam>0)
	  {
	    if((bin = fopen(path,"wb"))!=NULL)
	      {
		text("Abierto Exitosamente!!");
		for(i=0;i<ll_tam;i++)
		  {
		    emp_b=ll_get(pArrayListEmployee,i);
		    if(emp_b!=NULL)
		      {
			fwrite(emp_b,sizeof(Employee),1,bin);
			ok=0;
		      }
		  }
		fclose(bin);
	      }


	  }
	text("Datos .bin guardados");
      }
    else
      {
	text("No se pudo guardar");
      }
    return ok;
}

