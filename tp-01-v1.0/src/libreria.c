#include "libreria.h"
#include "utn-get.h"
#include <stdio.h>
#include <stdlib.h>



int menu(int *pOpcion, float kilometrosIngresados, float precioAerolineas,float precioLatam, float bitcoin)
{
	int opcionSelectora;
	int retornoFuncion;
	int rtn=-1;
	printf("\n---MENU PRINCIPAL--- \n");
	printf("1. Ingresar Kilómetros: (km=%.2f) \n", kilometrosIngresados);
	printf("2. Ingresar Precio de Vuelos: (Aerolíneas=$ %.2f, Latam=$ %.2f)\n", precioAerolineas, precioLatam);
	printf("--------------------------------------------------------------------\n"
			"3. Calcular todos los costos: \n "
			"A.Tarjeta de débito (descuento 10 %% )\n "
			"B) Tarjeta de crédito (interés 25 %% ) \n "
			"C) Bitcoin (1BTC -> %.2f Pesos Argentinos) \n"
			"D) Mostrar precio por km (precio unitario) \n "
			"E) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n", bitcoin);
	printf("--------------------------------------------------------------------\n"
			"4. Mostrar resultados \n "
			"--------------------------------------------------------------------\n");

	printf("5. Carga forzada de datos \n");
	printf("6. Salir \n");

	retornoFuncion=utn_getInt(&opcionSelectora, "Seleccione la opcion", "Opcion no valida", 1, 6,5);
	if(retornoFuncion==0)
	{
		*pOpcion = opcionSelectora;
		rtn = 0;
	}

	return rtn;
}




int menuOpcion4(float precioAerolineas, float precioLatam,float precioDebitoAerolineas,float precioDebitoLatam,float precioCreditoAerolineas,float precioCreditoLatam,
		float precioBitcoinAerolineas, float precioBitcoinLatam, float precioKilometroAerolineas, float precioKilometroLatam,
		float diferenciaPrecioLatamAerolineas)
{

	printf("RESULTADOS\n");
	printf("-----------------------------------------------\n"
	"Aerolineas: $ %.2f \n"
	"A) Precio con tarjeta de débito: $ %.2f \n"
	"B) Precio con tarjeta de crédito: $ %.2f \n"
	"C) Precio pagando con bitcoin: %.2f BTC \n"
	"D) Precio unitario: $ %.2f \n \n",precioAerolineas, precioDebitoAerolineas,precioCreditoAerolineas, precioBitcoinAerolineas, precioKilometroAerolineas);
	printf("--------------------------------------------------------------------\n"
	"Latam: $ %.2f \n"
	"A) Precio con tarjeta de débito: $ %.2f \n"
	"B) Precio con tarjeta de crédito: $ %.2f \n"
	"C) Precio pagando con bitcoin: %.2f BTC \n"
	"D) Precio unitario: $ %.2f \n", precioLatam,precioDebitoLatam,precioCreditoLatam, precioBitcoinLatam, precioKilometroLatam);
	printf("--------------------------------------------------------------------\n"
	"La diferencia de precio es: $ %.2f\n", diferenciaPrecioLatamAerolineas );
	return 0;
}






