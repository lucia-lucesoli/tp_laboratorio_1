/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Trabajo Practico 4
 ============================================================================
 */

#include "persona.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"

// Creacion de nuevo elemento
/** \brief Crea un nuevo puntero a persona, asignando espacio en la memoria dinámica
*
* \return Si se encontró espacio en la memoria para el elemento, retorna un puntero al mismo, de lo contrario retorna NULL
*/
ePersona* new_persona(void) {
    ePersona* nuevapersona = (ePersona*) malloc(sizeof(ePersona));
    if(nuevapersona != NULL) {
        nuevapersona->id = -1;
        strcpy(nuevapersona->nombre, "");
        nuevapersona->edad = -1;
        nuevapersona->sexo = ' ';
    }
    return nuevapersona;
}
/** \brief Recibe los parámetros para inicializar los campos de un nuevo elemento.
*
* \param id int
* \param nombre string
* \param edad int
* \param sexo char
* \return Si no hay lugar en memoria, o alguno de los parámetros no es válido, retorna NULL, de lo contrario, retorna un puntero al nuevo elemento
          con todos sus campos inicalizados.
*/
ePersona* new_persona_param(int id, char* nombre, int edad, char sexo) {
    ePersona* nuevapersona = new_persona();
    if(nuevapersona != NULL) {
        if(set_id_persona(nuevapersona, id)
        || set_nombre_persona(nuevapersona, nombre)
        || set_edad_persona(nuevapersona, edad)
        || set_sexo_persona(nuevapersona, toupper(sexo))) {
            free(nuevapersona);
            nuevapersona = NULL;
        }
    }
    return nuevapersona;
}
// Setters y getters
/** \brief Recibe un puntero a un elemento y un id. Le asigna el id al elemento
*
* \param persona puntero al elemento
* \param id int
* \return 1 si el puntero es NULL o si el id no es válido, 0 si OK
*/
int set_id_persona(ePersona* persona, int id) {
    int error = 1;
    if(persona != NULL && validar_id(id)) {
        persona->id = id;
        error = 0;
    }
    return error;
}
/** \brief Recibe un puntero a un elemento y un puntero a id al cual le asigna el valor que contenga el elemento
*
* \param persona puntero al elemento
* \param id puntero a entero
* \return 1 si el puntero es NULL, 0 si OK
*/
int get_id_persona(ePersona* persona, int* id) {
    int error = 1;
    if(persona != NULL) {
        *id = persona->id;
        error = 0;
    }
    return error;
}
/** \brief Recibe un puntero a un elemento y un nombre. Le asigna el nombre al elemento
*
* \param persona puntero al elemento
* \param nombre string
* \return 1 si el puntero al elemento o al nombre es NULL o si el nombre no es válido, 0 si OK
*/
int set_nombre_persona(ePersona* persona, char* nombre) {
    int error = 1;
    if(persona != NULL && validar_nombre(nombre)) {
        strcpy(persona->nombre, nombre);
        error = 0;
    }
    return error;
}
/** \brief Recibe un puntero a un elemento y un puntero a char al cual le asigna el valor que contenga el elemento
*
* \param persona puntero al elemento
* \param nombre puntero a char
* \return 1 si el puntero al elemento es NULL, 0 si OK
*/
int get_nombre_persona(ePersona* persona, char* nombre) {
    int error = 1;
    if(persona != NULL) {
        strcpy(nombre, persona->nombre);
        error = 0;
    }
    return error;
}
/** \brief Recibe un puntero a un elemento y un edad. Le asigna la edad al elemento
*
* \param persona puntero al elemento
* \param edad int
* \return 1 si el puntero es NULL o si el edad no es válido, 0 si OK
*/
int set_edad_persona(ePersona* persona, int edad) {
    int error = 1;
    if(persona != NULL && validar_edad(edad)) {
        persona->edad = edad;
        error = 0;
    }
    return error;
}
/** \brief Recibe un puntero a un elemento y un puntero a edad al cual le asigna el valor que contenga el elemento
*
* \param persona puntero al elemento
* \param edad puntero a int
* \return 1 si el puntero es NULL, 0 si OK
*/
int get_edad_persona(ePersona* persona, int* edad) {
    int error = 1;
    if(persona != NULL) {
        *edad = persona->edad;
        error = 0;
    }
    return error;
}
/** \brief Recibe un puntero a un elemento y un caracter con el sexo. Le asigna el sexo al elemento
*
* \param persona puntero al elemento
* \param sexo char
* \return 1 si el puntero es NULL o si el sexo no es válido, 0 si OK
*/
int set_sexo_persona(ePersona* persona, char sexo) {
    int error = 1;
    if(persona != NULL && validar_sexo(sexo)) {
        persona->sexo = sexo;
        error = 0;
    }
    return error;
}
/** \brief Recibe un puntero a un elemento y un puntero a char al cual le asigna el valor que contenga el elemento
*
* \param persona puntero al elemento
* \param sexo puntero a char
* \return 1 si el puntero es NULL o si el id no es válido0 si OK
*/
int get_sexo_persona(ePersona* persona, char* sexo) {
    int error = 1;
    if(persona != NULL) {
        *sexo = persona->sexo;
        error = 0;
    }
    return error;
}
// Validaciones
/** \brief Revisa que el ID se encuentre dentro del rango de IDs permitidos
*
* \param id int
* \return 0 si el dato no es válido, 1 si lo es
*/
int validar_id(int id) {
    int valido = 0;
    if(id >= 1 && id <= 5000) {
        valido = 1;
    }
    return valido;
}
/** \brief Revisa que el puntero al nombre no sea NULL y que su longitud cumpla con los requisitos de la estructura
*
* \param nombre puntero a char
* \return 0 si el dato no es válido, 1 si lo es
*/
int validar_nombre(char* nombre) {
    int valido = 0;
    if(nombre!= NULL && strlen(nombre) >= 2 && strlen(nombre) < 20) {
        valido = 1;
    }
    return valido;
}
/** \brief Revisa que el edad no sea negativo o igual a 0
*
* \param edad int
* \return 0 si el dato no es válido, 1 si lo es
*/
int validar_edad(int edad) {
    int valido = 0;
    if(edad > 0 && edad < 3) {
        valido = 1;
    }
    return valido;
}
/** \brief Revisa que el sexo asignado sea válido (b = blanco, n = negro, g = gris)
*
* \param sexo char
* \return 0 si el dato no es válido, 1 si lo es
*/
int validar_sexo(char sexo) {
    int valido = 0;
    if(sexo == 'F' || sexo == 'M') {
        valido = 1;
    }
    return valido;
}

// Eliminación de elemento
/** \brief Elimina un elemento liberando el espacio que ocupa en memoria
*
* \param persona puntero al elemento a eliminar
*/
void delete_persona(ePersona* persona) {
    if(persona != NULL) {
    persona = NULL;
    free(persona);
    }
}

// Mostrar elementos
/** \brief Imprime en consola los datos de un elemento
*
* \param persona puntero al elemento a mostrar
*/
void print_persona(ePersona* persona) {
    printf("%4d | %14s |  %d  | %c\n", persona->id, persona->nombre, persona->edad, persona->sexo);
}
/** \brief Recibe una lista de elementos y la itera, imprimiendo por pantalla cada elemento no nulo
*
* \param lista puntero a la lista de elementos
* \return 1 si el puntero a la lista es NULL, 0 si OK
*/
int print_personas(void* lista) {
    int error = 1;
    if(lista != NULL) {
        int tam = ll_len(lista);
        printf("  ID |     Nombre     | Edad | Sexo\n");
        for(int i = 0; i < tam; i++) {
            ePersona* persona = (ePersona*) ll_get(lista, i);
            if(persona != NULL) {
                print_persona(persona);
            }
        }
        error = 0;
    }
    return error;
}

// Ordenamiento
/** \brief Recibe dos punteros a personas y verifica la diferencia entre sus IDs
*
* \param persona1 puntero a persona
* \param persona2 puntero a persona
* \return 0 si son iguales, 1 si el primer elemento es mayor al segundo, -1 si el primer elemento es menor al segundo
*/
int sort_id_persona(void* p1, void* p2) {
    int orden = 0;
    ePersona* persona1 = (ePersona*) p1;
    ePersona* persona2 = (ePersona*) p2;
    if(persona1->id > persona2->id) {
        orden = 1;
    } else if(persona1->id < persona2->id) {
        orden = -1;
    }
    return orden;
}
/** \brief Recibe dos punteros a personas y verifica la diferencia entre sus nombres
*
* \param persona1 puntero a persona
* \param persona2 puntero a persona
* \return 0 si son iguales, 1 si el primer elemento es mayor al segundo, -1 si el primer elemento es menor al segundo
*/
int sort_nombre_persona(void* p1, void* p2) {
    int orden = 0;
    ePersona* persona1 = (ePersona*) p1;
    ePersona* persona2 = (ePersona*) p2;
    if(strcmp(persona1->nombre, persona2->nombre) > 0) {
        orden = 1;
    } else if(strcmp(persona1->nombre, persona2->nombre) < 0) {
        orden = -1;
    }
    return orden;
}
/** \brief Recibe dos punteros a personas y verifica la diferencia entre sus edades
*
* \param persona1 puntero a persona
* \param persona2 puntero a persona
* \return 0 si son iguales, 1 si el primer elemento es mayor al segundo, -1 si el primer elemento es menor al segundo
*/
int sort_edad_persona(void* p1, void* p2) {
    int orden = 0;
    ePersona* persona1 = (ePersona*) p1;
    ePersona* persona2 = (ePersona*) p2;
    if(persona1->edad > persona2->edad) {
        orden = 1;
    } else if(persona1->edad < persona2->edad) {
        orden = -1;
    }
    return orden;
}
/** \brief Recibe dos punteros a personas y verifica la diferencia entre sus sexoes
*
* \param persona1 puntero a persona
* \param persona2 puntero a persona
* \return 0 si son iguales, 1 si el primer elemento es mayor al segundo, -1 si el primer elemento es menor al segundo
*/
int sort_sexo_persona(void* p1, void* p2) {
    int orden = 0;
    ePersona* persona1 = (ePersona*) p1;
    ePersona* persona2 = (ePersona*) p2;
    if(persona1->sexo > persona2->sexo) {
        orden = 1;
    } else if(persona1->sexo < persona2->sexo) {
        orden = -1;
    }
    return orden;
}
int get_persona_ID(void* lista, int id) {
    int indice = -1;
    if(lista != NULL) {
        int len = ll_len(lista);
        for(int i = 0; i < len; i++) {
            ePersona* personaAux = ll_get(lista, i);
            if(personaAux->id == id) {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
