/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Trabajo Practico 3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
  int ok = -1;
  int cant;
  char buff[4][20];
  Employee* nEmp = NULL;

  fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buff[0], buff[1], buff[2], buff[3]);

    if(pFile!=NULL && pArrayListEmployee!=NULL)
      {
	while(!feof(pFile))
	  {

	    cant= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buff[0], buff[1], buff[2], buff[3]);
	    nEmp=employee_newParametros(buff[0], buff[1], buff[2], buff[3]);
	    if(nEmp!=NULL)
	      {
		ll_add(pArrayListEmployee,nEmp);
		ok=1;
	      }
	    if(cant < 4)
	      {
		if(feof(pFile))
		  {
		    break;
		  }
		else
		  {
		      ok=0;
		    break;
		  }
	      }

	  }
      }


    return ok;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ok=-1;
    int cant;
    Employee* nEmp=NULL;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
      {
	while(!feof(pFile))
	  {
	    cant=fread(nEmp,sizeof(Employee),1,pFile);
	    nEmp=employee_new();

	    if(nEmp!=NULL)
	      {
		ll_add(pArrayListEmployee,nEmp);
		ok=1;
	      }
	    else
	      {
		employee_delete(nEmp);
	      }
	    if(cant<1)
	      {
		if(feof(pFile))
		  {
		    break;
		  }
		else
		  {
		    ok=0;
		    break;
		  }
	      }
	  }
      }
    return ok;
}
