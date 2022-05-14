#include "Flight.h"


int eFlight_CantidadOcupados(Flight list[], int len)
{
	int cantidadOcupados=0;
	int i;
	int rtn;
	if(list != NULL)
	{
		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty==OCUPADO)
				{
					cantidadOcupados++;
				}
			}
			rtn=cantidadOcupados;
		}
		else
		{
			rtn=-2; //LEN MAL DEFINIDO
		}
	}
	else
	{
		rtn=-1; //ARRAY NULO
	}

	return rtn;
}


void eFlight_imprimirUno(Flight list)
{
	char estadoVuelo[30];
	switch(list.statusFlight)
	{
	case VUELO_EN_ESPERA:
		strncpy(estadoVuelo,"En espera de confirmacion",sizeof(estadoVuelo));
	break;
	case VUELO_ACTIVO:
		strncpy(estadoVuelo,"Vuelo activo",sizeof(estadoVuelo));
	break;
	default:
		puts("ERROR");
	break;
	}
	printf("|CODIGO DE VUELO|ESTADO VUELO             |\n");
	printf("+---------------+-------------------------+\n");
	printf("|%-15s|%-25s|\n",list.flycode, estadoVuelo);
}

void eFlight_imprimirUnoEncabezado(Flight list)
{
	char estadoVuelo[30];
	switch(list.statusFlight)
	{
	case VUELO_EN_ESPERA:
		strncpy(estadoVuelo,"En espera de confirmacion",sizeof(estadoVuelo));
	break;
	case VUELO_ACTIVO:
		strncpy(estadoVuelo,"Vuelo activo",sizeof(estadoVuelo));
	break;
	default:
		puts("ERROR");
	break;
	}
	printf("|%-15s|%-25s|\n",list.flycode, estadoVuelo);
}

int eFlight_imprimirTodosEstado(Flight list[], int tam, int estado)
{
	int rtn = 0;
	int i;
	if (list != NULL)
	{
		if (tam > 0)
		{
			printf("|CODIGO DE VUELO|ESTADO VUELO             |\n");
			printf("+---------------+-------------------------+\n");
			for (i = 0; i < tam; i++)
			{
				if (list[i].isEmpty == estado)
				{

					eFlight_imprimirUnoEncabezado(list[i]);
				}

			}
		} else
		{
			rtn = -2;
		}
	} else
	{
		rtn = -1;
	}
	return rtn;
}
int eFlight_Inicializar(Flight list[], int tam)
{
	int rtn = -1;
	int i;

	if(list != NULL && tam>0)
	{
		for (i = 0; i < tam; i++)
		{
			list[i].isEmpty=LIBRE;
			rtn = 0;
		}
	}

	return rtn;
}

int eFlight_BuscarEspacioLibre(Flight list[], int tam)
{
	int rtn = -1;
	int i;

	if(list != NULL && tam>0)
	{
		for (i = 0; i<tam ; i++)
		{
			if(list[i].isEmpty==LIBRE)
			{
			rtn = i;
			break;
			}
		}
	}
	return rtn;
}


int eFlight_Alta(Flight list[], int tam)
{
	int rtn = -1;
	int indiceLibre;
	int continuar;
	Flight auxiliarFlight;
	if(list != NULL)
	{
		if(tam >0)
		{
			indiceLibre=eFlight_BuscarEspacioLibre(list,tam);
			if(indiceLibre>=0)
			{
					auxiliarFlight= eFlight_CargarFlight();
					eFlight_imprimirUno(auxiliarFlight);
					utn_getInt(&continuar, "\nDESEA GUARDAR Y DAR EL ALTA DEL VUELO?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
					if(continuar==1)
					{
						auxiliarFlight.isEmpty = OCUPADO;
						list[indiceLibre]=auxiliarFlight;
						rtn= indiceLibre;
					}
					else
					{
						rtn=-4; //OPERACION CANCELADA.
					}
			}
			else
			{
				rtn=-1; //ARRAY LLENO
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

Flight eFlight_CargarFlight()
{
	Flight auxiliarFlight;
	int opcion;
	utn_getString(auxiliarFlight.flycode, "Ingrese el codigo del vuelo", "Error al ingresar codigo del vuelo\n", sizeof(auxiliarFlight.flycode),5);
	cambiarMinusMayus(auxiliarFlight.flycode, sizeof(auxiliarFlight.flycode));
	utn_getInt(&opcion, "Ingrese el estado del vuelo\n1.VUELO ACTIVO.\n2.VUELO EN ESPERA DE CONFIRMACION", "Error el estado del vuelo\n",1, 2, 5);
	switch(opcion)
	{
	case 1:
		auxiliarFlight.statusFlight=opcion;
	break;
	case 2:
		auxiliarFlight.statusFlight=opcion;
	break;
	}
	return auxiliarFlight;

}


int eFlightBuscarIndicePorCodigo(Flight list[], int tam, char flycode[])
{
	int rtn = -1;
	int i;
	int flag=0;

	if (list != NULL)
	{
		if (tam > 0)
		{
			for (i = 0; i < tam; i++)
			{
				if (list[i].isEmpty == OCUPADO)
				{
					cambiarMinusMayus(flycode, 10);
					if(strncmp(list[i].flycode,flycode,sizeof(10))==0)
					{
					rtn = i;
					flag=1;
					break;
					}
				}
			}
			if(flag==0)
			{
				rtn=-1; //NO EXISTE EL ID INDICADO O NO ESTA OCUPADO
			}
		}
		else
		{
			rtn = -2; //TAM MAL DEFINIDO
		}
	}
	else
	{
		rtn = -3; //ARRAY NULO
	}

	return rtn;
}







