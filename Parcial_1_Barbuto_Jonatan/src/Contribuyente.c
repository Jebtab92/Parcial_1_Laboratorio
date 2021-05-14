/*
 * Contribuyente.c
 *
 *  Created on: May 12, 2021
 *      Author: Jonatan Barbuto
 */

#include "Biblioteca.h"
#include "Contribuyente.h"

/*
 * \brief recibe un array de estructura y tamanio
 * \param pone isEmpty en 1 = LIBRE
 * \return void
 */
void eContribuyente_Inicializar(eContribuyente array[], int size)
{
	int i;
	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			array[i].isEmpty = LIBRE;
		}
	}
}

/*
 * \brief recibe un int id
 * \param lo incrementa en 1
 * \return retorna el id ya incrementado
 */
int eContribuyente_ObtenerID(int *Contribuyente_idIncremental)
{
	int rtn;
	rtn = *Contribuyente_idIncremental +=1;
	return rtn;
}

/*
 * \brief recibe array de estructura
 * \param busca el lugar libre isEmpty = 1
 * \return la primer posicion libre
 */
int eContribuyente_ObtenerIndexLibre(eContribuyente array[], int size)
{
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

/*
 * \brief recibe un array de estructura
 * \param busca un ID por el array
 * \return la posicion del ID
 */
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

/*
 * \brief recibe un array de estructura
 * \param imprime cada valor de la estructura
 * \return void
 */
void eContribuyente_MostrarUno(eContribuyente Contribuyente)
{
	printf("|%10d|  %20s|  %20s|  %10s| \n",
			Contribuyente.idContribuyente, Contribuyente.nombre, Contribuyente.apellido,
			Contribuyente.cuil);
}

/*
 * \brief recibe un array de estructura, tamanio
 * \param imprime todos por pantalla
 * \return int 1 si hay para mostrar 0 si no hay nada
 */
int eContribuyente_MostrarTodos(eContribuyente array[], int size)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	printf("*******************************************************************************\n");
	printf("|%10s  %20s  %20s  %10s| \n","ID","NOMBRE","APELLIDO","CUIL");
	printf("*******************************************************************************\n");

	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				eContribuyente_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}


	if(cantidad > 0)
	{
		rtn = 1;
	}

	return rtn;
}

/*
 * \brief void
 * \param crea una estructura auxiliar y pide los valores al usuario
 * \return el auxiliar
 */
eContribuyente eContribuyente_CargarDatos(void)
{
	eContribuyente auxiliar;

	// Pido datos
	Get_OnlyAlphabetString("Ingrese Nombre --> ", "Error, reingrese --> ", auxiliar.nombre, MAX_CHARS_CADENAS);
	Get_OnlyAlphabetString("Ingrese Apellido --> ", "Error, reingrese --> ", auxiliar.apellido, MAX_CHARS_CADENAS);
	Get_Cuil("Ingrese Cuil [xx-xxxxxxxx-xx] --> ", "Error, formato [xx-xxxxxxxx-xx] -->", auxiliar.cuil, MAX_CHARS_CADENAS);

	return auxiliar;
}

/*
 * \brief recibe un array de estructura
 * \param pide que variable se quiere modificar
 * \return retorna el auxiliar
 */
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
	return auxiliar;
}

/*
 * \brief recibe un array de estructura, id contribuyente, tamanio
 * \param pregunta si confirma el nuevo contribuyente asigna todo
 * \return int 1 si se dio de alta
 */
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

/*
 * \brief recibe un array de estructura, tamanio
 * \param muestro y pido id de baja, confirma y procede a cambiar isEmpty = LIBRE
 * \return int 1 si se dio de baja
 */
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
			array[index].isEmpty = LIBRE;
			rtn = 1;
		}
	}
	return rtn;
}

/*
 * \brief recibe un array de estructura, tamanio
 * \param muestra y pide id a modificar y llama a la funcion modificar uno
 * \return int 1 si se modifico
 */
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
