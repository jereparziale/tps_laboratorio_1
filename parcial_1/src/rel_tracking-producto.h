/*
 * rel_tracking-producto.h
 *
 *  Created on: 14 may. 2022
 *      Author: jerel
 */

#ifndef REL_TRACKING_PRODUCTO_H_
#define REL_TRACKING_PRODUCTO_H_
#include "Producto.h"
#include "Usuario.h"
#include "Tracking.h"
#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 2000
#define CANT_TRACKINGS 4000

//CARGA FORZADA
void rel_cargaForzada(Usuario* arrayUsuarios, int tam_usuarios,Producto arrayProductos[], int tam_productos,Tracking arrayTrackings[], int tam_trackings);

//2.1 COMPRA
int eTracking_Alta(Tracking arrayTrackings[], int tam_trackings,Usuario arrayUsuarios[],int tam_usuarios,int FK_idVendedor, int FK_idComprador, int cantidad, int codigoPostal,int FK_idProducto);
int rel_comprar(Usuario* arrayUsuarios, int tam_usuarios,Producto arrayProductos[], int tam_productos,Tracking arrayTrackings[], int tam_trackings,int indiceComprador);

//2.2 VENTA
int eProducto_Alta(Producto arrayProductos[], int tam_arrayProductos,Usuario arrayUsuarios[],int tam_usuarios,int indice_FK_idVendedor);

//2.3 ESTADO COMPRAS
int rel_EstadoCompras(Usuario* arrayUsuarios, int tam_usuarios,Producto arrayProductos[], int tam_productos,Tracking arrayTrackings[], int tam_trackings,int indiceUsuario);
int rel_ImprimirCompras(Usuario* arrayUsuarios, int tam_usuarios,Producto arrayProductos[], int tam_productos,Tracking arrayTrackings[], int tam_trackings, int FK_idComprador);

//2.4 ESTADO VENTAS
//A LISTADO VENTAS FINALZIDAS
int rel_ImprimirVentas(Usuario* arrayUsuarios, int tam_usuarios,Producto arrayProductos[], int tam_productos,Tracking arrayTrackings[], int tam_trackings, int FK_idComprador);
//B LISTADO PRODUCTOS A LA VENTA
int rel_ImprimirProductos(Usuario* arrayUsuarios, int tam_usuarios,Producto arrayProductos[], int tam_productos,Tracking arrayTrackings[], int tam_trackings, int FK_idVendedor);

//BAJA USUARIO Y SUS PRODUCTOS
int rel_Usuario_Baja(Usuario arrayUsuarios[], int tam_arrayUsuarios,Producto arrayProductos[], int tam_productos);


#endif /* REL_TRACKING_PRODUCTO_H_ */
