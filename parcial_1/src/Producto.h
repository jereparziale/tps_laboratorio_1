/*
 * Producto.h
 *
 *  Created on: 14 may. 2022
 *      Author: jerel
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 2000
#define CANT_TRACKINGS 4000
#define LIBRE -1
#define OCUPADO 0
#define BAJA 1
typedef struct
{
	int idProducto;
	int FK_idVendedor;
	short int isEmpty;
	char nombreProducto[25];
	float precio;
	int categoria;
	int stock;
}Producto;

/// @fn int eProducto_Inicializar(Producto[], int)
/// @brief Inicializa todo el array de productos como LIBRE
///
/// @pre
/// @post
/// @param arrayProductos
/// @param tam
/// @return ok (0)
int eProducto_Inicializar(Producto arrayProductos[], int tam);

/// @fn int eProducto_BuscarEspacioLibre(Producto[], int)
/// @brief  busca en todo el array de productos el primer indice como LIBRE en su isEmpty
///
/// @pre
/// @post
/// @param arrayProductos
/// @param tam
/// @return ok (0)
int eProducto_BuscarEspacioLibre(Producto arrayProductos[], int tam);

void eProducto_imprimirUno(Producto arrayProductos);
int eProducto_imprimirTodosEstado(Producto arrayProductos[], int tam, int estado);
void eProducto_imprimirUnoAuxiliar(Producto arrayProductos);

int eProductoPedirId(Producto* arrayProductos, int tam, int* auxiliarId);
int eProductoBuscarIndicePorId(Producto arrayProductos[], int tam, int id,int soloActivos_1_SI_0_NO);

Producto eProducto_CargarUnaProducto();

int eProducto_Baja(Producto arrayProductos[], int i);

int eProductoOrdenarCategoria(Producto arrayProductos[], int tam, int id_FKcomprador);
int eProductoOrdenarCategoriaAdmin(Producto arrayProductos[], int tam);


#endif /* PRODUCTO_H_ */
