/*
 * PassengerVuelo.h
 *
 *  Created on: 8 may. 2022
 *      Author: jerel
 */

#ifndef PASSENGERVUELO_H_
#define PASSENGERVUELO_H_
#include "Passenger.h"
#include "Flight.h"

/// @fn void cargaForzadaDatos(Passenger*, Flight*)
/// @brief carga forzada de los datos en los array de pasajeros y de vuelos
///
/// @pre
/// @post
/// @param list_Passenger array de pasajeros
/// @param list_flight array de vuelos
void cargaForzadaDatos(Passenger* list_Passenger, Flight* list_flight);

/// @fn int rel_PassengerVuelo_EstadoVuelo(Passenger*, int, Flight*, int)
/// @brief Por motivo de mantener la biblioteca Passanger con todas las funciones pedidas,
/// esta funcion recorre todo el array de pasajeros OCUPADO y actualiza el estado de su vuelo segun el flycode.
///
/// @pre
/// @post
/// @param list_Passenger array de pasajeros
/// @param len_Passenger tamaño del array de pasajeros
/// @param list_Flight array de vuelos
/// @param len_Flight tamaño del array de pasajeros
/// @return
int rel_PassengerVuelo_EstadoVuelo(Passenger* list_Passenger,int len_Passenger, Flight* list_Flight, int len_Flight);

/// @fn int rel_PassengerVuelo_ModificarCodigoVuelo(Passenger*, int, int, Flight*, int)
/// @brief Por motivo de mantener la biblioteca Passanger con todas las funciones pedidas,
/// esta funcion se inicia al seleccionar en el menu de modificacion la opcion de modificar flycode y por lo tanto
/// el estado del vuelo.
///
/// @pre
/// @post
/// @param list_Passenger array de pasajeros
/// @param len_Passenger tamaño del array de pasajeros
/// @param id para buscar el indice donde modificar el flycode
/// @param list_Flight array de vuelos
/// @param len_Flight tamaño del array de vuelos.
/// @return si ok retorna el indice del array modificado, -4 si cancela la modificacion,-1 si no se encuentra el id
/// -2,-3 si error.
int rel_PassengerVuelo_ModificarCodigoVuelo(Passenger* list_Passenger,int len_Passenger, int id, Flight* list_Flight, int len_Flight);




#endif /* PASSENGERVUELO_H_ */
