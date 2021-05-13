/*
 * Biblioteca.c
 *
 *  Created on: May 11, 2021
 *      Author: Jonatan Barbuto
 */

#include "Biblioteca.h"

// Validaciones

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
		if(contadorDigito == 11 && contadorGuion == 2)
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
double Get_Double(char *MSJ, char *ERROR_MSJ)
{
	char buffer[SIZE_BUFFER];
	double rtn;

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
double Get_DoubleRange(char *MSJ, char *ERROR_MSJ, double MIN, double MAX)
{
	double rtn = Get_Float(MSJ, ERROR_MSJ);

	while(rtn < MIN || rtn > MAX)
	{
		printf("ERROR, Fuera de rango -> [MIN]=%.2f [MAX]=%.2f.\n", MIN, MAX);
		rtn = Get_Float(MSJ, ERROR_MSJ);
	}
	return rtn;
}
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
			printf("Error, solo caracteres alfabeticos validos \n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(pString, buffer);
}
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

// Utilidades
void ArrayPrint_Int(int *pArray, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		printf("%d\n", pArray[i]);
	}
}
void ArrayPrint_Float(float *pArray, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		printf("%.2f\n", pArray[i]);
	}
}
int ArraySort_Int(int *pArray, int size, int criterio)
{
	int rtn = 0;
	int aux, i;

	if(pArray != NULL && size > 0)
	{
		switch(criterio)
		{
			case -1:
			{
				for(i = 0; i < size -1; i++)
				{
					for(int j = i + 1; j < size; j++)
					{
						if(pArray[i] > pArray[j])
						{
							aux = pArray[1];
							pArray[i] = pArray[j];
							pArray[j] = aux;
						}
					}
				}
				rtn = 1;
				break;
			}
			case 1:
			{
				for(i = 0; i < size -1; i++)
				{
					for(int j = i + 1; j < size; j++)
					{
						if(pArray[i] < pArray[j])
						{
							aux = pArray[1];
							pArray[i] = pArray[j];
							pArray[j] = aux;
						}
					}
				}
				rtn = 1;
				break;
			}
			default:
			{
				// Criterio mal ingresado
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}
int ArraySort_Float(float *pArray, int size, int criterio)
{
	int rtn = 0;
	int i;
	float aux;

	if(pArray != NULL && size > 0)
	{
		switch(criterio)
		{
			case -1:
			{
				for(i = 0; i < size -1; i++)
				{
					for(int j = i + 1; j < size; j++)
					{
						if(pArray[i] > pArray[j])
						{
							aux = pArray[1];
							pArray[i] = pArray[j];
							pArray[j] = aux;
						}
					}
				}
				rtn = 1;
				break;
			}
			case 1:
			{
				for(i = 0; i < size -1; i++)
				{
					for(int j = i + 1; j < size; j++)
					{
						if(pArray[i] < pArray[j])
						{
							aux = pArray[1];
							pArray[i] = pArray[j];
							pArray[j] = aux;
						}
					}
				}
				rtn = 1;
				break;
			}
			default:
			{
				// Criterio mal ingresado
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}
void Format_NameLastname(char *pName, char *pLastname, char *pFormatName)
{
	strcpy(pFormatName, pLastname);
	strcat(pFormatName, ", ");
	strcat(pFormatName, pName);

	strlwr(pFormatName);

	if(strlen(pName) > 0 && strlen(pLastname) > 0)
	{
		for(int i = 0; i < strlen(pFormatName); i++)
		{
			if(i == 0 && isspace(pFormatName[i]) == 0)
			{
				pFormatName[0] = toupper(pFormatName[0]);

			}
			else
			{
				if(isspace(pFormatName[i]) && i < strlen(pFormatName) - 1)
				{
					pFormatName[i + 1] = toupper(pFormatName[i + 1]);
				}
			}
		}
	}
}
void Menu(void)
{
	// Imprimir menu
}
