/*
 * CodigoVuelo.h
 *
 *  Created on: 8 may. 2022
 *      Author: jerel
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_
#include "utn_get.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE -1
#define OCUPADO 0
#define BAJA 1
#define PRIMERA_CLASE 1
#define CLASE_EJECUTIVA 2
#define CLASE_ECONOMICA 3
#define VUELO_ACTIVO 1
#define VUELO_EN_ESPERA 2

typedef struct
{
	char flycode[10];
	int statusFlight;
	int isEmpty;
} Flight;

/// @fn int eFlight_CantidadOcupados(Flight[], int)
/// @brief Realiza un contador de vuelos activos para crear un flag en el main y no permitir avanzar en demas opciones
///
/// @pre
/// @post
/// @param list recibe el array de vuelos
/// @param len recibe el tamaño de array de vuelos
/// @return la cantidad de vuelos activos (-2,-3) error
int eFlight_CantidadOcupados(Flight list[], int len);

/// @fn int eFlight_Inicializar(Flight[], int)
/// @brief recorre el array de vuelos indicando que todos estan libres en su dato isEmpty
///
/// @pre
/// @post
/// @param pArray recibe el array de vuelos.
/// @param tam recibe el tamaño del array de vuelos.
/// @return 0 si ok.
int eFlight_Inicializar(Flight list[], int tam);

/// @fn int eFlight_BuscarEspacioLibre(Flight[], int)
/// @brief busca el primer indice libre del array de vuelos
///
/// @pre
/// @post
/// @param list recibe el array de vuelos
/// @param tam recibe el tamaño del array de vuelos
/// @return
int eFlight_BuscarEspacioLibre(Flight list[], int tam);

/// @fn void eFlight_imprimirUno(Flight)
/// @brief imprime un vuelo.
///
/// @pre
/// @post
/// @param list array de pasajeros
void eFlight_imprimirUno(Flight list);

/// @fn void eFlight_imprimirUnoEncabezado(Flight)
/// @brief anidada con la funcion eFlight_imprimirTodosEstado imprime la fila de los datos del pasajero sin encabezado.
///
/// @pre
/// @post
/// @param list recibe el pasajero.
void eFlight_imprimirUnoEncabezado(Flight list);

/// @fn int eFlight_imprimirTodosEstado(Flight[], int, int)
/// @brief  imprime todo el array de vuelos segun el estado que se le indique por parametro
///
/// @pre
/// @post
/// @param list recibe el array de vuelos
/// @param tam recibe el tamaño del array de vuelos
/// @param estado recibe el estado del isEmpty por el cual imprimir el array
/// @return 0 si ok, -2 -1 error
int eFlight_imprimirTodosEstado(Flight list[], int tam, int estado);

/// @fn int eFlight_Alta(Flight[], int)
/// @brief Da el alta de un vuelo en el primer indice vacio que se encuentre.
///
/// @pre
/// @post
/// @param list array del vuelos
/// @param tam tamaño del array de vuelos
/// @return retorna el indice del array si ok, -4 si cancela el alta, -1,-2,-3 si error.
int eFlight_Alta(Flight list[], int tam);

/// @fn Flight eFlight_CargarFlight()
/// @brief Alta auxiliar de los datos de un vuelo para luego ser pasados como valor a la funcion eFlight_Alta
///
/// @pre
/// @post
/// @return retorna un auxiliarVuelo con todos sus datos.
Flight eFlight_CargarFlight();

/// @fn int eFlightBuscarIndicePorCodigo(Flight[], int, char[])
/// @brief busca en el array de vuelos el indice que coincida con el flycode que ingreso por valor
///
/// @pre
/// @post
/// @param list array de vuelos
/// @param tam tamaño del array de vuelos
/// @param flycode codigo de vuelo a buscar en el array
/// @return si ok retorna el estado del vuelo de ese flycode, -1 si no coincide, -2,-3 si error.
int eFlightBuscarIndicePorCodigo(Flight list[], int tam, char flycode[]);












#endif /* FLIGHT_H_ */
