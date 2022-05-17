#include "Tracking.h"


long int time_Current(void)
{
	return time(NULL);
}

long int time_Add(double secondsAdd)
{
	return secondsAdd + time_Current();
}

void eTracking_imprimirUno(Tracking arrayTrackings)
{
	char auxiliarEstado[15];
	switch(arrayTrackings.isEmpty)
	{
	case -1:
		strncpy(auxiliarEstado,"CANCELADO",15);
		break;
	case 1:
		strncpy(auxiliarEstado,"ENTREGADO",15);
		break;
	case 2:
		strncpy(auxiliarEstado,"EN VIAJE",15);
		break;
	default:
		puts("\nERROR, opcion invalida");
	break;
	}
	printf("ID   |ESTADO    |CANTIDAD ADQUIRIDA|DISTANCIA EN KM|\n");
	printf("-----+----------+------------------+---------------+");
	printf("\n%-5d|%-10s|%-19d|%-15d|",arrayTrackings.idTracking,auxiliarEstado,arrayTrackings.cantidad,arrayTrackings.distanciaKm);
}

void eTracking_imprimirUnoAuxiliar(Tracking arrayTrackings)
{
	char auxiliarEstado[15];
	switch(arrayTrackings.isEmpty)
	{
	case -1:
		strncpy(auxiliarEstado,"CANCELADO",15);
		break;
	case 1:
		strncpy(auxiliarEstado,"ENTREGADO",15);
		break;
	case 2:
		strncpy(auxiliarEstado,"EN VIAJE",15);
		break;
	default:
		puts("\nERROR, opcion invalida");
	break;
	}
	printf("ID   |ESTADO    |CANTIDAD ADQUIRIDA|DISTANCIA EN KM|\n");
	printf("-----+----------+------------------+---------------+");
	printf("\n%-5d|%-10s|%-19d|%-15d|",arrayTrackings.idTracking,auxiliarEstado,arrayTrackings.cantidad,arrayTrackings.distanciaKm);
}

int eTracking_ImprimirAdmin(Tracking arrayTrackings[], int tam)
{
	int rtn = 0;
	int i;
	char auxiliarEstado[15];
	int contadorTrakings=0;

	if (arrayTrackings != NULL)
	{
		if (tam > 0)
		{
			for(i=0;i<tam;i++)
			{
				if (arrayTrackings[i].isEmpty>=0 || arrayTrackings[i].isEmpty==CANCELADO)
				{
					contadorTrakings++;
				}
			}
			if(contadorTrakings>0)
			{
				printf("ID   |ESTADO    |ID COMPRADOR|ID VENDEDOR|\n");
				printf("-----+----------+------------+-----------+");
				for (i = 0; i < tam; i++)
				{
					if (arrayTrackings[i].isEmpty>=0 || arrayTrackings[i].isEmpty==CANCELADO)
					{
						switch(arrayTrackings[i].isEmpty)
						{
						case -1:
							strncpy(auxiliarEstado,"CANCELADO",15);
							break;
						case 1:
							strncpy(auxiliarEstado,"ENTREGADO",15);
							break;
						case 2:
							strncpy(auxiliarEstado,"EN VIAJE",15);
							break;
						default:
							puts("\nERROR, opcion invalida");
						break;
						}
						printf("\n%-5d|%-10s|%-12d|%-12d|",arrayTrackings[i].idTracking,auxiliarEstado,arrayTrackings[i].FK_idComprador,arrayTrackings[i].FK_idVendedor);
						contadorTrakings++;
					}

				}
				rtn=0;
			}
			else
			{
				rtn=-3; //NO HAY TRACKINGS A LISTAR
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
int eTracking_Inicializar(Tracking arrayTrackings[], int tam)
{
	int rtn = -1;
	int i;

	if(arrayTrackings != NULL && tam>0)
	{
		for (i = 0; i < tam; i++)
		{
			arrayTrackings[i].isEmpty=LIBRE;
			rtn = 0;
		}
	}

	return rtn;
}

int eTracking_BuscarEspacioLibre(Tracking arrayTrackings[], int tam)
{
	int rtn = -1;
	int i;

	if(arrayTrackings != NULL && tam>0)
	{
		for (i = 0; i<tam ; i++)
		{
			if(arrayTrackings[i].isEmpty==LIBRE)
			{
			rtn = i;
			break;
			}
		}
	}

	return rtn;
}


int eTrackingPedirId(Tracking* arrayTrackings, int tam, int* auxiliarId)
{
	int rtn = 0;

	if (arrayTrackings != NULL)
	{
		if (tam > 0)
		{
			utn_getInt(auxiliarId, "\nIngrese el ID a buscar:", "ERROR", 1000, 1199, 5);
			rtn= 0;
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

int eTrackingBuscarIndicePorId(Tracking arrayTrackings[], int tam, int id)
{
	int rtn = 0;
	int i;
	int flag=0;

	if (arrayTrackings != NULL)
	{
		if (tam > 0)
		{
			for (i = 0; i < tam; i++)
			{
				if (arrayTrackings[i].isEmpty == OCUPADO)
				{
					if(arrayTrackings[i].idTracking == id)
					{
					rtn = i;
					flag=1;
					break;
					}
				}
			}
			if(flag==0)
			{
				rtn=-3; //NO EXISTE EL ID INDICADO O NO ESTA OCUPADO
			}
		}
		else
		{
			rtn = -2; //TAM MAL DEFINIDO
		}
	}
	else
	{
		rtn = -1; //ARRAY NULO
	}

	return rtn;
}



int eTrackingCalcularEnvio(Tracking* arrayTrackings, int tam,int codigoPostal, int* segundos)
{
	int rtn = 0;
	int distanciaKm;
	if (arrayTrackings != NULL)
	{
		if (tam > 0)
		{
			if(codigoPostal>1 && codigoPostal<=3000)
			{
				distanciaKm=20;
				*segundos=40;
			}
			else
			{
				if(codigoPostal>=1001 && codigoPostal<=3000)
				{
					distanciaKm=30;
					*segundos=60;
				}
				else
				{

					if(codigoPostal>=3001 && codigoPostal<=5000)
					{
						distanciaKm=50;
						*segundos=100;
					}
					else
					{
						if(codigoPostal>=5001 && codigoPostal<=8000)
						{
							distanciaKm=80;
							*segundos=160;
						}
						else
						{
							if(codigoPostal>=8001 && codigoPostal<=9999)
							{
								distanciaKm=150;
								*segundos=300;
							}
						}
					}
				}
			}//FIN CODIGO POSTAL
			rtn=distanciaKm;
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

int eTrackingCalcularHoraLlegada(Tracking* arrayTrackings, int tam, int segundos,long int* horaLlegada)
{
	int rtn = 0;

	if (arrayTrackings != NULL)
	{
		if (tam > 0)
		{
			*horaLlegada=time_Add(segundos);
			rtn= 0;
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

int eTrackingCalcularEstadoEnvio(Tracking* arrayTrackings, int tam, long int horaLlegada,int* estado)
{
	int rtn = 0;
	if (arrayTrackings != NULL)
	{
		if (tam > 0)
		{
			if(horaLlegada<=time_Current())
			{
				*estado=ENTREGADO;
			}
			else
			{
				if(horaLlegada>time_Current())
				{
					*estado=EN_VIAJE;
				}
			}
			rtn= 0;
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

int eTrackingActualizarEstadoEnvio(Tracking* arrayTrackings, int tam)
{
	int rtn = 0;
	int i=0;
	if (arrayTrackings != NULL)
	{
		if (tam > 0)
		{
			for(i=0;i<tam;i++)
			{
				if(arrayTrackings[i].isEmpty!=ENTREGADO && arrayTrackings[i].isEmpty!=CANCELADO)
				{
					if(arrayTrackings[i].horaLlegada<=time_Current())
					{
						rtn=ENTREGADO;
					}
					else
					{
						if(arrayTrackings[i].horaLlegada>time_Current())
						{
							rtn=EN_VIAJE;
						}
					}
				}
				else
				{
					rtn=-3;//NO SE ENCONTRARON PARA ACTUALIZAR
				}
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


