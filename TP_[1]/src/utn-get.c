#include "libreria.h"
#include "utn-get.h"
#include <stdio.h>
#include <stdlib.h>

//FUNCION IMPRIMIR UN MENSAJE
char utn_printfString(char* mensaje)
{
	printf("%s \n", mensaje);
	return 0;
}


//FUNCION DE TOMA DE ENTEROS
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	 int rtn=-1;
	 int bufferInt;
	 int retornoScanf;
	 if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	 {

		 printf("%s \n", mensaje);
		 fflush (stdin);
		 retornoScanf=scanf(" \n %d", &bufferInt);
		do
		{
		 	 if(bufferInt < minimo || bufferInt > maximo || retornoScanf != 1)
			 {
				 printf("%s \n", mensajeError);
				 fflush (stdin);
				 retornoScanf=scanf("\n %d", &bufferInt);
				 reintentos--;
			 }
			 else
			 {
				 *pResultado = bufferInt;
				 rtn= 0;
				 reintentos=0;
			 }
		}while(reintentos>0);

	 }

	 return rtn;
}

//FUNCION DE TOMA DE NUMERO FLOAT
float utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int rtn=-1;
	 float bufferInt;
	 int retornoScanf;
	 if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	 {

		 printf("%s \n", mensaje);
		 fflush (stdin);
		 retornoScanf=scanf("\n %f", &bufferInt);
		do
		{
			 if(bufferInt < minimo || bufferInt > maximo || retornoScanf != 1)
			 {
				 printf("%s \n", mensajeError);
				 fflush (stdin);
				 retornoScanf=scanf("\n %f", &bufferInt);
				 reintentos--;
			 }
			 else
			 {
				 *pResultado = bufferInt;
				 rtn= 0;
				 reintentos=0;
			 }
		}while(reintentos>0);

	 }

	 return rtn;
}

//FUNCION DE TOMA DE UN CHAR
char utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	 int rtn=-1;
	 char bufferInt;
	 int retornoScanf;
	 if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	 {

		 printf("%s \n", mensaje);
		 fflush (stdin);
		 retornoScanf=scanf("\n %c", &bufferInt);
		do
		{
			 if(bufferInt < minimo || bufferInt > maximo || retornoScanf != 1)
			 {
				 printf("%s \n", mensajeError);
				 fflush (stdin);
				 retornoScanf=scanf("\n %c", &bufferInt);
				 reintentos--;
			 }
			 else
			 {
				 *pResultado = bufferInt;
				 rtn= 0;
				 reintentos=0;
			 }
		}while(reintentos>0);

	 }

	 return rtn;
}

//FUNCION SUMAR DOS FLOAT
float utn_sumaFloat(float* pResultado, float numA, float numB, char* mensajeError)
{
	int rtn=-1;

	if(pResultado != NULL && mensajeError != NULL)
	{
		*pResultado= numA+numB;
		rtn=0;
	}
	else
	{
		printf("%s \n", mensajeError);
	}

	return rtn;
}

//FUNCION SUMAR DOS INT
int utn_sumaInt(int* pResultado, int numA, int numB, char* mensajeError)
{
	int rtn=-1;

	if(pResultado != NULL && mensajeError != NULL)
	{
		*pResultado= numA+numB;
		rtn=0;
	}
	else
	{
		printf("%s \n", mensajeError);
	}

	return rtn;
}

//FUNCION RESTAR DOS FLOAT
float utn_restaFloat(float* pResultado, float numA, float numB, char* mensajeError)
{
	int rtn=-1;

	if(pResultado != NULL && mensajeError != NULL)
	{
		*pResultado= numA - numB;
		rtn=0;
	}
	else
	{
		printf("%s \n", mensajeError);
	}

	return rtn;
}

//FUNCION RESTAR DOS INT
int utn_restaInt(int* pResultado, int numA, int numB, char* mensajeError)
{
	int rtn=-1;

	if(pResultado != NULL && mensajeError != NULL)
	{
		*pResultado= numA - numB;
		rtn=0;
	}
	else
	{
		printf("%s \n", mensajeError);
	}

	return rtn;
}

//FUNCION MULTIPLICAR DOS FLOAT
float utn_multiFloat(float* pResultado, float numA, float numB, char* mensajeError)
{
	int rtn=-1;

	if(pResultado != NULL && mensajeError != NULL)
	{
		*pResultado= numA * numB;
		rtn=0;
	}
	else
	{
		printf("%s \n", mensajeError);
	}

	return rtn;
}

//FUNCION MULTIPLICAR DOS INT
int utn_multiInt(int* pResultado, int numA, int numB, char* mensajeError)
{
	int rtn=-1;

	if(pResultado != NULL && mensajeError != NULL)
	{
		*pResultado= numA * numB;
		rtn=0;
	}
	else
	{
		printf("%s \n", mensajeError);
	}

	return rtn;
}

//FUNCION DIVIDIR DOS FLOAT
float utn_divFloat(float* pResultado, float numA, float numB, char* mensajeError)
{
	int rtn=-1;

	if(pResultado != NULL && mensajeError != NULL)
	{
		if(numB>0)
		{
			*pResultado= numA / numB;
			rtn=0;
		}
		else
		{
			printf("%s \n", mensajeError);
		}

	}
	else
	{
		printf("%s \n", mensajeError);
	}

	return rtn;
}

//FUNCION DIVIDIR DOS INT
int utn_divInt(int* pResultado, int numA, int numB, char* mensajeError)
{
	int rtn=-1;

	if(pResultado != NULL && mensajeError != NULL)
	{
		if(numB>0)
		{
			*pResultado=  numA / numB;
			rtn=0;
		}
		else
		{
			printf("%s \n", mensajeError);
		}

	}
	else
	{
		printf("%s \n", mensajeError);
	}

	return rtn;
}



//FUNCION DE PORCENTAJE CON DESCUENTO O RECARGO
float utn_descuentoRecargoFloat(float* pResultado, float numero,float porcentaje, int UNOdescuentoCERORecargo, char* mensajeError)
{
	int rtn=-1;
	float bufferFloat;

	if(pResultado != NULL && mensajeError != NULL && (UNOdescuentoCERORecargo==0 || UNOdescuentoCERORecargo==1))
	{
		bufferFloat= (porcentaje * numero)/100;
		if(UNOdescuentoCERORecargo==1)
		{
			*pResultado= numero - bufferFloat;
			rtn=0;
		}
		else
		{
			*pResultado= numero + bufferFloat;
			rtn=0;
		}

	}
	else
	{
		printf("%s \n", mensajeError);
	}

	return rtn;
}









