#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "Salon.h"
#include "Juego.h"
#include "Arcade.h"
#include "utn_get.h"
#include "LinkedList.h"
#include "Parser.h"
#define AUDIOMONO 1
#define AUDIOESTEREO 2
#define PLATAFORMA 1
#define LABERINTO 2
#define AVENTURA 3
#define OTRO 4
#define AUDIOMONO 1
#define AUDIOESTEREO 2

/// @fn int myIdGenerator()
/// @brief carga el dato del ultimo id guardado.
///
/// @pre
/// @post
/// @return retorna el id
int myIdGenerator(char* path)
{
	int myId;
	FILE *pFile=NULL;
	pFile =fopen(path,"r");
	myId=parser_IdFromText(pFile);
	fclose(pFile);
	return myId;
}

/// @fn int saveId(int)
/// @brief Una vez confirmada el alta se guarda el id nuevo en el texto y se aumenta para la proxima consulta.
///
/// @pre
/// @post
/// @param nuevoId
/// @return rtn 0 si ok, -1 si pFile en NULL
int saveId(int nuevoId,char* path)
{
	int rtn=-1;
	char idAuxChar[100];
	FILE *pFile=NULL;
	pFile =fopen(path,"w+");
	if(pFile!=NULL)
	{
		nuevoId++;
		sprintf(idAuxChar,"%d",nuevoId);
		fprintf(pFile,"%d\n",nuevoId);
		rtn=0;
	}
	else
	{
		rtn=-1; //PFILE NULO
	}
	fclose(pFile);
	return rtn;
}

/** \brief Carga los datos de los salones  desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param ll_salon LinkedList*
 * \return int
 *
 */
int controller_loadSalonFromText(char* path , LinkedList* ll_salon, int* contadorErrores)
{
	int rtn=-1;
	int rtnParser=-1;
	FILE *pFile=NULL;
	pFile=fopen(path,"r");
	if(pFile!=NULL && ll_salon != NULL)
	{
		rtn=parser_SalonFromText(pFile ,ll_salon,contadorErrores);
		if(rtnParser==0)
		{
			rtn=0;
			//parser ok
		}
		else if(rtnParser==3)
		{
			rtn=-2; //No tiene la misma cantidad de datos la lista,
		}
	}
	else
	{
		rtn=-1; //FILE O LL NULL
	}
	fclose(pFile);
	return rtn;
}

/** \brief Carga los datos de los arcade  desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param ll_salon LinkedList*
 * \return int
 *
 */
int controller_loadArcadeFromText(char* path , LinkedList* ll_arcade, int* contadorErrores)
{
	int rtn=-1;
	int rtnParser=-1;
	FILE *pFile=NULL;
	pFile=fopen(path,"r");
	if(pFile!=NULL && ll_arcade != NULL)
	{
		rtn=parser_ArcadeFromText(pFile ,ll_arcade,contadorErrores);
		if(rtnParser==0)
		{
			rtn=0;
			//parser ok
		}
		else if(rtnParser==3)
		{
			rtn=-2; //No tiene la misma cantidad de datos la lista,
		}
	}
	else
	{
		rtn=-1; //FILE O LL NULL
	}
	fclose(pFile);
	return rtn;
}

/** \brief Carga los datos de los juegos  desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param ll_juego LinkedList*
 * \return int
 *
 */
int controller_loadJuegoFromText(char* path , LinkedList* ll_juego, int* contadorErrores)
{
	int rtn=-1;
	int rtnParser=-1;
	FILE *pFile=NULL;
	pFile=fopen(path,"r");
	if(pFile!=NULL && ll_juego != NULL)
	{
		rtn=parser_JuegoFromText(pFile ,ll_juego,contadorErrores);
		if(rtnParser==0)
		{
			rtn=0;
			//parser ok
		}
		else if(rtnParser==3)
		{
			rtn=-2; //No tiene la misma cantidad de datos la lista,
		}
	}
	else
	{
		rtn=-1; //FILE O LL NULL
	}
	fclose(pFile);
	return rtn;
}

/// @brief A partir de un id retorna en puntero del salon  y por referencia el indice.
///
/// @pre
/// @post
/// @param ll salones
/// @param auxiliarId
/// @param index_ll
/// @return rtn el puntero al salon, si no existe, NULL.
Salon* Salon_buscarPorId(LinkedList* ll_salones, int auxiliarId, int* index_ll)
{
	Salon* this;
	int len_ll=ll_len(ll_salones);
	int i;
	int idAux;
	for(i=0;i<len_ll;i++)
	{
		this=ll_get(ll_salones, i);
		Salon_getId(this, &idAux);
		if(idAux==auxiliarId)
		{
			//VALIDAR INDEX OF
			*index_ll=ll_indexOf(ll_salones, this);
			break;
		}
		else
		{
			this=NULL;
		}
	}
	return this;
}

/** \brief Alta de salon
 *
 * \param ll_salones LinkedList*
 * \return int
 *
 */
int controller_addSalon(LinkedList* ll_salones)
{
	Salon* this;
	int rtn=-1;
	int continuar;
	int idAux;
	if(ll_salones!=NULL)
	{
		this=AltaSalon();
		if(this!=NULL)
		{
			idAux=myIdGenerator("id_salon.csv");
			Salon_setId(this, idAux);
			printSalonAuxiliar(this);
			utn_getInt(&continuar, "\nDESEA GUARDAR Y DAR EL ALTA?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
			if(continuar==1)
			{
				saveId(idAux,"id_salon.csv");
				ll_add(ll_salones,this);
				rtn=0;
			}
			else
			{
				free(this);
				rtn=-3; //OPERACION CANCELADA.
			}
		}
		else
		{
			rtn=-2;//ERROR EN CARGA DATOS
		}
	}
	else
	{
		rtn=-1; //LL NULA
	}
    return rtn;
}

/** \brief Listar salones
 *
 * \param ll_salones LinkedList*
 * \return int 0 si ok, -2 si ll vacia -1 si ll nula
 *
 */
int controller_ListSalones(LinkedList* ll_salones)
{
	Salon* this;
	int rtn=-1;
	int i;
	int len_ll=ll_len(ll_salones);
	if(ll_salones!=NULL)
	{
		if(len_ll>0)
		{
			printf("+---------------LISTADO DE SALONES-----------------+\n");
			printf("ID  |NOMBRE         |DIRECCION       |TIPO DE SALON|\n");
			printf("----+---------------+----------------+-------------+");
			for(i=0;i<len_ll;i++)
			{
				this=ll_get(ll_salones, i);
				printSalon(this);
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


/** \brief Baja de salon
 *
 * \param ll_salones LinkedList*
 * \param ll_arcade LinkedList*
 * \return int  int 0 si ok, -2 si ll vacia -1 si ll nula, -3 error en toma de id, -4 operacion cancelada
 *
 */
int controller_removeSalon(LinkedList* ll_salones,LinkedList* ll_arcade)
{
	Salon* this;
	Arcade* this_arcade;
	int rtn=-1;
	int auxiliarId;
	int continuar;
	int index_llBorrar;
	int i;
	int idAux;
	int index_llBorrarArcade;
	int contador=0;
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
				printSalonAuxiliar(this);
				utn_getInt(&continuar, "\nDESEA DAR DE BAJA EL ID INGRESADO Y SU/S ARCADE7/S RELACIONADO/S?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
				if(continuar==1)
				{
					ll_remove(ll_salones, index_llBorrar);
					free(this);
					rtn=0;
					//BAJA DE LOS ARCADES
					puts("\nARCADES INCORPORADO AL SALON");
					printf("\nID  |NACIONALIDAD   |SONIDO  |JUGAD.|MAX FICHAS|ID SALON|ID JUEGO|\n");
					printf("----+---------------+--------+------+----------+--------+--------+");
					for (i=0;i<ll_len(ll_arcade);i++)
					{
						this_arcade=ll_get(ll_arcade, i);
						Arcade_getIdSalon(this_arcade, &idAux);
						if(idAux==auxiliarId)
						{
							printArcade(this_arcade);
							index_llBorrarArcade=ll_indexOf(ll_arcade, this_arcade);
							ll_remove(ll_arcade, index_llBorrarArcade);
							free(this_arcade);
							contador++;
						}
						else
						{
							this=NULL;
						}
					}
					if(contador==0)
					{
						puts("\nNO SE ENCONTRARON ARCADES RELACIONADOS");
					}

				}
				else
				{
					rtn=-4; //OPERACION CANCELADA.
				}
			}
			else
			{
				rtn=-3; //ERROR EN CARGA DE ALGUN DATO O ALTA NULA
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

/// @brief A partir de un id retorna en puntero del arcade y por referencia el indice.
///
/// @pre
/// @post
/// @param ll_arcade
/// @param auxiliarId
/// @param index_ll
/// @return rtn el puntero al arcade, si no existe, NULL.
Arcade* Arcade_buscarPorId(LinkedList* ll_arcade, int auxiliarId, int* index_ll)
{
	Arcade* this;
	int len_ll=ll_len(ll_arcade);
	int i;
	int idAux;
	for(i=0;i<len_ll;i++)
	{
		this=ll_get(ll_arcade, i);
		Arcade_getId(this, &idAux);
		if(idAux==auxiliarId)
		{
			//VALIDAR INDEX OF
			*index_ll=ll_indexOf(ll_arcade, this);
			break;
		}
		else
		{
			this=NULL;
		}
	}
	return this;
}


/** \brief Alta de arcade
 *
 * \param path char*
 * \param ll_arcades LinkedList*
 * \param ll_salones LinkedList*
 * \param ll_juegos LinkedList*
 *
 * \return int 0 si ok, -1 si ll vacia, -2 error en datos alta, -3/-4 ll salon/juego vacia,-5operacion cancelada.
 *
 */
int controller_addArcade(LinkedList* ll_arcades,LinkedList* ll_salones,LinkedList* ll_juegos)
{
	Arcade* this;
	Salon* this_salon;
	Juego* this_juego;
	int rtn=-1;
	int continuar;
	int idAux;
	int FK_idSalon;
	int FK_idJuego;
	int indice;

	if(ll_arcades!=NULL && ll_juegos !=NULL && ll_salones !=NULL) //OJO DIVIDIR PARA VALIDAR
	{
		if(ll_len(ll_salones)>0)
		{
			if(ll_len(ll_juegos)>0)
			{
				this=AltaArcade();
				if(this!=NULL)
				{
					//PIDO EL SALON
					if(controller_ListSalones(ll_salones)==0)
					{
						do
						{
							utn_getInt(&FK_idSalon, "\nIngrese el salon al que pertenece el arcade", "ERROR, reintente", 1000, 9999, 5);
							this_salon=Salon_buscarPorId(ll_salones, FK_idSalon,&indice);
						}while(this_salon==NULL);
						printSalonAuxiliar(this_salon);
					}
					Arcade_setIdSalon(this, FK_idSalon);
					//PIDO EL juego
					if(controller_ListJuegos(ll_juegos)==0)
					{
						do
						{
							utn_getInt(&FK_idJuego, "\nIngrese el juego que contiene el arcade", "ERROR, reintente", 1000, 9999, 5);
							this_juego=Juego_buscarPorId(ll_juegos, FK_idJuego,&indice);
						}while(this_juego==NULL);
						printJuegoAuxiliar(this_juego);
					}
					Arcade_setIdJuego(this, FK_idJuego);
					idAux=myIdGenerator("id_arcade.csv");
					Arcade_setId(this, idAux);
					printArcadeAuxiliar(this);
					utn_getInt(&continuar, "\nDESEA GUARDAR Y DAR EL ALTA?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
					if(continuar==1)
					{
						saveId(idAux,"id_arcade.csv");
						ll_add(ll_arcades,this);
						rtn=0;
					}
					else
					{
						free(this);
						rtn=-5; //OPERACION CANCELADA.
					}
				}
				else
				{
					rtn=-4; // NO HYANJUEGOS DE ALTA
				}
			}
			else
			{
				rtn=-3; //NO HAY SALONES DADOS DE ALTA
			}
		}
		else
		{
			rtn=-2;// ERROR EN CARGA DE DATOS
		}
	}
	else
	{
		rtn=-1; //LL NULA
	}
    return rtn;
}

/// @brief printf auxiliar para el listado de arcades que relacionas arcade y juegos
///
/// @pre
/// @post
/// @param this
/// @param this_Juego
/// @return 0 si ok, -1 si error en toma datos
int printArcadeJuego(Arcade* this, Juego* this_Juego)
{
	int rtn =-1;
	int idAux;
	char nacionalidadAux[50];
	int tipoSonidoAux;
	char tipoSonido[8];
	int cantJugadoresAux;
	int maxFichasAux;
	int FK_idSalonAux;
	int FK_idJuegoAux;
	char nombreAux[50];
	char empresaAux[50];
	int generoAux;
	char genero[12];
	if(this != NULL && this_Juego)
	{
		if(Arcade_getId(this, &idAux)==0 && Arcade_getNacionalidad(this, nacionalidadAux)==0 && Arcade_getTipoSonido(this, &tipoSonidoAux)==0 &&
				Arcade_getCantidadJugadores(this, &cantJugadoresAux)==0 && Arcade_getMaximoFichas(this, &maxFichasAux)==0 &&
				Arcade_getIdSalon(this, &FK_idSalonAux)==0 && Arcade_getIdJuego(this, &FK_idJuegoAux)==0 && Juego_getNombre(this_Juego, nombreAux)==0 && Juego_getEmpresa(this_Juego, empresaAux)==0 &&
				Juego_getTipoJuego(this_Juego, &generoAux)==0)//GET
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
				printf("\n%-4d|%-15s|%-8s|%-6d|%-10d|%-8d|%-8d|%-15s|%-16s|%-13s|",idAux,nacionalidadAux,tipoSonido,cantJugadoresAux,
						maxFichasAux,FK_idSalonAux,FK_idJuegoAux,nombreAux, empresaAux, genero);
				rtn=0;
		}
	}
	return rtn;
}

/// @brief listado de arcades y el juego que contiene cada uno
///
/// @pre
/// @post
/// @param ll_arcade
/// @param ll_juegos
/// @return rtn 0 si ok, -2 si ll vacia, -1 si ll null.
int controller_ListArcade(LinkedList* ll_arcade,LinkedList* ll_juegos)
{
	Arcade* this;
	Juego* this_Juego;
	int rtn=-1;
	int i;
	int len_ll=ll_len(ll_arcade);
	int auxIdJuego;
	int index;
	if(ll_arcade!=NULL && ll_juegos !=NULL)
	{
		if(len_ll>0)
		{
			printf("ID  |NACIONALIDAD   |SONIDO  |JUGAD.|MAX FICHAS|ID SALON|ID JUEGO|NOMBRE JUEGO   |EMPRESA         |GENERO       |\n");
			printf("----+---------------+--------+------+----------+--------+--------+---------------+----------------+-------------+");
			for(i=0;i<len_ll;i++)
			{
				this=ll_get(ll_arcade, i);
				Arcade_getIdJuego(this, &auxIdJuego);
				this_Juego=Juego_buscarPorId(ll_juegos, auxIdJuego, &index);
				printArcadeJuego(this,this_Juego);
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

/// @brief Modificar un arcade unicamente la cantidad de jugadores y su juego.
///
/// @pre
/// @post
/// @param ll_arcade
/// @param ll_juegos
/// @return 0 si ok -1 si ll null,-2 si ll vacia, -3 error en toma id arcade,-4 operacion cancelada.
int controller_editArcade(LinkedList* ll_arcade,LinkedList* ll_juegos)
{
	Arcade* auxiliarArcade;
	Arcade* this;
	Juego* this_juego;
	int rtn=-1;
	int auxiliarId;
	int continuar;
	int continuarModificacion;
	int opcionModificacion;
	int index_llModificar;
	int indice;
	int FK_idJuego;
	int cantidadJugadores;
	if(ll_arcade!=NULL && ll_juegos !=NULL)
	{
		if(controller_ListArcade(ll_arcade,ll_juegos)==0)
		{
			do
			{
				requestId(&auxiliarId);
				this=Arcade_buscarPorId(ll_arcade, auxiliarId,&index_llModificar);
			}while(this==NULL);
			auxiliarArcade=this;
			if(auxiliarArcade!=NULL)
			{
				printArcadeAuxiliar(auxiliarArcade);
					do
					{
						if(utn_getInt(&opcionModificacion, "\nIngrese la opcion del campo a modificar,\n1.Cantidad de jugadores.\n2.Juego que contiene."
														, "Error opcion no valida", 1, 2, 5)==0)
						{
							switch(opcionModificacion)
							{
							case 1:
								if(utn_getInt(&cantidadJugadores, "Ingrese la nueva cantidad de jugadores", "ERROR, reintente", 1, 8, 5)==0)
								{
									Arcade_setCantidadJugadores(auxiliarArcade, cantidadJugadores);
								}
							break;
							case 2:
								//PIDO EL juego
								if(controller_ListJuegos(ll_juegos)==0)
								{
									do
									{
										utn_getInt(&FK_idJuego, "\nIngrese el nuevo juego que contiene el arcade", "ERROR, reintente", 1000, 9999, 5);
										this_juego=Juego_buscarPorId(ll_juegos, FK_idJuego,&indice);
									}while(this_juego==NULL);
									printJuegoAuxiliar(this_juego);
								}
								Arcade_setIdJuego(auxiliarArcade, FK_idJuego);
							break;
							}
							printArcadeAuxiliar(auxiliarArcade);
							utn_getInt(&continuarModificacion, "\n\nDESEA MODIFICAR OTRO PARAMETRO?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
						}
					}while(continuarModificacion==1);
					utn_getInt(&continuar, "\n\nDESEA GUARDAR LOS CAMBIOS EFECTUADOS?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
					if(continuar==1)
					{
						this=auxiliarArcade;
						ll_set(ll_arcade, index_llModificar, this);
						rtn=0;
					}
					else
					{
						rtn=-4; //OPERACION CANCELADA.
					}
			}
			else
			{
				rtn=-3; //ERROR EN CARGA DE ALGUN DATO O ALTA NULA
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

/** \brief Baja de arcadeS
 *
 * \param ll_arcade LinkedList*
 * \param ll_juegos LinkedList*
 * \return int  int 0 si ok, -2 si ll vacia -1 si ll nula, -3 error en toma de id, -4 operacion cancelada
 *
 */int controller_removeArcade(LinkedList* ll_arcade,LinkedList* ll_juegos)
{
	Arcade* this;
	int rtn=-1;
	int auxiliarId;
	int continuar;
	int index_llBorrar;
	if(ll_arcade!=NULL)
	{
		if(controller_ListArcade(ll_arcade,ll_juegos)==0)
		{
			do
			{
				requestId(&auxiliarId);
				this=Arcade_buscarPorId(ll_arcade, auxiliarId,&index_llBorrar);
			}while(this==NULL);

			if(this!=NULL)
			{
				printArcadeAuxiliar(this);
				utn_getInt(&continuar, "\nDESEA DAR DE BAJA EL ID INGRESADO?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
				if(continuar==1)
				{
					ll_remove(ll_arcade, index_llBorrar);
					free(this);
					rtn=0;
				}
				else
				{
					rtn=-4; //OPERACION CANCELADA.
				}
			}
			else
			{
				rtn=-3; //ERROR EN CARGA DE ALGUN DATO O ALTA NULA
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

/// @brief A partir de un id retorna en puntero del juego y por referencia el indice.
///
/// @pre
/// @post
/// @param ll_juegos
/// @param auxiliarId
/// @param index_ll
/// @return rtn el puntero al juego, si no existe, NULL.
Juego* Juego_buscarPorId(LinkedList* ll_juegos, int auxiliarId, int* index_ll)
{
	Juego* this;
	int len_ll=ll_len(ll_juegos);
	int i;
	int idAux;
	for(i=0;i<len_ll;i++)
	{
		this=ll_get(ll_juegos, i);
		Juego_getId(this, &idAux);
		if(idAux==auxiliarId)
		{
			//VALIDAR INDEX OF
			*index_ll=ll_indexOf(ll_juegos, this);
			break;
		}
		else
		{
			this=NULL;
		}
	}
	return this;
}

/** \brief Alta de juego
 *
 * \param ll_juegos LinkedList*
 * \return int 0 si ok, -1 si ll null, -2 error en carga datos, -3 operacion cancelada.
 */
int controller_addJuego(LinkedList* ll_juegos)
{
	Juego* this;
	int rtn=-1;
	int continuar;
	int idAux;
	if(ll_juegos!=NULL)
	{
		this=AltaJuego();
		if(this!=NULL)
		{
			idAux=myIdGenerator("id_juego.csv");
			Juego_setId(this, idAux);
			printJuegoAuxiliar(this);
			utn_getInt(&continuar, "\nDESEA GUARDAR Y DAR EL ALTA?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
			if(continuar==1)
			{
				saveId(idAux,"id_juego.csv");
				ll_add(ll_juegos,this);
				rtn=0;
			}
			else
			{
				free(this);
				rtn=-3; //OPERACION CANCELADA.
			}
		}
		else
		{
			rtn=-2;//ERROR EN CARGA
		}
	}
	else
	{
		rtn=-1; //LL NULA
	}
    return rtn;
}


/** \brief Listar juegos
 *
 * \param ll_juegos LinkedList*
 * \return int 0 si ok, -1 ll null, -2 ll vacia.
 *
 */
int controller_ListJuegos(LinkedList* ll_juegos)
{
	Juego* this;
	int rtn=-1;
	int i;
	int len_ll=ll_len(ll_juegos);
	if(ll_juegos!=NULL)
	{
		if(len_ll>0)
		{
			printf("\n+---------------LISTADO DE JUEGOS-----------------+");
			printf("\nID  |NOMBRE         |EMPRESA         |GENERO       |\n");
			printf("----+---------------+----------------+-------------+");
			for(i=0;i<len_ll;i++)
			{
				this=ll_get(ll_juegos, i);
				printJuego(this);
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



/** \brief Guarda los datos de los salones en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param ll_salon LinkedList*
 * \return int
 *
 */
int controller_saveAsTextSalon(char* path , LinkedList* ll_salon)
{
	Salon* this;
	int rtn=-1;
	int i;
	int idAux;
	char idAuxChar[100];
	char nombreAux[100];
	char direccionAux[100];
	int tipoSalonAux;
	char tipoSalonChar[100];
	int contadorCargas=1;
	int len_ll=ll_len(ll_salon);

	//FALTA RETORNO.
	FILE *pFile=NULL;
	pFile=fopen(path,"w+");
	if(pFile!=NULL)
	{
		if(ll_salon!=NULL)
		{
			if(len_ll>0)
			{
				//VALIDAR SI CON R ES DISTINTO DE NULL
				for(i=0;i<len_ll;i++)
				{
					this=ll_get(ll_salon, i);
					if(this != NULL)
					{
						if(Salon_getId(this,&idAux)==0 && Salon_getNombre(this, nombreAux)==0 && Salon_getDireccion(this, direccionAux)==0
							&& Salon_getTipoSalon(this, &tipoSalonAux)==0)
						{

							sprintf(idAuxChar,"%d",idAux);
							sprintf(tipoSalonChar,"%d",tipoSalonAux);

							fprintf(pFile,"%d,%s,%s,%d\n",idAux,nombreAux,direccionAux,tipoSalonAux);
							rtn=contadorCargas++;
						}
						else
						{
							rtn=-4; //dato no leido
						}
					}
				}
			}
			else
			{
				rtn=-3; //LL VACIA
			}
		}
		else
		{
			rtn=-2; //LL NULO
		}
	}
	else
	{
		rtn=-1; //PFILE NULO
	}
	fclose(pFile);
	return rtn;
}

/** \brief Guarda los datos de los juegos en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param ll_juego LinkedList*
 * \return int
 *
 */
int controller_saveAsTextJuego(char* path , LinkedList* ll_juego)
{
	Juego* this;
	int rtn=-1;
	int i;
	int idAux;
	char idAuxChar[100];
	char nombreAux[100];
	char empresaAux[100];
	int tipoJuegoAux;
	char tipoJuegoChar[100];
	int contadorCargas=1;
	int len_ll=ll_len(ll_juego);

	//FALTA RETORNO.
	FILE *pFile=NULL;
	pFile=fopen(path,"w+");
	if(pFile!=NULL)
	{
		if(ll_juego!=NULL)
		{
			if(len_ll>0)
			{
				//VALIDAR SI CON R ES DISTINTO DE NULL
				for(i=0;i<len_ll;i++)
				{
					this=ll_get(ll_juego, i);
					if(this != NULL)
					{
						if(Juego_getId(this,&idAux)==0 && Juego_getNombre(this, nombreAux)==0 && Juego_getEmpresa(this, empresaAux)==0
							&& Juego_getTipoJuego(this, &tipoJuegoAux)==0)
						{

							sprintf(idAuxChar,"%d",idAux);
							sprintf(tipoJuegoChar,"%d",tipoJuegoAux);

							fprintf(pFile,"%d,%s,%s,%d\n",idAux,nombreAux,empresaAux,tipoJuegoAux);
							rtn=contadorCargas++;
						}
						else
						{
							rtn=-4; //dato no leido
						}
					}
				}
			}
			else
			{
				rtn=-3; //LL VACIA
			}
		}
		else
		{
			rtn=-2; //LL NULO
		}
	}
	else
	{
		rtn=-1; //PFILE NULO
	}
	fclose(pFile);
	return rtn;
}

/** \brief Guarda los datos de los arcade en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param ll_arcade LinkedList*
 * \return int
 *
 */
int controller_saveAsTextArcade(char* path , LinkedList* ll_arcade)
{
	Arcade* this;
	int rtn=-1;
	int i;
	int idAux;
	char idAuxChar[100];
	char nacionalidadAux[100];
	int tipoSonidoAux;
	char tipoSonidoChar[100];
	int cantJugadoresAux;
	char cantJugadoresChar[100];
	int maxFichasAux;
	char maxFichasChar[100];
	int FK_idSalonAux;
	char FK_idSalonChar[100];
	int FK_idJuegoAux;
	char FK_idJuegoChar[100];
	int contadorCargas=1;
	int len_ll=ll_len(ll_arcade);

	//FALTA RETORNO.
	FILE *pFile=NULL;
	pFile=fopen(path,"w+");
	if(pFile!=NULL)
	{
		if(ll_arcade!=NULL)
		{
			if(len_ll>0)
			{
				//VALIDAR SI CON R ES DISTINTO DE NULL
				for(i=0;i<len_ll;i++)
				{
					this=ll_get(ll_arcade, i);
					if(this != NULL)
					{
						if(Arcade_getId(this,&idAux)==0 && Arcade_getNacionalidad(this, nacionalidadAux)==0 &&  Arcade_getTipoSonido(this, &tipoSonidoAux)==0
								&& Arcade_getCantidadJugadores(this, &cantJugadoresAux)==0 && Arcade_getMaximoFichas(this, &maxFichasAux)==0 &&
								Arcade_getIdSalon(this, &FK_idSalonAux)==0 && Arcade_getIdJuego(this, &FK_idJuegoAux)==0)
						{

							sprintf(idAuxChar,"%d",idAux);
							sprintf(tipoSonidoChar,"%d",tipoSonidoAux);
							sprintf(cantJugadoresChar,"%d",cantJugadoresAux);
							sprintf(maxFichasChar,"%d",maxFichasAux);
							sprintf(FK_idSalonChar,"%d",FK_idSalonAux);
							sprintf(FK_idJuegoChar,"%d",FK_idJuegoAux);

							fprintf(pFile,"%d,%s,%d,%d,%d,%d,%d\n",idAux,nacionalidadAux,tipoSonidoAux,cantJugadoresAux,maxFichasAux,
									FK_idSalonAux,FK_idJuegoAux);
							rtn=contadorCargas++;
						}
						else
						{
							rtn=-4; //dato no leido
						}
					}
				}
			}
			else
			{
				rtn=-3; //LL VACIA
			}
		}
		else
		{
			rtn=-2; //LL NULO
		}
	}
	else
	{
		rtn=-1; //PFILE NULO
	}
	fclose(pFile);
	return rtn;
}


