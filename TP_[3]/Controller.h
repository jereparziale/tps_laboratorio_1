#include "Passenger.h"
#include "Flight.h"
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int* contadorErrores);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_loadFlightFromText(char* path ,LinkedList* listaVuelos);
int controller_addPassenger(LinkedList* pArrayListPassenger,LinkedList* listaVuelos);
int controller_editPassenger(LinkedList* pArrayListPassenger,LinkedList* listaVuelos);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_ListFlights(LinkedList* listaVuelos);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int myIdGenerator();
int saveId(int nuevoId);
Flight* Flight_buscarPorCodigo(LinkedList* listaVuelos,int* index_ll);
Passenger* Passenger_buscarPorId(LinkedList* pArrayListPassenger, int auxiliarId, int* index_ll);



