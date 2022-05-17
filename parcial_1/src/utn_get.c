#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"


//INGRESO DE CONTRASEÑA 9 CARACTERES
char utn_getEmail(char pResultado[], char* mensaje, char* mensajeError, int tam, int reintentos)
{
	 int rtn=-1;
	 char bufferInt[tam];
	 if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	 {

		 printf("%s \n", mensaje);
		do
		{
			 if(getEmail(bufferInt,tam)==0)
			 {
				 strcpy(pResultado,bufferInt);
				 rtn= 0;
				 break;
			 }
			 else
			 {
				 reintentos--;
				 printf("%s",mensajeError);
			 }
		}while(reintentos>0);

	 }
	 return rtn;
}

//FUNCION GETINT
char getEmail(char* pStringTomado, int tam)
{
	int rtn =-1;
	char textoAuxiliar[tam];

	if(pStringTomado != NULL)
	{
		if(myGetsEmail(textoAuxiliar, tam)==0)
		{
			strcpy(pStringTomado,textoAuxiliar);
			rtn = 0;
		}
	}
	return rtn;
}

//MYGETS
int myGetsEmail(char* cadena, int tam)
{
	int rtn=-1;
	int i;
	int flag=0;
	if(cadena != NULL && tam >0 && fgets(cadena,tam,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[0]=='\0')
		{
			rtn=-1;
		}
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		for(i=0;i<strlen(cadena);i++)
		{
			if(cadena[i]=='@')
			{
				flag++;
				break;
			}
			else
			{
				rtn=-1;
			}
		}
		for(i=0;i<strlen(cadena);i++)
		{
			if(cadena[i]=='.')
			{
				flag++;
				break;
			}
			else
			{
				rtn=-2;
			}
		}
		if(flag==2)
		{
			rtn=0;
		}
		else
		{
			rtn=-3;
		}
	}
	return rtn;
}


//CONVERTIR MINUSCULAS A MAYUSCULAS
int cambiarMinusMayus(char pArray[], int tam)
{
	int i;
	int auxiliarNombre;
	int rtn=-1;
	if(pArray != NULL && tam >0)
	{
		for(i=0;i<strlen(pArray);i++)
			{
				if((pArray[i]>='a' && pArray[i]<='z'))
				{
					auxiliarNombre= pArray[i];
					utn_restaInt(&auxiliarNombre, auxiliarNombre, 32, "ERROR");
					pArray[i]=auxiliarNombre;
				}
			}
		rtn=0;
	}
	return rtn;
}

//FUNCION DE ORDENAMIENTO POR BURBUJEO
int ordenarArrayIntDecreciente(int pArray [], int tam, int* contador)
{
	int flagSwap;
	int rtn=-1;
	int i;
	int bufferAux;
	int auxContador=0;
	int nuevoTam;

	if(pArray != NULL && tam >0)
	{
		do
		{
			flagSwap=0;
			nuevoTam= tam-1;
			for (i = 0; i < nuevoTam; ++i) //hago tam-1 para que no intercambie con una varibale que no existe
			{
				if (pArray [i] < pArray[i+1])
				{
					flagSwap=1;
					bufferAux=pArray [i];
					pArray [i]=pArray[i+1];
					pArray[i+1]=bufferAux;
				}
				auxContador++;

			}
			tam--;
		}while(flagSwap);
		*contador=auxContador;
	}
	return rtn;
}


int ordenarArrayIntCreciente(int pArray [], int tam, int* contador)
{
	int flagSwap;
	int rtn=-1;
	int i;
	int bufferAux;
	int auxContador=0;
	int nuevoTam;

	if(pArray != NULL && tam >0)
	{
		do
		{
			flagSwap=0;
			nuevoTam= tam-1;
			for (i = 0; i < nuevoTam; ++i) //hago tam-1 para que no intercambie con una varibale que no existe
			{
				if (pArray [i] > pArray[i+1])
				{
					flagSwap=1;
					bufferAux=pArray [i];
					pArray [i]=pArray[i+1];
					pArray[i+1]=bufferAux;
				}
				auxContador++;

			}
			tam--;
		}while(flagSwap);
		*contador=auxContador;
	}
	return rtn;
}
//FUNCION TOMAR UN ARRAY NO SE PONE PUNTERO XQ UN ARRAY ES UN PUNTERO Y TAMPOCO EL & EN EL MAIN
void cargarArray(int array [], int tam, char* mensaje)
{

	if(array != NULL && tam >0)
	{
		for(int i = 0; i < tam; i++)
		{
			printf("%d %s \n", i, mensaje);
			scanf("%d", &array[i]); //CUANDO TIENE ALGUNA VARIABLE O INDICE (I) SE PONE EL &
		}
	}

}

//FUNCION IMPRIMIR ARRAY
void imprimirArray(int array [], int tam)
{
	if(array != NULL && tam >0 )
	{
		for(int i = 0; i < tam ; i++)
		{
			printf("%d\n", array[i]);
		}
	}
}

//PROMEDIO ARRAYS
int calcularPromedioArray(int array [], int tam, float *promedio)
{
	int i;
	int acumulador=0;
	int rtn = -1;

if(array !=  NULL && promedio != NULL && tam >0)
	{
		for(i =0; i<tam; i++)
		{
			acumulador=acumulador+array[i];
		}
		*promedio=(float)acumulador/i;
		rtn=0;
	}
	else
	{
		printf("ERROR");
	}

	return  rtn;
}

//BANDERA MAXIMO
int banderaMaxArrayContador(int array [], int *maximo, int tam)
{
	int i;
	int contador=0;
	int maximoIngresado;

	for(i =0; i<tam; i++)
	{
		if(array[i]>maximoIngresado || i ==0)
		{
			maximoIngresado=array[i];
		}
	}

	for(i =0; i<tam; i++)
	{
		if(maximoIngresado==array[i])
		{
			contador++;
		}
	}
	*maximo=maximoIngresado;
	return contador;
}

//BANDERA MINIMO
int banderaMinArrayContador(int array [], int *minimo, int tam)
{
	int i;
	int contador=0;
	int minimoIngresado;

	for(i =0; i<tam; i++)
	{
		if(array[i]<minimoIngresado || i ==0)
		{
			minimoIngresado=array[i];
		}
	}

	for(i =0; i<tam; i++)
	{
		if(minimoIngresado==array[i])
		{
			contador++;
		}
	}


	*minimo=minimoIngresado;
	return contador;
}

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
	 if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	 {

		 printf("%s \n", mensaje);
		do
		{
			 if(getInt(&bufferInt)==0 && bufferInt >= minimo && bufferInt <= maximo)
			 {
				 *pResultado = bufferInt;
				 rtn= 0;
				 break;
			 }
			 else
			 {
				 reintentos--;
				 printf("%s",mensajeError);
			 }
		}while(reintentos>0);

	 }
	 return rtn;
}



//FUNCION GETINT
int getInt(int *pNumeroTomado)
{
	int rtn =-1;
	char numeroAuxiliar[11];

	if(pNumeroTomado != NULL)
	{
		if(myGets(numeroAuxiliar, 11)==0 && esNumerica(numeroAuxiliar)==1)
		{
			*pNumeroTomado = atoi(numeroAuxiliar);
			rtn = 0;
		}
	}
	return rtn;

}

//MYGETS
int myGets(char* cadena, int tam)
{
	int rtn=-1;
	if(cadena != NULL && tam >0 && fgets(cadena,tam,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		rtn=0;
		if(cadena[0]=='\0')
		{
			rtn=-1;
		}
	}
	return rtn;
}

//ES NUMERICA
int esNumerica(char cadena[])
{
	int rtn = 1;
	int i=0;
	if(cadena != NULL && strlen(cadena)>0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < 48 || cadena[i] > 57)
			{
				rtn=0;
				break;
			}
			i++;
		}
	}
	return rtn;
}

//FUNCION DE TOMA DE NUMERO FLOAT
float utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	 int rtn=-1;
	 float bufferFloat;
	 if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	 {
		 do
		 {
			 printf("%s \n", mensaje);
			 scanf("%f", &bufferFloat);
			 if(bufferFloat >= minimo && bufferFloat <= maximo)
			 {
				 *pResultado = bufferFloat;
				 rtn=0;
				 reintentos=0;
			 }
			 else
			 {
				 printf("%s \n", mensajeError);
				 reintentos--;
			 }
		 }while(reintentos>0);
	 }

	 return rtn;
}

//FUNCION DE TOMA DE NUMERO FLOAT NUEVA CON FGETS

float utn_getFloatNuevo(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	 int rtn=-1;
	 float bufferFloat;
	 if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	 {

		 printf("%s \n", mensaje);
		do
		{
			 if(getFloat(&bufferFloat)==0 && bufferFloat >= minimo && bufferFloat <= maximo)
			 {
				 *pResultado = bufferFloat;
				 rtn= 0;
				 break;
			 }
			 else
			 {
				 reintentos--;
				 printf("%s",mensajeError);
			 }
		}while(reintentos>0);

	 }
	 return rtn;
}




//FUNCION GETINT
int getFloat(float *pNumeroTomado)
{
	int rtn =-1;
	char numeroAuxiliar[20];

	if(pNumeroTomado != NULL)
	{
		if(myGets(numeroAuxiliar, 20)==0 && esNumeroDecimal(numeroAuxiliar)==1)
		{
			*pNumeroTomado = atof(numeroAuxiliar);
			rtn = 0;
		}
	}
	return rtn;
}

//ES FLOAT
int esNumeroDecimal(char cadena[])
{
	int rtn = 1;
	int i=0;
	int contadorPuntos=0;
	if(cadena != NULL && strlen(cadena)>0)
	{
		while(cadena[i] != '\0')
		{

			if(cadena[i] < 48 || cadena[i] > 57)
			{
				if((cadena[i]=='.' && contadorPuntos < 1))
				{
					contadorPuntos++;
				}
				else
				{
				rtn=0;
				printf("%s",cadena);
				break;
				}
			}
			i++;
		}
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

//FUNCION TOMA DE UN STRING
char utn_getPassword(char pResultado[], char* mensaje, char* mensajeError, int tam,int tam_minimo, int reintentos)
{
	 int rtn=-1;
	 char bufferInt[tam];
	 if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	 {

		 printf("%s \n", mensaje);
		do
		{
			 if(getPassword(bufferInt,tam,tam_minimo)==0)
			 {
				 strcpy(pResultado,bufferInt);
				 rtn= 0;
				 break;
			 }
			 else
			 {
				 reintentos--;
				 printf("%s",mensajeError);
			 }
		}while(reintentos>0);

	 }
	 return rtn;
}

//FUNCION GETINT
char getPassword(char* pStringTomado, int tam, int tam_minimo)
{
	int rtn =-1;
	char textoAuxiliar[tam];

	if(pStringTomado != NULL)
	{
		if(myGets(textoAuxiliar, tam)==0)
		{
			if(strlen(textoAuxiliar)>=tam_minimo)
			{
				strcpy(pStringTomado,textoAuxiliar);
				rtn = 0;
			}
			else
			{
				rtn=-4;
			}
		}
	}
	return rtn;
}


//FUNCION TOMA DE UN STRING
char utn_getString(char pResultado[], char* mensaje, char* mensajeError, int tam, int reintentos)
{
	 int rtn=-1;
	 char bufferInt[tam];
	 if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	 {

		 printf("%s \n", mensaje);
		do
		{
			 if(getString(bufferInt,tam)==0)
			 {
				 strcpy(pResultado,bufferInt);
				 rtn= 0;
				 break;
			 }
			 else
			 {
				 reintentos--;
				 printf("%s",mensajeError);
			 }
		}while(reintentos>0);

	 }
	 return rtn;
}

//FUNCION GETINT
char getString(char* pStringTomado, int tam)
{
	int rtn =-1;
	char textoAuxiliar[tam];

	if(pStringTomado != NULL)
	{
		if(myGets(textoAuxiliar, tam)==0)
		{
			strcpy(pStringTomado,textoAuxiliar);
			rtn = 0;
		}
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









