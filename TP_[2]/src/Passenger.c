#include "Passenger.h"


static int myId=999;

static int myIdGenerator()
{
	myId++;
	return myId;
}

int ePassenger_CantidadOcupados(Passenger list[], int len)
{
	int cantidadOcupados=0;
	int i;
	int rtn=-1;
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
		rtn=-3; //ARRAY NULO
	}

	return rtn;
}


int printPassengers(Passenger* list, int lenght)
{
	int i;
	int rtn =0;
	char tipoVuelo[20];
	char estadoVuelo[20];
	Passenger auxiliarPasajero;
	if(list != NULL)
	{
		if(lenght>0)
		{
			printf("ID  |NOMBRE    |APELLIDO  |PRECIO   |TIPO DE PASAJERO|CODIGO DE VUELO|ESTADO VUELO\n");
			printf("----+----------+----------+---------+----------------+---------------+------------");
			for (i = 0;i < lenght;i++)
			{
				if(list[i].isEmpty==OCUPADO)
				{
					auxiliarPasajero=list[i];
					switch(auxiliarPasajero.typePassenger)
					{
					case 1:
						strncpy(tipoVuelo,"PRIMERA CLASE",sizeof(tipoVuelo));
					break;
					case 2:
						strncpy(tipoVuelo,"CLASE EJECUTIVA",sizeof(tipoVuelo));
					break;
					case 3:
						strncpy(tipoVuelo,"CLASE ECONOMICA",sizeof(tipoVuelo));
					break;
					default:
						puts("ERROR");
					break;
					}
					switch(auxiliarPasajero.statusFlight)
					{
					case 1:
						strncpy(estadoVuelo,"VUELO ACTIVO",sizeof(estadoVuelo));
					break;
					case 2:
						strncpy(estadoVuelo,"VUELO EN ESPERA",sizeof(estadoVuelo));
					break;
					default:
						puts("ERROR");
					break;
					}
					printf("\n%-4d|%-10s|%-10s|$%-8.f|%-16s|%-15s|%-16s",list[i].id, list[i].name, list[i].lastName, list[i].price, tipoVuelo, list[i].flycode, estadoVuelo);
				}
				else
				{
					rtn=-1; //NO HAY PASAJEROS DADOS DE ALTA
				}
			}
		}
		else
		{
			rtn=-2;//LENGHT MAL DEFINIDO
		}
	}
	else
	{
		rtn=-3; //ARRAY NULO
	}

	return rtn;
}

int printPassengerAuxiliar(Passenger* list)
{
	int rtn =-1;
	char tipoVuelo[20];
	if(list != NULL)
	{
		switch(list->typePassenger)
		{
		case 1:
			strncpy(tipoVuelo,"PRIMERA CLASE",sizeof(tipoVuelo));
		break;
		case 2:
			strncpy(tipoVuelo,"CLASE EJECUTIVA",sizeof(tipoVuelo));
		break;
		case 3:
			strncpy(tipoVuelo,"CLASE ECONOMICA",sizeof(tipoVuelo));
		break;
		default:
			puts("ERROR");
		break;
		}
		printf("ID  |NOMBRE    |APELLIDO  |PRECIO   |TIPO DE PASAJERO|CODIGO DE VUELO|\n");
		printf("----+----------+----------+---------+----------------+---------------+------------");
		printf("\n%-4d|%-10s|%-10s|$%-8.f|%-16s|%-15s|\n",list->id, list->name, list->lastName, list->price, tipoVuelo, list->flycode);

		rtn=0;
	}

	return rtn;
}


int printPassengerIndice(Passenger* list, int i)
{
	int rtn=0;
	char tipoVuelo[20];
	char estadoVuelo[20];
	Passenger auxiliarPasajero;


	if(list != NULL)
	{
		if(i>=0)
		{
			auxiliarPasajero=list[i];
			switch(auxiliarPasajero.typePassenger)
			{
			case 1:
				strncpy(tipoVuelo,"PRIMERA CLASE",sizeof(tipoVuelo));
				break;
			case 2:
				strncpy(tipoVuelo,"CLASE EJECUTIVA",sizeof(tipoVuelo));
				break;
			case 3:
				strncpy(tipoVuelo,"CLASE ECONOMICA",sizeof(tipoVuelo));
				break;
			default:
				puts("ERROR");
				break;
			}
			switch(auxiliarPasajero.statusFlight)
			{
			case 1:
				strncpy(estadoVuelo,"VUELO ACTIVO",sizeof(estadoVuelo));
				break;
			case 2:
				strncpy(estadoVuelo,"VUELO EN ESPERA",sizeof(estadoVuelo));
				break;
			default:
				puts("ERROR");
				break;
			}
			printf("ID  |NOMBRE    |APELLIDO  |PRECIO   |TIPO DE PASAJERO|CODIGO DE VUELO|ESTADO VUELO\n");
			printf("----+----------+----------+---------+----------------+---------------+------------");
			printf("\n%-4d|%-10s|%-10s|$%-8.f|%-16s|%-15s|%-16s",list[i].id, list[i].name, list[i].lastName, list[i].price, tipoVuelo, list[i].flycode, estadoVuelo);

		}
		else
		{
			rtn=-1; //INDICE INCORRECTO
		}
	}
	else
	{
		rtn=-2; //ARRAY NULO
	}

	return rtn;
}



int initPassengers(Passenger* list, int len)
{
	int rtn = -1;
	int i;

	if(list != NULL && len>0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty=LIBRE;
			rtn = 0;
		}
	}

	return rtn;
}

int buscarEmpty(Passenger* list, int tam)
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


Passenger AltaPasajero()
{
	Passenger auxiliarPasajero;
	int auxiliarTipo;
	puts("ALTA DE PASAJERO");
	if(utn_getString(auxiliarPasajero.name, "Ingrese su nombre por favor.", "Error al ingresar el nombre", sizeof(auxiliarPasajero.name), 5)==0 &&
			utn_getString(auxiliarPasajero.lastName, "Ingrese su apellido por favor.", "Error al ingresar el apellido", sizeof(auxiliarPasajero), 5)==0 &&
			utn_getFloatNuevo(&auxiliarPasajero.price, "Ingrese el precio del vuelo por favor", "Error al ingresar el precio",1, 5000000, 5)==0 &&
			utn_getInt(&auxiliarTipo, "Ingrese el tipo de pasajero\n1.PRIMERA CLASE.\n2.CLASE EJECUTIVA\n3.CLASE ECONOMICA", "Error al ingresar tipo de pasajero",1, 3, 5)==0)
	switch(auxiliarTipo)
	{
	case 1:
		auxiliarPasajero.typePassenger=auxiliarTipo;
	break;
	case 2:
		auxiliarPasajero.typePassenger=auxiliarTipo;
	break;
	case 3:
		auxiliarPasajero.typePassenger=auxiliarTipo;
	break;
	}
	return auxiliarPasajero;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,
		int typePassenger, char flycode[])
{
	int rtn = -1;
	int indiceLibre;
	int continuar;
	Passenger auxiliarPasajero;
	if(list != NULL)
	{
		if(len >0)
		{
			indiceLibre=buscarEmpty(list, len);
			if(indiceLibre>=0)
			{
				auxiliarPasajero.id=id;
				strncpy(auxiliarPasajero.name,name, sizeof(auxiliarPasajero.name));
				strncpy(auxiliarPasajero.lastName,lastName, sizeof(auxiliarPasajero.lastName));
				auxiliarPasajero.price=price;
				auxiliarPasajero.typePassenger=typePassenger;
				strncpy(auxiliarPasajero.flycode,flycode, sizeof(auxiliarPasajero.flycode));
				auxiliarPasajero.id=myIdGenerator();
				printPassengerAuxiliar(&auxiliarPasajero);
				utn_getInt(&continuar, "\nDESEA GUARDAR Y DAR EL ALTA?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
				if(continuar==1)
				{
					auxiliarPasajero.isEmpty = OCUPADO;
					list[indiceLibre]=auxiliarPasajero;
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

return rtn;
}

int requestId(Passenger* list, int tam, int* auxiliarId)
{
	int rtn = 0;

	if (list != NULL)
	{
		if (tam > 0)
		{
			printPassengers(list, tam);
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

int findPassengerById(Passenger* list, int len, int id)
	{
	int rtn = 0;
	int i;
	int flag=0;

	if (list != NULL)
	{
		if (len > 0)
		{
			for (i = 0; i < len; i++)
			{
				if (list[i].isEmpty == OCUPADO)
				{
					if(list[i].id == id)
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



int removePassenger(Passenger* list, int len,int id)
{
	int rtn = -1;
	int indiceBaja;
	int continuar;
	if(list != NULL)
	{
		if(len >0)
		{
			indiceBaja=findPassengerById(list, len, id);
			if(indiceBaja>=0)
			{
				printPassengerAuxiliar(&list[indiceBaja]);
				utn_getInt(&continuar, "\nDESEA DAR DE BAJA EL ID INGRESADO?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
				if(continuar==1)
				{
					list[indiceBaja].isEmpty=BAJA;
					rtn=indiceBaja;
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

Passenger ModificarPasajero(Passenger auxiliarPasajero, int opcionMod)
{
	int auxiliarTipo;

	switch (opcionMod)
	{
	case 1:
		utn_getString(auxiliarPasajero.name, "Ingrese su nombre por favor.", "Error al ingresar el nombre",
				sizeof(auxiliarPasajero.name), 5);
		break;
	case 2:
		utn_getString(auxiliarPasajero.lastName, "Ingrese su apellido por favor.", "Error al ingresar el apellido",
				sizeof(auxiliarPasajero), 5);
		break;
	case 3:
		utn_getFloatNuevo(&auxiliarPasajero.price, "Ingrese el precio del vuelo por favor", "Error al ingresar el precio",
				0, 5000000, 5);
		break;
	case 4:
		utn_getInt(&auxiliarTipo, "Ingrese el tipo de pasajero\n1.PRIMERA CLASE.\n2.CLASE EJECUTIVA\n3.CLASE ECONOMICA"
				, "Error al ingresar tipo de pasajero",
				1, 3, 5);
		switch(auxiliarTipo)
		{
		case 1:
			auxiliarPasajero.typePassenger=auxiliarTipo;
			break;
		case 2:
			auxiliarPasajero.typePassenger=auxiliarTipo;
			break;
		case 3:
			auxiliarPasajero.typePassenger=auxiliarTipo;
			break;
		}
			break;
		default:
			puts("ERROR");
			break;
	}
	return auxiliarPasajero;
}



int modifyPassenger(Passenger* list, int len, int id, int opcionMod)
{
	int rtn = -1;
	int indiceModificacion;
	int continuar;
	Passenger auxiliarPasajero;
	if(list != NULL)
	{
		if(len >0)
		{
			indiceModificacion=findPassengerById(list, len, id);
			if(indiceModificacion>=0)
			{
				auxiliarPasajero=list[indiceModificacion];
				auxiliarPasajero=ModificarPasajero(auxiliarPasajero,opcionMod);
				printPassengerAuxiliar(&auxiliarPasajero);
				utn_getInt(&continuar, "\nDESEA GUARDAR LOS CAMBIOS EFECTUADOS?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
				if(continuar==1)
				{
					list[indiceModificacion]=auxiliarPasajero;
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


int sortPassengers(Passenger* list, int len, int order)
{
	int rtn=-1;
	int flagSwap;
	int i;
	int nuevoTam;
	Passenger auxiliarPasajero[len];
	Passenger bufferAux;

	if(list != NULL)
	{
		if(len >0)
		{
			initPassengers(auxiliarPasajero, len);

			for (i = 0; i < len; i++)
			{
				if(list[i].isEmpty==OCUPADO)
				{
				auxiliarPasajero[i]=list[i];
				}
			}
			switch(order)
			{
			case 0:
				do
				{
					flagSwap=0;
					nuevoTam= len-1;
					for (i = 0; i < nuevoTam; i++) //hago tam-1 para que no intercambie con una varibale que no existe
					{
						if(auxiliarPasajero[i].isEmpty==OCUPADO && auxiliarPasajero[i+1].isEmpty==OCUPADO)
						{
							if (strncmp(auxiliarPasajero[i].lastName,auxiliarPasajero[i+1].lastName,59)>0)
							{
								flagSwap=1;
								bufferAux=auxiliarPasajero[i];
								auxiliarPasajero[i]=auxiliarPasajero[i+1];
								auxiliarPasajero[i+1]=bufferAux;
							}
						}
					}
					len--;
					rtn=0;
				}while(flagSwap);
				do
				{
					flagSwap=0;
					nuevoTam= len-1;
					for (i = 0; i < nuevoTam; i++) //hago tam-1 para que no intercambie con una varibale que no existe
					{
						if(auxiliarPasajero[i].isEmpty==OCUPADO && auxiliarPasajero[i+1].isEmpty==OCUPADO &&
								(strncmp(auxiliarPasajero[i].lastName,auxiliarPasajero[i+1].lastName,59)==0))
						{
							if (auxiliarPasajero[i].typePassenger<auxiliarPasajero[i+1].typePassenger)
							{
								flagSwap=1;
								bufferAux=auxiliarPasajero[i];
								auxiliarPasajero[i]=auxiliarPasajero[i+1];
								auxiliarPasajero[i+1]=bufferAux;
							}
						}
					}
					len--;
					rtn=0;
				}while(flagSwap);
				puts("PASAJEROS ORDENADOS POR APELLIDO Y TIPO");
				printPassengers(auxiliarPasajero, len);
			break;

			case 1:
			do
			{
				flagSwap=0;
				nuevoTam= len-1;
				for (i = 0; i < nuevoTam; i++) //hago tam-1 para que no intercambie con una varibale que no existe
				{
					if(auxiliarPasajero[i].isEmpty==OCUPADO && auxiliarPasajero[i+1].isEmpty==OCUPADO)
					{
						if (strncmp(auxiliarPasajero[i].lastName,auxiliarPasajero[i+1].lastName,59)<0)
						{
							flagSwap=1;
							bufferAux=auxiliarPasajero[i];
							auxiliarPasajero[i]=auxiliarPasajero[i+1];
							auxiliarPasajero[i+1]=bufferAux;
						}
					}
				}
				len--;
				rtn=0;
			}while(flagSwap);
			do
			{
				flagSwap=0;
				nuevoTam= len-1;
				for (i = 0; i < nuevoTam; i++) //hago tam-1 para que no intercambie con una varibale que no existe
				{
					if(auxiliarPasajero[i].isEmpty==OCUPADO && auxiliarPasajero[i+1].isEmpty==OCUPADO &&
							(strncmp(auxiliarPasajero[i].lastName,auxiliarPasajero[i+1].lastName,59)==0))
					{
						if (auxiliarPasajero[i].typePassenger>auxiliarPasajero[i+1].typePassenger)
						{
							flagSwap=1;
							bufferAux=auxiliarPasajero[i];
							auxiliarPasajero[i]=auxiliarPasajero[i+1];
							auxiliarPasajero[i+1]=bufferAux;
						}
					}
				}
				len--;
				rtn=0;
			}while(flagSwap);
			puts("PASAJEROS ORDENADOS POR APELLIDO Y TIPO");
			printPassengers(auxiliarPasajero, len);
			break;
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

int ePassanger_CalcularPrecios(Passenger* list, int len)
{
	int rtn=0;
	int i;
	float acumuladorPrecio=0;
	int contadorPasajes=0;
	float promedioPrecio;
	int contadorMayorPromedio=0;
	if(list != NULL)
	{
		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty==OCUPADO)
				{
					acumuladorPrecio=acumuladorPrecio+list[i].price;
					contadorPasajes++;
				}
			}
			promedioPrecio=acumuladorPrecio/contadorPasajes;
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty==OCUPADO && list[i].price>promedioPrecio)
				{
					acumuladorPrecio=acumuladorPrecio+list[i].price;
					contadorMayorPromedio++;
				}
			}
			printf("El precio promedio por pasaje es de $ %.2f."
					"\n La cantidad de pasajes que superan el promedio es de: %d",promedioPrecio,contadorMayorPromedio);
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


int sortPassengersByCode(Passenger* list, int len, int order)
{
	int rtn=-1;
	int flagSwap;
	int i;
	int nuevoTam;
	Passenger auxiliarPasajero[len];
	Passenger bufferAux;

	if(list != NULL)
	{
		if(len >0)
		{
			initPassengers(auxiliarPasajero, len);

			for (i = 0; i < len; i++)
			{
				if(list[i].isEmpty==OCUPADO)
				{
				auxiliarPasajero[i]=list[i];
				}
			}
			switch(order)
			{
			case 0:
				do
				{
					flagSwap=0;
					nuevoTam= len-1;
					for (i = 0; i < nuevoTam; i++) //hago tam-1 para que no intercambie con una varibale que no existe
					{
						if(auxiliarPasajero[i].isEmpty==OCUPADO && auxiliarPasajero[i+1].isEmpty==OCUPADO)
						{
							if (strncmp(auxiliarPasajero[i].flycode,auxiliarPasajero[i+1].flycode,59)>0)
							{
								flagSwap=1;
								bufferAux=auxiliarPasajero[i];
								auxiliarPasajero[i]=auxiliarPasajero[i+1];
								auxiliarPasajero[i+1]=bufferAux;
							}
						}
					}
					len--;
					rtn=0;
				}while(flagSwap);
				do
				{
					flagSwap=0;
					nuevoTam= len-1;
					for (i = 0; i < nuevoTam; i++) //hago tam-1 para que no intercambie con una varibale que no existe
					{
						if(auxiliarPasajero[i].isEmpty==OCUPADO && auxiliarPasajero[i+1].isEmpty==OCUPADO &&
								auxiliarPasajero[i].flycode==auxiliarPasajero[i+1].flycode)
						{
							if (auxiliarPasajero[i].statusFlight<auxiliarPasajero[i+1].statusFlight)
							{
								flagSwap=1;
								bufferAux=auxiliarPasajero[i];
								auxiliarPasajero[i]=auxiliarPasajero[i+1];
								auxiliarPasajero[i+1]=bufferAux;
							}
						}
					}
					len--;
					rtn=0;
				}while(flagSwap);
				puts("PASAJEROS ORDENADOS POR CODIGO DE VUELO Y ACTIVO");
				printPassengers(auxiliarPasajero, len);
			break;

			case 1:
			do
			{
				flagSwap=0;
				nuevoTam= len-1;
				for (i = 0; i < nuevoTam; i++) //hago tam-1 para que no intercambie con una varibale que no existe
				{
					if(auxiliarPasajero[i].isEmpty==OCUPADO && auxiliarPasajero[i+1].isEmpty==OCUPADO)
					{
						if (strncmp(auxiliarPasajero[i].flycode,auxiliarPasajero[i+1].flycode,59)>0)
						{
							flagSwap=1;
							bufferAux=auxiliarPasajero[i];
							auxiliarPasajero[i]=auxiliarPasajero[i+1];
							auxiliarPasajero[i+1]=bufferAux;
						}
					}
				}
				len--;
				rtn=0;
			}while(flagSwap);
			do
			{
				flagSwap=0;
				nuevoTam= len-1;
				for (i = 0; i < nuevoTam; i++) //hago tam-1 para que no intercambie con una varibale que no existe
				{
					if(auxiliarPasajero[i].isEmpty==OCUPADO && auxiliarPasajero[i+1].isEmpty==OCUPADO &&
							auxiliarPasajero[i].flycode==auxiliarPasajero[i+1].flycode)
					{
						if (auxiliarPasajero[i].statusFlight<auxiliarPasajero[i+1].statusFlight)
						{
							flagSwap=1;
							bufferAux=auxiliarPasajero[i];
							auxiliarPasajero[i]=auxiliarPasajero[i+1];
							auxiliarPasajero[i+1]=bufferAux;
						}
					}
				}
				len--;
				rtn=0;
			}while(flagSwap);
			puts("PASAJEROS ORDENADOS POR CODIGO DE VUELO Y ACTIVO");
			printPassengers(auxiliarPasajero, len);
			break;
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























