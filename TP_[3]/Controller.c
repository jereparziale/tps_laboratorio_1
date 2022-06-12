#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "LinkedList.h"
#include "parser.h"
#include "Passenger.h"
#include "Flight.h"
#define ARCHIVO_PATH "./data.csv"
#define CLASE_EJECUTIVA 1
#define CLASE_PRIMERA 2
#define CLASE_ECONOMICA 3
#define ESTADO_ATERRIZADO 1
#define ESTADO_ENHORARIO 2
#define ESTADO_ENVUELO 3
#define ESTADO_DEMORADO 4
#define LIBRE -1
#define OCUPADO 0


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int* contadorErrores)
{
	int rtn=-1;
	int rtnParser=-1;
	FILE *pFile=NULL;
	pFile=fopen(path,"r");
	if(pFile!=NULL && pArrayListPassenger != NULL)
	{
		rtn=parser_PassengerFromText(pFile ,pArrayListPassenger,contadorErrores);
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

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFlightFromText(char* path ,LinkedList* listaVuelos,int tam)
{
	int rtn=-1;
	FILE *pFile=NULL;
	pFile=fopen(path,"r");
	parser_FlightFromText(pFile, listaVuelos, tam);
	fclose(pFile);
	return rtn;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int rtn=-1;
	//FALTA RETORNO.
	FILE *pFile=NULL;
	pFile=fopen(path,"rb");
	rtn=parser_PassengerFromBinary(pFile, pArrayListPassenger);
	fclose(pFile);
	return rtn;
}

/// @fn int myIdGenerator()
/// @brief carga el dato del ultimo id guardado.
///
/// @pre
/// @post
/// @return retorna el id
int myIdGenerator()
{
	int myId;
	FILE *pFile=NULL;
	pFile =fopen("id_data.csv","r");
	myId=parser_IdFromText(pFile);
	fclose(pFile);
	return myId;
}

/// @fn int saveId(int)
/// @brief Una vez confirmada el alta de pasajero se guarda el id nuevo en el texto y se aumenta para la proxima consulta.
///
/// @pre
/// @post
/// @param nuevoId
/// @return rtn 0 si ok, -1 si pFile en NULL
int saveId(int nuevoId)
{
	int rtn=-1;
	char idAuxChar[100];
	FILE *pFile=NULL;
	pFile =fopen("id_data.csv","w+");
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

/// @fn int controller_ListFlights(LinkedList*)
/// @brief Lista los vuelos disponibles.
///
/// @pre
/// @post
/// @param listaVuelos
/// @return rtn o si ok, -1 si pFile NULL y -2 si ll es 0<
int controller_ListFlights(LinkedList* listaVuelos)
{
	Flight* this;
	int rtn=-1;
	int i;
	if(listaVuelos!=NULL)
	{
		if(ll_len(listaVuelos)>0)
		{
			printf("|CODIGO DE VUELO|ESTADO VUELO             |\n");
			printf("+---------------+-------------------------+\n");
			for(i=0;i<ll_len(listaVuelos);i++)
			{
				this=ll_get(listaVuelos, i);
				eFlight_imprimirUno(this);
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

/// @fn Passenger Passenger_buscarPorId*(LinkedList*, int, int*)
/// @brief A partir de un id retorna en puntero del pasajero y por referencia el indice.
///
/// @pre
/// @post
/// @param pArrayListPassenger
/// @param auxiliarId
/// @param index_ll
/// @return rtn el puntero al pasajero, si no existe, NULL.
Passenger* Passenger_buscarPorId(LinkedList* pArrayListPassenger, int auxiliarId, int* index_ll)
{
	Passenger* this;
	int len_ll=ll_len(pArrayListPassenger);
	int i;
	int idAux;
	for(i=0;i<len_ll;i++)
	{
		this=ll_get(pArrayListPassenger, i);
		Passenger_getId(this, &idAux);
		if(idAux==auxiliarId)
		{
			//VALIDAR INDEX OF
			*index_ll=ll_indexOf(pArrayListPassenger, this);
			break;
		}
		else
		{
			this=NULL;
		}
	}
	return this;
}


/// @fn Flight* Flight_buscarPorCodigo(LinkedList* listaVuelos,  int* index_ll)
/// @brief A partir de un codigo de vueloy retorna en puntero del vuelo  y por referencia el indice.
///
/// @pre
/// @post
/// @param pArrayListPassenger
/// @param auxiliarId
/// @param index_ll
/// @return rtn el puntero al vuelo, si no existe, NULL.
Flight* Flight_buscarPorCodigo(LinkedList* listaVuelos,  int* index_ll)
{
	Flight* this;
	int i;
	char codigoVuelo[10];
	char codigoVueloThis[10];
	int flag=0;

	if (listaVuelos != NULL)
	{
		controller_ListFlights(listaVuelos);
		do
		{
		utn_getString(codigoVuelo, "Ingrese el codigo de vuelo a utilizar", "ERROR, codigo de vuelo inexistente", 10, 5);
		cambiarMinusMayus(codigoVuelo, 10);
		for(i=0;i<ll_len(listaVuelos);i++)
		{
			this=ll_get(listaVuelos, i);
			Flight_getCodigoVuelo(this, codigoVueloThis);
			if(strncmp(codigoVueloThis,codigoVuelo,8)==0)
			{
				*index_ll=ll_indexOf(listaVuelos, this);
				flag=1;
				break;
			}
		}
		}while(flag==0);
	}
	return this;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,LinkedList* listaVuelos)
{
	Passenger* this;
	Flight* vuelo;
	int rtn=-1;
	int continuar;
	int index;
	char codigoVueloAux[10];
	char codigoVueloAuxPassenger[10];
	int estadoVueloAux;
	int estadoVueloAuxPassenger;
	int idAux;
	if(pArrayListPassenger!=NULL && listaVuelos != NULL)
	{
		vuelo=Flight_buscarPorCodigo(listaVuelos, &index);
		if(vuelo !=NULL)
		{
			this=AltaPasajero();
			if(this!=NULL)
			{
				Flight_getCodigoVuelo(vuelo, codigoVueloAux);
				strncpy(codigoVueloAuxPassenger,codigoVueloAux,10);
				Passenger_setCodigoVuelo(this, codigoVueloAuxPassenger);
				Flight_getEstadoVuelo(vuelo, &estadoVueloAux);
				estadoVueloAuxPassenger=estadoVueloAux;
				Passenger_setEstadoVuelo(this, estadoVueloAuxPassenger);
				idAux=myIdGenerator();
				Passenger_setId(this, idAux);
				printPassengerAuxiliar(this);
				utn_getInt(&continuar, "\nDESEA GUARDAR Y DAR EL ALTA?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
				if(continuar==1)
				{
					saveId(idAux);
					ll_add(pArrayListPassenger,this);
					rtn=0;
				}
				else
				{
					free(this);
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
			rtn=-2;
		}
	}
	else
	{
		rtn=-1; //LL NULA
	}
    return rtn;
}


/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* this;
	int rtn=-1;
	int i;
	int len_ll=ll_len(pArrayListPassenger);
	if(pArrayListPassenger!=NULL)
	{
		if(len_ll>0)
		{
			printf("ID  |NOMBRE    |APELLIDO  |PRECIO   |TIPO DE PASAJERO|CODIGO DE VUELO|ESTADO VUELO\n");
			printf("----+----------+----------+---------+----------------+---------------+------------\n");
			for(i=0;i<len_ll;i++)
			{
				this=ll_get(pArrayListPassenger, i);
				printPassengers(this);
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



/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger,LinkedList* listaVuelos)
{
	Passenger* auxiliarPasajero;
	Passenger* this;
	Flight* vuelo;
	int rtn=-1;
	int auxiliarId;
	int continuar;
	int continuarModificacion;
	int opcionModificacion;
	int index_llModificar;
	char codigoVueloAux[10];
	char codigoVueloAuxPassenger[10];
	int estadoVueloAux;
	int estadoVueloAuxPassenger;
	int index;
	if(pArrayListPassenger!=NULL)
	{
		if(controller_ListPassenger(pArrayListPassenger)==0)
		{
			do
			{
				requestId(&auxiliarId);
				this=Passenger_buscarPorId(pArrayListPassenger, auxiliarId,&index_llModificar);
			}while(this==NULL);
			auxiliarPasajero=this;
			if(auxiliarPasajero!=NULL)
			{
				printPassengerAuxiliar(auxiliarPasajero);
					do
					{
						if(utn_getInt(&opcionModificacion, "\nIngrese la opcion del campo a modificar,\n1.Nombre\n2.Apellido\n3.Precio\n4.Tipo de pasajero"
														"\n5.Codigo de vuelo", "Error opcion no valida", 1, 5, 5)==0)
						{
							switch(opcionModificacion)
							{
							case 5:
								vuelo=Flight_buscarPorCodigo(listaVuelos, &index);
								puts("paso");
								Flight_getCodigoVuelo(vuelo, codigoVueloAux);
								strncpy(codigoVueloAuxPassenger,codigoVueloAux,10);
								Passenger_setCodigoVuelo(auxiliarPasajero, codigoVueloAuxPassenger);
								Flight_getEstadoVuelo(vuelo, &estadoVueloAux);
								estadoVueloAuxPassenger=estadoVueloAux;
								Passenger_setEstadoVuelo(auxiliarPasajero, estadoVueloAuxPassenger);
							break;
							default:
								auxiliarPasajero=ModificarPasajero(auxiliarPasajero, opcionModificacion);
							break;
							}
							printPassengerAuxiliar(auxiliarPasajero);
							utn_getInt(&continuarModificacion, "\nDESEA MODIFICAR OTRO PARAMETRO?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
						}
					}while(continuarModificacion==1);
					utn_getInt(&continuar, "\nDESEA GUARDAR LOS CAMBIOS EFECTUADOS?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
					if(continuar==1)
					{
						this=auxiliarPasajero;
						ll_set(pArrayListPassenger, index_llModificar, this);
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

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	Passenger* this;
	int rtn=-1;
	int auxiliarId;
	int continuar;
	int index_llBorrar;
	if(pArrayListPassenger!=NULL)
	{
		if(controller_ListPassenger(pArrayListPassenger)==0)
		{
			do
			{
				requestId(&auxiliarId);
				this=Passenger_buscarPorId(pArrayListPassenger, auxiliarId,&index_llBorrar);
			}while(this==NULL);

			if(this!=NULL)
			{
				printPassengerAuxiliar(this);
				utn_getInt(&continuar, "\nDESEA DAR DE BAJA EL ID INGRESADO?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
				if(continuar==1)
				{
					ll_remove(pArrayListPassenger, index_llBorrar);
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


/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int rtn;
	LinkedList* auxiliarOrdenar;
	int len_ll=ll_len(pArrayListPassenger);
	if(pArrayListPassenger!=NULL)
	{
		if(len_ll>0)
		{
			auxiliarOrdenar=ll_clone(pArrayListPassenger);
			rtn=ll_sort(auxiliarOrdenar, Passenger_criterioNombre, 1);
			controller_ListPassenger(auxiliarOrdenar);
		}
		else
		{
			rtn=-2; //LL VACNIA
		}
	}
	else
	{
		rtn=-1; // LL NULA
	}
    return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	Passenger* this;
	int rtn=-1;
	int i;
	int idAux;
	char idAuxChar[100];
	char nombreAux[100];
	char apellidoAux[100];
	float precioAux;
	char precioChar[100];
	char codigoVueloAux[100];
	int tipoPasajeroAux;
	char tipoPasajeroChar[100];
	int estadoVuelo;
	char estadoVueloChar[100];
	int contadorCargas=1;
	int len_ll=ll_len(pArrayListPassenger);

	//FALTA RETORNO.
	FILE *pFile=NULL;
	pFile=fopen(path,"w+");
	if(pFile!=NULL)
	{
		if(pArrayListPassenger!=NULL)
		{
			if(len_ll>0)
			{
				//VALIDAR SI CON R ES DISTINTO DE NULL
				for(i=0;i<len_ll;i++)
				{
					this=ll_get(pArrayListPassenger, i);
					if(this != NULL)
					{
						if(Passenger_getId(this,&idAux)==0 && Passenger_getNombre(this, nombreAux)==0 && Passenger_getApellido(this, apellidoAux)==0
								&& Passenger_getPrecio(this, &precioAux)==0  && Passenger_getTipoPasajero(this, &tipoPasajeroAux)==0 && Passenger_getCodigoVuelo(this, codigoVueloAux) == 0
								&& Passenger_getEstadoVuelo(this, &estadoVuelo)==0)
						{

							switch(tipoPasajeroAux)
							{
							case 1:
								strncpy(tipoPasajeroChar,"FirstClass",sizeof(tipoPasajeroChar));
							break;
							case 2:
								strncpy(tipoPasajeroChar,"ExecutiveClass",sizeof(tipoPasajeroChar));
							break;
							case 3:
								strncpy(tipoPasajeroChar,"EconomyClass",sizeof(tipoPasajeroChar));
							break;
							default:
								puts("ERROR");
							break;
							}
							switch(estadoVuelo)
							{
							case ESTADO_ATERRIZADO:
								strncpy(estadoVueloChar,"Aterrizado",sizeof(estadoVueloChar));
							break;
							case ESTADO_ENHORARIO:
								strncpy(estadoVueloChar,"En Horario",sizeof(estadoVueloChar));
							break;
							case ESTADO_ENVUELO:
								strncpy(estadoVueloChar,"En Vuelo",sizeof(estadoVueloChar));
							break;
							case ESTADO_DEMORADO:
								strncpy(estadoVueloChar,"Demorado",sizeof(estadoVueloChar));
							break;
							default:
								puts("ERROR");
							break;
							}
							sprintf(idAuxChar,"%d",idAux);
							sprintf(precioChar,"%1f",precioAux);

							fprintf(pFile,"%d,%s,%s,%1f,%s,%s,%s\n",idAux,nombreAux,apellidoAux,precioAux,codigoVueloAux,
									tipoPasajeroChar,estadoVueloChar);
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

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	Passenger* this;
	int rtn=-1;
	int i;
	int contadorCargas=1;
	int len_ll=ll_len(pArrayListPassenger);
	FILE *pFile=NULL;
	//ANTES DE FOPEN
	pFile=fopen(path,"wb");
	if(pFile!=NULL)
	{
		if(pArrayListPassenger!=NULL)
		{
			//guardar ll_len guardar en variable.
			for(i=0;i<len_ll;i++)
			{
				this=ll_get(pArrayListPassenger, i);
				if(this != NULL)
				{
					fwrite(this,sizeof(Passenger),1,pFile);
					rtn=contadorCargas++;
				}
			}
		}

	}
	fclose(pFile);
	return rtn;
}


