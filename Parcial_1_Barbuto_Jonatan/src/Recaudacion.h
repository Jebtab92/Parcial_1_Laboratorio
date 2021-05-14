/*
 * Recaudacion.h
 *
 *  Created on: May 12, 2021
 *      Author: Jonatan Barbuto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

#ifndef ERecaudacion_H_
#define ERecaudacion_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 1
#define OCUPADO 0

//*** ESTRUCTURA
typedef struct
{
	int idEstado;
	char estado[MAX_CHARS_CADENAS];
}	eEstado;


typedef struct
{
	int idTipo;
	char nombreTipo[MAX_CHARS_CADENAS];
} eTipo;

typedef struct
{
	int idRecaudacion;
	int idContribuyente;
	int mes;
	eTipo idTipo;
	float importe;
	eEstado idEstado;
	int isEmpty;
} eRecaudacion;
//***
void hardCodeTipo(eTipo array[]);
void hardCodeEstado(eEstado array[]);
/** INICIO CABECERAS DE FUNCION*/
void eRecaudacion_Inicializar(eRecaudacion array[], int size);
int eRecaudacion_ObtenerID(int *Recaudacion_idIncremental);
int eRecaudacion_ObtenerIndexLibre(eRecaudacion array[], int size);
int eRecaudacion_BuscarPorID(eRecaudacion array[], int size, int ID);
void eRecaudacion_MostrarUno(eRecaudacion Recaudacion);
int eRecaudacion_MostrarTodos(eRecaudacion array[], int size);


//ABM
eRecaudacion eRecaudacion_CargarDatos(void);
eRecaudacion eRecaudacion_ModificarUno(eRecaudacion Recaudacion);
int eRecaudacion_Alta(eRecaudacion array[],int *idRecaudacion, int size);
int eRecaudacion_Baja(eRecaudacion array[], int size);
int eRecaudacion_Modificacion(eRecaudacion array[], int size);
/** FIN CABECERAS DE FUNCION*/
#endif
