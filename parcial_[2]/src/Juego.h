/*
 * Juego.h
 *
 *  Created on: 25 jun. 2022
 *      Author: jerel
 */

#ifndef JUEGO_H_
#define JUEGO_H_
typedef struct
{
	int id_juego;
	char nombre[50];
	char empresa[50];
	int genero;
}Juego;
int printJuegoAuxiliar(Juego* this);
int printJuego(Juego* this);
Juego* Juego_new();
Juego* Juego_newParametros(char* idStr,char* nombreStr,char* empresaStr,char* generoStr, int* errores);
Juego* AltaJuego();
void Juego_delete(Juego* this);
int Juego_setId(Juego* this,int id);
int Juego_setNombre(Juego* this,char* nombre);
int Juego_setEmpresa(Juego* this,char* empresa);
int Juego_setTipoJuego(Juego* this,int genero);
int Juego_getId(Juego* this,int* id);
int Juego_getNombre(Juego* this,char* nombre);
int Juego_getEmpresa(Juego* this,char* empresa);
int Juego_getTipoJuego(Juego* this,int* genero);
int Juego_criterioNombre(void* juego1, void* juego2);



#endif /* JUEGO_H_ */
