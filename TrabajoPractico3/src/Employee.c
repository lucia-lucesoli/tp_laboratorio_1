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
#include "utn.h"
#include "parser.h"
#include "Controller.h"

Employee* employee_new()
{
  Employee* this =(Employee*)malloc(sizeof(Employee));
  if(this!=NULL)
    {
      employee_setId(this,0);
      employee_setNombre(this," ");
      employee_setSueldo(this,0);
      employee_setHorasTrabajadas(this,0);
    }
	return this;
}
Employee* employee_newParametros(char* id,char* nombre,char* horasTrabajadas, char* sueldo)
{
    Employee* auxP = employee_new();

      if(id!=NULL && nombre!=NULL && horasTrabajadas!=NULL && sueldo!=NULL)
	{

	  employee_setId(auxP,atoi(id));
	  employee_setHorasTrabajadas(auxP,atoi(horasTrabajadas));
	  employee_setNombre(auxP,nombre);
	  employee_setSueldo(auxP,atoi(sueldo));
	}

    return auxP;
}

int employee_setId(Employee* this,int id)
{
	int ok=-1;
	if(this!=NULL && id>0){
		this->id = id;
		ok=0;
	}
	return ok;
}
int employee_getId(Employee* this,int* id)
{
	int ok=-1;
	if(this!=NULL && id>0)
	  {
	    *id = this->id;
	    ok=0;
	  }
	return ok;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int ok=-1;
	if(this!=NULL && strlen(nombre)>0)
	  {
	    strcpy(this->nombre,nombre);
	    ok=0;
	  }
	return ok;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int ok=-1;
	if(this!=NULL)
	  {
	    strcpy(nombre,this->nombre);
	    ok=0;
	  }
	return ok;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int ok=-1;
	if(this!=NULL && horasTrabajadas>=0)
	  {
	    this->horasTrabajadas = horasTrabajadas;
	    ok=0;
	  }
	return ok;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int ok=-1;
	if(this!=NULL && horasTrabajadas >= 0)
	  {
	    *horasTrabajadas = this->horasTrabajadas;
	    ok=0;
	  }
	return ok;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int ok=-1;
	if(this!=NULL && sueldo >= 0)
	  {
	    this->sueldo = sueldo;
	    ok=0;
	  }
	return ok;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int ok=-1;
	if(this!=NULL && sueldo>=0)
	  {
	    *sueldo = this->sueldo;
	    ok=0;
	  }
	return ok;
}

void employee_delete(Employee* this)
{
     if(this!=NULL)
       {
	 free(this);
       }
}

int auto_id(LinkedList* this)
{
    int ultimoId,id,i;
    static int id_incre;

    Employee* nEmp;

	if(this!=NULL)
	  {
	    for(i=0;i<ll_len(this);i++)
	      {
		nEmp =(Employee*)ll_get(this,i);
		employee_getId(nEmp,&id);

		if(i==0 && id>0)
		  {
		    ultimoId = id;
		  }
		else if(id>ultimoId)
		  {
		    ultimoId = id;
		  }
	      }
	  }
	if(ultimoId > id_incre)
	  {
	    id_incre=ultimoId+1;
	  }
	else
	  {
	    id_incre++;
	  }
	//printf("id_incr %d",id_incre);
	return id_incre;

}

void mostrarEmpleado(Employee* pArrayList)
{
  if(pArrayList!=NULL)
    {
      printf("\n%5d %10s %10d %15d",pArrayList->id,pArrayList->nombre,pArrayList->horasTrabajadas,pArrayList->sueldo);
    }
  else
    {
      printf("\nNo hay empleados para mostrar.");
    }
}
int emp_ord_id(void* emp_1,void* emp_2)
{
  int ok=-1;
  int id_Emp1,id_Emp2;
  Employee* empleado1= NULL;
  Employee* empleado2= NULL;

  if(emp_1 != NULL && emp_2 != NULL)
    {
      empleado1=(Employee*)emp_1;
      empleado2=(Employee*)emp_2;
      employee_getId(empleado1,&id_Emp1);
      employee_getId(empleado2,&id_Emp2);
      if(id_Emp1 > id_Emp2)
	{
	  ok=1;
	}
      else if(id_Emp1 < id_Emp2)
	{
	  ok=0;
	}
    }

  return ok;
}




int emp_ord_nombre(void* emp_1,void* emp_2)
{
  int ok=-1;
  char nombre_Emp1[20],nombre_Emp2[20];
  Employee* empleado1= NULL;
  Employee* empleado2= NULL;

  if(emp_1 != NULL && emp_2 != NULL)
    {
      empleado1=(Employee*)emp_1;
      empleado2=(Employee*)emp_2;
      employee_getNombre(empleado1,nombre_Emp1);
      employee_getNombre(empleado2,nombre_Emp2);
      if(strcmp(nombre_Emp1,nombre_Emp2)>0)
	{
	  ok=1;
	}
      else if(strcmp(nombre_Emp1,nombre_Emp2)<0)
	{
	  ok=0;
	}
    }

  return ok;
}







int emp_ord_horas_trabajadas(void* emp_1,void* emp_2)
{
  int ok=-1;
  int horas_trabajadas_Emp1,horas_trabajadas_Emp2;
  Employee* empleado1= NULL;
  Employee* empleado2= NULL;

  if(emp_1 != NULL && emp_2 != NULL)
    {
      empleado1=(Employee*)emp_1;
      empleado2=(Employee*)emp_2;
      employee_getHorasTrabajadas(empleado1,&horas_trabajadas_Emp1);
      employee_getHorasTrabajadas(empleado2,&horas_trabajadas_Emp2);
      if(horas_trabajadas_Emp1 > horas_trabajadas_Emp2)
	{
	  ok=1;
	}
      else if(horas_trabajadas_Emp1 < horas_trabajadas_Emp2)
	{
	  ok=0;
	}
    }

  return ok;
}



int emp_ord_sueldo(void* emp_1,void* emp_2)
{
  int ok=-1;
  int sueldoEmp1,sueldoEmp2;
  Employee* empleado1= NULL;
  Employee* empleado2= NULL;

  if(emp_1 != NULL && emp_2 != NULL)
    {
      empleado1=(Employee*)emp_1;
      empleado2=(Employee*)emp_2;
      employee_getSueldo(empleado1,&sueldoEmp1);
      employee_getSueldo(empleado2,&sueldoEmp2);
      if(sueldoEmp1 > sueldoEmp2)
	{
	  ok=1;
	}
      else if(sueldoEmp1 < sueldoEmp2)
	{
	  ok=0;
	}
    }

  return ok;
}
