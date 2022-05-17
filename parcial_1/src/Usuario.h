/*
 * Usuario.h
 *
 *  Created on: 14 may. 2022
 *      Author: jerel
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 2000
#define CANT_TRACKINGS 4000
#define LIBRE -1
#define ACTIVO 0
#define BAJA 1
#define ADMIN 1
#define USUARIO 2

typedef struct
{
	int idUsuario;
	short int isEmpty;
	int tipo;
	char correo[25];
	char password[10];
	char direccion[50];
	int codPostal;
}Usuario;

/// @fn int validarIngreso(Usuario*, int)
/// @brief valida los datos de un usuario sean correctos y da el ingreso al sistema
///
/// @pre
/// @post
/// @param arrayUsuarios
/// @param tam
/// @return ok (indice del usuario), -5,-3 (Datos ingresados erroneos), -1 -2 ERROR ARRAY
int validarIngreso(Usuario* arrayUsuarios, int tam);

/// @fn int eUsuario_Inicializar(Usuario[], int)
/// @brief Inicializa todo el array de usuarios como LIBRE
///
/// @pre
/// @post
/// @param arrayUsuarios
/// @param tam
/// @return ok (0)
int eUsuario_Inicializar(Usuario arrayUsuarios[], int tam);

/// @fn int eUsuario_BuscarEspacioLibre(Usuario arrayUsuarios[], int tam);
/// @brief busca en todo el array de usuarios el primer indice como LIBRE en su isEmptyS
///
/// @pre
/// @post
/// @param arrayUsuarios
/// @param tam
/// @return ok (0)
int eUsuario_BuscarEspacioLibre(Usuario arrayUsuarios[], int tam);

/// @fn void eUsuario_imprimirUno(Usuario)
/// @brief Imprime un usuario pasado como valor
///
/// @pre
/// @post
/// @param arrayUsuarios
void eUsuario_imprimirUno(Usuario arrayUsuarios);

/// @fn void eUsuario_imprimirUno(Usuario)
/// @brief Imprime un usuario pasado como valor sin encabezado de impresion para usar en bucle
///
/// @pre
/// @post
/// @param arrayUsuarios
void eUsuario_imprimirUnoAuxiliar(Usuario arrayUsuarios);

/// @fn int eUsuario_imprimirTodosEstado(Usuario[], int, int)
/// @brief Imprime todo el array de usuarios segun el valor del estado que recibe como parametre
///
/// @pre
/// @post
/// @param arrayUsuarios
/// @param tam
/// @param soloActivos_1_SI_0_NO Si selecciona 1 se listan unicamente los usuarios activos, 0 los usuarios baja y activos a excepcion del administrador
/// @return ok (cantidad de usuarios listados), -3 (no hay usuarios a listar), (-1,-2) ERROR en array
int eUsuario_imprimirTodosEstado(Usuario arrayUsuarios[], int tam, int soloActivos_1_SI_0_NO);

/// @fn int eUsuarioPedirId(Usuario*, int, int*)
/// @brief Solicita el ingreso de un id dentro del array de usuarios
///
/// @pre
/// @post
/// @param arrayUsuarios
/// @param tam
/// @param auxiliarId devuelve el id por referenciaS
/// @return (0) ok (-1,-2) ERROR en array
int eUsuarioPedirId(Usuario* arrayUsuarios, int tam, int* auxiliarId);

/// @fn int eUsuarioBuscarIndicePorId(Usuario[], int, int)
/// @brief devuelve el indice de un id del array de usuarios que recibe por parametro
///
/// @pre
/// @post
/// @param arrayUsuarios
/// @param tam
/// @param id id a buscar que recibe por parametro
/// @return (ok) indice del id, (-3) no existe el id ingresado, (-1,-2) ERROR en array
int eUsuarioBuscarIndicePorId(Usuario arrayUsuarios[], int tam, int id);

/// @fn int eUsuario_Alta(Usuario[], int)
/// @brief realiza el alta de un usuario y se toman los datos con la funcion eProducto_CargarUnaUsuario();
///
/// @pre
/// @post
/// @param arrayUsuarios
/// @param i
/// @return (ok) indice usuario, -4 alta cancelada, -5 ERROR en ingreso de datos, -3 arrayUsuarios lleno,(-1,-2) ERROR en array
int eUsuario_Alta(Usuario arrayUsuarios[], int i);

/// @fn Usuario eProducto_CargarUnaUsuario()
/// @brief Alta secundaria que toma todos los datos del alta y se retornan como Usuario;
///
/// @pre
/// @post
/// @return ok Usuario con todos sus valores y idUsuario=0, si uno de los datos es incorrecto el valor
/// idUsuario se retorna con -1 y se valida en eUsuario_Alta;
Usuario eProducto_CargarUnaUsuario();

/// @fn int eUsuario_Baja(Usuario[], int)
/// @brief Se realiza la baja de un usuario
///
/// @pre
/// @post
/// @param arrayUsuarios
/// @param i indice del cual realizar la baja
/// @return ok indice de baja, -5 baja cancelada, -4,-3 ID no encontrado o no dado de alta,(-1,-2) ERROR en array
int eUsuario_Baja(Usuario arrayUsuarios[], int i);

#endif /* USUARIO_H_ */
