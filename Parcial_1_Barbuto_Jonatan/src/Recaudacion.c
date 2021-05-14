/*
 * Recaudacion.c
 *
 *  Created on: May 12, 2021
 *      Author: Jonatan Barbuto
 */

#include "Biblioteca.h"
#include "Recaudacion.h"


void hardCodeTipo(eTipo array[])
{
	if(array != NULL)
	{
		array[0].idTipo = 1;
		strcpy(array[0].nombreTipo,"ARBA");

		array[1].idTipo = 2;
		strcpy(array[1].nombreTipo,"IIBB");

		array[2].idTipo = 3;
		strcpy(array[2].nombreTipo,"GANANCIAS");
	}
}

void eRecaudacion_Inicializar(eRecaudacion array[], int size)
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

int eRecaudacion_ObtenerID(int *Recaudacion_idIncremental)
{
	int rtn;
	rtn = *Recaudacion_idIncremental +=1;
	return rtn;
}

int eRecaudacion_ObtenerIndexLibre(eRecaudacion array[], int size) {
	int rtn = -1;
	int i;
	if (array != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eRecaudacion_BuscarPorID(eRecaudacion array[], int size, int ID)
{
	int rtn = -1;
	int i;
	if (array != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			if (array[i].idRecaudacion == ID && array[i].isEmpty == OCUPADO) {

				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eRecaudacion_MostrarUno(eRecaudacion Recaudacion) {
	//PRINTF DE UN SOLO Recaudacion
	printf("%5d\n", Recaudacion.idRecaudacion);
}

int eRecaudacion_MostrarTodos(eRecaudacion array[], int size) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	//puts("\n\t> LISTADO Recaudacion");
	//printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < size; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Recaudacion
				eRecaudacion_MostrarUno(array[i]);
				//CONTADOR DE Recaudacion
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Recaudacion PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eRecaudacion_MostrarDadosDeBaja(eRecaudacion array[], int size) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Recaudacion\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < size; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Recaudacion
				eRecaudacion_MostrarUno(array[i]);
				//CONTADOR DE Recaudacion
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Recaudacion PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eRecaudacion eRecaudacion_CargarDatos(void) {
	eRecaudacion auxiliar;

	// Pido datos


	auxiliar.idContribuyente = Get_IntRange("\nIngrese ID del contribuyente --> ", "ID invalido -->", 1000, 2000);


	auxiliar.idTipo = Get_IntRange("\nIngrese tipo de recaudacion\n"
			"\t1) ARBA\n"
			"\t2) IIBB\n"
			"\t3) GANANCIAS\n --> ", "Tipo invalido -->", 1, 3);

	auxiliar.mes = Get_IntRange("Ingrese mes --> ", "Error, reingrese --> \n", 1, 12);
	auxiliar.importe = Get_Float("Ingrese importe --> ", "Error, reingrese --> \n");



	return auxiliar;
}

eRecaudacion eRecaudacion_ModificarUno(eRecaudacion Recaudacion) {
	eRecaudacion auxiliar = Recaudacion;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eRecaudacion_Alta(eRecaudacion array[],int *idRecaudacion, int size)
{
	int rtn = 0;
	eRecaudacion auxRecaudacion;

	//BUSCO ESPACIO EN ARRAY
	int index = eRecaudacion_ObtenerIndexLibre(array, size);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
			//PIDO DATOS - CARGO Recaudacion AUXILIAR
			auxRecaudacion = eRecaudacion_CargarDatos();

			//CAMBIO SU ESTADO A "OCUPADO"
			auxRecaudacion.isEmpty = OCUPADO;

			eRecaudacion_MostrarUno(auxRecaudacion);
			//mostrar antes de guardar
			if(Validate_Exit_SN("Desea continuar Si[s] - No[n]: ", "Error, Reingrese: "))
			{
				//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
				auxRecaudacion.idRecaudacion = eRecaudacion_ObtenerID(&*idRecaudacion);

				//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
				array[index] = auxRecaudacion;

				//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
				rtn = 1;
			}
			else
			{
				printf("Alta Cancelada");
			}

		}

		return rtn;
}

int eRecaudacion_Baja(eRecaudacion array[], int size) {
	int rtn = 0;
	int idRecaudacion;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Recaudacion
	if(eRecaudacion_MostrarTodos(array, size)) {
		//BANDERA EN 1 SI HAY Recaudacion DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Recaudacion PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idRecaudacion);

		//BUSCO INDEX POR ID EN ARRAY
		while (eRecaudacion_BuscarPorID(array, size, idRecaudacion) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idRecaudacion);
		}

		//OBTENGO INDEX DEL ARRAY DE Recaudacion A DAR DE BAJA
		index = eRecaudacion_BuscarPorID(array, size, idRecaudacion);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECsizeENTE
		rtn = 1;
	}

	return rtn;
}

int eRecaudacion_Modificacion(eRecaudacion array[], int size) {
	int rtn = 0;
	int idRecaudacion;
	int index;
	int flag = 0;
	eRecaudacion auxiliar;

	//LISTO TODOS LOS Recaudacion
	if (eRecaudacion_MostrarTodos(array, size)) {
		//BANDERA EN 1 SI HAY Recaudacion DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Recaudacion PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idRecaudacion);

		//BUSCO INDEX POR ID EN ARRAY
		while (eRecaudacion_BuscarPorID(array, size, idRecaudacion) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idRecaudacion);
		}

		//OBTENGO INDEX DEL ARRAY DE Recaudacion A MODIFICAR
		index = eRecaudacion_BuscarPorID(array, size, idRecaudacion);

		//LLAMO A FUNCION QUE MODIFICA Recaudacion
		auxiliar = eRecaudacion_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECsizeENTE
		rtn = 1;
	}

	return rtn;
}
