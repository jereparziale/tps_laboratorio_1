#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "Producto.h"
#include "Usuario.h"
#include "Tracking.h"

static int myId=20000;

static int myIdGenerator()
{
	return myId++;
}

static int myIdProducto=1000;

static int myIdGeneratorProducto()
{
	return myIdProducto++;
}
//CARGA FORZADA
void rel_cargaForzada(Usuario* arrayUsuarios, int tam_usuarios,Producto arrayProductos[], int tam_productos,Tracking arrayTrackings[], int tam_trackings)
{

	//ARRAY USUARIOS
	arrayUsuarios[1].idUsuario=2;
	arrayUsuarios[1].tipo=USUARIO;
	strncpy(arrayUsuarios[1].correo,"ori@.com",25);
	strncpy(arrayUsuarios[1].password,"hola",10);
	arrayUsuarios[1].codPostal=8001;
	arrayUsuarios[1].isEmpty=ACTIVO;

	arrayUsuarios[2].idUsuario=1;
	arrayUsuarios[2].tipo=USUARIO;
	strncpy(arrayUsuarios[2].correo,"jere@gmail.com",25);
	strncpy(arrayUsuarios[2].password,"hola",10);
	arrayUsuarios[2].codPostal=1824;
	arrayUsuarios[2].isEmpty=ACTIVO;


	//USUARIO ADMIN
	arrayUsuarios[3].idUsuario=3;
	arrayUsuarios[3].tipo=ADMIN;
	strncpy(arrayUsuarios[3].correo,"edu@gmail.com",25);
	strncpy(arrayUsuarios[3].password,"hola",10);
	arrayUsuarios[3].codPostal=5000;
	arrayUsuarios[3].isEmpty=ACTIVO;

	/* HARDCODEOS EXTRAS
	//PRIMER PRODUCTO VENDEDOR JERE
	arrayProductos[5].idProducto=1100;
	arrayProductos[5].FK_idVendedor=1;
	arrayProductos[5].isEmpty=OCUPADO;
	strncpy(arrayProductos[5].nombreProducto,"Pichu",25);
	arrayProductos[5].precio=2000;
	arrayProductos[5].categoria=1;
	arrayProductos[5].stock=100;
	//SEGUNDO PRODUCTO VENDEDOR JERE
	arrayProductos[6].idProducto=1101;
	arrayProductos[6].FK_idVendedor=1;
	arrayProductos[6].isEmpty=OCUPADO;
	strncpy(arrayProductos[6].nombreProducto,"Michi",25);
	arrayProductos[6].precio=3000;
	arrayProductos[6].categoria=2;
	arrayProductos[6].stock=200;
	//TERCER PRODUCTO VENDEDOR JERE
	arrayProductos[7].idProducto=1102;
	arrayProductos[7].FK_idVendedor=1;
	arrayProductos[7].isEmpty=OCUPADO;
	strncpy(arrayProductos[7].nombreProducto,"Piojito",25);
	arrayProductos[7].precio=4000;
	arrayProductos[7].categoria=3;
	arrayProductos[7].stock=100;
	//TERCER PRODUCTO VENDEDOR JERE
	arrayProductos[8].idProducto=1103;
	arrayProductos[8].FK_idVendedor=1;
	arrayProductos[8].isEmpty=OCUPADO;
	strncpy(arrayProductos[8].nombreProducto,"Hijitus",25);
	arrayProductos[8].precio=5000;
	arrayProductos[8].categoria=2;
	arrayProductos[8].stock=10;
	//TERCER PRODUCTO VENDEDOR JERE
	arrayProductos[9].idProducto=1104;
	arrayProductos[9].FK_idVendedor=1;
	arrayProductos[9].isEmpty=OCUPADO;
	strncpy(arrayProductos[9].nombreProducto,"Arroba",25);
	arrayProductos[9].precio=5000;
	arrayProductos[9].categoria=2;
	arrayProductos[9].stock=10;

	//COMPRA ORI
	arrayTrackings[5].idTracking=20010;
	arrayTrackings[5].FK_idProducto=1101;
	arrayTrackings[5].FK_idComprador=2;
	arrayTrackings[5].FK_idVendedor=1;
	arrayTrackings[5].cantidad=20;
	arrayTrackings[5].distanciaKm=150;
	arrayTrackings[5].horaLlegada=1;
	arrayTrackings[5].isEmpty=CANCELADO;

	//COMPRA ORI
	arrayTrackings[6].idTracking=20011;
	arrayTrackings[6].FK_idProducto=1100;
	arrayTrackings[6].FK_idComprador=2;
	arrayTrackings[6].FK_idVendedor=1;
	arrayTrackings[6].cantidad=10;
	arrayTrackings[6].distanciaKm=150;
	arrayTrackings[6].horaLlegada=1;
	arrayTrackings[6].isEmpty=ENTREGADO;

	//COMPRA ORI
	arrayTrackings[7].idTracking=20012;
	arrayTrackings[7].FK_idProducto=1103;
	arrayTrackings[7].FK_idComprador=2;
	arrayTrackings[7].FK_idVendedor=1;
	arrayTrackings[7].cantidad=20;
	arrayTrackings[7].distanciaKm=150;
	arrayTrackings[7].horaLlegada=1;
	arrayTrackings[7].isEmpty=ENTREGADO;
	*/
}

//2.1 COMPRA
int eTracking_Alta(Tracking arrayTrackings[], int tam_trackings,Usuario arrayUsuarios[],int tam_usuarios,int FK_idVendedor, int FK_idComprador, int cantidad, int codigoPostal,int FK_idProducto)
{
	int rtn = -1;
	int indiceLibre;
	int kilometrosAuxiliar;
	int segundosAuxiliar;
	long int horaLlegada;
	int estadoAuxiliar;
	Tracking auxiliarTracking;
	if(arrayTrackings != NULL)
	{
		if(tam_trackings >0)
		{
			indiceLibre=eTracking_BuscarEspacioLibre(arrayTrackings,tam_trackings);
			if(indiceLibre>=0)
			{

					auxiliarTracking.idTracking=myIdGenerator(); //CARGAR ID
					auxiliarTracking.FK_idVendedor=FK_idVendedor; //CARGAR ID VENDEDOR
					auxiliarTracking.FK_idComprador=FK_idComprador; //CARGAR ID COMPRADOR
					auxiliarTracking.FK_idProducto=FK_idProducto; //CARGAR ID PRODUCTO
					auxiliarTracking.cantidad=cantidad; //CARGAR CANTIDAD COMPRADA
					auxiliarTracking.isEmpty = OCUPADO;
					//CARGAR KM DE DISTANCIA
					kilometrosAuxiliar=eTrackingCalcularEnvio(arrayTrackings, tam_trackings, codigoPostal,&segundosAuxiliar);
					auxiliarTracking.distanciaKm = kilometrosAuxiliar;
					//CARGAR HORA LLEGADA
					eTrackingCalcularHoraLlegada(arrayTrackings, tam_trackings, segundosAuxiliar,&horaLlegada);
					auxiliarTracking.horaLlegada=horaLlegada;
					//CARGAR ESTADO DEL ENVIO
					eTrackingCalcularEstadoEnvio(arrayTrackings, tam_trackings, horaLlegada, &estadoAuxiliar);
					auxiliarTracking.isEmpty=estadoAuxiliar;
					if(kilometrosAuxiliar>0 && horaLlegada>0 && estadoAuxiliar>0)
					{
						eTracking_imprimirUno(auxiliarTracking);
						arrayTrackings[indiceLibre]=auxiliarTracking;
						rtn= indiceLibre;
					}
					else
					{
						rtn=-5; //CALCULO DE DATOS ERRONEO
					}
			}
			else
			{
				rtn=-3; //ARRAY LLENO
			}
		}
		else
		{
			rtn=-2; //TAM MAL DEFINIDO
		}
	}
	else
	{
		rtn=-1; //ARRAY NULO
	}

	return rtn;
}
int rel_comprar(Usuario* arrayUsuarios, int tam_usuarios,Producto arrayProductos[], int tam_productos,Tracking arrayTrackings[], int tam_trackings,int indiceComprador)
{
	int rtn;
	int idProductoAuxiliar;
	int indiceProducto;
	int stockAuxiliar;
	int totalStock;
	int totalCompra;
	int continuar;
	int FK_idVendedor;
	int FK_idComprador;
	int codigoPostalAuxiliar;
	//int FK_idComprador;
	if(arrayUsuarios != NULL && arrayProductos != NULL && arrayTrackings != NULL)
	{
		if(tam_usuarios>0 && tam_productos >0 && tam_trackings>0)
		{
			FK_idComprador=arrayUsuarios[indiceComprador].idUsuario;
			if(eProductoOrdenarCategoria(arrayProductos, tam_productos,FK_idComprador)==0)
			{
				if(eProductoPedirId(arrayProductos, tam_productos, &idProductoAuxiliar)==0)
				{
					indiceProducto=eProductoBuscarIndicePorId(arrayProductos, tam_productos, idProductoAuxiliar,1);
					if(indiceProducto>=0)
					{
						utn_getInt(&stockAuxiliar, "Ingrese la cantidad del producto a comprar", "ERROR invalido", 1, arrayProductos[indiceProducto].stock, 5);
						utn_restaInt(&totalStock, arrayProductos[indiceProducto].stock, stockAuxiliar, "ERROR, valores invalidos");
						arrayProductos[indiceProducto].stock=totalStock;
						utn_multiInt(&totalCompra, stockAuxiliar, arrayProductos[indiceProducto].precio, "ERROR, valores invalidos");
						printf("El total de la compra son: $%d",totalCompra);
						utn_getInt(&continuar, "\n¿Desea confirmar la compra?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
						if(continuar==1)
						{
							//ALTA TRACKING
							FK_idVendedor=arrayProductos[indiceProducto].FK_idVendedor;
							codigoPostalAuxiliar=arrayUsuarios[indiceComprador].codPostal;
							eTracking_Alta(arrayTrackings, tam_trackings, arrayUsuarios, tam_usuarios, FK_idVendedor, FK_idComprador, stockAuxiliar, codigoPostalAuxiliar,idProductoAuxiliar);
							rtn=0;
						}
						else
						{
							rtn=-5; //OPERACION CANCELADA.
						}
					}
					else
					{
						rtn=-4;//ID NO ENCONTRADO O INEXISTENTE
					}
				}
				else
				{
					rtn =-3; //ID INVALIDO
				}
			}
			else
			{
				rtn=-6; //NO HAY PRODUCTOS PARA COMPRAR
			}
		}
		else
		{
			rtn=-2; //TAM MAL DEFINO
		}
	}
	else
	{
		rtn=-1; //ARRAY NULO
	}
	return rtn;
}

//2.2 VENTA
int eProducto_Alta(Producto arrayProductos[], int tam_arrayProductos,Usuario arrayUsuarios[],int tam_usuarios,int indice_FK_idVendedor)
{
	int rtn = -1;
	int indiceLibre;
	int continuar;
	int FK_idVendedor;
	Producto auxiliarProducto;
	if(arrayProductos != NULL)
	{
		if(tam_arrayProductos >0)
		{
			indiceLibre=eProducto_BuscarEspacioLibre(arrayProductos,tam_arrayProductos);
			if(indiceLibre>=0)
			{
					auxiliarProducto= eProducto_CargarUnaProducto();
					auxiliarProducto.idProducto=myIdGeneratorProducto();
					FK_idVendedor=arrayUsuarios[indice_FK_idVendedor].idUsuario;
					auxiliarProducto.FK_idVendedor=FK_idVendedor;
					eProducto_imprimirUno(auxiliarProducto);
					utn_getInt(&continuar, "\nDESEA GUARDAR Y DAR EL ALTA?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
					if(continuar==1)
					{
						auxiliarProducto.isEmpty = OCUPADO;
						arrayProductos[indiceLibre]=auxiliarProducto;
						rtn= indiceLibre;
					}
					else
					{
						rtn=-4; //OPERACION CANCELADA.
					}
			}
			else
			{
				rtn=-3; //ARRAY LLENO
			}
		}
		else
		{
			rtn=-2; //TAM MAL DEFINIDO
		}
	}
	else
	{
		rtn=-1; //ARRAY NULO
	}

	return rtn;
}

//2.3 ESTADO COMPRAS
int rel_ImprimirCompras(Usuario* arrayUsuarios, int tam_usuarios,Producto arrayProductos[], int tam_productos,Tracking arrayTrackings[], int tam_trackings, int FK_idComprador)
{
	int rtn;
	int i;
	int indiceProductoAuxiliar;
	char auxiliarEstado[15];
	int idProductoAuxiliar;
	char auxiliarCategoria[20];
	int contadorCompras=0;
	if(arrayUsuarios != NULL && arrayProductos != NULL && arrayTrackings != NULL)
	{
		if(tam_usuarios>0 && tam_productos >0 && tam_trackings>0)
		{
			for(i=0;i<tam_trackings;i++)
			{
				if (arrayTrackings[i].FK_idComprador==FK_idComprador)
				{
					contadorCompras++;
				}
			}
			if(contadorCompras>0)
			{
				printf("ID PRODUCTO|CATEGORIA      |NOMBRE         |PRECIO  |ESTADO ENVIO|\n");
				printf("-----------+---------------+---------------+--------+------------+");
				for (i = 0; i < tam_trackings; i++)
				{
					if (arrayTrackings[i].FK_idComprador==FK_idComprador)
					{
						idProductoAuxiliar=arrayTrackings[i].FK_idProducto;
						indiceProductoAuxiliar=eProductoBuscarIndicePorId(arrayProductos, tam_productos, idProductoAuxiliar,0);
						switch(arrayTrackings[i].isEmpty)
						{
						case -2:
							strncpy(auxiliarEstado,"CANCELADO",15);
							break;
						case 1:
							strncpy(auxiliarEstado,"ENTREGADO",15);
							break;
						case 2:
							strncpy(auxiliarEstado,"EN VIAJE",15);
							break;
						}
						switch(arrayProductos[indiceProductoAuxiliar].categoria)
						{
						case 1:
							strncpy(auxiliarCategoria,"Belleza",20);
						break;
						case 2:
							strncpy(auxiliarCategoria,"Muebles",20);
						break;
						case 3:
							strncpy(auxiliarCategoria,"Electrodomesticos",20);
						break;
						case 4:
							strncpy(auxiliarCategoria,"Herramientas",20);
						break;
						case 5:
							strncpy(auxiliarCategoria,"Hogar",20);
						break;
						case 6:
							strncpy(auxiliarCategoria,"Tecnologia",20);
							break;
						}
						printf("\n%-11d|%-15s|%-15s|$%-8.f|%-12s|",arrayProductos[indiceProductoAuxiliar].idProducto,arrayProductos[indiceProductoAuxiliar].nombreProducto,auxiliarCategoria,
								arrayProductos[indiceProductoAuxiliar].precio,auxiliarEstado);
						rtn=0;
					}

				}
			}
			else
			{
				rtn=-3; //NO HAY COMPRAS REALIZADAS
			}
}
		else
		{
			rtn=-2; //TAM MAL DEFINO
		}
	}
	else
	{
		rtn=-1; //ARRAY NULO
	}
	return rtn;
}
int rel_EstadoCompras(Usuario* arrayUsuarios, int tam_usuarios,Producto arrayProductos[], int tam_productos,Tracking arrayTrackings[], int tam_trackings,int indiceUsuario)
{
	int rtn;
	int FK_IdComprador;
	int idProductoModificar;
	int cantidadEnViaje=0;
	int i;
	int opcion;
	int idCorrecto=0;

	if(arrayUsuarios != NULL && arrayProductos != NULL && arrayTrackings != NULL)
	{
		if(tam_usuarios>0 && tam_productos >0 && tam_trackings>0)
		{
			if(eTrackingActualizarEstadoEnvio(arrayTrackings, tam_trackings)>0)
			{
				FK_IdComprador=arrayUsuarios[indiceUsuario].idUsuario;
				if(rel_ImprimirCompras(arrayUsuarios, tam_usuarios, arrayProductos, tam_productos, arrayTrackings, tam_trackings, FK_IdComprador)==0)
				{
					for(i=0;i<tam_trackings;i++)
					{
						if(arrayTrackings[i].isEmpty==EN_VIAJE)
						{
							cantidadEnViaje++;
						}
					}
					if(utn_getInt(&opcion, "\n1.SELECCIONAR UN PRODUCTO A CANCELAR\n0.SALIR", "ERROR, opcion invalida", 0, 1, 5)==0)
					{
						switch(opcion)
						{
						case 0:
							break;
						case 1:
							if(cantidadEnViaje>0)
							{
								do
								{
									utn_getInt(&idProductoModificar, "Ingrese el ID a CANCELAR", "ERROR, ID invalido", 1000, 3000, 5);
									{
										for(i=0;i<tam_productos;i++)
										{
											if(arrayTrackings[i].FK_idComprador==FK_IdComprador && arrayTrackings[i].isEmpty==EN_VIAJE)
											{
												if(idProductoModificar==arrayTrackings[i].FK_idProducto)
												{
													arrayTrackings[i].isEmpty=CANCELADO;
													idCorrecto=1;
													rtn=0;
												}
											}
										}
									}
								}while(idCorrecto==0);
							}
							else
							{
								rtn=-4; //NO HAY COMPRAS EN_VIAJE
							}
						}
					}
				}
				else
				{
					rtn=-3;//NO EXISTEN COMPRAS
				}
			}

		}
		else
		{
			rtn=-2; //TAM MAL DEFINO
		}
	}
	else
	{
		rtn=-1; //ARRAY NULO
	}
	return rtn;
}

//2.4 ESTADO VENTAS
//A LISTADO VENTAS FINALZIDAS
int rel_ImprimirVentas(Usuario* arrayUsuarios, int tam_usuarios,Producto arrayProductos[], int tam_productos,Tracking arrayTrackings[], int tam_trackings, int FK_idVendedor)
{
	int rtn;
	int i;
	int indiceProductoAuxiliar;
	char auxiliarEstado[15];
	int idProductoAuxiliar;
	int auxiliarFK_idVendedor;
	int contadorVentas=0;
	char auxiliarCategoria[20];
	if(arrayUsuarios != NULL && arrayProductos != NULL && arrayTrackings != NULL)
	{
		if(tam_usuarios>0 && tam_productos >0 && tam_trackings>0)
		{
			auxiliarFK_idVendedor=arrayUsuarios[FK_idVendedor].idUsuario;
			for (i = 0; i < tam_trackings; i++)
			{
				if (arrayTrackings[i].FK_idVendedor==auxiliarFK_idVendedor && arrayTrackings[i].isEmpty!=EN_VIAJE)
				{
					contadorVentas++;
				}
			}
			if(contadorVentas>0)
			{
				printf("ID PRODUCTO|CATEGORIA           |NOMBRE         |PRECIO  |ESTADO ENVIO|\n");
				printf("-----------+--------------------+---------------+--------+------------+");
				for (i = 0; i < tam_trackings; i++)
				{
					if (arrayTrackings[i].FK_idVendedor==auxiliarFK_idVendedor && arrayTrackings[i].isEmpty!=EN_VIAJE)
					{
						switch(arrayTrackings[i].isEmpty)
						{
						case 1:
							strncpy(auxiliarEstado,"ENTREGADO",15);
							break;
						case -2:
							strncpy(auxiliarEstado,"CANCELADO",15);
							break;
						}
						switch(arrayProductos[i].categoria)
						{
						case 1:
							strncpy(auxiliarCategoria,"Belleza",20);
						break;
						case 2:
							strncpy(auxiliarCategoria,"Muebles",20);
						break;
						case 3:
							strncpy(auxiliarCategoria,"Electrodomesticos",20);
						break;
						case 4:
							strncpy(auxiliarCategoria,"Herramientas",20);
						break;
						case 5:
							strncpy(auxiliarCategoria,"Hogar",20);
						break;
						case 6:
							strncpy(auxiliarCategoria,"Tecnologia",20);
							break;
						}
						idProductoAuxiliar=arrayTrackings[i].FK_idProducto;
						indiceProductoAuxiliar=eProductoBuscarIndicePorId(arrayProductos, tam_productos, idProductoAuxiliar,0);
						printf("\n%-11d|%-20s|%-15s|$%-7.2f|%-12s|",arrayProductos[indiceProductoAuxiliar].idProducto,auxiliarCategoria,arrayProductos[indiceProductoAuxiliar].nombreProducto,
								arrayProductos[indiceProductoAuxiliar].precio,auxiliarEstado);
						rtn=0;
					}

				}
			}
			else
			{
				rtn=-3; //NO EXISTEN PRODUCTOS EN VENTA
			}

		}
		else
		{
			rtn=-2; //TAM MAL DEFINO
		}
	}
	else
	{
		rtn=-1; //ARRAY NULO
	}
	return rtn;
}
//B LISTADO PRODUCTOS A LA VENTA
int rel_ImprimirProductos(Usuario* arrayUsuarios, int tam_usuarios,Producto arrayProductos[], int tam_productos,Tracking arrayTrackings[], int tam_trackings, int FK_idVendedor)
{
	int rtn = 0;
	int i;
	int auxiliarFK_idVendedor;
	int contadorProductos=0;
	if(arrayUsuarios != NULL && arrayProductos != NULL && arrayTrackings != NULL)
	{
		if(tam_usuarios>0 && tam_productos >0 && tam_trackings>0)
		{
			auxiliarFK_idVendedor=arrayUsuarios[FK_idVendedor].idUsuario;
			for (i = 0; i < tam_productos; i++)
			{
				if (arrayProductos[i].FK_idVendedor==auxiliarFK_idVendedor && arrayProductos[i].stock>0)
				{
					contadorProductos++;
				}
			}
			if(contadorProductos>0)
			{
				printf("ID  |NOMBRE         |PRECIO   |CATEGORIA           |STOCK |\n");
				printf("----+---------------+---------+--------------------+--------+");
				for (i = 0; i < tam_productos; i++)
				{
					if (arrayProductos[i].FK_idVendedor==auxiliarFK_idVendedor && arrayProductos[i].stock>0)
					{
						eProducto_imprimirUnoAuxiliar(arrayProductos[i]);
					}

				}
			}
			else
			{
				rtn=-3; //EL USUARIO NO TIENE PRODUCTOS PUBLICADOS
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

//BAJA USUARIO Y SUS PRODUCTOS
int rel_Usuario_Baja(Usuario arrayUsuarios[], int tam_arrayUsuarios,Producto arrayProductos[], int tam_productos)
{
	int rtn = -1;
	int indiceBaja;
	int continuar;
	int idAuxiliar;
	int i;
	if(arrayUsuarios != NULL)
	{
		if(tam_productos >0)
		{
			if(eUsuario_imprimirTodosEstado(arrayUsuarios, tam_arrayUsuarios, 1)>=0)
			{
				if(eUsuarioPedirId(arrayUsuarios, tam_arrayUsuarios, &idAuxiliar)==0)
				{
					indiceBaja=eUsuarioBuscarIndicePorId(arrayUsuarios,tam_arrayUsuarios,idAuxiliar);
					if(indiceBaja>=0)
					{
						eUsuario_imprimirUno(arrayUsuarios[indiceBaja]);
						utn_getInt(&continuar, "\nDESEA DAR DE BAJA EL ID INGRESADO?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
						if(continuar==1)
						{
							//BAJA PRODUCTOS
							for(i=0;i<tam_productos;i++)
							{
								if(arrayProductos[i].FK_idVendedor==arrayUsuarios[indiceBaja].idUsuario)
								{
									arrayProductos[i].isEmpty=BAJA;
								}
							}
							//BAJA USUARIO
							arrayUsuarios[indiceBaja].isEmpty=BAJA;
							rtn=indiceBaja;
						}
						else
						{
							rtn=-6; //OPERACION CANCELADA.
						}
					}
					else
					{
						rtn=-5; //ID NO ENCONTRADO O NO DADO DE ALTA!
					}
				}
				else
				{
					rtn=-4; //ID NO ENCONTRADO O NO DADO DE ALTA!
				}
			}
			else
			{
				rtn=-3; //NO EXISTEN USUARIOS A DAR DE BAJA
			}
		}
		else
		{
			rtn=-2; //TAM MAL DEFINIDO
		}
	}
	else
	{
		rtn=-1; //ARRAY NULO
	}

	return rtn;
}



