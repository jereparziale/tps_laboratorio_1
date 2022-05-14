/*
 * Passenger.h
 *
 *  Created on: 26 abr. 2022
 *      Author: jerel
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

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


typedef struct {
		int id;
		char name[51];
		char lastName[51];
		float price;
		int statusFlight;
		char flycode[10];
		int typePassenger;
		int isEmpty;
	} Passenger;
	/// @brief Realiza un contador de pasajeros activos para crear un flag en el main y no permitir avanzar en demas opciones
	///
	/// @pre
	/// @post
	/// @param list Passenger*
	/// @param len len arrayPassengers
	/// @return retorna la cantidad de pasajeros ocupados, caso contrario -1.
	int ePassenger_CantidadOcupados(Passenger* list, int len);

	/** \brief print the content of passengers array
	*
	* \param list Passenger*
	* \param length int
	* \return int
	*
	*/
	int printPassengers(Passenger* list, int lenght);

	/// @brief imprime unicamente un pasajero recibiendo un auxiliarPasajero.
	///
	/// @pre
	/// @post
	/// @param list recibe el array de pasajeros
	/// @return
	int printPassengerAuxiliar(Passenger* list);

	/// @fn int printPassengerIndice(Passenger*, int)
	/// @brief imprime uno de los pasajeros en la posicion del array indicada
	///
	/// @pre
	/// @post
	/// @param list array de pasajeros.
	/// @param i indice del array a imprimir
	/// @return
	int printPassengerIndice(Passenger* list, int i);
	/** \brief To indicate that all position in the array are empty,
	* this function put the flag (isEmpty) in TRUE in all
	* position of the array
	* \param list Passenger* Pointer to array of passenger
	* \param len int Array length
	* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	*
	*/
	int initPassengers(Passenger* list, int len);

	/// @brief buscar el primer indice del array pasajeros libre
	///
	/// @pre
	/// @post
	/// @param list Pointer to array of passenger
	/// @param tam int Array length
	/// @return retorna el indice libre, caso de no haber libres (-1).
	int buscarEmpty(Passenger* list, int tam);

	/// @brief Alta auxiliar de los datos de un pasajero para luego ser pasados como valor a la funcion addPassenger
	///
	/// @pre
	/// @post
	/// @return retorna un auxiliarPasajero con todos sus datos.
	Passenger AltaPasajero();

	/** \brief add in a existing list of passengers the values received as parameters
	* in the first empty position
	* \param list passenger*
	* \param len int
	* \param id int
	* \param name[] char
	* \param lastName[] char
	* \param price float
	* \param typePassenger int
	* \param flycode[] char
	* \return int Return (-1) if Error [Invalid length or NULL pointer or without
	free space] - (0) if Ok
	*/
	int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,
			int typePassenger, char flycode[]);

	/// @brief lista los pasajeros activos y da elegir al usuario uno de ellos y retorna el id.
	///
	/// @pre
	/// @post
	/// @param list Passenger*
	/// @param tam int
	/// @param auxiliarId int
	/// @return Retorna 0 si es correcto, -2 array null y -3 tam mal definido
	int requestId(Passenger* list, int tam, int* auxiliarId);

	/** \brief find a Passenger by Id en returns the index position in array.
	*
	* \param list Passenger*
	* \param len int
	* \param id int
	* \return Return passenger index position or (-1) if [Invalid length or
	NULL pointer received or passenger not found]
	*
	*/
	int findPassengerById(Passenger* list, int len, int id);

	/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
	*
	* \param list Passenger*
	* \param len int
	* \param id int
	* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
	find a passenger] - (0) if Ok
	*
	*/
	int removePassenger(Passenger* list, int len,int id);

	/// @brief Modificacion auxiliar de los datos de un pasajero para luego ser pasados a la funcion modifyPassenger.
	///
	/// @pre
	/// @post
	/// @param auxiliarPasajero Recibe el pasajero con todos sus datos para luego ser modificados
	/// @param opcionMod Recibe como valor el dato que se va a modificar de ese pasajeros
	/// @return retorna un auxiliarPasajero con todos sus datos.
	Passenger ModificarPasajero(Passenger auxiliarPasajero, int opcionMod);

	/// @brief Recibe como valor el array de pasajeros y permite modificar uno de sus datos a un pasajero.
	///
	/// @pre
	/// @post
	/// @param list Recibe el array de pasajeros
	/// @param len Recibe el tamaño del array de pasajeros
	/// @param id Recibe como valor el Id de pasajero a modificar.
	/// @param opcionMod Recibe como valor el dato que se va a modificar de ese pasajero
	/// @return Retorna el indice del pasajero a modificar.
	int modifyPassenger(Passenger* list, int len, int id, int opcionMod);


	/** \brief Sort the elements in the array of passengers, the argument order
	indicate UP or DOWN order
	*
	* \param list Passenger*
	* \param len int
	* \param order int [1] indicate UP - [0] indicate DOWN
	* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	*
	*/
	int sortPassengers(Passenger* list, int len, int order);

	/// @brief calcula el precio promedio de los pasajes y cuantos pasajeros superan al mismo.
	///
	/// @pre
	/// @post
	/// @param list array de pasajeros.
	/// @param len tamaño del array de pasajeros
	/// @return 0 si el ordenamiento fue exitoso
	int ePassanger_CalcularPrecios(Passenger* list, int len);

	/** \brief Sort the elements in the array of passengers, the argument order
	indicate UP or DOWN order
	*
	* \param list Passenger*
	* \param len int
	* \param order int [1] indicate UP - [0] indicate DOWN
	* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	*
	*/
	int sortPassengersByCode(Passenger* list, int len, int order);








#endif /* PASSENGER_H_ */
