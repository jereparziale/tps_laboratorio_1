#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn_get.h"
#include "Flight.h"

#define ARCHIVO_PATH "./data.csv"
#define ARCHIVO_VUELOS_PATH "./flights_data.csv"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option;
    int salir=1;
    int rtnLoadText=-1;
    int erroresLoadText=-1;
    int rtnAdd=-1;
    int rtnEdit=-1;
    int rtnRemove=-1;
    int rtnList=-1;
    int rtnSort=-1;
    int rtnSaveTxt=-1;
    int rtnSaveBin=-1;

    LinkedList* listaPasajeros = ll_newLinkedList();
    LinkedList* listaVuelos = ll_newLinkedList();

    controller_loadFlightFromText(ARCHIVO_VUELOS_PATH, listaVuelos);
    do{
    	if(utn_getInt(&option, "\n--------------MENU--------------\n"
		 "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n" //OK
		 "2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n" //OK
		 "3. Alta de pasajero\n" //OK
		 "4. Modificar datos de pasajero\n"//OK
		 "5. Baja de pasajero\n" //OK
		 "6. Listar pasajeros\n" //OK
		 "7. Ordenar pasajeros\n" //OK
		 "8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"//OK
		 "9. Guardar los datos de los pasajeros en el archivo data_bin.bin (modo binario).\n" //ok
		"10. Salir\n","\nError opcion no valida", 1, 10, 5)==0) //OK
    	{
    		switch(option)
			{
				case 1:
					printf("Largo inicial LL: %d\n",ll_len(listaPasajeros));
					rtnLoadText=controller_loadFromText("data.csv",listaPasajeros,&erroresLoadText);
					if(rtnLoadText==0)
					{
						printf("LECTURA EXISTOSA\nLargo LL final: %d\n",ll_len(listaPasajeros));
					}
					else if(rtnLoadText==-2)
					{
						puts("La lista no tiene la cantidad de datos pedida");
					}
					else
					{
						puts("ERROR, pFile o LL NULL");
					}
				break;
				case 2:
					printf("largo lista %d",ll_len(listaPasajeros));
					controller_loadFromBinary("data_bin.bin", listaPasajeros);
					printf("largo lista %d",ll_len(listaPasajeros));
				break;
				case 3:
					rtnAdd=controller_addPassenger(listaPasajeros,listaVuelos);
					if(rtnAdd==0)
					{
						puts("ALTA EXISTOSA\n");
					}else if(rtnAdd==-4)
					{
						puts("OPERACION CANCELADA\n");
					}else if(rtnAdd==-3)
					{
						puts("ERROR EN CARGA DE DATOS, REINTENTE\n");
					}else if(rtnAdd ==-2)
					{
						puts("ERROR EN CARGA DE VUELO");
					}else if(rtnAdd==-1)
					{
						puts("ERROR (-1)");
					}
				break;
				case 4:
					rtnEdit=controller_editPassenger(listaPasajeros,listaVuelos);
					if(rtnEdit==0)
					{
						puts("MODIFICACION EXISTOSA\n");
					}else if(rtnEdit==-4)
					{
						puts("OPERACION CANCELADA\n");
					}else if(rtnEdit==-3)
					{
						puts("ERROR EN CARGA DE DATOS, REINTENTE\n");
					}else if(rtnEdit ==-2)
					{
						puts("NO HAY PASAJEROS EN LISTADO");
					}else if(rtnEdit==-1)
					{
						puts("ERROR (-1)");
					}
				break;
				case 5:
					rtnRemove=controller_removePassenger(listaPasajeros);
					if(rtnRemove==0)
					{
						puts("BAJA EXISTOSA\n");
					}else if(rtnRemove==-4)
					{
						puts("OPERACION CANCELADA\n");
					}else if(rtnRemove==-3)
					{
						puts("ERROR EN BUSQUEDA DE ID\n");
					}else if(rtnRemove ==-2)
					{
						puts("NO HAY PASAJEROS EN LISTADO");
					}else if(rtnRemove==-1)
					{
						puts("ERROR (-1)");
					}
				break;
				case 6:
					rtnList=controller_ListPassenger(listaPasajeros);
					if(rtnList==0)
					{
						puts("FIN LISTADO\n");
					}else if(rtnList ==-2)
					{
						puts("NO HAY PASAJEROS EN LISTADO");
					}else if(rtnList==-1)
					{
						puts("ERROR (-1)");
					}
				break;
				case 7:
					rtnSort=controller_sortPassenger(listaPasajeros);
					if(rtnSort==0)
					{
						puts("FIN LISTADO\n");
					}else if(rtnSort ==-2)
					{
						puts("NO HAY PASAJEROS EN LISTADO");
					}else if(rtnSort==-1)
					{
						puts("ERROR (-1)");
					}
				break;
				case 8:
					rtnSaveTxt=controller_saveAsText("data.csv", listaPasajeros);
					if(rtnSaveTxt>0)
					{
						printf("GUARDADO EXISTOSO\nDatos escritos: %d.",rtnSaveTxt);
					}else if(rtnRemove==-4)
					{
						puts("FORMATO DE DATOS INCORRECTO\n");
					}else if(rtnSaveTxt==-3)
					{
						puts("NO HAY PASAJEROS EN LISTADO");
					}else if(rtnSaveTxt ==-2 || rtnSaveTxt==-1)
					{
						printf("ERROR (%d)",rtnSaveTxt);
					}
				break;
				case 9:
					rtnSaveBin=controller_saveAsBinary("data_bin.bin", listaPasajeros);
					printf("contador cargas .bin %d",rtnSaveBin);
				break;
				case 10:
					if(rtnSaveTxt>0 || rtnSaveBin>0)
					{
						salir=0;
						puts("GRACIAS POR UTILIZAR EL PROGRAMA.");
					}
					else
					{
						puts("NO FUE POSIBLE POR FAVOR GUARDAR SELECCIONANDO LA OPCION 8 Y 9.");
					}
				break;

			}
    	}

    }while(salir==1);
    return 0;
}

