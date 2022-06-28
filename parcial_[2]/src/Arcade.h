/*int printArcade(Arcade* this)
 *
 * Arcade.h
 *
 *  Created on: 25 jun. 2022
 *      Author: jerel
 */

#ifndef ARCADE_H_
#define ARCADE_H_
typedef struct
{
	int id_arcade;
	char nacionalidad[50];
	int tipoSonido;
	int cantJugadores;
	int maxFichas;
	int FK_idSalon;
	int FK_idJuego;
}Arcade;
int printArcadeAuxiliar(Arcade* this);
int printArcade(Arcade* this);
Arcade* Arcade_new();
Arcade* Arcade_newParametros(char* idStr,char* nacionalidadStr,char* tipoSonido,char* cantJugadores,
		char* maxFichas,char* FK_idSalon, char* FK_idJuego, int* errores);
Arcade* AltaArcade();
void Arcade_delete(Arcade* this);
int Arcade_setId(Arcade* this,int id);
int Arcade_setNacionalidad(Arcade* this,char* nacionalidad);
int Arcade_setTipoSonido(Arcade* this,int tipoSonido);
int Arcade_setCantidadJugadores(Arcade* this,int cantJugadores);
int Arcade_setMaximoFichas(Arcade* this,int maxFichas);
int Arcade_setIdSalon(Arcade* this,int FK_idSalon);
int Arcade_setIdJuego(Arcade* this,int FK_idJuego);
int Arcade_getId(Arcade* this,int* id);
int Arcade_getNacionalidad(Arcade* this,char* nacionalidad);
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido);
int Arcade_getCantidadJugadores(Arcade* this,int* cantJugadores);
int Arcade_getMaximoFichas(Arcade* this,int* maxFichas);
int Arcade_getIdSalon(Arcade* this,int* FK_idSalon);
int Arcade_getIdJuego(Arcade* this,int* FK_idJuego);

int Arcade_criterioNacionalidad(void* arcade1, void* arcade2);


#endif /* ARCADE_H_ */
