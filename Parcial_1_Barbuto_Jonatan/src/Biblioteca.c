/*
 * Biblioteca.c
 *
 *  Created on: May 11, 2021
 *      Author: Jonatan Barbuto
 */

#include "Biblioteca.h"

// Validaciones

/*
 * \brief recibe un string
 * \param valida que sea int
 * \return int 1 si es correcto
 */
int Validate_OnlyNumberInt(char *pData)
{
	int rtn = 1;

	if(strlen(pData) > 0)
	{
		for(int i = 0; i < strlen(pData); i++)
		{
			if(isdigit(pData[i]) == 0)
			{
				if(i == 0)
				{
					if(pData[0] != '-')
					{
						rtn = 0;
						break;
					}
				}
				else
				{
					rtn = 0;
					break;
				}
			}
		}
	}
	else
	{
		rtn = 0;
	}

	return rtn;
}

/*
 * \brief recibe un string
 * \param valida que sea float
 * \return int 1 si es correcto
 */
int Validate_OnlyNumberFloat(char *pData)
{
	int countSigno = 0;
	int rtn = 1;

	if(strlen(pData) > 0)
	{
		for(int i = 0; i < strlen(pData); i++)
		{

			if(pData[i] == '.' || pData[i] == ',')
			{
				countSigno++;
			}
			else
			{
				if(isdigit(pData[i]) == 0)
				{
					if(i == 0)
					{
						if(pData[0] != '-')
						{
							rtn = 0;
							break;
						}
					}
					else
					{
						rtn = 0;
						break;
					}
				}
			}
		}

		if(countSigno > 1)
		{
			rtn = 0;
		}
	}
	else
	{
		rtn = 0;
	}

	return rtn;
}

/*
 * \brief recibe un string
 * \param valida que sea solo letras
 * \return int 1 si es correcto
 */
int Validate_OnlyAlphabet(char *pData)
{
	int rtn = 1;

	if(strlen(pData) > 0)
	{
		for(int i = 0; i < strlen(pData); i++)
		{
			if(isalpha(pData[i]) == 0)
			{
				rtn = 0;
				break;
			}
		}
	}
	else
	{
		rtn = 0;
	}

	return rtn;
}

/*
 * \brief recibe un string
 * \param valida que sea solo letras con un espacio
 * \return int 1 si es correcto
 */
int Validate_OnlyAlphabetWithSpaces(char *pData)
{
	int rtn = 1;

	if(strlen(pData) > 0)
	{
		for(int i = 0; i < strlen(pData); i++)
		{
			if(isalpha(pData[i]) == 0)
			{
				if(isspace(pData[i]) == 0)
				{
					rtn = 0;
					break;
				}
			}
		}
	}
	else
	{
		rtn = 0;
	}

	return rtn;
}

/*
 * \brief Ingresa mensaje
 * \param valida que sea s o n
 * \return int 1 si es s
 */
int Validate_Exit_SN(char *MSJ, char *ERROR_MSJ)
{
	int rtn = 0;
	char c;

	c = Get_Char(MSJ, ERROR_MSJ);
	c = toupper(c);

	while(c != 'S' && c != 'N')
	{
		printf("Error, opcion no valida");
		c = Get_Char(MSJ, ERROR_MSJ);
		c = toupper(c);
	}

	if(c == 'S')
	{
		rtn = 1;
	}

	return rtn;
}

/*
 * \brief Ingresa string de cuil
 * \param valida que sea formato cuil
 * \return int 1 si es correcto
 */
int Validate_Cuit(char *pData)
{
	int rtn = 1;
	int i;
	int contadorDigito=0;
	int contadorGuion=0;

	if(pData!=NULL)
	{
		for(i=0; i < strlen(pData);i++)
		{
			if(isdigit(pData[i]) != 0)
			{
				contadorDigito++;
			}
			if(pData[i] == '-')
			{
				contadorGuion++;
			}
		}
		if(contadorDigito >= 10 && contadorGuion == 2)
		{
			rtn = 1;
		}
		else
		{
			rtn = 0;
		}
	}
	return rtn;
}

// Get

/*
 * \brief Ingresa mensaje
 * \param valida que sea int
 * \return int ingresado
 */
int Get_Int(char *MSJ, char *ERROR_MSJ)
{
	int rtn;
	char buffer[SIZE_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(Validate_OnlyNumberInt(buffer) == 0)
	{
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn = atoi(buffer);
	return rtn;
}

/*
 * \brief Ingresa mensaje, minimo y maximo
 * \param valida que sea int y este en el rango
 * \return int ingresado
 */
int Get_IntRange(char *MSJ, char *ERROR_MSJ, int MIN, int MAX)
{
	int rtn = Get_Int(MSJ, ERROR_MSJ);

	while(rtn < MIN || rtn > MAX)
	{
		printf("ERROR, Fuera de rango -> [MIN]=%d [MAX]=%d.\n", MIN, MAX);
		rtn = Get_Int(MSJ, ERROR_MSJ);
	}
	return rtn;
}

/*
 * \brief Ingresa mensaje
 * \param valida que sea int y positivo
 * \return int ingresado
 */
int Get_IntPositive(char *MSJ, char *ERROR_MSJ)
{
	int rtn = Get_Int(MSJ, ERROR_MSJ);
	while(rtn < 0)
	{
		printf("ERROR, Solo numeros positivos");
		rtn = Get_Int(MSJ, ERROR_MSJ);
	}
	return rtn;
}

/*
 * \brief Ingresa mensaje
 * \param valida que sea int y negativo
 * \return int ingresado
 */
int Get_IntNegative(char *MSJ, char *ERROR_MSJ)
{
	int rtn = Get_Int(MSJ, ERROR_MSJ);
	while(rtn > 0)
	{
		printf("ERROR, Solo numeros positivos");
		rtn = Get_Int(MSJ, ERROR_MSJ);
	}
	return rtn;
}

/*
 * \brief Ingresa mensaje
 * \param valida que sea float
 * \return float ingresado
 */
float Get_Float(char *MSJ, char *ERROR_MSJ)
{
	int rtn;
	char buffer[SIZE_BUFFER];
	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(Validate_OnlyNumberFloat(buffer) == 0)
	{
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}
	rtn = atof(buffer);
	return rtn;

}

/*
 * \brief Ingresa mensaje, minimo y maximo
 * \param valida que sea float y este dentro del rango
 * \return float ingresado
 */
float Get_FloatRange(char *MSJ, char *ERROR_MSJ, float MIN, float MAX)
{
	float rtn = Get_Float(MSJ, ERROR_MSJ);

	while(rtn < MIN || rtn > MAX)
	{
		printf("ERROR, Fuera de rango -> [MIN]=%.2f [MAX]=%.2f.\n", MIN, MAX);
		rtn = Get_Float(MSJ, ERROR_MSJ);
	}
	return rtn;
}


/*
 * \brief Ingresa mensaje
 * \param valida que sean solo letras y no nulo
 * \return char ingresado
 */
char Get_Char(char *MSJ, char *ERROR_MSJ)
{
	char rtn;
	char buffer[SIZE_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer) > 1 || Validate_OnlyAlphabet(buffer) == 0)
	{
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn = buffer[0];

	return rtn;
}

/*
 * \brief Ingresa mensaje, string y tamanio del string
 * \param valida que no sea nulo o 0 el string
 * \return no retorna nada
 */
void Get_String(char *MSJ, char *ERROR_MSJ, char *pString, int size)
{
	char buffer[SIZE_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer) > size || strlen(buffer) == 0)
	{
		printf("Error, Fuera de rango -> Caracteres [MIN] = 1 [MAX] = %d \n", size);
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}
	strcpy(pString, buffer);
}

/*
 * \brief Ingresa mensaje, string y tamanio del string
 * \param valida que tenga solo letras
 * \return no retorna nada
 */
void Get_OnlyAlphabetString(char *MSJ, char *ERROR_MSJ, char *pString, int size)
{
	char buffer[SIZE_BUFFER];
	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer) > size || strlen(buffer) == 0 || Validate_OnlyAlphabet(buffer) == 0)
	{
		if(strlen(buffer) > size || strlen(buffer) == 0)
		{
			printf("Error, fuera de rango -> Caracteres [MIN] = 1 [MAX] = %d \n", size);
		}
		else
		{
			printf("\n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(pString, buffer);
}

/*
 * \brief Ingresa mensaje, string y tamanio del string
 * \param valida que tenga letras y espacio
 * \return no retorna nada
 */
void Get_OnlyAlphabetStringWithSpaces(char *MSJ, char *ERROR_MSJ, char *pString, int size)
{
	char buffer[SIZE_BUFFER];
	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer) > size || strlen(buffer) == 0 || Validate_OnlyAlphabetWithSpaces(buffer) == 0)
	{
		if(strlen(buffer) > size || strlen(buffer) == 0)
		{
			printf("Error, fuera de rango -> Caracteres [MIN] = 1 [MAX] = %d \n", size);
		}
		else
		{
			printf("Error, solo caracteres alfabeticos validos \n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(pString, buffer);
}

/*
 * \brief Ingresa mensaje y string
 * \param valida que tenga formato cuil
 * \return no retorna nada
 */
void Get_Cuil(char *MSJ, char *ERROR_MSJ, char *pString, int size)
{
	char buffer[SIZE_BUFFER];
	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer) > size || strlen(buffer) == 0 || Validate_Cuit(buffer) == 0)
	{
		if(strlen(buffer) > size || strlen(buffer) == 0)
		{
			printf("Error, fuera de rango -> Caracteres [MIN] = 1 [MAX] = %d \n", size);
		}
		else
		{
			printf("Error, solo formato [XX-XXXXXXXX-X] \n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(pString, buffer);

}

/*
 * \brief Ingresa mensaje y string
 * \param valida que tenga formato dni
 * \return no retorna nada
 */
void Get_DNI(char *MSJ, char *ERROR_MSJ, char *pString, int size)
{
	char buffer[SIZE_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer) > 8 || strlen(buffer) < 7 || Validate_OnlyNumberInt(buffer) == 0)
	{
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(pString, buffer);
}

/*
 * \brief Imprimir menu
 * \param Menu principal
 * \return no retorna nada
 */
void Menu(void)
{
	printf("\n--Menu Principal--\n"
			"1) Alta de contribuyente\n"
			"2) Modificar datos del contribuyente\n"
			"3) Baja de contribuyente\n"
			"4) Recaudacion\n"
			"5) Refinanciar recaudacion\n"
			"6) Saldar recaudacion\n"
			"7) Imprimir contribuyentes\n"
			"8) Imprimir recaudacion\n"
			"9) Salir\n");
}
