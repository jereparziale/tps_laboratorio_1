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



#ifndef LISTADOS_H_
#define LISTADOS_H_

//LISTADOS
int controller_List10A(LinkedList* ll_salones,LinkedList* ll_arcade);
int printB(Arcade* this, Juego* this_Juego, Salon* this_Salon);
int controller_List10B(LinkedList* ll_arcade,LinkedList* ll_juegos, LinkedList* ll_salones);
int controller_List10C(LinkedList* ll_salones);
int controller_List10D(LinkedList* ll_salones,LinkedList* ll_arcade,LinkedList* ll_juegos);
int printE(Arcade* this, Juego* this_juego,int contador);
int controller_List10E(LinkedList* ll_salones,LinkedList* ll_arcade,LinkedList* ll_juegos);
int controller_List10F(LinkedList* ll_salones,LinkedList* ll_arcade);
int printG(Arcade* this, Juego* this_Juego, int contadorOcurrencias);
int controller_List10G(LinkedList* ll_arcade,LinkedList* ll_juegos);
int controller_ListFilterSalon(LinkedList* ll_salones);
int controller_ListFilterArcade(LinkedList* ll_arcade,LinkedList* ll_juegos);





#endif /* CONTROLLER_H_ */
