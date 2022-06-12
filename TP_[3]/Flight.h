/*
 * CodigoVuelo.h
 *
 *  Created on: 8 may. 2022
 *      Author: jerel
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_
#include "utn_get.h"

typedef struct
{
	char codigoVuelo[10];
	int estadoVuelo;
} Flight;


/// @fn void eFlight_imprimirUno(Flight)
/// @brief imprime un vuelo.
///
/// @pre
/// @post
/// @param list array de pasajeros
void eFlight_imprimirUno(Flight* this);

/// @fn void eFlight_imprimirUnoEncabezado(Flight)
/// @brief anidada con la funcion eFlight_imprimirTodosEstado imprime la fila de los datos del pasajero sin encabezado.
///
/// @pre
/// @post
/// @param list recibe el pasajero.
void eFlight_imprimirUnoEncabezado(Flight* this);

/// @fn int eFlight_imprimirTodosEstado(Flight[], int, int)
/// @brief  imprime todo el array de vuelos segun el estado que se le indique por parametro
///
/// @pre
/// @post
/// @param list recibe el array de vuelos
/// @param tam recibe el tama�o del array de vuelos
/// @param estado recibe el estado del isEmpty por el cual imprimir el array
/// @return 0 si ok, -2 -1 error
int eFlight_imprimirTodosEstado(Flight list[], int tam, int estado);

Flight* eFlight_new();

/// @fn int eFlight_Alta(Flight[], int)
/// @brief Da el alta de un vuelo en el primer indice vacio que se encuentre.
///
/// @pre
/// @post
/// @param list array del vuelos
/// @param tam tama�o del array de vuelos
/// @return retorna el indice del array si ok, -4 si cancela el alta, -1,-2,-3 si error.
Flight* eFlight_newParametros(char* codigoVuelosStr, char* estadoVueloStr);



int Flight_setCodigoVuelo(Flight* this,char* codigoVuelo);
int Flight_setEstadoVuelo(Flight* this,int estadoVuelo);
int Flight_getCodigoVuelo(Flight* this,char* codigoVuelo);//ok
int Flight_getEstadoVuelo(Flight* this,int* estadoVuelo);












#endif /* FLIGHT_H_ */
