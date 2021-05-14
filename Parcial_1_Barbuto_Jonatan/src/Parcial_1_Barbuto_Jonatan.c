/*
 ============================================================================
 Name        : Parcial_1_Barbuto_Jonatan.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Contribuyente.h"
#include "Recaudacion.h"

#define TAM_ESTRUCTURA 50

int main(void)
{
	setbuf(stdout, NULL);

	int idContribuyente = 999;
	int idRecaudacion = 99;
	int opc;

	// Creo los array necesarios
	eContribuyente Contribuyente[TAM_ESTRUCTURA];
	eRecaudacion Recaudacion[TAM_ESTRUCTURA];


	// Creo array tipo y cargo los tres valores
	eEstado estado[2];
	eTipo Tipo[2];
	hardCodeTipo(Tipo);
	hardCodeEstado(estado);

	// Inicializo ambos arrays
	eContribuyente_Inicializar(Contribuyente, TAM_ESTRUCTURA);
	eRecaudacion_Inicializar(Recaudacion, TAM_ESTRUCTURA);


	do
	{

		Menu();

		opc = Get_IntRange("\nIngrese Opcion --> ", "Error, opcion no valida\n", 1, 9);

		switch(opc)
		{

			case 1:
			{

				if(eContribuyente_Alta(Contribuyente, &idContribuyente, TAM_ESTRUCTURA))
				{
					printf(" * Contribuyente DADO DE ALTA EXITOSAMENTE\n");
				}
				else
				{
					printf(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Contribuyente\n");
				}
				break;
			}
			case 2:
			{
				// Modificar
				if(eContribuyente_Modificacion(Contribuyente, TAM_ESTRUCTURA))
				{
					printf("\n * MODIFICACION DE Contribuyente EXITOSA\n");
					eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA);
				}
				else
				{
					printf("\n * No hay contribuyente para modificar");
				}
				break;
			}
			case 3:
			{
				// Baja

				if(eContribuyente_Baja(Contribuyente, TAM_ESTRUCTURA))
				{
					printf("\n * BAJA DE Contribuyente EXITOSA");
					eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA);
				}
				else
				{
					printf("\n * No hay contribuyente para dar de baja");
				}
				break;
			}

			// FALTAAA ****//////
			case 4:
			{
				// Alta Recaudacion
				eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA);
				if(eRecaudacion_Alta(Recaudacion, &idRecaudacion, TAM_ESTRUCTURA))
				{
					printf(" * Recaudacion DADO DE ALTA EXITOSAMENTE");
				}
				else
				{
					printf(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Recaudaciones\n");
				}
				break;
			}
			case 5:
			{
				// Refinanciar Recaudacion
				break;
			}
			case 6:
			{
				// Saldar Recaudacion
				break;
			}
			case 7:
			{
				eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA);
				break;
			}
			case 8:
			{
				break;
			}
			case 9:
			{
				// Salir
				break;
			}
		}

	}while(opc != 9);

	printf("\n--FIN PROGRAMA--");

	return 0;
}
