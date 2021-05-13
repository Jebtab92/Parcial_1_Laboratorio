/*
 * Biblioteca.h
 *
 *  Created on: May 11, 2021
 *      Author: Jonatan Barbuto
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE_BUFFER 1000

// Validaciones
int Validate_OnlyNumberInt(char *buffer);
int Validate_OnlyNumberFloat(char *buffer);
int Validate_OnlyAlphabet(char *buffer);
int Validate_OnlyAphabetWithSpaces(char *buffer);
int Validate_Exit_SN(char *MSJ, char *ERROR_MSJ);
int Validate_Cuit(char *pData);

// Get
int Get_Int(char *MSJ, char *ERROR_MSJ);
int Get_IntRange(char *MSJ, char *ERROR_MSJ, int MIN, int MAX);
int Get_IntPositive(char *MSJ, char *ERROR_MSJ);
int Get_IntNegative(char *MSJ, char *ERROR_MSJ);
float Get_Float(char *MSJ, char *ERROR_MSJ);
float Get_FloatRange(char *MSJ, char *ERROR_MSJ, float MIN, float MAX);
double Get_Double(char *MSJ, char *ERROR_MSJ);
double Get_DoubleRange(char *MSJ, char *ERROR_MSJ, double MIN, double MAX);

char Get_Char(char *MSJ, char *ERROR_MSJ);
void Get_String(char *MSJ, char *ERROR_MSJ, char *pString, int size);
void Get_OnlyAlphabetString(char *MSJ, char *ERROR_MSJ, char *pString, int size);
void Get_OnlyAlphabetStringWithSpaces(char *MSJ, char *ERROR_MSJ, char *pString, int size);
void Get_Cuil(char *MSJ, char *ERROR_MSJ, char *pString, int size);
void Get_DNI(char *MSJ, char *ERROR_MSJ, char *pString, int size);

// Utilidades
void ArrayPrint_Int(int *pArray, int size);
void ArrayPrint_Float(float *pArray, int size);
// Criterio -> -1 = Menor a Mayor | 1 = Mayor a Menor
int ArraySort_Int(int *pArray, int size, int criterio);
int ArraySort_Float(float *pArray, int size, int criterio);
void Format_NameLastname(char *pName, char *pLastname, char *pFormatName);
void Menu(void);




#endif /* BIBLIOTECA_H_ */
