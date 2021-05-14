/*
 * Contribuyente.h
 *
 *  Created on: May 12, 2021
 *      Author: Jonatan Barbuto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

#ifndef EContribuyente_H_
#define EContribuyente_H_

//*** Define
#define MAX_CHARS_CADENAS 30
#define LIBRE 1
#define OCUPADO 0
#define BAJA -1

//*** Estructura
typedef struct
{
	int idContribuyente;
	char nombre[MAX_CHARS_CADENAS];
	char apellido[MAX_CHARS_CADENAS];
	char cuil[MAX_CHARS_CADENAS];
	int isEmpty;
} eContribuyente;


/** INICIO CABECERAS DE FUNCION*/
void eContribuyente_Inicializar(eContribuyente array[], int size);
int eContribuyente_ObtenerID(int *Contribuyente_idIncremental);
int eContribuyente_ObtenerIndexLibre(eContribuyente array[], int size);
int eContribuyente_BuscarPorID(eContribuyente array[], int size, int ID);
void eContribuyente_MostrarUno(eContribuyente Contribuyente);
int eContribuyente_MostrarTodos(eContribuyente array[], int size);
int eContribuyente_MostrarDadosDeBaja(eContribuyente array[], int size);

//ABM
eContribuyente eContribuyente_CargarDatos(void);
eContribuyente eContribuyente_ModificarUno(eContribuyente Contribuyente);
int eContribuyente_Alta(eContribuyente array[],int *idContribuyente, int size);
int eContribuyente_Baja(eContribuyente array[], int size);
int eContribuyente_Modificacion(eContribuyente array[], int size);
/** FIN CABECERAS DE FUNCION*/
#endif
