/*
 * Tracking.h
 *
 *  Created on: 14 may. 2022
 *      Author: jerel
 */

#ifndef TRACKING_H_
#define TRACKING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn_get.h"
#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 2000
#define CANT_TRACKINGS 4000
#define CANCELADO -2
#define LIBRE -1
#define OCUPADO 0
#define ENTREGADO 1
#define EN_VIAJE 2
#define ADMIN 1
#define USUARIO 2

typedef struct
{
	int idTracking;
	int FK_idVendedor;
	int FK_idComprador;
	int FK_idProducto;
	int isEmpty;
	int cantidad;
	int distanciaKm;
	long int horaLlegada;
}Tracking;
//FUNCIONES TIME
long int time_Add(double secondsAdd);
long int time_Current(void);

//INICIALIZAR Y LIBRE
int eTracking_Inicializar(Tracking arrayTrackings[], int tam);
int eTracking_BuscarEspacioLibre(Tracking arrayTrackings[], int tam);

void eTracking_imprimirUnoAuxiliar(Tracking arrayTrackings);
void eTracking_imprimirUno(Tracking arrayTrackings);
int eTracking_ImprimirAdmin(Tracking arrayTrackings[], int tam);

//BUSCAR ID/INDICE
int eTrackingPedirId(Tracking* arrayTrackings, int tam, int* auxiliarId);
int eTrackingBuscarIndicePorId(Tracking arrayTrackings[], int tam, int id);

//CALCULAR
int eTrackingCalcularEnvio(Tracking* arrayTrackings, int tam,int codigoPostal, int* segundosS);
int eTrackingCalcularEstadoEnvio(Tracking* arrayTrackings, int tam, long int horaLlegada,int* estado);
int eTrackingCalcularHoraLlegada(Tracking* arrayTrackings, int tam, int segundos,long int* horaLlegada);
int eTrackingActualizarEstadoEnvio(Tracking* arrayTrackings, int tam);









#endif /* TRACKING_H_ */
