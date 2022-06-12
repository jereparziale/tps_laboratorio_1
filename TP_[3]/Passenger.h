/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	int estadoVuelo;

}Passenger;

Passenger* AltaPasajero();

Passenger* Passenger_new();//OK

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr,int* errores);

void Passenger_delete(Passenger* this); //OK

Passenger* AltaPasajero();

Passenger* ModificarPasajero(Passenger* auxiliarPasajero, int opcionMod);


int printPassengerAuxiliar(Passenger* this);

int printPassengers(Passenger* this);

int requestId(int* auxiliarId);

int Passenger_setId(Passenger* this,int id); //OK
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);//OK
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);//OK
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);//OKSSs
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero); //OK
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio); //OK
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo); //OK
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

int Passenger_criterioNombre(void* pasajero1, void* pasajero2);

#endif /* PASSENGER_H_ */
