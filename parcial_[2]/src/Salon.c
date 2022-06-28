#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salon.h"
#include "utn_get.h"
#define SHOPPING 1
#define LOCAL 2
#define TAMSALON 50
static int Salon_esString(char* nombre, int tam);
static int Salon_esDireccion(char* codigo, int tam);



/// @fn int printSalonAuxiliar(Salon*)
/// @brief Imprime un salon en consola con encabezado.
///
/// @pre
/// @post
/// @param this
/// @return rtn 0 ok, rtn -1 si this es NULL
int printSalonAuxiliar(Salon* this)
{
	int rtn =-1;
	int idAux;
	char nombreAux[50];
	char direccionAux[50];
	int tipoSalonAux;
	char tipoSalon[10];
	if(this != NULL)
	{
		if(Salon_getId(this, &idAux)==0 && Salon_getNombre(this, nombreAux)==0 && Salon_getDireccion(this, direccionAux)==0 &&
				Salon_getTipoSalon(this, &tipoSalonAux)==0)//GET
		{
			switch(tipoSalonAux)
			{
				case SHOPPING:
					strncpy(tipoSalon,"SHOPPING",10);
				break;
				case LOCAL:
					strncpy(tipoSalon,"LOCAL",10);
				break;
				default:
					puts("ERROR");
				break;
			}
				printf("ID  |NOMBRE         |DIRECCION       |TIPO DE SALON|\n");
				printf("----+---------------+----------------+-------------+");
				printf("\n%-4d|%-15s|%-16s|%-13s|",idAux, nombreAux, direccionAux, tipoSalon);
				rtn=0;
		}
	}
	return rtn;
}

/// @fn int printSalons(Salon*)
/// @brief Imprime un salon en consola sin encabezado para usar en bucle.
///
/// @pre
/// @post
/// @param this
/// @return rtn 0 ok, rtn -1 si this es NULL
int printSalon(Salon* this)
{
	int rtn =-1;
	int idAux;
	char nombreAux[50];
	char direccionAux[50];
	int tipoSalonAux;
	char tipoSalon[10];
	if(this != NULL)
	{
		if(Salon_getId(this, &idAux)==0 && Salon_getNombre(this, nombreAux)==0 && Salon_getDireccion(this, direccionAux)==0 &&
				Salon_getTipoSalon(this, &tipoSalonAux)==0)//GET
		{
			switch(tipoSalonAux)
			{
				case SHOPPING:
					strncpy(tipoSalon,"SHOPPING",10);
				break;
				case LOCAL:
					strncpy(tipoSalon,"LOCAL",10);
				break;
				default:
					puts("ERROR");
				break;
			}
				printf("\n%-4d|%-15s|%-16s|%-13s|",idAux, nombreAux, direccionAux, tipoSalon);
				rtn=0;
		}
	}
	return rtn;
}

/// @fn Salon Salon_new*()
/// @brief Asigna memoria dinamica con malloc para un nuevo this.
///
/// @pre
/// @post
/// @return
Salon* Salon_new()
{
	Salon* auxiliarP=NULL;
	auxiliarP=(Salon*)malloc(sizeof(Salon));
	return auxiliarP; //OJO
}

Salon* Salon_newParametros(char* idStr,char* nombreStr,char* direccionStr,char* tipoSalonStr, int* errores)
{
	Salon* this=NULL;
	this=Salon_new();
	errores=0;
	if(this != NULL)
	{

		if(atoi(idStr)>0 && Salon_esString(nombreStr, 50)==0 && Salon_esDireccion(direccionStr, 50)==0 &&
				(atoi(tipoSalonStr)>0 && atoi(tipoSalonStr)<=2))
			{
				if(Salon_setId(this, atoi(idStr))==0 && Salon_setNombre(this, nombreStr) ==0 && Salon_setDireccion(this, direccionStr) ==0 &&
						Salon_setTipoSalon(this, atoi(tipoSalonStr))==0)

				{
				}
				else
				{
					//mostrar error en el salon que se cargo.
					//printf("error %s-%s-%s-%s-%s-%s-%s\n", idStr,nombreStr,direccionStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVueloStr);
					free(this);
					this=NULL;
					errores++;
					puts("\n no paso new");

				}
			}
	}
	return this;
}

/// @fn Salon AltaSalon*()
/// @brief Alta de un salon con pedido de los datos necesarios.
///
/// @pre
/// @post
/// @return retorna el puntero al salon, si hay un error en algun dato NULL.
Salon* AltaSalon()
{
	Salon* this=NULL;
	this=Salon_new();
	puts("ALTA SALON");
	if(utn_getString(this->nombre, "\nIngrese el nombre del salon", "\nERROR,reintente", TAMSALON, 5)==0 &&
			utn_getString(this->direccion, "Ingrese la direccion del salon", "\nERROR,reintente", TAMSALON, 5)==0 &&
			utn_getInt(&this->tipoSalon, "Ingrese el tipo de salon\n1.SHOPPING\n2.LOCAL", "\nERROR,reintente", 1, 2, 5)==0)
	{
		cambiarMinusPrimerChar(this->nombre, 50);
		cambiarMinusPrimerChar(this->direccion, 50);
	}
	else
	{
		puts("paso null");
		this=NULL;
	}
	return this;
}

/// @fn Salon ModificarSalon*(Salon*, int)
/// @brief Recibe un puntero a salon y una opcion de un parametro amodificar.
///
/// @pre
/// @post
/// @param auxiliarSalon
/// @param opcionMod
/// @return el puntero al salon, si un dato es erroneo NULL y free al puntero.
Salon* ModificarSalon(Salon* auxiliarSalon, int opcionMod)
{
	switch (opcionMod)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
	break;
	default:
		puts("ERROR");
	break;
	}
	return auxiliarSalon;
}

/// @fn void Salon_delete(Salon*)
/// @brief Free a un puntero a salon.
///
/// @pre
/// @post
/// @param this
void Salon_delete(Salon* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

/// @fn int requestId(int*)
/// @brief Pide al usuario un id y lo retorna por referencia.
///
/// @pre
/// @post
/// @param auxiliarId
/// @return o ai ok.
int requestId(int* auxiliarId)
{
	int rtn = -1;

	if(utn_getInt(auxiliarId, "\nIngrese el ID a buscar:", "ERROR", 1, 10000, 5)==0)
	{
	rtn= 0;
	}

	return rtn;
}


//SETTERS
/// @fn int Salon_setId(Salon*, int)
/// @brief Setea el id a un salon.
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return rtn 0 si ok
int Salon_setId(Salon* this,int id)
{
	int rtn=-1;
	if(this !=NULL && id>=0)
	{
		this->idSalon=id;
		rtn=0;
	}
	return rtn;
}

/// @fn int Salon_setNombre(Salon*, char*)
/// @brief Setea el nombre a un salon.
///
/// @pre
/// @post
/// @param this
/// @param nombre
/// @return rtn 0 si ok
int Salon_setNombre(Salon* this,char* nombre)
{
	int rtn=-1;
	if(this !=NULL && nombre!=NULL)
	{
		strncpy(this->nombre,nombre,50);
		rtn=0;
	}
	return rtn;
}

/// @brief Setea la direccion a un salon.
///
/// @pre
/// @post
/// @param this
/// @param direccion
/// @return rtn 0 si ok
int Salon_setDireccion(Salon* this,char* direccion)
{
	int rtn=-1;
	if(this !=NULL && direccion!=NULL)
	{
		strncpy(this->direccion,direccion,50);
		rtn=0;
	}
	return rtn;
}

/// @fn int Salon_setTipoSalon(Salon*, int)
/// @brief Setea el tipo de salon a un salon.
///
/// @pre
/// @post
/// @param this
/// @param tipoSalon
/// @return 0 si ok
int Salon_setTipoSalon(Salon* this,int tipoSalon)
{
	int rtn=-1;
	if(this !=NULL && (tipoSalon>0 && tipoSalon <= 2))
	{
		this->tipoSalon=tipoSalon;
		rtn=0;
	}
	return rtn;
}


//GETTERS
/// @fn int Salon_getId(Salon*, int*)
/// @brief Toma el id de un salon y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return 0 si ok.
int Salon_getId(Salon* this,int* id)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*id=this->idSalon;
		rtn=0;
	}
	return rtn;
}

/// @fn int Salon_getNombre(Salon*, char*)
/// @brief Toma el nombre de un salon y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param nombre
/// @return 0 si ok
int Salon_getNombre(Salon* this,char* nombre)//ok
{
	int rtn=-1;
	if(this !=NULL && nombre!=NULL)
	{
		strncpy(nombre,this->nombre,50);
		rtn=0;
	}
	return rtn;
}

/// @brief Toma la direccion de un salon y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param direccion
/// @return 0 si ok
int Salon_getDireccion(Salon* this,char* direccion)//ok
{
	int rtn=-1;
	if(this !=NULL && direccion!=NULL)
	{
		strncpy(direccion,this->direccion,50);
		rtn=0;
	}
	return rtn;
}

/// @fn int Salon_getTipoSalon(Salon*, int*)
/// @brief Toma el tipo de salon de un salon y lo devuelve.
///
/// @pre
/// @post
/// @param this
/// @param tipoSalon
/// @return
int Salon_getTipoSalon(Salon* this,int* tipoSalon)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*tipoSalon=this->tipoSalon;
		rtn=0;
	}
	return rtn;
}

//OJO ORDENADOR PUNTERO
/// @fn int Salon_criterioNombre(void*, void*)
/// @brief Recibe como parametro dos punteros a void que luego se asignan a un salon y si el nombre es mayor rtn = 1.
///
/// @pre
/// @post
/// @param salon1
/// @param salon2
/// @return
int Salon_criterioNombre(void* salon1, void* salon2)
{
	Salon* salonA;
	salonA=salon1;
	Salon* salonB;
	salonB=salon2;
	int rtn;
	if(salonA != NULL && salonB != NULL)
	{
		if(strncmp(salonA->nombre,salonB->nombre,50)>0)
		{
			puts("Cargando...");
			rtn=1;
		}
		else
		{
			if(strncmp(salonA->nombre,salonB->nombre,50)<0)
			{
				rtn=0;
			}
		}
	}
	return rtn;
}

//FUNCIONES ESTATICAS DE VALIDACION
/// @fn int Salon_esString(char*, int)
/// @brief Funcion que valida que un string sea solo de letras.
///
/// @pre
/// @post
/// @param nombre
/// @param tam
/// @return 0 si ok.
static int Salon_esString(char* nombre, int tam)
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

/// @fn int Salon_esCodigoVuelo(char*, int)
/// @brief   Funcion que valida que un string sea solo de letras y numeros..
///
/// @pre
/// @post
/// @param codigo
/// @param tam
/// @return 0 si ok
static int Salon_esDireccion(char* codigo, int tam)
{
	int rtn=-1;
	if(codigo!=NULL && tam>0)
	{
		for(int i=0;i<tam && codigo[i] != '\0';i++)
		{
			if((codigo[i] < 'A' || codigo[i] > 'Z') || (codigo[i] < 'a' || codigo[i] > 'z') || (codigo[i] < 48 || codigo[i] > 57))
			{
				rtn=0;
				break;
			}
		}
	}
	return rtn;
}












