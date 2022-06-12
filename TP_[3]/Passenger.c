/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "utn_get.h"
#define CLASE_EJECUTIVA 1
#define CLASE_PRIMERA 2
#define CLASE_ECONOMICA 3
#define ESTADO_ATERRIZADO 1
#define ESTADO_ENHORARIO 2
#define ESTADO_ENVUELO 3
#define ESTADO_DEMORADO 4
static int Passenger_esString(char* nombre, int tam);
static int Passenger_esCodigoVuelo(char* codigo, int tam);
//static int Passenger_esNumerica(int numero);
//static int Passenger_esNumeroDecimal(float numero);
int printPassengerAuxiliar(Passenger* this)
{
	int rtn =-1;
	int idAux;
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	int tipoPasajeroAux;
	char codigoVueloAux[8];
	int estadoVueloAux;
	char tipoVuelo[20];
	char estadoVuelo[30];
	if(this != NULL)
	{
		if(Passenger_getId(this,&idAux)==0 && Passenger_getNombre(this, nombreAux)==0 && Passenger_getApellido(this, apellidoAux)==0
										&& Passenger_getPrecio(this, &precioAux)==0  && Passenger_getTipoPasajero(this, &tipoPasajeroAux)==0 && Passenger_getCodigoVuelo(this, codigoVueloAux) == 0
										&& Passenger_getEstadoVuelo(this, &estadoVueloAux)==0)
		{
			switch(tipoPasajeroAux)
			{
				case 1:
					strncpy(tipoVuelo,"CLASE EJECUTIVA",sizeof(tipoVuelo));
				break;
				case 2:
					strncpy(tipoVuelo,"PRIMERA CLASE",sizeof(tipoVuelo));
				break;
				case 3:
					strncpy(tipoVuelo,"CLASE ECONOMICA",sizeof(tipoVuelo));
				break;
				default:
					puts("ERROR");
				break;
				}
				switch(estadoVueloAux)
				{
				case ESTADO_ATERRIZADO:
					strncpy(estadoVuelo,"Aterrizado",30);
				break;
				case ESTADO_ENHORARIO:
					strncpy(estadoVuelo,"En Horario",30);
				break;
				case ESTADO_ENVUELO:
					strncpy(estadoVuelo,"En Vuelo",30);
				break;
				case ESTADO_DEMORADO:
					strncpy(estadoVuelo,"Demorado",30);
				break;
				default:
					puts("ERROR");
				break;
				}
				printf("ID  |NOMBRE    |APELLIDO  |PRECIO   |TIPO DE PASAJERO|CODIGO DE VUELO|ESTADO VUELO   |\n");
				printf("----+----------+----------+---------+----------------+---------------+---------------+");
				printf("\n%-4d|%-10s|%-10s|$%-8.f|%-16s|%-15s|%-15s|",idAux, nombreAux, apellidoAux, precioAux, tipoVuelo, codigoVueloAux,estadoVuelo);

				rtn=0;
		}
	}

	return rtn;
}

int printPassengers(Passenger* this)
{
	int rtn =-1;
	int idAux;
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	int tipoPasajeroAux;
	char codigoVueloAux[8];
	int estadoVueloAux;
	char tipoVuelo[20];
	char estadoVuelo[30];
	if(this != NULL)
	{
		if(Passenger_getId(this,&idAux)==0 && Passenger_getNombre(this, nombreAux)==0 && Passenger_getApellido(this, apellidoAux)==0
										&& Passenger_getPrecio(this, &precioAux)==0  && Passenger_getTipoPasajero(this, &tipoPasajeroAux)==0 && Passenger_getCodigoVuelo(this, codigoVueloAux) == 0
										&& Passenger_getEstadoVuelo(this, &estadoVueloAux)==0)
		{
			switch(tipoPasajeroAux)
			{
				case 1:
					strncpy(tipoVuelo,"CLASE EJECUTIVA",sizeof(tipoVuelo));
				break;
				case 2:
					strncpy(tipoVuelo,"PRIMERA CLASE",sizeof(tipoVuelo));
				break;
				case 3:
					strncpy(tipoVuelo,"CLASE ECONOMICA",sizeof(tipoVuelo));
				break;
				default:
					puts("");
				break;
				}
				switch(estadoVueloAux)
				{
				case ESTADO_ATERRIZADO:
					strncpy(estadoVuelo,"Aterrizado",30);
				break;
				case ESTADO_ENHORARIO:
					strncpy(estadoVuelo,"En Horario",30);
				break;
				case ESTADO_ENVUELO:
					strncpy(estadoVuelo,"En Vuelo",30);
				break;
				case ESTADO_DEMORADO:
					strncpy(estadoVuelo,"Demorado",30);
				break;
				default:
					puts("");
				break;
				}
				printf("\n%-4d|%-10s|%-10s|$%-8.f|%-16s|%-15s|%-15s|\n",idAux, nombreAux, apellidoAux, precioAux, tipoVuelo, codigoVueloAux,estadoVuelo);

				rtn=0;
		}
	}

	return rtn;
}

Passenger* Passenger_new()
{
	Passenger* auxiliarP=NULL;
	auxiliarP=(Passenger*)malloc(sizeof(Passenger));
	return auxiliarP; //OJO
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr, int* errores)
{
	Passenger* this=NULL;
	this=Passenger_new();
	int auxiliarTipoPasajero;
	int auxiliarEstadoVuelo;
	int rtnauxiliarTipoPasajero;
	int rtnauxiliarEstadoVuelo;
	errores=0;
	if(this != NULL)
	{

		if(idStr>0 && Passenger_esString(nombreStr, 50)==0 && Passenger_esString(apellidoStr, 50)==0 && precioStr>0 &&
				Passenger_esString(tipoPasajeroStr, 50)==0 && Passenger_esString(estadoVueloStr, 50)==0 && Passenger_esCodigoVuelo(codigoVueloStr,9)==0)
			{
			//INICIO CODIFICACION
				if(strncmp(tipoPasajeroStr,"ExecutiveClass",17)==0)
				{
					auxiliarTipoPasajero=CLASE_EJECUTIVA;
				}
				else
				{
					if(strncmp(tipoPasajeroStr,"FirstClass",11)==0)
					{
						auxiliarTipoPasajero=CLASE_PRIMERA;
					}
					else
					{
						if(strncmp(tipoPasajeroStr,"EconomyClass",13)==0)
						{
							auxiliarTipoPasajero=CLASE_ECONOMICA;
						}
						else
						{
							rtnauxiliarTipoPasajero=-1;
						}
					}
				}
				if(strncmp(estadoVueloStr,"Aterrizado",11)==0)
				{
					auxiliarEstadoVuelo=ESTADO_ATERRIZADO;
				}
				else
				{
					if(strncmp(estadoVueloStr,"En Horario",11)==0)
					{
						auxiliarEstadoVuelo=ESTADO_ENHORARIO;
					}
					else
					{
						if(strncmp(estadoVueloStr,"En Vuelo",9)==0)
						{
							auxiliarEstadoVuelo=ESTADO_ENVUELO;
						}
						else
						{
							if(strncmp(estadoVueloStr,"Demorado",9)==0)
							{
								auxiliarEstadoVuelo=ESTADO_DEMORADO;
							}
							else
							{
								rtnauxiliarEstadoVuelo=-1;
							}
						}
					}
				}//FIN CODIFICACION
				if(Passenger_setId(this, atoi(idStr))==0 && Passenger_setNombre(this, nombreStr) ==0 &&
								Passenger_setApellido(this, apellidoStr) == 0 && Passenger_setPrecio(this, atof(precioStr)) == 0 &&
						Passenger_setCodigoVuelo(this, codigoVueloStr) ==0 && rtnauxiliarTipoPasajero != -1 && rtnauxiliarEstadoVuelo != -1)
				{
					Passenger_setTipoPasajero(this, auxiliarTipoPasajero);
					Passenger_setEstadoVuelo(this, auxiliarEstadoVuelo);
				}
				else
				{
					//mostrar error en el pasajero que se cargo.
					//printf("error %s-%s-%s-%s-%s-%s-%s\n", idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVueloStr);
					free(this);
					this=NULL;
					errores++;
				}
			}
	}

	return this;
}


Passenger* AltaPasajero()
{
	Passenger* this=NULL;
	this=Passenger_new();
	puts("ALTA DE PASAJERO");
	if(utn_getString(this->nombre, "Ingrese su nombre por favor.", "Error al ingresar el nombre", sizeof(this->nombre), 5)==0 &&
			utn_getString(this->apellido, "Ingrese su apellido por favor.", "Error al ingresar el apellido", sizeof(this->apellido), 5)==0 &&
			utn_getFloatNuevo(&this->precio, "Ingrese el precio del vuelo por favor", "Error al ingresar el precio",1, 5000000, 5)==0 &&
			utn_getInt(&this->tipoPasajero, "Ingrese el tipo de pasajero\n1.CLASE EJECUTIVA.\n2.PRIMERA CLASE\n3.CLASE ECONOMICA", "Error al ingresar tipo de pasajero",1, 3, 5)==0)
	{
		cambiarMinusPrimerChar(this->nombre, 50);
		cambiarMinusPrimerChar(this->apellido, 50);
	}
	else
	{
		puts("paso null");
		this=NULL;
	}
	return this;
}

Passenger* ModificarPasajero(Passenger* auxiliarPasajero, int opcionMod)
{
	switch (opcionMod)
	{
	case 1:
		utn_getString(auxiliarPasajero->nombre, "Ingrese su nombre por favor.", "Error al ingresar el nombre",
				sizeof(auxiliarPasajero->nombre), 5);
		break;
	case 2:
		utn_getString(auxiliarPasajero->apellido, "Ingrese su apellido por favor.", "Error al ingresar el apellido",
				sizeof(auxiliarPasajero->apellido), 5);
		break;
	case 3:
		utn_getFloatNuevo(&auxiliarPasajero->precio, "Ingrese el precio del vuelo por favor", "Error al ingresar el precio",
				0, 5000000, 5);
		break;
	case 4:
		utn_getInt(&auxiliarPasajero->tipoPasajero, "Ingrese el tipo de pasajero\n1.PRIMERA CLASE.\n2.CLASE EJECUTIVA\n3.CLASE ECONOMICA"
				, "Error al ingresar tipo de pasajero",
				1, 3, 5);
	break;
		default:
			puts("ERROR");
			break;
	}
	return auxiliarPasajero;
}

void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

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
int Passenger_setId(Passenger* this,int id)
{
	int rtn=-1;
	if(this !=NULL && id>=0)
	{
		this->id=id;
		rtn=0;
	}
	return rtn;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int rtn=-1;
	if(this !=NULL && nombre!=NULL)
	{
		strncpy(this->nombre,nombre,50);
		rtn=0;
	}
	return rtn;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int rtn=-1;
	if(this !=NULL && apellido!=NULL)
	{
		strncpy(this->apellido,apellido,50);
		rtn=0;
	}
	return rtn;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rtn=-1;
	if(this !=NULL && codigoVuelo!=NULL)
	{
		strncpy(this->codigoVuelo,codigoVuelo,8);
		rtn=0;
	}
	return rtn;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int rtn=-1;
	if(this !=NULL && (tipoPasajero>0 && tipoPasajero<4))
	{
		this->tipoPasajero=tipoPasajero;
		rtn=0;
	}
	return rtn;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int rtn=-1;
	if(this !=NULL && precio>=0)
	{
		this->precio=precio;
		rtn=0;
	}
	return rtn;
}

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo)
{
	int rtn=-1;
	if(this !=NULL && (estadoVuelo>0 && estadoVuelo<5))
	{
		this->estadoVuelo=estadoVuelo;
		rtn=0;
	}
	return rtn;
}


//GETTERS
int Passenger_getId(Passenger* this,int* id)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*id=this->id;
		rtn=0;
	}
	return rtn;
}

int Passenger_getNombre(Passenger* this,char* nombre)//ok
{
	int rtn=-1;
	if(this !=NULL && nombre!=NULL)
	{
		strncpy(nombre,this->nombre,50);
		rtn=0;
	}
	return rtn;
}

int Passenger_getApellido(Passenger* this,char* apellido)//ok
{
	int rtn=-1;
	if(this !=NULL && apellido!=NULL)
	{
		strncpy(apellido,this->apellido,50);
		rtn=0;
	}
	return rtn;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)//ok
{
	int rtn=-1;
	if(this !=NULL && codigoVuelo!=NULL)
	{
		strncpy(codigoVuelo,this->codigoVuelo,8);
		rtn=0;
	}
	return rtn;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*tipoPasajero=this->tipoPasajero;
		rtn=0;
	}
	return rtn;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int rtn=-1;
	if(this !=NULL && precio>=0)
	{
		*precio=this->precio;
		rtn=0;
	}
	return rtn;
}

int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*estadoVuelo=this->estadoVuelo;
		rtn=0;
	}
	return rtn;
}

int Passenger_criterioNombre(void* pasajero1, void* pasajero2)
{
	Passenger* pasajeroA;
	pasajeroA=pasajero1;
	Passenger* pasajeroB;
	pasajeroB=pasajero2;
	int rtn;
	if(pasajeroA != NULL && pasajeroB != NULL)
	{
		if(strncmp(pasajeroA->nombre,pasajeroB->nombre,50)>0)
		{
			puts("Cargando...");
			rtn=1;
		}
		else
		{
			if(strncmp(pasajeroA->nombre,pasajeroB->nombre,50)<0)
			{
				rtn=0;
			}
		}
	}
	return rtn;
}


//FUNCIONES ESTATICAS DE VALIDACION
static int Passenger_esString(char* nombre, int tam)
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

static int Passenger_esCodigoVuelo(char* codigo, int tam)
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












