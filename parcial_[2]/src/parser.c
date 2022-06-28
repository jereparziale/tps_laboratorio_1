#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "Salon.h"
#include "Juego.h"
#include "Arcade.h"

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

/** \brief Parsea los datos  de los salones desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param ll_salon LinkedList*
 * \return int
 */
int parser_SalonFromText(FILE* pFile , LinkedList* ll_salon, int* contadorErrores)
{
	Salon* this;
	int rtn=-1;
	char id[100];
	char nombreAux[100];
	char direccionAux[100];
	char tipoSalonAux[100];
	int datos;

	if(pFile!=NULL)
	{
		if(ll_salon!=NULL)
		{
			do
			{

				datos=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombreAux,direccionAux,tipoSalonAux);
				if(datos==4)
				{
					this=Salon_newParametros(id, nombreAux, direccionAux,tipoSalonAux,contadorErrores);
					if(this!=NULL)
					{
						ll_add(ll_salon,this);
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

/** \brief Parsea los datos  de los arcade desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param ll_arcade LinkedList*
 * \return int
 */
int parser_ArcadeFromText(FILE* pFile , LinkedList* ll_arcade, int* contadorErrores)
{
	Arcade* this;
	int rtn=-1;
	char id[100];
	char nacionalidadAux[100];
	char tipoSonidoAux[100];
	char cantJugadoresAux[100];
	char maxFichasAux[100];
	char FK_idSalonAux[100];
	char FK_idJuegoAux[100];
	int datos;

	if(pFile!=NULL)
	{
		if(ll_arcade!=NULL)
		{
			do
			{

				datos=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,nacionalidadAux,tipoSonidoAux,cantJugadoresAux,maxFichasAux,FK_idSalonAux,FK_idJuegoAux);
				if(datos==7)
				{
					this=Arcade_newParametros(id,nacionalidadAux,tipoSonidoAux,cantJugadoresAux,maxFichasAux,FK_idSalonAux,FK_idJuegoAux,contadorErrores);
					if(this!=NULL)
					{
						ll_add(ll_arcade,this);
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

/** \brief Parsea los datos  de los juegos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param ll_juego LinkedList*
 * \return int
 */
int parser_JuegoFromText(FILE* pFile , LinkedList* ll_juego, int* contadorErrores)
{
	Juego* this;
	int rtn=-1;
	char id[100];
	char nombreAux[100];
	char empresaAux[100];
	char generoAux[100];
	int datos;

	if(pFile!=NULL)
	{
		if(ll_juego!=NULL)
		{
			do
			{

				datos=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombreAux,empresaAux,generoAux);
				if(datos==4)
				{
					this=Juego_newParametros(id, nombreAux, empresaAux,generoAux,contadorErrores);
					if(this!=NULL)
					{
						ll_add(ll_juego,this);
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
