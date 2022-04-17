#ifndef LIBRERIA_H_
#define LIBRERIA2_H_
#include <stdio.h>
#include <stdlib.h>

//Cabecera de las funciones especificas del TP_1

/// @fn int menu(int*, float, float, float, float)
/// @brief Funcion del menu principal en donde se encuentran las opciones 1, 2, 3, 4, 5, y 6.
///
/// @pre
/// @post
/// @param pOpcion	Resultado de la funcion, puntero, numero int validado entre 1 y 6 para elegir la opcion en el main.
/// @param kilometrosIngresados kilometros ingresados del viaje para ser mostrados en el menu
/// @param precioAerolineas precio del vuelo de aerolineas para ser mostrados en el menu
/// @param precioLatam precio del vuelo de aerolinease para ser mostrados en el menu
/// @param bitcoin precio de un BTC en pesos argentinos (ARS) para ser mostrados en el menu
/// @return retorna -1 en caso de no cumplir con las validaciones y 0 en caso positivo
int menu(int *pOpcion, float kilometrosIngresados, float precioAerolineas,float precioLatam, float bitcoin);

/// @fn int menuOpcion4(float, float, float, float, float, float, float, float, float, float, float)
/// @brief Submenu de la opcion 4 y 5 elegidas del menu principal con el objetivo de informar los resultados
///
/// @pre
/// @post
/// @param precioAerolineas parametro para ser mostrado en el submenu
/// @param precioLatam parametro para ser mostrado en el submenu
/// @param precioDebitoAerolineas parametro para ser mostrado en el submenu
/// @param precioDebitoLatam parametro para ser mostrado en el submenu
/// @param precioCreditoAerolineas parametro para ser mostrado en el submenu
/// @param precioCreditoLatam parametro para ser mostrado en el submenu
/// @param precioBitcoinAerolineas parametro para ser mostrado en el submenu
/// @param precioBitcoinLatam parametro para ser mostrado en el submenu
/// @param precioKilometroAerolineas parametro para ser mostrado en el submenu
/// @param precioKilometroLatam parametro para ser mostrado en el submenu
/// @param diferenciaPrecioLatamAerolineas parametro para ser mostrado en el submenu
/// @return
int menuOpcion4(float precioAerolineas, float precioLatam,float precioDebitoAerolineas,float precioDebitoLatam,float precioCreditoAerolineas,float precioCreditoLatam,
		float precioBitcoinAerolineas, float precioBitcoinLatam, float precioKilometroAerolineas, float precioKilometroLatam,
		float diferenciaPrecioLatamAerolineas);
#endif /* LIBRERIA_H_ */
