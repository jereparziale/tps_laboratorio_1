/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Jeremias
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PassengerVuelo.h"
#include "utn_get.h"

#define CANT_PASAJEROS 2000
#define CANT_VUELOS 200
#define VUELO_ACTIVO 1
#define VUELO_EN_ESPERA 2
int main(void)
{
	setbuf(stdout, NULL);

	Passenger arrayPasajeros[CANT_PASAJEROS];
	Passenger auxiliarPasajero;
	Flight arrayVuelos[CANT_VUELOS];

	int opcion;
	int rtnAlta;
	int continuarAlta;
	int rtnBaja;
	int continuarBaja;
	int opcionModificacion;
	int rtnModificacion;
	int continuarModificacion;
	int continuar=0;
	int continuarVuelo;
	int idAuxiliar;
	int rtnSort;
	int rtnCalcular;
	int rtnListar;
	int opcion4;
	int flagOcupados;
	int flagVuelosOcupados;
	int rtnAltaVuelo;
	int rtnRelacion;

	initPassengers(arrayPasajeros, CANT_PASAJEROS);
	eFlight_Inicializar(arrayVuelos, CANT_VUELOS);


	do
	{
		if(utn_getInt(&opcion, "\n--------------MENU--------------\n"
				"Ingrese la opcion...\n1.ALTA.\n2.BAJA.\n3.MODIFICACION.\n4.INFORMACION/LISTADOS.\n5.CARGA FORZADA DE DATOS.\n6.SALIR DEL PROGRAMA.",
				"\nError opcion no valida", 1, 6, 5)==0)
		{

			if(ePassenger_CantidadOcupados(arrayPasajeros, CANT_PASAJEROS)>0)
			{
				flagOcupados=1;
			}
			else
			{
				flagOcupados=-1;
			}
			if(eFlight_CantidadOcupados(arrayVuelos, CANT_VUELOS)>0)
			{
				flagVuelosOcupados=1;

			}
			else
			{
				flagVuelosOcupados=-1;
			}
			if(flagOcupados>0 && flagVuelosOcupados>0)
			{
				rtnRelacion=rel_PassengerVuelo_EstadoVuelo(arrayPasajeros, CANT_PASAJEROS, arrayVuelos, CANT_VUELOS);
			}
			switch (opcion)
			{
			case 1:
				do
				{
					if(flagVuelosOcupados==1)
					{
						utn_getInt(&continuarVuelo, "Desea ingresar un pasajero para un vuelo en uso o generar un nuevo vuelo"
								"\nEN USO (1)  --- NUEVO VUELO (0)", "ERROR, opcion no valida.", 0, 1, 5);
						switch(continuarVuelo)
						{
						case 0:
							rtnAltaVuelo=eFlight_Alta(arrayVuelos, CANT_VUELOS);
							break;
						case 1:
							eFlight_imprimirTodosEstado(arrayVuelos, CANT_VUELOS, OCUPADO);
							do
							{
								utn_getString(auxiliarPasajero.flycode, "Ingrese el codigo de vuelo a utilizar", "ERROR", 10, 5);
								rtnAltaVuelo=eFlightBuscarIndicePorCodigo(arrayVuelos, CANT_VUELOS, auxiliarPasajero.flycode);
							}while(rtnAltaVuelo<0);
						}
					}
					else
					{
						puts("No se encontraron vuelos en sistema por favor dar de alta para poder continuar.");
						rtnAltaVuelo=eFlight_Alta(arrayVuelos, CANT_VUELOS);
					}
					if(rtnAltaVuelo>-1)
					{
						flagVuelosOcupados=1;
						auxiliarPasajero=AltaPasajero();
						strncpy(auxiliarPasajero.flycode,arrayVuelos[rtnAltaVuelo].flycode,sizeof(auxiliarPasajero.flycode));
						rtnAlta=addPassenger(arrayPasajeros, CANT_PASAJEROS, auxiliarPasajero.id, auxiliarPasajero.name,
								auxiliarPasajero.lastName, auxiliarPasajero.price, auxiliarPasajero.typePassenger, auxiliarPasajero.flycode);
						if(rtnAlta>=0)
						{
							puts("\nCARGA DE PASAJERO EXITOSA!");
						}
						else
						{
							if(rtnAlta==-1)
							{
								puts("\nERROR(1), listo de pasajeros llena.");
							}
							else
							{
								if(rtnAlta==-4)
								{
									puts("\nAlta cancelada");
								}
								else
								{
									puts("\nERROR(2-3), en la carga.");
								}
							}
						}
						utn_getInt(&continuarAlta, "\nPara realizar otra alta o reintentar ingrese 1, de lo contrario ingrese 0.", "ERROR, opcion no valida", 0, 1, 5);
					}
					else
					{
						utn_getInt(&continuarAlta, "\nAlta de vuelo fallida o cancelada, para reintentar ingrese 1 de lo contrario ingrese 0.", "ERROR, opcion no valida", 0, 1, 5);
					}
				}while(continuarAlta==1);
				break;
			case 2:
				if(flagOcupados>0)
				{
					do
					{
						requestId(arrayPasajeros, CANT_PASAJEROS, &idAuxiliar);
						rtnBaja=removePassenger(arrayPasajeros, CANT_PASAJEROS,idAuxiliar);
						if(rtnBaja>=0)
						{
							puts("\nBAJA DEL PASAJERO EXITOSA!");
						}
						else
						{
							if(rtnBaja==-1)
							{
								puts("\nERROR(1), ID no encontrado o ID no dado de ALTA.");
							}
							else
							{
								if(rtnBaja==-4)
								{
									puts("\nModificacion cancelada");
								}
								else
								{
									puts("\nERROR(2-3), en la carga.");
								}
							}
						}
						utn_getInt(&continuarBaja, "\nPara realizar otra baja o reintentar ingrese 1, de lo contrario ingrese 0.", "ERROR, opcion no valida", 0, 1, 5);
					}while(continuarBaja==1);
				}
				else
				{
					printf("ERROR, por favor antes de utilizar esta opcion verificar que haya pasajeros dados de alta.\n");
				}
				break;
			case 3:
				if(flagOcupados>0)
				{
					do
					{
						requestId(arrayPasajeros, CANT_PASAJEROS, &idAuxiliar);
						findPassengerById(arrayPasajeros, CANT_PASAJEROS, idAuxiliar);
						if(utn_getInt(&opcionModificacion, "\nIngrese la opcion del campo a modificar,\n1.Nombre\n2.Apellido\n3.Precio\n4.Tipo de pasajero"
								"\n5.Codigo de vuelo", "Error opcion no valida", 1, 5, 5)==0)
						{
							if(opcionModificacion==5)
							{
								rtnModificacion=rel_PassengerVuelo_ModificarCodigoVuelo(arrayPasajeros, CANT_PASAJEROS, idAuxiliar, arrayVuelos, CANT_VUELOS);
								if(rtnModificacion>=0)
								{
									puts("\nMODIFICACION DEL PASAJERO EXITOSA!");
								}
								else
								{
									if(rtnModificacion==-1)
									{
										puts("\nERROR(1), ID no encontrado o ID no dado de ALTA.");
									}
									else
									{
										if(rtnModificacion==-4)
										{
											puts("\nModificacion cancelada");
										}
										else
										{
											puts("\nERROR(2-3), en la carga.");
										}
									}
								}
							}
							else
							{
								rtnModificacion=modifyPassenger(arrayPasajeros, CANT_PASAJEROS,idAuxiliar,opcionModificacion);
								if(rtnModificacion>=0)
								{
									puts("\nMODIFICACION DEL PASAJERO EXITOSA!");
								}
								else
								{
									if(rtnModificacion==-1)
									{
										puts("\nERROR(1), ID no encontrado o ID no dado de ALTA.");
									}
									else
									{
										if(rtnModificacion==-4)
										{
											puts("\nModificacion cancelada");
										}
										else
										{
											puts("\nERROR(2-3), en la carga.");
										}
									}
								}
							}
						}
						utn_getInt(&continuarModificacion, "\nPara realizar otra modificacion o reintentar ingrese 1, de lo contrario ingrese 0.", "ERROR, opcion no valida", 0, 1, 5);
					}while(continuarModificacion==1);
				}
				else
				{
					printf("ERROR, por favor antes de utilizar esta opcion verificar que haya pasajeros dados de alta.\n");
				}
				break;

			case 4:
				if(flagOcupados>0)
				{
					if(utn_getInt(&opcion4, "\n--------------MENU--------------\n"
							"Ingrese la opcion...\n1.LISTAR PASAJEROS POR APELLIDO Y TIPO DE VUELO."
							"\n2.TOTAL Y PROMEDIO DEL $ DE LOS PASAJES Y CANTIDAD DE PASAJEROS QUE LO SUPERAN."
							"\n3.LISTAR PASAJEROS POR CODIGO DE VUELO Y ESTADO ACTIVO.",
							"\nError opcion no valida", 1, 4, 5)==0)
					{
						switch (opcion4)
						{
						case 1:
							rtnSort=sortPassengers(arrayPasajeros, CANT_PASAJEROS, 0);
							if(rtnSort>=0)
							{
								puts("\nFIN DEL LISTADO.");
							}
							else
							{
								puts("\nERROR(2-3), en la carga.");
							}
							break;
						case 2:
							rtnCalcular=ePassanger_CalcularPrecios(arrayPasajeros, CANT_PASAJEROS);
							if(rtnCalcular>=0)
							{
								puts("\nFIN DEL LISTADO.");
							}
							else
							{
								puts("\nERROR(2-3), en la carga.");
							}
							break;
						case 3:
							rtnListar=sortPassengersByCode(arrayPasajeros, CANT_PASAJEROS, 0);
							if(rtnListar>=0)
							{
								puts("\nFIN DEL LISTADO.");
							}
							else
							{
								puts("\nERROR(2-3), en la carga.");
							}
							break;
						}
					}
				}
				else
				{
					printf("ERROR, por favor antes de utilizar esta opcion verificar que haya pasajeros dados de alta.\n");
				}
				break;
			case 5:
				cargaForzadaDatos(arrayPasajeros, arrayVuelos);
				puts("Carga forzada exitosa");
				break;
			case 6:
				puts("Gracias por utilizar el programa!");
				continuar=1;

				break;

			}
		}
	}while(continuar == 0);
}

















