#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Producto.h"
#include "rel_tracking-producto.h"

#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 2000
#define CANT_TRACKINGS 4000
#define LIBRE -1
#define OCUPADO 0
#define BAJA 1
#define ADMIN 1
#define USUARIO 2
int main(void)
{
	setbuf(stdout, NULL);

	Usuario arrayUsuarios[CANT_USUARIOS];
	Producto arrayProductos[CANT_PRODUCTOS];
	Tracking arrayTrackings[CANT_TRACKINGS];

	eUsuario_Inicializar(arrayUsuarios, CANT_USUARIOS);
	eProducto_Inicializar(arrayProductos, CANT_PRODUCTOS);
	eTracking_Inicializar(arrayTrackings, CANT_TRACKINGS);

	int opcionIngreso;
	int salir=0;
	int rtnAlta;
	int indiceUsuarioActual;
	int opcionUsuario;
	int continuarMenuUsuario=0;
	int rtnAltaProducto;
	int tipoUsuario;
	int continuarAltaProducto=0;
	int rtnAltaCompra;
	int rtnEstadoCompras;
	int rtnEstadoVentasCase1;
	int rtnEstadoVentasCase2;
	int opcionEstadoCompras;
	int continuarMenuAdmin=0;
	int opcionAdmin;
	int rtnListarUsuarios;
	int rtnOrdenarAdmin;
	int rtnBajaProducto;
	int rtnBajaUsuario;
	int rtnListarTrackings;
rel_cargaForzada(arrayUsuarios, CANT_USUARIOS, arrayProductos, CANT_PRODUCTOS, arrayTrackings, CANT_TRACKINGS);
	do
	{
		if(utn_getInt(&opcionIngreso, "\n**************************\n"
				"**1er EXAMEN LAB I - 1H **\n"
				"**************************\n"
				"Ingrese la opcion...\n1.INGRESAR.\n2.REGISTRARSE.\n0.SALIR.","\nError opcion no valida", 0, 2, 5)==0)
		{
			switch(opcionIngreso)
			{
			case 0:
				salir=1;
				break;
			case 1:
				//INGRESO
				indiceUsuarioActual=validarIngreso(arrayUsuarios, CANT_USUARIOS);
				if(indiceUsuarioActual>=0)
				{
					puts("\nINGRESO EXITOSO!");
					if(arrayUsuarios[indiceUsuarioActual].tipo==ADMIN)
					{
						tipoUsuario=ADMIN;
					}
					else
					{
						tipoUsuario=USUARIO;
					}
					switch(tipoUsuario)
					{
					case 1:
						/*-----------------------------------MENU ADMIN---------------------------------*/
						do
						{
							continuarMenuAdmin=0;//REINICIO VARIABLE
							if(utn_getInt(&opcionAdmin, "\n*************************\n**1er EXAMEN LAB I - 1H **\n**********ADMIN*********\n"
								"**************************\n1.LISTAR ESTADO DE LOS USUARIOS.\n2.LISTAR PRODUCTOS POR CATEGORIA."
								"\n3.BAJA DE UN PRODUCTO.\n4.BAJA DE UN USUARIO\n5.TRACKING GLOBAL\n0.SALIR","\nError opcion no valida", 0, 5, 5)==0)
							{
								switch(opcionAdmin)
								{
								case 0:
									continuarMenuAdmin=1;
									break; //SALIR ADMIN
								case 1:
									//LISTAR USUARIOS
									rtnListarUsuarios=eUsuario_imprimirTodosEstado(arrayUsuarios, CANT_USUARIOS,0);
									if(rtnListarUsuarios==0)
									{
										puts("\nFIN DEL LISTADO.");
									}
									else
									{
										if(rtnListarUsuarios==-3)
										{
											puts("\nNo existen usuarios a listar.");
										}
										else
										{
											puts("\nERROR(1-2), en la carga.");
										}
									}
									//FIN LISTAR USUARIOS
									break;
								case 2:
									//LISTAR PRODUCTOS
									rtnOrdenarAdmin=eProductoOrdenarCategoriaAdmin(arrayProductos, CANT_PRODUCTOS);
									if(rtnOrdenarAdmin==0)
									{
										puts("\nFIN DEL LISTADO.");
									}
									else
									{
										if(rtnOrdenarAdmin==-3)
										{
											puts("\nNo existen productos a listar.");
										}
										else
										{
											puts("\nERROR(1-2), en la carga.");
										}
									}
									//FALTA VALIDACIONES
									break;
								case 3:
									//BAJA PRODUCTO
									rtnBajaProducto=eProducto_Baja(arrayProductos, CANT_PRODUCTOS);
									if(rtnBajaProducto>=0)
									{
										puts("\nBAJA EXITOSA!");
									}
									else
									{
										if(rtnBajaProducto==-6)
										{
											puts("Baja cancelada.");
										}
										else
										{
											if(rtnBajaProducto==-3)
											{
												puts("\nNo existen productos a dar de baja.");
											}
											else
											{
												if(rtnBajaProducto==-4 || rtnBajaProducto ==-5)
												{
													puts("\nError ID invalido o no existe.");
												}
												else
												{
													puts("\nERROR(2-1), en la carga.");
												}
											}
										}

									}
									//FALTA VALIDACIONES
									break;
								case 4:
									//BAJA USUARIO
									rtnBajaUsuario=rel_Usuario_Baja(arrayUsuarios, CANT_USUARIOS, arrayProductos, CANT_PRODUCTOS);
									if(rtnBajaUsuario>=0)
									{
										puts("\nBAJA EXITOSA!");
									}
									else
									{
										if(rtnBajaUsuario==-6)
										{
											puts("Baja cancelada.");
										}
										else
										{
											if(rtnBajaUsuario==-3)
											{
												puts("\nNo existen usuarios a dar de baja.");
											}
											else
											{
												if(rtnBajaUsuario==-4 || rtnBajaUsuario ==-5)
												{
													puts("\nError ID invalido o no existe.");
												}
												else
												{
													puts("\nERROR(2-1), en la carga.");
												}
											}
										}

									}
									break;
								case 5:
									//IMPRIMIR TRACKINS
									rtnListarTrackings=eTracking_ImprimirAdmin(arrayTrackings, CANT_TRACKINGS);
									if(rtnListarTrackings==0)
									{
										puts("\nFIN DEL LISTADO.");
									}
									else
									{
										if(rtnListarTrackings==-3)
										{
											puts("\nNo existen trackings a listar.");
										}
										else
										{
											puts("\nERROR(1-2), en la carga.");
										}
									}
									break;
								}
							}
						}while(continuarMenuAdmin==0);
						break;
					case 2:
						/*-----------------------------------MENU USUARIO---------------------------------*/
						do
						{
							continuarMenuUsuario=0; //REINICIO VARIABLE
							if(utn_getInt(&opcionUsuario, "\n*************************\n**1er EXAMEN LAB I - 1H **\n**********USUARIO*********\n"
									"**************************\n1.COMPRAR.\n2.VENDER.\n3.ESTADO COMPRAS.\n4.ESTADO DE VENTAS\n0.SALIR","\nError opcion no valida", 0, 4, 5)==0)
							{
								switch(opcionUsuario)
								{
								case 0://SALIR
									continuarMenuUsuario=1;
									break;

								case 1: //COMPRAR
									//RELACION PRODUCTO TRACKING
									rtnAltaCompra=rel_comprar(arrayUsuarios, CANT_USUARIOS, arrayProductos, CANT_PRODUCTOS, arrayTrackings, CANT_TRACKINGS, indiceUsuarioActual);
									if(rtnAltaCompra>=0)
									{
										puts("\nCOMPRA EXITOSA!");
									}
									else
									{
										if(rtnAltaCompra==-6)
										{
											puts("No existen productos para adquirir.");
										}
										else
										{
											if(rtnAltaCompra==-5)
											{
												puts("\nERROR(5), error en carga de datos.");
											}
											else
											{
												if(rtnAltaCompra==-4 || rtnAltaCompra ==-3)
												{
													puts("\nError ID invalido o no existe.");
												}
												else
												{
													puts("\nERROR(2-1), en la carga.");
												}
											}
										}

									}
									break;
								case 2:	//VENDER (ALTA PRODUCTO)
									do
									{

										rtnAltaProducto=eProducto_Alta(arrayProductos, CANT_PRODUCTOS,arrayUsuarios, CANT_PRODUCTOS,indiceUsuarioActual);
										if(rtnAltaProducto>=0)
										{
											puts("\nCARGA DE PRODUCTO EXITOSA!");
										}
										else
										{
											if(rtnAltaProducto==-3)
											{
												puts("\nERROR(3), lista de productos llena.");
											}
											else
											{
												if(rtnAltaProducto==-4)
												{
													puts("\nAlta cancelada.");
												}
												else
												{
													puts("\nERROR(2-1), en la carga.");
												}
											}
										}
										utn_getInt(&continuarAltaProducto, "¿Desea dar de alta otro producto? SI(1) -- NO (0)", "ERROR, opcion no valida", 0, 1, 5);
									}while(continuarAltaProducto==1);
									break;
								case 3://ESTADO COMPRAS
										rtnEstadoCompras=rel_EstadoCompras(arrayUsuarios, CANT_USUARIOS, arrayProductos, CANT_PRODUCTOS, arrayTrackings, CANT_TRACKINGS, indiceUsuarioActual);
										{
											if(rtnEstadoCompras==0)
											{
												puts("\nCOMPRA CANCELADA");
											}
											else
											{
												if(rtnEstadoCompras==-4)
												{
													puts("\nNo existen compras a cancelar.");
												}
												else
												{
													if(rtnEstadoCompras==-3)
													{
														puts("\nEl usuario no realizo compras al momento.");
													}
													else
													{
													puts("\nERROR(1-2), en la carga.");
													}
												}
											}
										}
									break;
								case 4: //ESTADO VENTAS
									utn_getInt(&opcionEstadoCompras, "\nSELECCIONE EL LISTADO A MOSTRAR.\n1.LISTADO DE VENTAS FINALIZADAS"
											"\n2.PRODUCTOS A LA VENTA", "\nERROR, opcion invalida.", 1, 2, 5);
									switch(opcionEstadoCompras)
									{
									case 1: //LISTADO VENTAS FINALIZADAS
										rtnEstadoVentasCase1=rel_ImprimirVentas(arrayUsuarios, CANT_USUARIOS, arrayProductos, CANT_PRODUCTOS, arrayTrackings, CANT_TRACKINGS, indiceUsuarioActual);
										if(rtnEstadoVentasCase1==0)
										{
											puts("\nFIN DEL LISTADO.");
										}
										else
										{
											if(rtnEstadoVentasCase1==-3)
											{
												puts("\nEl usuario no realizo ventas al momento.");
											}
											else
											{
												puts("\nERROR(1-2), en la carga.");
											}
										}
										break;//BREAK 4.A.
									case 2: //LISTADO DE PRODUCTOS EN VENTA
										rtnEstadoVentasCase2=rel_ImprimirProductos(arrayUsuarios, CANT_USUARIOS, arrayProductos, CANT_PRODUCTOS, arrayTrackings, CANT_TRACKINGS, indiceUsuarioActual);
										if(rtnEstadoVentasCase2==0)
										{
											puts("\nFIN DEL LISTADO.");
										}
										else
										{
											if(rtnEstadoVentasCase2==-3)
											{
												puts("\nEl usuario no publico productos al momento.");
											}
											else
											{
												puts("\nERROR(1-2), en la carga.");
											}
										}
										break;//BREAK 4.B
									default:
										puts("\nERROR, opcion invalida");
										break;
									}
									break;
								}
							}
						}while(continuarMenuUsuario==0);
						//FIN MENU USUARIO
						break;
					default:
						puts("ERROR, tipo de usuario invalido");
						break;
					}
				}
				else //ERRORES INGRESO
				{
					if(indiceUsuarioActual==-6)
					{
						puts("NO EXISTEN USUARIOS DADOS DE ALTA");
					}
					else
					{
						if(indiceUsuarioActual==-5 || indiceUsuarioActual==-3)
						{
							puts("ERROR, Email o Password incorrecto/s.");
						}
						else
						{
							if(indiceUsuarioActual==-4)
							{
								puts("\nNo existe el usuario dado de alta, por favor registrarse.");
							}
							else
							{
								puts("\nERROR(2-1), en la carga.");
							}
						}
					}
				}
				break;
			case 2:
				//ALTA DE USUARIO
				rtnAlta=eUsuario_Alta(arrayUsuarios, CANT_USUARIOS);
				if(rtnAlta>=0)
				{
					puts("\nCARGA DE USUARIOS EXITOSA!");
				}
				else
				{
					if(rtnAlta==-3)
					{
						puts("\nERROR(3), lista de usuarios llena.");
					}
					else
					{
						if(rtnAlta==-4)
						{
							puts("\nAlta cancelada");
						}
						else
						{
							if(rtnAlta==-5)
							{
								puts("DATOS NO VALIDOS VUELVA A REGISTRARSE");
							}
							else
							{
								puts("\nERROR(3-4), en la carga.");
							}
						}
					}
				}
				break;
			}
		}
	}while(salir==0);
	return 0;
}


