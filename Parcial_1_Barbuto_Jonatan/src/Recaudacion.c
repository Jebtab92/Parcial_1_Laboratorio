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

void hardCodeEstado(eEstado array[])
{
	if(array != NULL)
	{
		array[0].idEstado = 1;
		strcpy(array[0].estado,"Adeudado");

		array[1].idEstado = 2;
		strcpy(array[1].estado,"Refinanciado");

		array[2].idEstado = 3;
		strcpy(array[2].estado,"Saldado");
	}
}

/*
 * \brief recibe un array de estructura y tamanio
 * \param pone isEmpty en 1 = LIBRE
 * \return void
 */
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

/*
 * \brief recibe un int id
 * \param lo incrementa en 1
 * \return retorna el id ya incrementado
 */
int eRecaudacion_ObtenerID(int *Recaudacion_idIncremental)
{
	int rtn;
	rtn = *Recaudacion_idIncremental +=1;
	return rtn;
}

/*
 * \brief recibe array de estructura
 * \param busca el lugar libre isEmpty = 1
 * \return la primer posicion libre
 */
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

/*
 * \brief recibe un array de estructura
 * \param busca un ID por el array
 * \return la posicion del ID
 */
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

/*
 * \brief recibe un array de estructura
 * \param imprime cada valor de la estructura
 * \return void
 */
void eRecaudacion_MostrarUno(eRecaudacion Recaudacion) {
	//PRINTF DE UN SOLO Recaudacion
	printf("%5d\n", Recaudacion.idRecaudacion);
}

/*
 * \brief recibe un array de estructura, tamanio
 * \param imprime todos por pantalla
 * \return int 1 si hay para mostrar 0 si no hay nada
 */
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

/*
 * \brief void
 * \param crea una estructura auxiliar y pide los valores al usuario
 * \return el auxiliar
 */
eRecaudacion eRecaudacion_CargarDatos(void) {
	eRecaudacion auxiliar;

	// Pido datos


	auxiliar.idContribuyente = Get_IntRange("\nIngrese ID del contribuyente --> ", "ID invalido -->", 1000, 2000);


	auxiliar.idTipo.idTipo = Get_IntRange("\nIngrese tipo de recaudacion\n"
			"\t1) ARBA\n"
			"\t2) IIBB\n"
			"\t3) GANANCIAS\n --> ", "Tipo invalido -->", 1, 3);

	auxiliar.mes = Get_IntRange("Ingrese mes --> ", "Error, reingrese --> \n", 1, 12);
	auxiliar.importe = Get_Float("Ingrese importe --> ", "Error, reingrese --> \n");



	return auxiliar;
}

/*
 * \brief recibe un array de estructura
 * \param pide que variable se quiere modificar
 * \return retorna el auxiliar
 */
eRecaudacion eRecaudacion_ModificarUno(eRecaudacion Recaudacion) {
	eRecaudacion auxiliar = Recaudacion;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

/*
 * \brief recibe un array de estructura, id contribuyente, tamanio
 * \param pregunta si confirma el nuevo contribuyente asigna todo
 * \return int 1 si se dio de alta
 */
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

/*
 * \brief recibe un array de estructura, tamanio
 * \param muestro y pido id de baja, confirma y procede a cambiar isEmpty = LIBRE
 * \return int 1 si se dio de baja
 */
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

		array[index].isEmpty = LIBRE;

		rtn = 1;
	}

	return rtn;
}

/*
 * \brief recibe un array de estructura, tamanio
 * \param muestra y pide id a modificar y llama a la funcion modificar uno
 * \return int 1 si se modifico
 */
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
