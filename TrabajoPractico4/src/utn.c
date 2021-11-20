/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Trabajo Practico 4
 ============================================================================
 */

#include "utn.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_PersonaFromText(FILE* pFile , LinkedList* pArrayListPersona)
{
	int retorno = 1;
	if(pFile != NULL && pArrayListPersona != NULL) {
		int cant;
		int salida = 0;
		ePersona* persona = NULL;
		char idStr[50], nombre[20], edadStr[10], sexo;
		while(!salida){
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, edadStr, &sexo);

            if(cant == 4) {
                persona = new_persona_param(atoi(idStr), nombre, atof(edadStr), sexo);
                if(persona != NULL) {
                    ll_add(pArrayListPersona, persona);
                }
            }

            salida = feof(pFile);
        }
        retorno = atoi(idStr);
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_PersonaFromBinary(FILE* pFile , LinkedList* pArrayListPersona)
{
	int retorno = -1;
    ePersona* persona = NULL;
    int id;
    char nombre[20];
    int edad;
    char sexo;
    if(pFile != NULL && pArrayListPersona != NULL) {
        do {
            if(fread(&id, sizeof(int), 1, pFile)
            && fread(nombre, 20, 1, pFile)
            && fread(&edad, sizeof(int), 1, pFile)
            && fread(&sexo, sizeof(char), 1, pFile)) {
                persona = new_persona_param(id, nombre, edad, sexo);
                ll_add(pArrayListPersona, persona);
                retorno = 0;
            }
        }while(!feof(pFile));
    }
    return retorno;
}
int leerArchivoTexto(LinkedList* lista) {
    int error = 1;
    if(lista != NULL) {
        FILE* f = fopen("data.csv", "r");
        if(f != NULL) {
            parser_PersonaFromText(f, lista);
            error = 0;
        }
        fclose(f);
    }
    return error;
}
int leerArchivoBinario(LinkedList* lista) {
    int error = 1;
    if(lista != NULL) {
        FILE* f = fopen("data.bin", "rb");
        if(f != NULL) {
            parser_PersonaFromBinary(f, lista);
            error = 0;
        }
        fclose(f);
    }
    return error;
}
int cargaDatos(LinkedList* lista) {
    int error = 1;
    if(lista != NULL) {
        if(leerArchivoTexto(lista)) {
            int opcion;
            printf("No se pudieron leer los datos. Desea probar de cargar desde un archivo binario?\n");
            printf("1: Si  -  2: No\n\n");
            scanf("%d", &opcion);
            opcion--;
            if(!opcion) {
                if(leerArchivoBinario(lista)) {
                    printf("No se pudieron leer los datos.\n\n");
                } else {
                    error = 0;
                }
            }
        } else {
            error = 0;
        }
    }
    return error;
}
int imprimirTamanio(LinkedList* lista) {
    int error = 1;
    printf("El tamanio de la LinkedList es: %d\n\n", ll_len(lista));
    return error;
}
int cargaNuevoElemento(LinkedList* lista, int id) {
    int error = 1;
    if(lista != NULL) {
        ePersona* personaAux = NULL;
        printf("*** Carga de nuevo elemento ***\n\n");

        printf("Ingrese un nombre: ");
        char nombre[20];
        fflush(stdin);
        scanf("%s", nombre);

        printf("Ingrese la edad: ");
        int edad;
        scanf("%d", &edad);

        printf("Ingrese el sexo (M o F): ");
        char sexo;
        fflush(stdin);
        scanf("%c", &sexo);

        personaAux = new_persona_param(id,nombre,edad,sexo);
        if(personaAux != NULL) {
            ll_add(lista, personaAux);
            error = 0;
        }
    }
    return error;
}
int modificarElemento(LinkedList* lista) {
    int error = 1;
    if(lista != NULL) {
        printf("*** Modificacion de elemento ***\n\n");
        int numero;
        printf("Ingrese el ID de la persona a modificar: ");
        scanf("%d", &numero);

        if(numero > 0 && numero < 5000) {
            printf("Persona %d:\n", numero); // El numero corresponde al ID, pero los ID empiezan en 1 y el indice en 0
            ePersona* persAux = ll_get(lista, numero-1);
            print_persona(persAux);

            printf("Ingrese un nuevo nombre: ");
            fflush(stdin);
            scanf("%s", persAux->nombre);

            printf("Ingrese la edad: ");
            scanf("%d", &persAux->edad);

            printf("Ingrese el sexo: ");
            fflush(stdin);
            scanf("%c", &persAux->sexo);
        }
        error = 0;
    }
    return error;
}
int guardarBinario(LinkedList* lista) {
    int error = 1;
    if(lista != NULL) {
        FILE* fb = fopen("data.bin", "wb");
        if(fb != NULL) {
            int len = ll_len(lista);
            for(int i = 0; i < len; i++) {
                ePersona* persona = ll_get(lista, i);
                if(persona != NULL) {
                    fwrite(persona, sizeof(ePersona), 1, fb);
                }
            }
        }
        fclose(fb);
        error = 0;
    }
    return error;
}
ePersona* crearPersona(int id) {
    ePersona* personaAux;

    printf("Ingrese un nombre: ");
    char nombre[20];
    fflush(stdin);
    scanf("%s", nombre);

    printf("Ingrese la edad: ");
    int edad;
    scanf("%d", &edad);

    printf("Ingrese el sexo (M o F): ");
    char sexo;
    fflush(stdin);
    scanf("%c", &sexo);

    personaAux = new_persona_param(id,nombre,edad,sexo);

    return personaAux;
}
