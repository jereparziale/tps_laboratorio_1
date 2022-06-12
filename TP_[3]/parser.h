#include "LinkedList.h"
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger,int* contadorErrores);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_FlightFromText(FILE* pFile ,LinkedList* listaVuelos,int tam);
int parser_IdFromText(FILE* pFile);
