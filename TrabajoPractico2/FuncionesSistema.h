#ifndef FUNCIONESSISTEMA_H_INCLUDED
#define FUNCIONESSISTEMA_H_INCLUDED
#endif // FUNCIONESSISTEMA_H_INCLUDED

typedef struct{

	int legajo;
	char apellido[40];
	char nombre[30];
    int sector;
	float sueldo;
	int isEmpty;

}ePersona;

/** \brief es el menu principal del sistema
 *
 * \param
 * \param
 * \return vuelve al menu principal
 *
 */
int menuPrincipal;

 /** \brief muestra la informacion del alta del empleado
  *
  * \param
  * \param
  * \return vuelve al menu principal
  *
  */
int mostrarEmpleado;

/** \brief muestra el menu para dar de alta a un empleado
 *
 * \param
 * \param
 * \return confirma si fue dado de alta exitosamente y permite regresar al menu principal
 *
 */
int altaPersona;

/** \brief muestra los parametros de sueldo y de Empty
 *
 * \param
 * \param
 * \return verifica que no haya ningun error
 *
 */

int inicioDePersonas;

/** \brief permite ordenar los empleados por sector
 *
 * \param
 * \param
 * \return verifica que no haya ningun error y confirma si fue realizado con exito
 *
 */
int ordenPersonasSector;

/** \brief permite buscar un empleado (ej: por numero de legajo)
 *
 * \param
 * \param
 * \return brinda la informacion del empleado o informa si es inexistente
 *
 */
int buscarPersona;

/** \brief permite ordenar los empleados por apellido
 *
 * \param
 * \param
 * \return verifica que no haya ningun error y confirma si fue realizado con exito
 *
 */
int ordenPersonasApellido;

/** \brief permite modificar datos del empleado
 *
 * \param
 * \param
 * \return confirma si fueron realizados los cambios con exito o si hubo un error.
 *
 */
int modificarPersona;

/** \brief permite dar de baja un empleado para eliminarlo del sistema
 *
 * \param
 * \param
 * \return confirma que se haya dado de baja el empleado con exito o si hubo un error.
 *
 */
int bajaPersona;










