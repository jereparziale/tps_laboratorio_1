#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arcade.h"
#include "utn_get.h"
#define AUDIOMONO 1
#define AUDIOESTEREO 2
#define TAMSALON 50
static int Arcade_esString(char* nacionalidad, int tam);


/// @fn int printArcadeAuxiliar(Arcade*)
/// @brief Imprime un arcade en consola con encabezado.
///
/// @pre
/// @post
/// @param this
/// @return rtn 0 ok, rtn -1 si this es NULL
int printArcadeAuxiliar(Arcade* this)
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
	if(this != NULL)
	{
		if(Arcade_getId(this, &idAux)==0 && Arcade_getNacionalidad(this, nacionalidadAux)==0 && Arcade_getTipoSonido(this, &tipoSonidoAux)==0 &&
				Arcade_getCantidadJugadores(this, &cantJugadoresAux)==0 && Arcade_getMaximoFichas(this, &maxFichasAux)==0 &&
				Arcade_getIdSalon(this, &FK_idSalonAux)==0 && Arcade_getIdJuego(this, &FK_idJuegoAux)==0)//GET
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


				printf("\nID  |NACIONALIDAD   |SONIDO  |JUGAD.|MAX FICHAS|ID SALON|ID JUEGO|\n");
				printf("----+---------------+--------+------+----------+--------+--------+");
				printf("\n%-4d|%-15s|%-8s|%-6d|%-10d|%-8d|%-8d|",idAux,nacionalidadAux,tipoSonido,cantJugadoresAux,
						maxFichasAux,FK_idSalonAux,FK_idJuegoAux);
				rtn=0;
		}
		else
		{
		}
	}
	return rtn;
}

/// @fn int printArcades(Arcade*)
/// @brief Imprime un arcade en consola sin encabezado para usar en bucle.
///
/// @pre
/// @post
/// @param this
/// @return rtn 0 ok, rtn -1 si this es NULL
int printArcade(Arcade* this)
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
	if(this != NULL)
	{
		if(Arcade_getId(this, &idAux)==0 && Arcade_getNacionalidad(this, nacionalidadAux)==0 && Arcade_getTipoSonido(this, &tipoSonidoAux)==0 &&
				Arcade_getCantidadJugadores(this, &cantJugadoresAux)==0 && Arcade_getMaximoFichas(this, &maxFichasAux)==0 &&
				Arcade_getIdSalon(this, &FK_idSalonAux)==0 && Arcade_getIdJuego(this, &FK_idJuegoAux)==0)//GET
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
				printf("\n%-4d|%-15s|%-8s|%-6d|%-10d|%-8d|%-8d|",idAux,nacionalidadAux,tipoSonido,cantJugadoresAux,
						maxFichasAux,FK_idSalonAux,FK_idJuegoAux);
				rtn=0;
		}
	}
	return rtn;
}


/// @fn Arcade Arcade_new*()
/// @brief Asigna memoria dinamica con malloc para un nuevo this.
///
/// @pre
/// @post
/// @return
Arcade* Arcade_new()
{
	Arcade* auxiliarP=NULL;
	auxiliarP=(Arcade*)malloc(sizeof(Arcade));
	return auxiliarP; //OJO
}

Arcade* Arcade_newParametros(char* idStr,char* nacionalidadStr,char* tipoSonido,char* cantJugadores,
		char* maxFichas,char* FK_idSalon, char* FK_idJuego, int* errores)
{
	Arcade* this=NULL;
	this=Arcade_new();
	errores=0;

	if(this != NULL)
	{

		if(atoi(idStr)>0 && Arcade_esString(nacionalidadStr, 50)==0 && (atoi(tipoSonido)==1 || atoi(tipoSonido)==2) &&
				(atoi(cantJugadores)>0 && atoi(cantJugadores)<9) && (atoi(maxFichas)>0 && atoi(maxFichas)<101))
			{
				if(Arcade_setId(this, atoi(idStr))==0 && Arcade_setNacionalidad(this, nacionalidadStr)==0 && Arcade_setTipoSonido(this, atoi(tipoSonido))==0 &&
						Arcade_setCantidadJugadores(this, atoi(cantJugadores))==0 && Arcade_setMaximoFichas(this, atoi(maxFichas))==0 && Arcade_setIdSalon(this, atoi(FK_idSalon))==0
						&& Arcade_setIdJuego(this, atoi(FK_idJuego))==0)

				{
				}
				else
				{
					//mostrar error en el arcade que se cargo.
					//printf("error %s-%s-%s-%s-%s-%s-%s\n", idStr,nacionalidadStr,direccionStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVueloStr);
					free(this);
					this=NULL;
					errores++;
					puts("\n no paso new");

				}
			}
	}
	return this;
}


/// @fn Arcade AltaArcade*()
/// @brief Alta de un arcade con pedido de los datos necesarios.
///
/// @pre
/// @post
/// @return retorna el puntero al arcade, si hay un error en algun dato NULL.
Arcade* AltaArcade()
{
	Arcade* this=NULL;
	this=Arcade_new();
	puts("ALTA ARCADE");
	if(utn_getString(this->nacionalidad, "Ingrese el nacionalidad del arcade.", "\nERROR,reintente", 50, 5)==0 &&
			utn_getInt(&this->tipoSonido, "Ingrese tipoSonido del arcade.\n1.MONO\n2.ESTEREO", "\nERROR,reintente", 1, 2, 5)==0 &&
			utn_getInt(&this->cantJugadores, "Ingrese la cantidad de jugadores.", "ERROR, reintente", 1, 8, 5)==0 &&
			utn_getInt(&this->maxFichas, "Ingrese la cantidad maxima de fichas.", "ERROR, reintente", 1, 100, 5)==0)
	{
		cambiarMinusPrimerChar(this->nacionalidad, 50);
	}
	else
	{
		puts("paso null");
		this=NULL;
	}
	return this;
}



/// @fn void Arcade_delete(Arcade*)
/// @brief Free a un puntero a arcade.
///
/// @pre
/// @post
/// @param this
void Arcade_delete(Arcade* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}



//SETTERS
/// @fn int Arcade_setId(Arcade*, int)
/// @brief Setea el id a un arcade.
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return rtn 0 si ok
int Arcade_setId(Arcade* this,int id)
{
	int rtn=-1;
	if(this !=NULL && id>=0)
	{
		this->id_arcade=id;
		rtn=0;
	}
	return rtn;
}

/// @fn int Arcade_setNacionalidad(Arcade*, char*)
/// @brief Setea el nacionalidad a un arcade.
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return rtn 0 si ok
int Arcade_setNacionalidad(Arcade* this,char* nacionalidad)
{
	int rtn=-1;
	if(this !=NULL && nacionalidad!=NULL)
	{
		strncpy(this->nacionalidad,nacionalidad,50);
		rtn=0;
	}
	return rtn;
}


/// @fn int Arcade_setTipoSonido(Arcade*, int)
/// @brief Setea el tipo de sonido a un arcade.
///
/// @pre
/// @post
/// @param this
/// @param tipoSonido
/// @return 0 si ok
int Arcade_setTipoSonido(Arcade* this,int tipoSonido)
{
	int rtn=-1;
	if(this !=NULL && (tipoSonido>0 && tipoSonido <= 2))
	{
		this->tipoSonido=tipoSonido;
		rtn=0;
	}
	return rtn;
}

/// @brief Setea la cantidad de jugadores a un arcade.
///
/// @pre
/// @post
/// @param this
/// @param tipoSonido
/// @return 0 si ok
int Arcade_setCantidadJugadores(Arcade* this,int cantJugadores)
{
	int rtn=-1;
	if(this !=NULL && (cantJugadores>0 && cantJugadores <= 8))
	{
		this->cantJugadores=cantJugadores;
		rtn=0;
	}
	return rtn;
}

/// @brief Setea el maximo de fichas a un arcade.
///
/// @pre
/// @post
/// @param this
/// @param tipoSonido
/// @return 0 si ok
int Arcade_setMaximoFichas(Arcade* this,int maxFichas)
{
	int rtn=-1;
	if(this !=NULL && (maxFichas>0 && maxFichas <= 100))
	{
		this->maxFichas=maxFichas;
		rtn=0;
	}
	return rtn;
}

/// @brief Setea el id de la FK del salon relacionado a un arcade.
///
/// @pre
/// @post
/// @param this
/// @param tipoSonido
/// @return 0 si ok
int Arcade_setIdSalon(Arcade* this,int FK_idSalon)
{
	int rtn=-1;
	if(this !=NULL && (FK_idSalon>0))
	{
		this->FK_idSalon=FK_idSalon;
		rtn=0;
	}
	return rtn;
}

/// @brief Setea el id de la FK del juego relacionado a un arcade.
///
/// @pre
/// @post
/// @param this
/// @param tipoSonido
/// @return 0 si ok
int Arcade_setIdJuego(Arcade* this,int FK_idJuego)
{
	int rtn=-1;
	if(this !=NULL && (FK_idJuego>0))
	{
		this->FK_idJuego=FK_idJuego;
		rtn=0;
	}
	return rtn;
}

//GETTERS
/// @fn int Arcade_getId(Arcade*, int*)
/// @brief Toma el id de un arcade y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return 0 si ok.
int Arcade_getId(Arcade* this,int* id)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*id=this->id_arcade;
		rtn=0;
	}
	return rtn;
}

/// @fn int Arcade_getNacionalidad(Arcade*, char*)
/// @brief Toma la nacionalidad de un arcade y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param nacionalidad
/// @return 0 si ok
int Arcade_getNacionalidad(Arcade* this,char* nacionalidad)//ok
{
	int rtn=-1;
	if(this !=NULL && nacionalidad!=NULL)
	{
		strncpy(nacionalidad,this->nacionalidad,50);
		rtn=0;
	}
	return rtn;
}

/// @fn int Arcade_getTipoSonido(Arcade*, int*)
/// @brief Toma el tipo de sonido de un arcade y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param tipoSonido
/// @return
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*tipoSonido=this->tipoSonido;
		rtn=0;
	}
	return rtn;
}

/// @brief Toma la cantidad de jugadores de un arcade y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param cantJugadores
/// @return 0 si ok
int Arcade_getCantidadJugadores(Arcade* this,int* cantJugadores)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*cantJugadores=this->cantJugadores;
		rtn=0;
	}
	return rtn;
}

/// @brief Toma el maximo de ficahs de un arcade y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param maxFichas
/// @return 0 si ok
int Arcade_getMaximoFichas(Arcade* this,int* maxFichas)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*maxFichas=this->maxFichas;
		rtn=0;
	}
	return rtn;
}

/// @brief Toma el id de la FK del salon relacionado de un arcade y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param FK_idSalon
/// @return 0 si ok
int Arcade_getIdSalon(Arcade* this,int* FK_idSalon)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*FK_idSalon=this->FK_idSalon;
		rtn=0;
	}
	return rtn;
}

/// @brief Toma el id de la FK del juego relacionado de un arcade y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param FK_idJuego
/// @return 0 si ok
int Arcade_getIdJuego(Arcade* this,int* FK_idJuego)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*FK_idJuego=this->FK_idJuego;
		rtn=0;
	}
	return rtn;
}

/// @brief Recibe como parametro dos punteros a void que luego se asignan a un arcade y si el nacionalidad es mayor rtn = 1.
///
/// @pre
/// @post
/// @param arcade1
/// @param arcade2
/// @return
int Arcade_criterioNacionalidad(void* arcade1, void* arcade2)
{
	Arcade* arcadeA;
	arcadeA=arcade1;
	Arcade* arcadeB;
	arcadeB=arcade2;
	int rtn;
	if(arcadeA != NULL && arcadeB != NULL)
	{
		if(strncmp(arcadeA->nacionalidad,arcadeB->nacionalidad,50)>0)
		{
			rtn=1;
		}
		else
		{
			if(strncmp(arcadeA->nacionalidad,arcadeB->nacionalidad,50)<0)
			{
				rtn=-1;
			}
		}
	}
	return rtn;
}

//FUNCIONES ESTATICAS DE VALIDACION
/// @fn int Arcade_esString(char*, int)
/// @brief Funcion que valida que un string sea solo de letras.
///
/// @pre
/// @post
/// @param nacionalidad
/// @param tam
/// @return 0 si ok.
static int Arcade_esString(char* nacionalidad, int tam)
{
	int rtn=-1;
	if(nacionalidad!=NULL && tam>0)
	{
		for(int i=0;i<tam && nacionalidad[i] != '\0';i++)
		{
			if((nacionalidad[i] < 'A' || nacionalidad[i] > 'Z') || (nacionalidad[i] < 'a' || nacionalidad[i] > 'z'))
			{
				rtn=0;
				break;
			}
		}
	}
	return rtn;
}










