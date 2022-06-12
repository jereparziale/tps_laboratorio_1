#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_get.h"
#include "Flight.h"
#define CLASE_EJECUTIVA 1
#define CLASE_PRIMERA 2
#define CLASE_ECONOMICA 3
#define ESTADO_ATERRIZADO 1
#define ESTADO_ENHORARIO 2
#define ESTADO_ENVUELO 3
#define ESTADO_DEMORADO 4
#define LIBRE -1
#define OCUPADO 0
static int Flight_esCodigoVuelo(char* codigo, int tam);
static int Passenger_esString(char* nombre, int tam);



void eFlight_imprimirUno(Flight* this)
{
	int estadoVueloAux;
	char codigoVueloAux[8];
	char estadoVuelo[30];
	if(Flight_getCodigoVuelo(this, codigoVueloAux)==0 && Flight_getEstadoVuelo(this, &estadoVueloAux)==0)
	{
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
		printf("|%-15s|%-25s|\n",codigoVueloAux, estadoVuelo);
	}
}
void eFlight_imprimirUnoEncabezado(Flight* this)
{
	int estadoVueloAux;
	char codigoVueloAux[8];
	char estadoVuelo[30];
	if(Flight_getCodigoVuelo(this, codigoVueloAux)==0 && Flight_getEstadoVuelo(this, &estadoVueloAux)==0)
	{
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
		printf("|CODIGO DE VUELO|ESTADO VUELO             |\n");
		printf("+---------------+-------------------------+\n");
		printf("|%-15s|%-25s|\n",codigoVueloAux, estadoVuelo);
	}
}

Flight* eFlight_new()
{
	Flight* auxiliarP=NULL;
	auxiliarP=(Flight*)malloc(sizeof(Flight));
	return auxiliarP; //OJO
}

Flight* eFlight_newParametros(char* codigoVueloStr, char* estadoVueloStr)
{
	Flight* this=NULL;
	this=eFlight_new();
	int auxiliarEstadoVuelo;
	int rtnauxiliarEstadoVuelo;
	if(this != NULL)
	{
		if(Flight_esCodigoVuelo(codigoVueloStr,10)==0 && Passenger_esString(estadoVueloStr,50)==0)
		{
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
			if(Flight_setCodigoVuelo(this, codigoVueloStr)==0 && rtnauxiliarEstadoVuelo!=-1)
			{
				Flight_setEstadoVuelo(this, auxiliarEstadoVuelo);
			}
			else
			{
				//mostrar error en el vuelo que se cargo.
				free(this);
				this=NULL;

			}
		}
		else
		{
			puts("error");
			//mostrar error en el vuelo que se cargo.
			free(this);
			this=NULL;

		}
	}
	return this;
}


int Flight_setCodigoVuelo(Flight* this,char* codigoVuelo)
{
	int rtn=-1;
	if(this !=NULL && codigoVuelo!=NULL)
	{
		strncpy(this->codigoVuelo,codigoVuelo,8);
		rtn=0;
	}
	return rtn;
}

int Flight_setEstadoVuelo(Flight* this,int estadoVuelo)
{
	int rtn=-1;
	if(this !=NULL && (estadoVuelo>0 && estadoVuelo<5))
	{
		this->estadoVuelo=estadoVuelo;
		rtn=0;
	}
	return rtn;
}

int Flight_getCodigoVuelo(Flight* this,char* codigoVuelo)//ok
{
	int rtn=-1;
	if(this !=NULL && codigoVuelo!=NULL)
	{
		strncpy(codigoVuelo,this->codigoVuelo,8);
		rtn=0;
	}
	return rtn;
}

int Flight_getEstadoVuelo(Flight* this,int* estadoVuelo)
{
	int rtn=-1;
	if(this !=NULL)
	{
		*estadoVuelo=this->estadoVuelo;
		rtn=0;
	}
	return rtn;
}


static int Flight_esCodigoVuelo(char* codigo, int tam)
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

