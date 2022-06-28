/*
 * Controller.h
 *
 *  Created on: 25 jun. 2022
 *      Author: jerel
 */
#include "LinkedList.h"
#include "Salon.h"
#include "Juego.h"
#include "Arcade.h"



#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int myIdGenerator(char* path);
int saveId(int nuevoId,char* path);
int controller_loadSalonFromText(char* path , LinkedList* ll_salon, int* contadorErrores);
int controller_loadArcadeFromText(char* path , LinkedList* ll_arcade, int* contadorErrores);
int controller_loadJuegoFromText(char* path , LinkedList* ll_juego, int* contadorErrores);
//SALON
Salon* Salon_buscarPorId(LinkedList* ll_salones, int auxiliarId, int* index_ll);
int controller_addSalon(LinkedList* ll_salones);
int controller_ListSalones(LinkedList* ll_salones);
int controller_removeSalon(LinkedList* ll_salones,LinkedList* ll_arcade);
//ARCADE
Arcade* Arcade_buscarPorId(LinkedList* ll_arcade, int auxiliarId, int* index_ll);
Arcade* Arcade_buscarPorIdSalon(LinkedList* ll_arcade, int auxiliarId, int* index_ll);
int controller_addArcade(LinkedList* ll_arcades,LinkedList* ll_salones,LinkedList* ll_juegos);
int controller_editArcade(LinkedList* ll_arcade,LinkedList* ll_juegos);
int controller_removeArcade(LinkedList* ll_arcade,LinkedList* ll_juegos);
int printArcadeJuego(Arcade* this, Juego* this_Juego);
int controller_ListArcade(LinkedList* ll_arcade,LinkedList* ll_juegos);
//JUEGO
Juego* Juego_buscarPorId(LinkedList* ll_juegos, int auxiliarId, int* index_ll);
int controller_addJuego(LinkedList* ll_juegos);
int controller_ListJuegos(LinkedList* ll_juegos);
//GUARDAR
int controller_saveAsTextSalon(char* path , LinkedList* ll_salon);
int controller_saveAsTextJuego(char* path , LinkedList* ll_juego);
int controller_saveAsTextArcade(char* path , LinkedList* ll_arcade);





#endif /* CONTROLLER_H_ */
