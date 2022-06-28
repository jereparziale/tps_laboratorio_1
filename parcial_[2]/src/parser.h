#include "LinkedList.h"
int parser_IdFromText(FILE* pFile);
int parser_SalonFromText(FILE* pFile , LinkedList* ll_salon, int* contadorErrores);
int parser_JuegoFromText(FILE* pFile , LinkedList* ll_juego, int* contadorErrores);
int parser_ArcadeFromText(FILE* pFile , LinkedList* ll_arcade, int* contadorErrores);
