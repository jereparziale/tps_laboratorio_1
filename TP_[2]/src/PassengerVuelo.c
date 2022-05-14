#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "Flight.h"
#include "utn_get.h"

static int myId=999;

static int myIdGeneratorGeneral()
{
	myId++;
	return myId;
}

void cargaForzadaDatos(Passenger* list_Passenger, Flight* list_flight)
{

	//PRIMER CARGA
	strcpy(list_flight[0].flycode,"AZF121");
	list_flight[0].statusFlight=VUELO_ACTIVO;
	list_flight[0].isEmpty=OCUPADO;



	//SEGUNDA CARGA
	strcpy(list_flight[1].flycode,"AAF123");
	list_flight[1].statusFlight=VUELO_ACTIVO;
	list_flight[1].isEmpty=OCUPADO;



	//TERCER CARGA
	strcpy(list_flight[2].flycode,"AFF124");
	list_flight[2].statusFlight=VUELO_EN_ESPERA;
	list_flight[2].isEmpty=OCUPADO;


	//PRIMER CARGA
	list_Passenger[0].id=myIdGeneratorGeneral();
	strcpy(list_Passenger[0].name,"JEREMIAS");
	strcpy(list_Passenger[0].lastName,"PARZIALE");
	list_Passenger[0].price=1000;
	strcpy(list_Passenger[0].flycode,"AZF121");
	list_Passenger[0].typePassenger=1;
	list_Passenger[0].isEmpty=OCUPADO;

	//SEGUNDA CARGA
	list_Passenger[1].id=myIdGeneratorGeneral();
	strcpy(list_Passenger[1].name,"ORIANA");
	strcpy(list_Passenger[1].lastName,"GODOY");
	list_Passenger[1].price=10000;
	strcpy(list_Passenger[1].flycode,"AAF123");
	list_Passenger[1].typePassenger=1;
	list_Passenger[1].isEmpty=OCUPADO;

	//TERCER CARGA
	list_Passenger[2].id=myIdGeneratorGeneral();
	strcpy(list_Passenger[2].name,"MARTIN");
	strcpy(list_Passenger[2].lastName,"ROCCA");
	list_Passenger[2].price=20000;
	strcpy(list_Passenger[2].flycode,"AAF123");
	list_Passenger[2].typePassenger=3;
	list_Passenger[2].isEmpty=OCUPADO;

	//CUARTA CARGA
	list_Passenger[3].id=myIdGeneratorGeneral();
	strcpy(list_Passenger[3].name,"MAIA");
	strcpy(list_Passenger[3].lastName,"RODRIGUEZ");
	list_Passenger[3].price=300000;
	strcpy(list_Passenger[3].flycode,"AFF124");
	list_Passenger[3].typePassenger=1;
	list_Passenger[3].isEmpty=OCUPADO;

	//QUINTA CARGA
	list_Passenger[4].id=myIdGeneratorGeneral();
	strcpy(list_Passenger[4].name,"MICA");
	strcpy(list_Passenger[4].lastName,"RODRIGUEZ");
	list_Passenger[4].price=120000;
	strcpy(list_Passenger[4].flycode,"AFF124");
	list_Passenger[4].typePassenger=2;
	list_Passenger[4].isEmpty=OCUPADO;

	//SEXTO CARGA
	list_Passenger[5].id=myIdGeneratorGeneral();
	strcpy(list_Passenger[5].name,"JAVIER");
	strcpy(list_Passenger[5].lastName,"PEREZ");
	list_Passenger[5].price=180000;
	strcpy(list_Passenger[5].flycode,"AZF121");
	list_Passenger[5].typePassenger=3;
	list_Passenger[5].isEmpty=OCUPADO;
}

int rel_PassengerVuelo_EstadoVuelo(Passenger* list_Passenger,int len_Passenger, Flight* list_Flight, int len_Flight)
{
	int rtn=-10;
	int i;
	int indiceFlycode;
	char flycodeAuxiliar[10];
	if(list_Passenger != NULL)
	{
		if(list_Flight != NULL)
		{
			if(len_Passenger >0 && len_Flight>0)
			{
				for(i=0;i<len_Passenger;i++)
				{
					if(list_Passenger[i].isEmpty==OCUPADO)
					{
						strncpy(flycodeAuxiliar,list_Passenger[i].flycode,sizeof(flycodeAuxiliar));
						indiceFlycode=eFlightBuscarIndicePorCodigo(list_Flight,len_Flight,flycodeAuxiliar);
						if(indiceFlycode>-1)
						{
							list_Passenger[i].statusFlight=list_Flight[indiceFlycode].statusFlight;
							rtn=0;
						}
					}

				}
			}
			else
			{
				rtn=-3; //TAM MAL DEFINIDO
			}
		}
		else
		{
			rtn=-2;//ARRAY CONTRA NULO
		}
	}
	else
	{
		rtn=-1; //ARRAY NULO
	}

return rtn;
}

int rel_PassengerVuelo_ModificarCodigoVuelo(Passenger* list_Passenger,int len_Passenger, int id, Flight* list_Flight, int len_Flight)
{
	int rtn = -1;
	int indiceModificacion;
	int continuar;
	int rtnModificacion;
	Passenger auxiliarPasajero;
	if(list_Passenger != NULL)
	{
		if(len_Passenger >0)
		{
			indiceModificacion=findPassengerById(list_Passenger, len_Passenger, id);
			if(indiceModificacion>=0)
			{
				auxiliarPasajero=list_Passenger[indiceModificacion];
				utn_getInt(&continuar, "Desea cambiar el vuelo por uno existente o generar un nuevo vuelo"
																				"\nEN USO (1)  --- NUEVO VUELO (0)", "ERROR, opcion no valida.", 0, 1, 5);
				switch(continuar)
				{
				case 0:
					rtnModificacion=eFlight_Alta(list_Flight, len_Flight);
					break;
				case 1:
					eFlight_imprimirTodosEstado(list_Flight, len_Flight, OCUPADO);
					do
					{
						utn_getString(auxiliarPasajero.flycode, "Ingrese el codigo de vuelo a utilizar", "ERROR, codigo de vuelo inexistente", 10, 5);
						rtnModificacion=eFlightBuscarIndicePorCodigo(list_Flight, len_Flight, auxiliarPasajero.flycode);
					}while(rtnModificacion<0);
				}
				printPassengerAuxiliar(&auxiliarPasajero);
				utn_getInt(&continuar, "\nDESEA GUARDAR LOS CAMBIOS EFECTUADOS?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
				if(continuar==1)
				{
					list_Passenger[indiceModificacion]=auxiliarPasajero;
					rtn=indiceModificacion;
				}
				else
				{
					rtn=-4; //OPERACION CANCELADA.
				}
			}
			else
			{
				rtn=-1; //ID NO ENCONTRADO O NO DADO DE ALTA!
			}
		}
		else
		{
			rtn=-2; //TAM MAL DEFINIDO
		}
	}
	else
	{
		rtn=-3; //ARRAY NULO
	}

	return rtn;
}







