#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "Passenger.h"
#include "Flight.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger, int* contadorErrores)
{
	Passenger* this;
	int rtn=-1;
	char id[100];
	char nombreAux[100];
	char apellidoAux[100];
	char precioAux[100];
	char codigoVueloAux[100];
	char tipoPasajeroAux[100];
	char estadoVuelo[100];
	int datos;

	if(pFile!=NULL)
	{
		if(pArrayListPassenger!=NULL)
		{
			do
			{

				datos=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,nombreAux,apellidoAux,precioAux,codigoVueloAux,tipoPasajeroAux,estadoVuelo);
				if(datos==7)
				{
					this=Passenger_newParametros(id, nombreAux, apellidoAux, precioAux, tipoPasajeroAux, codigoVueloAux,estadoVuelo,contadorErrores);
					if(this!=NULL)
					{
						ll_add(pArrayListPassenger,this);
						rtn=0;
					}
					else
					{
						rtn=-3; //ERROR EN CARGA DE DATOS
					}
				}
			}while(feof(pFile) == 0);
		}
		else
		{
			rtn=-2; //LL NULA
		}
	}
	else
	{
		rtn=-1; //FILE NULO
	}
    return rtn;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* this=NULL;
	int rtn=-1;
	if(pFile!=NULL)
	{
		if(pArrayListPassenger!=NULL)
		{
			do
			{
				this=Passenger_new();
				rtn=fread(this,sizeof(Passenger),1,pFile);
				if(rtn==1)
				{
					if(this!=NULL)
					{

						ll_add(pArrayListPassenger,this);
						rtn=0;
					}
					else
					{
						rtn=-3; //ERROR EN CARGA DE DATOS
					}
				}
				else
				{
					free(this);
				}
			}while(feof(pFile) == 0);
		}
		else
		{
			rtn=-2; //LL NULA
		}
	}
	else
	{
		rtn=-1; //FILE NULO
	}
    return rtn;
}

/** \brief Parsea los datos los datos de los vuelos desde el archivo vuelos_data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_FlightFromText(FILE* pFile ,LinkedList* listaVuelos,int tam)
{
	Flight* this;
	int rtn=-1;
	char codigoVueloAux[100];
	char estadoVuelo[100];
	int datos;


	if(pFile!=NULL)
	{
		if(listaVuelos!=NULL)
		{
			do
			{

			datos=fscanf(pFile, "%[^,],%[^\n]\n",codigoVueloAux,estadoVuelo);
			if(datos==2)
			{
				this=eFlight_newParametros(codigoVueloAux, estadoVuelo);
				if(this!=NULL)
				{
					ll_add(listaVuelos,this);
					rtn=0;
				}
				else
				{
					rtn=-3; //ERROR EN CARGA DE DATOS
				}
			}
			}while(feof(pFile) == 0);
		}
		else
		{
			rtn=-2; //LL NULA
		}
	}
	else
	{
		rtn=-1; //FILE NULO
	}
    return rtn;
}

/** \brief Parsea los datos los datos del id desde el archivo id_data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_IdFromText(FILE* pFile)
{
	int rtn=-1;
	char idAux[100];
	int datos;

	if(pFile!=NULL)
	{
			do
			{

			datos=fscanf(pFile, "%[^\n]\n",idAux);
			if(datos==1)
			{
				rtn=atoi(idAux);
			}
			}while(feof(pFile) == 0);
	}
	else
	{
		rtn=-1;
	}
    return rtn;
}
