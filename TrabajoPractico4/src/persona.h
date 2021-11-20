/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Trabajo Practico 4
 ============================================================================
 */

#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    int edad;
    char sexo;
} ePersona;

#endif // PERSONA_H_INCLUDED


// Creación de nuevo elemento
ePersona* new_persona(void);
ePersona* new_persona_param(int id, char* nombre, int edad, char sexo);

// Setters y getters
int set_id_persona(ePersona* persona, int id);
int get_id_persona(ePersona* persona, int* id);
int set_nombre_persona(ePersona* persona, char* nombre);
int get_nombre_persona(ePersona* persona, char* nombre);
int set_edad_persona(ePersona* persona, int edad);
int get_edad_persona(ePersona* persona, int* edad);
int set_sexo_persona(ePersona* persona, char sexo);
int get_sexo_persona(ePersona* persona, char* sexo);

// Validaciones
int validar_id(int id);
int validar_nombre(char* nombre);
int validar_edad(int edad);
int validar_sexo(char sexo);

// Eliminación de elemento
void delete_persona(ePersona* persona);

// Mostrar elementos
void print_persona(ePersona* persona);
int print_personas(void* lista);

// Ordenamiento
int sort_id_persona(void* persona1, void* persona2);
int sort_nombre_persona(void* persona1, void* persona2);
int sort_edad_persona(void* persona1, void* persona2);
int sort_sexo_persona(void* persona1, void* persona2);

// Buscar elemento por ID
int get_persona_ID(void* lista, int id);
