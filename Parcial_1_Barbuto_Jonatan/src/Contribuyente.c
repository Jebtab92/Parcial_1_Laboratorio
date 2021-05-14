/*
 * Contribuyente.c
 *
 *  Created on: May 12, 2021
 *      Author: Jonatan Barbuto
 */

#include "Biblioteca.h"
#include "Contribuyente.h"


void eContribuyente_Inicializar(eContribuyente array[], int size) {
	int i;
	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			array[i].isEmpty = LIBRE;
		}
	}
}

int eContribuyente_ObtenerID(int *Contribuyente_idIncremental)
{
	int rtn;
	rtn = *Contribuyente_idIncremental +=1;
	return rtn;
}

int eContribuyente_ObtenerIndexLibre(eContribuyente array[], int size) {
	int rtn = -1;
	int i;

	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			if(array[i].isEmpty == LIBRE)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int eContribuyente_BuscarPorID(eContribuyente array[], int size, int ID)
{
	int rtn = -1;
	int i;

	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			if(array[i].idContribuyente == ID && array[i].isEmpty == OCUPADO)
			{

				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

void eContribuyente_MostrarUno(eContribuyente Contribuyente) {
	//PRINTF DE UN SOLO Contribuyente
	printf("|%10d|  %20s|  %20s|  %10s| \n",
			Contribuyente.idContribuyente, Contribuyente.nombre, Contribuyente.apellido,
			Contribuyente.cuil);
}

int eContribuyente_MostrarTodos(eContribuyente array[], int size)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	printf("*******************************************************************************\n");
	printf("|%10s  %20s  %20s  %10s| \n","ID","NOMBRE","APELLIDO","CUIL");
	printf("*******************************************************************************\n");

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < size; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Contribuyente
				eContribuyente_MostrarUno(array[i]);
				//CONTADOR DE Contribuyente
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Contribuyente PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eContribuyente_MostrarDadosDeBaja(eContribuyente array[], int size) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Contribuyente\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < size; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Contribuyente
				eContribuyente_MostrarUno(array[i]);
				//CONTADOR DE Contribuyente
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Contribuyente PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eContribuyente eContribuyente_CargarDatos(void)
{
	eContribuyente auxiliar;

	// Pido datos
	Get_OnlyAlphabetString("Ingrese Nombre --> ", "Error, reingrese --> ", auxiliar.nombre, MAX_CHARS_CADENAS);
	Get_OnlyAlphabetString("Ingrese Apellido --> ", "Error, reingrese --> ", auxiliar.apellido, MAX_CHARS_CADENAS);
	Get_Cuil("Ingrese Cuil [xx-xxxxxxxx-xx] --> ", "Error, formato [xx-xxxxxxxx-xx] -->", auxiliar.cuil, MAX_CHARS_CADENAS);

	return auxiliar;
}

eContribuyente eContribuyente_ModificarUno(eContribuyente Contribuyente)
{
	eContribuyente auxiliar = Contribuyente;
	int opcion;

	printf("\n--Menu Modificacion--\n"
			"1) Modificar nombre\n"
			"2) Modificar apellido\n"
			"3) Modificar cuil\n"
			"4) Salir\n");
	opcion = Get_IntRange("Ingrese opcion --> ", "Opcion fuera de rango\n", 1, 4);

	switch(opcion)
	{
		case 1:
		{
			Get_OnlyAlphabetString("Ingrese nuevo nombre -->", "Error, reingrese", auxiliar.nombre, MAX_CHARS_CADENAS);
			break;
		}
		case 2:
		{
			Get_OnlyAlphabetString("Ingrese nuevo apellido -->", "Error, reingrese", auxiliar.apellido, MAX_CHARS_CADENAS);
			break;
		}
		case 3:
		{
			Get_Cuil("Ingrese nuevo cuil [xx-xxxxxxxx-xx] --> ", "Error, formato [xx-xxxxxxxx-xx] -->", auxiliar.cuil, MAX_CHARS_CADENAS);
			break;
		}
		case 4:
		{
			break;
		}
	}

	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eContribuyente_Alta(eContribuyente array[],int *idContribuyente, int size)
{
	int rtn = 0;
	eContribuyente auxContribuyente;

	// Busco libre en el array
	int index = eContribuyente_ObtenerIndexLibre(array, size);

	// Si Index -1 ya esta lleno el array
	// Si Index != -1 tengo lugar para agregarlo
	if(index != -1)
	{
			// Pido datos

			auxContribuyente = eContribuyente_CargarDatos();

			// Cambio el estado a Ocupado
			auxContribuyente.isEmpty = OCUPADO;

			// Muestro nuevo contribuyente
			eContribuyente_MostrarUno(auxContribuyente);

			// Confirmo y guardo
			if(Validate_Exit_SN("Desea continuar Si[s] - No[n] -->", "Error, Si[s] - No[n] -->"))
			{
				// id unico
				auxContribuyente.idContribuyente = eContribuyente_ObtenerID(&*idContribuyente);

				// Paso a array original
				array[index] = auxContribuyente;

				rtn = 1;
			}
			else
			{
				printf("Alta Cancelada");
			}

	}
	return rtn;
}

int eContribuyente_Baja(eContribuyente array[], int size)
{
	int rtn = 0;
	int idBaja;
	int index;
	int flag = 0;

	// Muestro todos los contribuyentes
	if(eContribuyente_MostrarTodos(array, size))
	{
		flag = 1;
	}

	// Si hay altas entro al if
	if(flag)
	{
		idBaja = Get_IntPositive("\nIngrese Id a dar de baja --> ", "Solo numeros positivos --> ");

		while(eContribuyente_BuscarPorID(array, size, idBaja) == -1)
		{
			printf("--Id no encontrado--\n");
			idBaja = Get_IntPositive("\nIngrese Id a dar de baja --> ", "Solo numeros positivos --> ");
		}

		index = eContribuyente_BuscarPorID(array, size, idBaja);

		if(Validate_Exit_SN("Desea continuar Si[s] - No[n] -->", "Error, Si[s] - No[n] -->"))
		{
			array[index].isEmpty = BAJA;
			rtn = 1;
		}
	}
	return rtn;
}

int eContribuyente_Modificacion(eContribuyente array[], int size)
{
	int rtn = 0;
	int idModificar;
	int index;
	int flag = 0;
	eContribuyente auxiliar;

	// Muestro Contribuyentes
	if(eContribuyente_MostrarTodos(array, size))
	{
		flag = 1;
	}

	// Si hay altas entro al if
	if(flag)
	{
		idModificar = Get_IntPositive("\nIngrese Id a modificar --> ", "Solo numeros positivos --> ");

		// Busco que ID exista
		while(eContribuyente_BuscarPorID(array, size, idModificar) == -1)
		{
			printf("--Id no encontrado--\n");
			idModificar = Get_IntPositive("\nIngrese Id a modificar --> ", "Solo numeros positivos --> ");

		}
		index = eContribuyente_BuscarPorID(array, size, idModificar);
		// Llamo a mi funcion para modificar Contribuyente
		auxiliar = eContribuyente_ModificarUno(array[index]);

		if(Validate_Exit_SN("Desea continuar Si[s] - No[n] -->", "Error, Si[s] - No[n] -->"))
		{
			array[index] = auxiliar;
			rtn = 1;
		}

	}

	return rtn;
}
