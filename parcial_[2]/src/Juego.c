#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Juego.h"
#include "utn_get.h"
#define PLATAFORMA 1
#define LABERINTO 2
#define AVENTURA 3
#define OTRO 4
#define TAMJUEGO 50
static int Juego_esString(char* nombre, int tam);


/// @fn int printJuegoAuxiliar(Juego*)
/// @brief Imprime un juego en consola con encabezado.
///
/// @pre
/// @post
/// @param this
/// @return rtn 0 ok, rtn -1 si this es NULL
int printJuegoAuxiliar(Juego* this)
{
	int rtn =-1;
	int idAux;
	char nombreAux[50];
	char empresaAux[50];
	int generoAux;
	char genero[12];
	if(this != NULL)
	{
		if(Juego_getId(this, &idAux)==0 && Juego_getNombre(this, nombreAux)==0 && Juego_getEmpresa(this, empresaAux)==0 &&
				Juego_getTipoJuego(this, &generoAux)==0)//GET
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
				printf("ID  |NOMBRE         |EMPRESA         |GENERO       |\n");
				printf("----+---------------+----------------+-------------+");
				printf("\n%-4d|%-15s|%-16s|%-13s|",idAux, nombreAux, empresaAux, genero);
				rtn=0;
		}
	}
	return rtn;
}

/// @fn int printJuegos(Juego*)
/// @brief Imprime un juego en consola sin encabezado para usar en bucle.
///
/// @pre
/// @post
/// @param this
/// @return rtn 0 ok, rtn -1 si this es NULL
int printJuego(Juego* this)
{
	int rtn =-1;
	int idAux;
	char nombreAux[50];
	char empresaAux[50];
	int generoAux;
	char genero[12];
	if(this != NULL)
	{
		if(Juego_getId(this, &idAux)==0 && Juego_getNombre(this, nombreAux)==0 && Juego_getEmpresa(this, empresaAux)==0 &&
				Juego_getTipoJuego(this, &generoAux)==0)//GET
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
					puts("ERROR");
				break;
			}
				printf("\n%-4d|%-15s|%-16s|%-13s|",idAux, nombreAux, empresaAux, genero);
				rtn=0;
		}
	}
	return rtn;
}

/// @fn Juego Juego_new*()
/// @brief Asigna memoria dinamica con malloc para un nuevo this.
///
/// @pre
/// @post
/// @return
Juego* Juego_new()
{
	Juego* auxiliarP=NULL;
	auxiliarP=(Juego*)malloc(sizeof(Juego));
	return auxiliarP; //OJO
}


Juego* Juego_newParametros(char* idStr,char* nombreStr,char* empresaStr,char* generoStr, int* errores)
{
	Juego* this=NULL;
	this=Juego_new();
	errores=0;
	if(this != NULL)
	{

		if(atoi(idStr)>0 && Juego_esString(nombreStr, 50)==0 && Juego_esString(empresaStr, 50)==0 &&
				(atoi(generoStr)>0 && atoi(generoStr)<=4))
			{
				if(Juego_setId(this, atoi(idStr))==0 && Juego_setNombre(this, nombreStr) ==0 && Juego_setEmpresa(this, empresaStr) ==0 &&
						Juego_setTipoJuego(this, atoi(generoStr))==0)

				{
				}
				else
				{
					//mostrar error en el juego que se cargo.
					//printf("error %s-%s-%s-%s-%s-%s-%s\n", idStr,nombreStr,empresaStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVueloStr);
					free(this);
					this=NULL;
					errores++;
					puts("\n no paso new");

				}
			}
	}
	return this;
}

/// @fn Juego AltaJuego*()
/// @brief Alta de un juego con pedido de los datos necesarios.
///
/// @pre
/// @post
/// @return retorna el puntero al juego, si hay un error en algun dato NULL.
Juego* AltaJuego()
{
	Juego* this=NULL;
	this=Juego_new();
	puts("ALTA JUEGO");
	if(utn_getString(this->nombre, "Ingrese el nombre del juego", "\nERROR,reintente", TAMJUEGO, 5)==0 &&
			utn_getString(this->empresa, "Ingrese la empresa del juego", "\nERROR,reintente", TAMJUEGO, 5)==0 &&
			utn_getInt(&this->genero, "Ingrese genero del juego\n1.PLATAFORMA\n2.LABERINTO\n3.AVENTURA\n4.OTRO", "\nERROR,reintente", 1, 4, 5)==0)
	{
		cambiarMinusPrimerChar(this->nombre, 50);
		cambiarMinusPrimerChar(this->empresa, 50);
	}
	else
	{
		puts("paso null");
		this=NULL;
	}
	return this;
}


/// @fn void Juego_delete(Juego*)
/// @brief Free a un puntero a juego.
///
/// @pre
/// @post
/// @param this
void Juego_delete(Juego* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}



//SETTERS
/// @fn int Juego_setId(Juego*, int)
/// @brief Setea el id a un juego.
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return rtn 0 si ok
int Juego_setId(Juego* this,int id)
{
	int rtn=-1;
	if(this !=NULL && id>=0)
	{
		this->id_juego=id;
		rtn=0;
	}
	return rtn;
}

/// @fn int Juego_setNombre(Juego*, char*)
/// @brief Setea el nombre a un juego.
///
/// @pre
/// @post
/// @param this
/// @param nombre
/// @return rtn 0 si ok
int Juego_setNombre(Juego* this,char* nombre)
{
	int rtn=-1;
	if(this !=NULL && nombre!=NULL)
	{
		strncpy(this->nombre,nombre,50);
		rtn=0;
	}
	return rtn;
}

/// @brief Setea la empresa a un juego.
///
/// @pre
/// @post
/// @param this
/// @param empresa
/// @return rtn 0 si ok
int Juego_setEmpresa(Juego* this,char* empresa)
{
	int rtn=-1;
	if(this !=NULL && empresa!=NULL)
	{
		strncpy(this->empresa,empresa,50);
		rtn=0;
	}
	return rtn;
}

/// @brief Setea el tipo de juego a un juego.
///
/// @pre
/// @post
/// @param this
/// @param genero
/// @return 0 si ok
int Juego_setTipoJuego(Juego* this,int genero)
{
	int rtn=-1;
	if(this !=NULL && (genero>0 && genero <= 4))
	{
		this->genero=genero;
		rtn=0;
	}
	return rtn;
}


//GETTERS
/// @fn int Juego_getId(Juego*, int*)
/// @brief Toma el id de un juego y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return 0 si ok.
int Juego_getId(Juego* this,int* id)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*id=this->id_juego;
		rtn=0;
	}
	return rtn;
}

/// @fn int Juego_getNombre(Juego*, char*)
/// @brief Toma el nombre de un juego y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param nombre
/// @return 0 si ok
int Juego_getNombre(Juego* this,char* nombre)//ok
{
	int rtn=-1;
	if(this !=NULL && nombre!=NULL)
	{
		strncpy(nombre,this->nombre,50);
		rtn=0;
	}
	return rtn;
}

/// @brief Toma la empresa de un juego y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param empresa
/// @return 0 si ok
int Juego_getEmpresa(Juego* this,char* empresa)//ok
{
	int rtn=-1;
	if(this !=NULL && empresa!=NULL)
	{
		strncpy(empresa,this->empresa,50);
		rtn=0;
	}
	return rtn;
}

/// @fn int Juego_getTipoJuego(Juego*, int*)
/// @brief Toma el tipo de juego de un juego y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param genero
/// @return
int Juego_getTipoJuego(Juego* this,int* genero)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*genero=this->genero;
		rtn=0;
	}
	return rtn;
}



//FUNCIONES ESTATICAS DE VALIDACION
/// @fn int Juego_esString(char*, int)
/// @brief Funcion que valida que un string sea solo de letras.
///
/// @pre
/// @post
/// @param nombre
/// @param tam
/// @return 0 si ok.
static int Juego_esString(char* nombre, int tam)
{
	int rtn=-1;
	if(nombre!=NULL && tam>0)
	{
		for(int i=0;i<tam && nombre[i] != '\0';i++)
		{
			if((nombre[i] < 'A' || nombre[i] > 'Z') || (nombre[i] < 'a' || nombre[i] > 'z'))
			{
				rtn=0;
				break;
			}
		}
	}
	return rtn;
}


/// @brief Recibe como parametro dos punteros a void que luego se asignan a un juego y si el nombre es mayor rtn = 1.
///
/// @pre
/// @post
/// @param juego1
/// @param juego2
/// @return
int Juego_criterioNombre(void* juego1, void* juego2)
{
	Juego* juegoA;
	juegoA=juego1;
	Juego* juegoB;
	juegoB=juego2;
	int rtn;
	if(juegoA != NULL && juegoB != NULL)
	{
		if(strncmp(juegoA->nombre,juegoB->nombre,50)>0)
		{
			puts("Cargando...");
			rtn=1;
		}
		else
		{
			if(strncmp(juegoA->nombre,juegoB->nombre,50)<0)
			{
				rtn=-1;
			}
		}
	}
	return rtn;
}







