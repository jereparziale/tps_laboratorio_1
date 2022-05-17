#ifndef UTN_GET_H_
#define UTN_GET_H_
#include <stdio.h>
#include <stdlib.h>

//Cabecera de las funciones utn generales

//CONVERTIR MINUSCULAS A MAYUSCULAS
int cambiarMinusMayus(char pArray[], int tam);

//FUNCION DE ORDENAMIENTO POR BURBUJEO
int ordenarArrayIntDecreciente(int pArray [], int tam, int* contador);

int ordenarArrayIntCreciente(int pArray [], int tam, int* contador);
//FUNCION IMPRIMIR UN ARRAY CON INT
int printfArray(int tamArray, int array []);

//BANDERA MAXIMO
int banderaMaxArrayContador(int array [], int *maximo, int tam);

//BANDERA MINIMO
int banderaMinArrayContador(int array [], int *minimo, int tam);

//PROMEDIO
int calcularPromedioArray(int array [], int tam, float *promedio);

//FUNCION TOMAR UN ARRAY
void cargarArray(int array [], int tam, char* mensaje);

//FUNCION IMPRIMIR ARRAY
void imprimirArray(int array [], int tam);

char utn_getEmail(char pResultado[], char* mensaje, char* mensajeError, int tam, int reintentos);

char getEmail(char* pStringTomado, int tam);

int myGetsEmail(char* cadena, int tam);

char utn_getPassword(char pResultado[], char* mensaje, char* mensajeError, int tam,int tam_minimo, int reintentos);

char getPassword(char* pStringTomado, int tam, int tam_minimo);



//FUNCION IMPRIMIR UN MENSAJE
/// @fn char utn_printfString(char*)
/// @brief funcion de imprimir un mensaje por medio de un printf por string
///
/// @pre
/// @post
/// @param mensaje mensaje a imprimir
/// @return 0
char utn_printfString(char* mensaje);

//FUNCION DE TOMA DE ENTEROS
/// @fn int utn_getInt(int*, char*, char*, int, int, int)
/// @brief toma un numero de tipo int segun un maximo y un minimo, valida y caso contrario se especifica
/// un mensaje de error y una cantidad de reintentos
/// @pre
/// @post
/// @param pResultado	resultado de la funcion, puntero, numero int ingresado
/// @param mensaje mensaje antes de pedir el numero
/// @param mensajeError mensaje en caso de que lo que ingrese el usuario no pase las validaciones
/// @param minimo numero int minimo para ingresar
/// @param maximo numero int maximo para ingresar
/// @param reintentos cantidad de intentos en caso de no pasar las validaciones
/// @return retorna -1 en caso de no cumplir con las validaciones en la cantidad de reintentos y 0 en caso positivo
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

//FUNCION GETINT
int getInt(int *pNumeroTomado);

//MYGETS
int myGets(char* cadena, int tam);

int esNumerica(char cadena[]);



float utn_getFloatNuevo(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int getFloat(float *pNumeroTomado);
int esNumeroDecimal(char cadena[]);

//FUNCION DE TOMA DE NUMERO FLOAT
/// @fn float utn_getFloat(float*, char*, char*, float, float, int)
/// @brief toma un numero de tipo float segun un maximo y un minimo, valida y caso contrario se especifica
/// un mensaje de error y una cantidad de reintentos
/// @pre
/// @post
/// @param pResultado resultado de la funcion, puntero, numero float ingresado
/// @param mensaje mensaje antes de pedir el numero
/// @param mensajeError mensaje en caso de que lo que ingrese el usuario no pase las validaciones
/// @param minimo numero float minimo para ingresar
/// @param maximo numero float maximo para ingresar
/// @param reintentos cantidad de intentos en caso de no pasar las validaciones
/// @return retorna -1 en caso de no cumplir con las validaciones en la cantidad de reintentos y 0 en caso positivo
float utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


//FUNCION DE TOMA DE UN CHAR
/// @fn char utn_getChar(char*, char*, char*, char, char, int)
/// @brief toma un caracter de tipo char segun un maximo y un minimo, valida y caso contrario se especifica
/// un mensaje de error y una cantidad de reintentos
///
/// @pre
/// @post
/// @param pResultado  resultado de la funcion, puntero, caracter char ingresado
/// @param mensaje mensaje antes de pedir el caracter
/// @param mensajeError mensaje en caso de que lo que ingrese el usuario no pase las validaciones
/// @param minimo char  minimo para ingresar
/// @param maximo char  maximo para ingresar
/// @param reintentos cantidad de intentos en caso de no pasar las validaciones
/// @return retorna -1 en caso de no cumplir con las validaciones en la cantidad de reintentos y 0 en caso positivo
char utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

char utn_getString(char pResultado[], char* mensaje, char* mensajeError, int tam, int reintentos);
char getString(char pStringTomado[], int tam);


//FUNCION SUMAR DOS FLOAT
/// @fn float utn_sumaFloat(float*, float, float, char*)
/// @brief Realiza la suma de dos numeros de tipo float anteriormente validados
///
/// @pre
/// @post
/// @param pResultado resultado de la funcion, puntero, suma de ambos numeros.
/// @param numA Primer numero de la suma.
/// @param numB Segundo numero de la suma
/// @param mensajeError mensaje de error en caso de no pasar las validaciones de puntero
/// @return retorna -1 en caso de no cumplir con las validaciones y 0 en caso positivo
float utn_sumaFloat(float* pResultado, float numA, float numB, char* mensajeError);

//FUNCION SUMAR DOS INT
/// @fn int utn_sumaInt(int*, int, int, char*)
/// @brief  Realiza la suma de dos numeros de tipo int anteriormente validados
///
/// @pre
/// @post
/// @param pResultado resultado de la funcion, puntero, suma de ambos numeros.
/// @param numA Primer numero de la suma.
/// @param numB Segundo numero de la suma
/// @param mensajeError mensaje de error en caso de no pasar las validaciones de puntero
/// @return retorna -1 en caso de no cumplir con las validaciones y 0 en caso positivo
int utn_sumaInt(int* pResultado, int numA, int numB, char* mensajeError);

//FUNCION RESTAR DOS FLOAT
/// @fn float utn_restaFloat(float*, float, float, char*)
/// @brief Realiza la resta de dos numeros de tipo float anteriormente validados
///
/// @pre
/// @post
/// @param pResultado resultado de la funcion, puntero, resta de ambos numeros.
/// @param numA Primer numero de la resta.
/// @param numB Segundo numero de la resta
/// @param mensajeError mensaje de error en caso de no pasar las validaciones de puntero
/// @return retorna -1 en caso de no cumplir con las validaciones y 0 en caso positivo
float utn_restaFloat(float* pResultado, float numA, float numB, char* mensajeError);

//FUNCION RESTAR DOS INT
/// @fn int utn_restaInt(int*, int, int, char*)
/// @brief  Realiza la resta de dos numeros de tipo int anteriormente validados
///
/// @pre
/// @post
/// @param pResultado resultado de la funcion, puntero, resta de ambos numeros.
/// @param numA Primer numero de la resta.
/// @param numB Segundo numero de la resta
/// @param mensajeError mensaje de error en caso de no pasar las validaciones de puntero
/// @return retorna -1 en caso de no cumplir con las validaciones y 0 en caso positivo
int utn_restaInt(int* pResultado, int numA, int numB, char* mensajeError);

//FUNCION MULTIPLICAR DOS FLOAT
/// @fn float utn_multiFloat(float*, float, float, char*)
/// @brief  Realiza la multiplicacion de dos numeros de tipo float anteriormente validados
///
/// @pre
/// @post
/// @param pResultado resultado de la funcion, puntero, multiplicacion de ambos numeros.
/// @param numA Primer numero de la multiplicacion.
/// @param numB Segundo numero de la emultiplicacion
/// @param mensajeError mensaje de error en caso de no pasar las validaciones de puntero
/// @return retorna -1 en caso de no cumplir con las validaciones y 0 en caso positivo
float utn_multiFloat(float* pResultado, float numA, float numB, char* mensajeError);

//FUNCION MULTIPLICAR DOS INT
/// @fn float utn_multiFloat(float*, float, float, char*)
/// @brief  Realiza la multiplicacion de dos numeros de tipo int anteriormente validados
///
/// @pre
/// @post
/// @param pResultado resultado de la funcion, puntero, multiplicacion de ambos numeros.
/// @param numA Primer numero de la multiplicacion.
/// @param numB Segundo numero de la remultiplicacion
/// @param mensajeError mensaje de error en caso de no pasar las validaciones de puntero
/// @return retorna -1 en caso de no cumplir con las validaciones y 0 en caso positivo
int utn_multiInt(int* pResultado, int numA, int numB, char* mensajeError);

//FUNCION DIVIDIR DOS FLOAT
/// @fn float utn_divFloat(float*, float, float, char*)
/// @brief  Realiza la division de dos numeros de tipo float anteriormente validados
///
/// @pre
/// @post
/// @param pResultado resultado de la funcion, puntero, division de ambos numeros.
/// @param numA Primer numero de la division.
/// @param numB Segundo numero de la division, debe ser mayor a cero.
/// @param mensajeError mensaje de error en caso de no pasar las validaciones de puntero y que numB sea mayor a 0
/// @return retorna -1 en caso de no cumplir con las validaciones y 0 en caso positivo
float utn_divFloat(float* pResultado, float numA, float numB, char* mensajeError);

//FUNCION DIVIDIR DOS INT
/// @fn int utn_divInt(int*, int, int, char*)
/// @brief  Realiza la division de dos numeros de tipo int anteriormente validados
///
/// @pre
/// @post
/// @param pResultado resultado de la funcion, puntero, division de ambos numeros.
/// @param numA Primer numero de la division.
/// @param numB Segundo numero de la division, debe ser mayor a cero.
/// @param mensajeError mensaje de error en caso de no pasar las validaciones de puntero y que numB sea mayor a 0
/// @return retorna -1 en caso de no cumplir con las validaciones y 0 en caso positivo
int utn_divInt(int* pResultado, int numA, int numB, char* mensajeError);

//FUNCION DE PORCENTAJE CON DESCUENTO O RECARGO
/// @fn float utn_descuentoFloat(float*, float, float, int, char*)
/// @brief Funcion donde se ingresa un numero y un porcentaje a resultar por regla de 3 simple, y segun el parametro
/// descuentoRecargo se realiza un descuento o un recargo
/// @pre
/// @post
/// @param pResultado resultado de la funcion, puntero.
/// @param numero numero de tipo float a realizar la operacion
/// @param porcentaje porcentaje a extraer del numero
/// @param UNOdescuentoCERORecargo Si el parametro es 1 se realiza descuento, si es 0 se realiza un recargo
/// @param mensajeError
/// @return
float utn_descuentoRecargoFloat(float* pResultado, float numero,float porcentaje, int UNOdescuentoCERORecargo,char* mensajeError);




#endif /* UTN_GET_H_ */
