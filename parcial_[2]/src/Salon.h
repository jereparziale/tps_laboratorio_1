/*
 * Salon.h
 *
 *  Created on: 25 jun. 2022
 *      Author: jerel
 */

#ifndef SALON_H_
#define SALON_H_
typedef struct
{
	int idSalon;
	char nombre[50];
	char direccion[50];
	int tipoSalon;
}Salon;

int printSalonAuxiliar(Salon* this);
int printSalon(Salon* this);
Salon* Salon_new();
Salon* Salon_newParametros(char* idStr,char* nombreStr,char* direccionStr,char* tipoSalonStr, int* errores);

Salon* AltaSalon();
Salon* ModificarSalon(Salon* auxiliarSalon, int opcionMod);
void Salon_delete(Salon* this);
int requestId(int* auxiliarId);
int Salon_setId(Salon* this,int id);
int Salon_setNombre(Salon* this,char* nombre);
int Salon_setDireccion(Salon* this,char* direccion);
int Salon_setTipoSalon(Salon* this,int tipoSalon);
int Salon_getId(Salon* this,int* id);
int Salon_getNombre(Salon* this,char* nombre);
int Salon_getDireccion(Salon* this,char* direccion);
int Salon_getTipoSalon(Salon* this,int* tipoSalon);
int Salon_criterioNombre(void* salon1, void* salon2);
int Salon_filterTipo(void* salon1);


#endif /* SALON_H_ */
