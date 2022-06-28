#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "Salon.h"
#include "Juego.h"
#include "Arcade.h"
#include "utn_get.h"
#include "LinkedList.h"
#include "Listados.h"
#define AUDIOMONO 1
#define AUDIOESTEREO 2
#define PLATAFORMA 1
#define LABERINTO 2
#define AVENTURA 3
#define OTRO 4
#define AUDIOMONO 1
#define AUDIOESTEREO 2

//--------------------------------------INFORMES------------------------------------
/** \brief Listar por citrerio punto 10 a
 *
 * \param path char*
 * \param ll_salones LinkedList*
 * S\param ll_arcade LinkedList*
 *
 * \return int
 *
 */
int controller_List10A(LinkedList* ll_salones,LinkedList* ll_arcade)
{
	Salon* this;
	Arcade* this_arcade;
	int rtn=-3;
	int i;
	int j;
	int len_ll=ll_len(ll_salones);
	int len_llArcade=ll_len(ll_arcade);
	int FK_idSalonAux;
	int idSalonAux;
	int contadorOcurrencias=0;
	int flagOcu=0;
	if(ll_salones!=NULL)
	{
		if(len_ll>0)
		{
			printf("+---------------LISTADO DE SALONES MAS DE 4 ARCADES-----------------+\n");
			printf("ID  |NOMBRE         |DIRECCION       |TIPO DE SALON|\n");
			printf("----+---------------+----------------+-------------+");
			for(i=0;i<len_ll;i++)
			{
				contadorOcurrencias=0;
				this=ll_get(ll_salones, i);
				for(j=0;j<len_llArcade;j++)
				{
					this_arcade=ll_get(ll_arcade, j);
					Arcade_getIdSalon(this_arcade, &FK_idSalonAux);
					Salon_getId(this, &idSalonAux);
					if(idSalonAux==FK_idSalonAux)
					{
						contadorOcurrencias++;
					}
					if(contadorOcurrencias>4)
					{
						printSalon(this);
						flagOcu=1;
						break;
					}
				}

			}
			if(flagOcu==1)
			{
				rtn=0;
			}
		}
		else
		{
			rtn=-2;
		}
	}
	else
	{
		rtn=-1; //LL NULA
	}
	return rtn;
}

int printB(Arcade* this, Juego* this_Juego, Salon* this_Salon)
{
	int rtn =-1;
	int idAux;
	int cantJugadoresAux;
	char nombreAux[50];
	int generoAux;
	char genero[12];
	char nombreSalon[50];
	if(this != NULL)
	{
		if(Arcade_getId(this, &idAux)==0 && Arcade_getCantidadJugadores(this, &cantJugadoresAux)==0 &&
		 Juego_getNombre(this_Juego, nombreAux)==0 && Juego_getTipoJuego(this_Juego, &generoAux)==0 && Salon_getNombre(this_Salon, nombreSalon)==0)//GET
		{
			switch(generoAux)
			{
				case PLATAFORMA:
					strncpy(genero,"PLATAFORMA",12);
				break;
				case LABERINTO:
					strncpy(genero,"LABERINTO",12);
				break;
				case AVENTURA:
					strncpy(genero,"AVENTURA",12);
				break;
				case OTRO:
					strncpy(genero,"OTRO",12);
				break;
				default:
					puts("ERROR, genero.");
				break;
			}
				printf("\n%-4d|%-6d|%-15s|%-13s|%-15s|",idAux,cantJugadoresAux,
						nombreAux, genero,nombreSalon);
				rtn=0;
		}
	}
	return rtn;
}

int controller_List10B(LinkedList* ll_arcade,LinkedList* ll_juegos, LinkedList* ll_salones)
{
	Arcade* this;
	Juego* this_Juego;
	Salon* this_Salon;
	int rtn=-4;
	int i;
	int len_ll=ll_len(ll_arcade);
	int auxIdJuego;
	int auxIdSalon;
	int index;
	int cantidadJugadores;
	if(ll_arcade!=NULL)
	{
		if(len_ll>0)
		{
			printf("ID  |JUGAD.|NOMBRE JUEGO   |GENERO       |NOMBRE SALON   ||\n");
			printf("----+------+---------------+-------------+---------------+");
			for(i=0;i<len_ll;i++)
			{
				this=ll_get(ll_arcade, i);
				Arcade_getCantidadJugadores(this, &cantidadJugadores);
				if(cantidadJugadores>2)
				{
					Arcade_getIdJuego(this, &auxIdJuego);
					this_Juego=Juego_buscarPorId(ll_juegos, auxIdJuego, &index);
					Arcade_getIdSalon(this, &auxIdSalon);
					this_Salon=Salon_buscarPorId(ll_salones, auxIdSalon, &index);
					if(printB(this,this_Juego,this_Salon)==0)
					{
						rtn=0;
					}
					else
					{
						rtn=-3;//ERROR AL IMPRIMIR
					}

				}
			}
		}
		else
		{
			rtn=-2;
		}
	}
	else
	{
		rtn=-1; //LL NULA
	}
	return rtn;
}

int controller_List10C(LinkedList* ll_salones)
{
	Salon* this;
	int rtn=-1;
	int auxiliarId;
	int index_llBorrar;
	if(ll_salones!=NULL)
	{
		if(controller_ListSalones(ll_salones)==0)
		{
			do
			{
				requestId(&auxiliarId);
				this=Salon_buscarPorId(ll_salones, auxiliarId,&index_llBorrar);
			}while(this==NULL);
			if(this!=NULL)
			{
				puts("\nSALON SELECCIONADO");
				printSalonAuxiliar(this);
				rtn=0;
			}
			else
			{
				rtn=-3; //TOMA ID
			}
		}
		else
		{
			rtn=-2; //LL VACIA
		}
	}
	else
	{
		rtn=-1; //LL NULA
	}
	return rtn;
}

/** \brief Listar por citrerio punto 10 a
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_List10D(LinkedList* ll_salones,LinkedList* ll_arcade,LinkedList* ll_juegos)
{
	Salon* this;
	Arcade* this_arcade;
	Juego* this_juego;
	int rtn=-3;
	int i;
	int j;
	int len_ll=ll_len(ll_salones);
	int len_llArcade=ll_len(ll_arcade);
	int FK_idSalonAux;
	int idSalonAux;
	int FK_idJuegoAux;
	int contadorPlataforma=0;
	int contadorLaberinto=0;
	int contadorAventura=0;
	int index;
	int generoAux;
	int flagOcu=0;
	if(ll_salones!=NULL && ll_arcade!=NULL && ll_juegos!=NULL)
	{
		if(len_ll>0 && len_llArcade>0)
		{
			printf("+---------------LISTADO DE SALONES COMPLETOS-----------------+\n");
			printf("ID  |NOMBRE         |DIRECCION       |TIPO DE SALON|\n");
			printf("----+---------------+----------------+-------------+");
			//RECORRO LOS SALONES
			for(i=0;i<len_ll;i++)
			{
				contadorPlataforma=0;
				contadorLaberinto=0;
				contadorAventura=0;
				this=ll_get(ll_salones, i);
				//RECORRO LOS ARCADES
				for(j=0;j<len_llArcade;j++)
				{
					this_arcade=ll_get(ll_arcade, j);
					Arcade_getIdSalon(this_arcade, &FK_idSalonAux);
					Salon_getId(this, &idSalonAux);
					//TOMO LOS 2 ID(SALON Y FK_SALON ARCADE
					if(idSalonAux==FK_idSalonAux)
					{
						//SI HAY COINCIDENCIA TOMO EL JUEGO Y BUSCO SU GENERO--
						//--Y CUENTO EN CASO DE NO CUMPLIR SE REINICIA SINO IMPRIME
						Arcade_getIdJuego(this_arcade, &FK_idJuegoAux);
						this_juego=Juego_buscarPorId(ll_juegos, FK_idJuegoAux, &index);
						Juego_getTipoJuego(this_juego, &generoAux);
						switch(generoAux)
						{
						case PLATAFORMA:
							contadorPlataforma++;
						break;
						case LABERINTO:
							contadorLaberinto++;
						break;
						case AVENTURA:
							contadorAventura++;
						break;
						}
					}
					if(contadorPlataforma>=4 && contadorLaberinto>=3 && contadorAventura>=5)
					{
						printSalon(this);
						flagOcu=1;
						break;
					}
				}

			}
			if(flagOcu==1)
			{
				rtn=0;
			}
		}
		else
		{
			rtn=-2;
		}
	}
	else
	{
		rtn=-1; //LL NULA
	}
	return rtn;
}

/// @fn int printArcadeAuxiliar(Arcade*)
/// @brief Imprime un pasajero en consola con encabezado.
///
/// @pre
/// @post
/// @param this
/// @return rtn 0 ok, rtn -1 si this es NULL
int printE(Arcade* this, Juego* this_juego,int contador)
{
	int rtn =-1;
	int idAux;
	char nacionalidadAux[50];
	int tipoSonidoAux;
	char tipoSonido[8];
	int cantJugadoresAux;
	int maxFichasAux;
	char nombreAux[50];
	if(this != NULL)
	{
		if(Arcade_getId(this, &idAux)==0 && Arcade_getNacionalidad(this, nacionalidadAux)==0 && Arcade_getTipoSonido(this, &tipoSonidoAux)==0 &&
				Arcade_getCantidadJugadores(this, &cantJugadoresAux)==0 && Arcade_getMaximoFichas(this, &maxFichasAux)==0 &&
				Juego_getNombre(this_juego, nombreAux)==0)//GET
		{
			switch(tipoSonidoAux)
			{
				case AUDIOMONO:
					strncpy(tipoSonido,"MONO",8);
				break;
				case AUDIOESTEREO:
					strncpy(tipoSonido,"ESTEREO",8);
				break;
				default:
					puts("ERROR");
				break;
			}
			if(contador==0)
			{
				puts("\nARCADES RELACIONADOS");
				printf("ID  |NACIONALIDAD   |SONIDO  |JUGAD.|MAX FICHAS|NOMBRE JUEGO   |\n");
				printf("----+---------------+--------+------+----------+---------------+");
			}
				printf("\n%-4d|%-15s|%-8s|%-6d|%-10d|%-15s|",idAux,nacionalidadAux,tipoSonido,cantJugadoresAux,
						maxFichasAux,nombreAux);
				rtn=0;
		}
		else
		{
		}
	}
	return rtn;
}

int controller_List10E(LinkedList* ll_salones,LinkedList* ll_arcade,LinkedList* ll_juegos)
{
	Salon* this;
	Arcade* this_arcade;
	Juego* this_juego;
	int rtn=-4;
	int auxiliarId;
	int index;
	int i;
	int len_llArcade=ll_len(ll_arcade);
	int FK_idSalonAux;
	int idSalonAux;
	int auxIdJuego;
	int contadorOcurrencias=0;
	if(ll_salones!=NULL && ll_arcade!=NULL && ll_juegos!=NULL)
	{
		if(controller_ListSalones(ll_salones)==0)
		{
			do
			{
				requestId(&auxiliarId);
				this=Salon_buscarPorId(ll_salones, auxiliarId,&index);
			}while(this==NULL);
			if(this!=NULL)
			{
				puts("\nSALON SELECCIONADO");
				printSalonAuxiliar(this);
				//RECORRO LOS ARCADE
				for(i=0;i<len_llArcade;i++)
				{
					this_arcade=ll_get(ll_arcade, i);
					Arcade_getIdSalon(this_arcade, &FK_idSalonAux);
					Salon_getId(this, &idSalonAux);
					if(idSalonAux==FK_idSalonAux)
					{
						Arcade_getIdJuego(this_arcade, &auxIdJuego);
						this_juego=Juego_buscarPorId(ll_juegos, auxIdJuego, &index);
						//SI HAY OCURRENCIA EL PRIMERO IMPRIME EL ENCABEZADO
						printE(this_arcade, this_juego,contadorOcurrencias);
						contadorOcurrencias++;
						rtn=0;
					}
				}
			}
			else
			{
				rtn=-3; //TOMA ID
			}
		}
		else
		{
			rtn=-2; //LL VACIA
		}
	}
	else
	{
		rtn=-1; //LL NULA
	}
	return rtn;
}



/** \brief Listar por citrerio punto 10 a
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_List10F(LinkedList* ll_salones,LinkedList* ll_arcade)
{
	Salon* this;
	Arcade* this_arcade;
	Arcade* this_arcadeAux;
	LinkedList* ll_arcadeSort=ll_newLinkedList();
	int rtn=-1;
	int i;
	int j;
	int len_ll=ll_len(ll_salones);
	int len_llArcade=ll_len(ll_arcade);
	int FK_idSalonAux;
	int idSalonAux;
	int contador;
	int max=0;
	int idMax;
	int index;
	if(ll_salones!=NULL)
	{
		if(len_ll>0 && len_llArcade>0)
		{
			printf("+---------------SALON CON MAS ARCADES INCORPORADOS-----------------+\n");
			for(i=0;i<len_ll;i++)
			{
				contador=0;
				this=ll_get(ll_salones, i);
				for(j=0;j<len_llArcade;j++)
				{
					this_arcade=ll_get(ll_arcade, j);
					Arcade_getIdSalon(this_arcade, &FK_idSalonAux);
					Salon_getId(this, &idSalonAux);
					if(idSalonAux==FK_idSalonAux)
					{
						contador++;
					}
					if(i==0)
					{
						if(contador>0)
						{
							max=contador;
						}
					}
					if(contador>max)
					{
						max=contador;
						idMax=idSalonAux;
					}
				}
			}
			if(max>0)
			{
				//TOMO LOS ARCADE DE ESTE SALON
				this=Salon_buscarPorId(ll_salones, idMax, &index);
				for(j=0;j<len_llArcade;j++)
				{
					this_arcade=ll_get(ll_arcade, j);
					Arcade_getIdSalon(this_arcade, &FK_idSalonAux);
					Salon_getId(this, &idSalonAux);
					if(idSalonAux==FK_idSalonAux)
					{
						ll_add(ll_arcadeSort, this_arcade);
					}
				}
				//FIN CONTADOR MAX
				this=Salon_buscarPorId(ll_salones, idMax, &index);
				printSalonAuxiliar(this);
				printf("\n\n----------La cantidad de arcades incorporados es de: %d----------+",max);
				ll_sort(ll_arcadeSort, Arcade_criterioNacionalidad, 1);
				printf("\nID  |NACIONALIDAD   |SONIDO  |JUGAD.|MAX FICHAS|ID SALON|ID JUEGO|\n");
				printf("----+---------------+--------+------+----------+--------+--------+");
				for(i=0;i<ll_len(ll_arcadeSort);i++)
				{
					this_arcadeAux=ll_get(ll_arcadeSort, i);
					printArcade(this_arcadeAux);
					rtn=0;
				}
			}
			else
			{
				rtn=-3;//NO HUBO OCURRENCIAS
			}

		}
		else
		{
			rtn=-2;//LL VACIA
		}
	}
	else
	{
		rtn=-1; //LL NULA
	}
	return rtn;
}

int printG(Arcade* this, Juego* this_Juego, int contadorOcurrencias)
{
	int rtn =-1;
	int idAux;
	int cantJugadoresAux;
	char nombreAux[50];
	int generoAux;
	char genero[12];
	if(this != NULL)
	{
		if(Juego_getNombre(this_Juego, nombreAux)==0 && Juego_getTipoJuego(this_Juego, &generoAux)==0 &&
		 Arcade_getId(this, &idAux)==0 && Arcade_getCantidadJugadores(this, &cantJugadoresAux)==0 )//GET
		{
			switch(generoAux)
			{
				case PLATAFORMA:
					strncpy(genero,"PLATAFORMA",12);
				break;
				case LABERINTO:
					strncpy(genero,"LABERINTO",12);
				break;
				case AVENTURA:
					strncpy(genero,"AVENTURA",12);
				break;
				case OTRO:
					strncpy(genero,"OTRO",12);
				break;
				default:
					puts("ERROR, genero.");
				break;
			}
			if(contadorOcurrencias==0)
			{
				printf("|NOMBRE JUEGO   |GENERO       |CANT. JUG.|ID ARCADE|\n");
				printf("+---------------+------------------------+---------+");
			}
				printf("\n|%-15s|%-13s|%-11d|%-7d|",nombreAux,genero,cantJugadoresAux,idAux);
				rtn=0;
		}
	}
	return rtn;
}

int controller_List10G(LinkedList* ll_arcade,LinkedList* ll_juegos)
{
	Arcade* this;
	Juego* this_Juego;
	LinkedList* ll_juegoAux=ll_newLinkedList();
	int rtn=-3;//sin ocurrencias
	int i;
	int len_ll=ll_len(ll_arcade);
	int auxIdJuego;
	int index;
	int sonido;
	int genero;
	int FK_idJuego;
	int contadorOcurrencias=0;
	int flagOcu=0;
	if(ll_arcade!=NULL)
	{
		if(len_ll>0)
		{

			for(i=0;i<len_ll;i++)
			{
				this=ll_get(ll_arcade, i);
				Arcade_getTipoSonido(this, &sonido);
				if(sonido==AUDIOMONO)
				{
					Arcade_getIdJuego(this, &auxIdJuego);
					this_Juego=Juego_buscarPorId(ll_juegos, auxIdJuego, &index);
					Juego_getTipoJuego(this_Juego, &genero);
					if(genero==PLATAFORMA)
					{
						ll_add(ll_juegoAux, this_Juego);
					}
				}
			}
			//ORDENO
			ll_sort(ll_juegoAux, Juego_criterioNombre, 1);
			//RECORRO LOS JUEGOS YA ORDENADOS Y TOMO EL ARCADE RELACIONADO PARA IMPRIMIR DATOS
			for(i=0;i<ll_len(ll_juegoAux);i++)
			{
				this_Juego=ll_get(ll_juegoAux, i);
				for(int j=0;i<ll_len(ll_arcade);j++)
				{
					this=ll_get(ll_arcade, j);
					Arcade_getIdJuego(this, &FK_idJuego);
					Juego_getId(this_Juego, &auxIdJuego);
					if(FK_idJuego== auxIdJuego)
					{
						printG(this, this_Juego,contadorOcurrencias);
						contadorOcurrencias++;
						flagOcu=1;
						break;
					}
				}
			}
			if(flagOcu==1)
			{
				rtn=0;
			}
		}
		else
		{
			rtn=-2;
		}
	}
	else
	{
		rtn=-1; //LL NULA
	}
	return rtn;
}

