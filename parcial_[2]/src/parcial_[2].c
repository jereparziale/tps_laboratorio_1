#include <stdio.h>
#include <stdlib.h>
#include "utn_get.h"
#include "Controller.h"
#include "Listados.h"

int main()
{
	//agregar un funcion filter algo en la linked list, es como el sort te ordena por algo externo, esto es igual
	//filtro algo y lo paso por puntero a funcion.
	setbuf(stdout, NULL);
    int option;
    int salir=1;
    int errores;
    int opcionListados;
    int rtnAltaSalon;
    int rtnBajaSalon;
    int rtnListarSalon;
    int rtnModSalon;
    int rtnAddArcade;
    int rtnBajaArcade;
    int rtnListarArcade;
    int rtnAddJuego;
    int rtnListarJuegos;
    int rtnListarA;
    int rtnListarB;
    int rtnListarC;
    int rtnListarD;
    int rtnListarE;
    int rtnListarF;
    int rtnListarG;
    int rtnFilterSalon;
    int rtnFilterArcade;
    LinkedList* listaSalones = ll_newLinkedList();
    LinkedList* listaJuegos = ll_newLinkedList();
    LinkedList* listaArcades = ll_newLinkedList();
    controller_loadSalonFromText("data_salon.csv", listaSalones, &errores);
	controller_loadJuegoFromText("data_juego.csv", listaJuegos, &errores);
	controller_loadArcadeFromText("data_arcade.csv", listaArcades, &errores);

    do{
    	if(utn_getInt(&option, "\n--------------MENU--------------\n"
		 "1. ALTA SALON.\n"//OK
		 "2. ELIMINAR SALON.\n"//OK
		 "3. LISTAR SALONES\n"//OK
		 "4. INCORPORAR ARCADE\n"//OK
		 "5. MODIFICAR ARCADE\n"//OK
		 "6. ELIMINAR ARCADE\n"//OK
		 "7. IMPRIMIR LISTA ARCADE\n"//OK
		 "8. AGREGAR JUEGO\n"//OK
		 "9. IMPRIMIR JUEGO\n"//OK
		 "10. INFORMES\n"
		 "11. SALIR\n" //falta guardar
		,"\nError opcion no valida", 1, 11, 5)==0) //OK
    	{
    		switch(option)
			{
				case 1:
					rtnAltaSalon=controller_addSalon(listaSalones);
					if(rtnAltaSalon==0)
						{
							puts("ALTA EXISTOSA\n");
						}else if(rtnAltaSalon==-3)
						{
							puts("OPERACION CANCELADA\n");
						}else if(rtnAltaSalon==-2)
						{
							puts("ERROR EN CARGA DE DATOS, REINTENTE\n");
						}else if(rtnAltaSalon==-1)
						{
							puts("ERROR (-1)");
						}
				break;
				case 2:
					rtnBajaSalon=controller_removeSalon(listaSalones, listaArcades);
					if(rtnBajaSalon==0)
					{
						puts("BAJA EXISTOSA\n");
					}else if(rtnBajaSalon==-4)
					{
						puts("OPERACION CANCELADA\n");
					}else if(rtnBajaSalon==-3)
					{
						puts("ERROR EN BUSQUEDA DE ID\n");
					}else if(rtnBajaSalon ==-2)
					{
						puts("NO HAY SALONES EN LISTADO");
					}else if(rtnBajaSalon==-1)
					{
						puts("ERROR (-1)");
					}
				break;
				case 3:
					rtnListarSalon=controller_ListSalones(listaSalones);
					if(rtnListarSalon==0)
					{
						puts("\nFIN LISTADO\n");
					}else if(rtnListarSalon ==-2)
					{
						puts("NO HAY SALONES EN LISTADO");
					}else if(rtnListarSalon==-1)
					{
						puts("ERROR (-1)");
					}
				break;
				case 4:
					rtnAddArcade=controller_addArcade(listaArcades, listaSalones, listaJuegos);
					if(rtnAddArcade==0)
					{
						puts("ALTA EXITOSO\n");
					}else if(rtnAddArcade==-5)
					{
						puts("OPERACION CANCELADA\n");
					}
					else if(rtnAddArcade==-4)
					{
						puts("NO HAY JUEGOS DADOS DE ALTA\n");
					}else if(rtnAddArcade==-3)
					{
						puts("NO HAY SALONES DADOS DE ALTA\n");
					}else if(rtnAddArcade ==-2)
					{
						puts("ERROR EN CARGA DE DATOS");
					}else if(rtnAddArcade==-1)
					{
						puts("ERROR (-1)");
					}
				break;
				case 5:
					rtnModSalon=controller_editArcade(listaArcades, listaJuegos);
					if(rtnModSalon==0)
					{
						puts("MODIFICACION EXISTOSA\n");
					}else if(rtnModSalon==-4)
					{
						puts("OPERACION CANCELADA\n");
					}else if(rtnModSalon==-3)
					{
						puts("ERROR EN CARGA DE DATOS, REINTENTE\n");
					}else if(rtnModSalon ==-2)
					{
						puts("NO HAY PASAJEROS EN LISTADO");
					}else if(rtnModSalon==-1)
					{
						puts("ERROR (-1)");
					}
				break;
				case 6:
					rtnBajaArcade=controller_removeArcade(listaArcades,listaJuegos);
					if(rtnBajaArcade==0)
					{
						puts("BAJA EXISTOSA\n");
					}else if(rtnBajaArcade==-4)
					{
						puts("OPERACION CANCELADA\n");
					}else if(rtnBajaArcade==-3)
					{
						puts("ERROR EN BUSQUEDA DE ID\n");
					}else if(rtnBajaArcade ==-2)
					{
						puts("NO HAY ARCADE EN LISTADO");
					}else if(rtnBajaArcade==-1)
					{
						puts("ERROR (-1)");
					}
				break;
				case 7:
					rtnListarArcade=controller_ListArcade(listaArcades,listaJuegos);
					if(rtnListarArcade==0)
					{
						puts("FIN LISTADO\n");
					}else if(rtnListarArcade ==-2)
					{
						puts("NO HAY ARCADES EN LISTADO");
					}else if(rtnListarArcade==-1)
					{
						puts("ERROR (-1)");
					}
				break;
				case 8:
					rtnAddJuego=controller_addJuego(listaJuegos);
					if(rtnAddJuego==0)
					{
						puts("ALTA EXISTOSA\n");
					}else if(rtnAddJuego==-3)
					{
						puts("OPERACION CANCELADA\n");
					}else if(rtnAddJuego==-2)
					{
						puts("ERROR EN CARGA DE DATOS, REINTENTE\n");
					}else if(rtnAddJuego==-1)
					{
						puts("ERROR (-1)");
					}

				break;
				case 9:
					puts("PRUEBA FILTRAR SALONES QUE SEAN SHOPPING");
					rtnListarJuegos=controller_ListJuegos(listaJuegos);
					if(rtnListarJuegos==0)
					{
						puts("\nFIN LISTADO\n");
					}else if(rtnListarJuegos ==-2)
					{
						puts("NO HAY JUEGOS EN LISTADO");
					}else if(rtnListarJuegos==-1)
					{
						puts("ERROR (-1)");
					}
					puts("PRUEBA FILTRAR ARCADES QUE SEAN MONO");


				break;
				case 10:
					if(utn_getInt(&opcionListados, "\n--------------MENU INFORMES--------------\n"
					 "1. LISTAR SALONES CON MAS DE 4 ARCADES.\n"//OK
					 "2. LISTAR ARCADE PARA MAS DE 2 JUGADORES.\n"//ok
					 "3. IMPRIMIR UN SALON\n"//ok
					 "4. LISTAR SALONES COMPLETOS\n"//ok
					 "5. LISTAR ARCADES DE UN SALON\n"//ok
					 "6. IMPRIMIR SALON CON MAS ARCADE\n"//ok
					 "7. LISTAR ARCADE MONO Y JUEGO TIPO PLATAFORMA\n"//ok
					"8. PRUEBA FUNCION FILTER\n"//ok
					,"\nError opcion no valida", 1, 8, 5)==0)
					{
						switch(opcionListados)
						{
							case 1:
								rtnListarA=controller_List10A(listaSalones, listaArcades);
								if(rtnListarA==0)
								{
									puts("\nFIN LISTADO\n");
								}else if(rtnListarA==-3)
								{
									puts("\nNO HAY OCURRENCIAS\n");
								}else if(rtnListarA==-2)
								{
									puts("\nNO HAY ARCADES DE ALTA\n");
								}else if(rtnListarA==-1)
								{
									puts("\nERROR (-1)");
								}
							break;
							case 2:
								rtnListarB=controller_List10B(listaArcades, listaJuegos, listaSalones);
								if(rtnListarB==0)
								{
									puts("\nFIN LISTADO\n");
								}else if(rtnListarB==-4)
								{
									puts("\nNO SE ENCONTRARON OCURRENCIAS\n");
								}else if(rtnListarB==-3)
								{
									puts("\nERROR AL IMPRIMIR LOS DATOS\n");
								}else if(rtnListarB ==-2)
								{
									puts("\nNO HAY ARCADE EN LISTADO");
								}else if(rtnListarB==-1)
								{
									puts("\nERROR (-1)");
								}
							break;
							case 3:
								rtnListarC=controller_List10C(listaSalones);
								if(rtnListarC==0)
								{
									puts("\nFIN LISTADO\n");
								}else if(rtnListarC==-3)
								{
									puts("\nERROR EN TOMA ID\n");
								}else if(rtnListarC==-2)
								{
									puts("\nNO HAY SALONES DE ALTA\n");
								}else if(rtnListarC==-1)
								{
									puts("\nERROR (-1)");
								}
							break;
							case 4:
								rtnListarD=controller_List10D(listaSalones, listaArcades, listaJuegos);
								if(rtnListarD==0)
								{
									puts("\nFIN LISTADO\n");
								}else if(rtnListarD==-3)
								{
									puts("\nNO SE ENCONTRARON OCURRENCIAS\n");
								}else if(rtnListarD==-2)
								{
									puts("\nNO HAY SALONES O ARCADES DE ALTA\n");
								}else if(rtnListarD==-1)
								{
									puts("\nERROR (-1)");
								}
							break;
							case 5:
								rtnListarE=controller_List10E(listaSalones, listaArcades, listaJuegos);
								if(rtnListarE==0)
								{
									puts("\nFIN LISTADO\n");
								}else if(rtnListarB==-4)
								{
									puts("\nNO SE ENCONTRARON OCURRENCIAS\n");
								}else if(rtnListarE==-3)
								{
									puts("\nERROR AL TOMAR ID SALON\n");
								}else if(rtnListarE ==-2)
								{
									puts("\nNO HAY ARCADE/SALON EN LISTADO");
								}else if(rtnListarE==-1)
								{
									puts("\nERROR (-1)");
								}
							break;
							case 6:
								rtnListarF=controller_List10F(listaSalones, listaArcades);
								if(rtnListarF==0)
								{
									puts("\nFIN LISTADO\n");
								}else if(rtnListarF==-3)
								{
									puts("\nSIN OCURRENCIAS\n");
								}else if(rtnListarF ==-2)
								{
									puts("\nSIN ARCADES/SALONES DE ALTA");
								}else if(rtnListarF==-1)
								{
									puts("\nERROR (-1)");
								}
							break;
							case 7:
								rtnListarG=controller_List10G(listaArcades, listaJuegos);
								if(rtnListarG==0)
								{
									puts("\nFIN LISTADO\n");
								}else if(rtnListarG==-3)
						 		{
									puts("\nSIN OCURRENCIAS\n");
								}else if(rtnListarG ==-2)
								{
									puts("\nSIN ARCADES DE ALTA");
								}else if(rtnListarG==-1)
								{
									puts("\nERROR (-1)");
								}
							break;
							case 8:
								rtnFilterSalon=controller_ListFilterSalon(listaSalones);
								if(rtnFilterSalon==0)
								{
									puts("\nFIN LISTADO\n");
								}else if(rtnFilterSalon==-3)
								{
									puts("\nSIN OCURRENCIAS\n");
								}else if(rtnFilterSalon ==-2)
								{
									puts("\nSIN SALONES DE ALTA");
								}else if(rtnFilterSalon==-1)
								{
									puts("\nERROR (-1)");
								}
								rtnFilterArcade=controller_ListFilterArcade(listaArcades, listaJuegos);
								if(rtnFilterArcade==0)
								{
									puts("\nFIN LISTADO\n");
								}else if(rtnFilterArcade==-3)
								{
									puts("\nSIN OCURRENCIAS\n");
								}else if(rtnFilterArcade ==-2)
								{
									puts("\nSIN ARCADES DE ALTA");
								}else if(rtnFilterArcade==-1)
								{
									puts("\nERROR (-1)");
								}
							break;
						}
					}
				break;
				case 11:
					if(
					controller_saveAsTextSalon("data_salon.csv", listaSalones)>0 &&
					controller_saveAsTextJuego("data_juego.csv", listaJuegos)>0 &&
					controller_saveAsTextArcade("data_arcade.csv", listaArcades)>0)
					{
						puts("GUARDADO EXISTOSO");
					}
					salir=0;
					puts("GRACIAS POR UTILIZAR EL PROGRAMA.");
				break;

			}
    	}

    }while(salir==1);
    return 0;
}
