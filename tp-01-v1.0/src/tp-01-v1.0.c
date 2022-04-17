/*
Parziale Jeremias DNI: 42839805 DIV 1-H
 */

#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include "utn-get.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcionSelectora;
	float kilometrosIngresados;
	int retornoFuncionKilometros;
	float precioAerolineas;
	int retornoFuncionPrecioAerolineas;
	float precioLatam;
	int retornoFuncionPrecioLatam;
	float precioDebitoAerolineas;
	float precioDebitoLatam;
	float precioCreditoAerolineas;
	float precioCreditoLatam;
	float bitcoin;
	float precioBitcoinAerolineas;
	float precioBitcoinLatam;
	float precioKilometroAerolineas;
	float precioKilometroLatam;
	float diferenciaPrecioLatamAerolineas;
	int retornoCase3;
	int case4;
	int case5;
	int finalizar;



	kilometrosIngresados=0;
	precioAerolineas=0;
	precioLatam=0;
	finalizar=0;
	bitcoin=4484008.96;

	do
	{
		menu(&opcionSelectora, kilometrosIngresados,precioAerolineas,precioLatam,bitcoin);
		switch (opcionSelectora)
			{
			case 1:
				retornoFuncionKilometros=utn_getFloat(&kilometrosIngresados, "Ingrese los km. del viaje", "Km. no validos", 1, 1000000,10);
			break;
			case 2:
				retornoFuncionPrecioAerolineas=utn_getFloat(&precioAerolineas, "-Precio vuelo Aerolineas:", "Precio no valido"
						, 0, 5000000,10);
				retornoFuncionPrecioLatam=utn_getFloat(&precioLatam, "-Precio vuelo Latam:", "Precio no valido"
						, 0, 5000000,10);

			break;

			//CASO 3
			case 3:
					if(retornoFuncionKilometros==0 && retornoFuncionPrecioAerolineas==0 && retornoFuncionPrecioLatam==0)
					{
					utn_descuentoRecargoFloat(&precioDebitoAerolineas, precioAerolineas, 10,1, "Error en descuento");
					utn_descuentoRecargoFloat(&precioDebitoLatam, precioLatam, 10,1, "Error en descuento");

					utn_descuentoRecargoFloat(&precioCreditoAerolineas, precioAerolineas, 25, 0,"Error en recargo");
					utn_descuentoRecargoFloat(&precioCreditoLatam, precioLatam, 25, 0,"Error en recargo");

					utn_divFloat(&precioBitcoinAerolineas, precioAerolineas, bitcoin, "Error en valor Bitcoin");
					utn_divFloat(&precioBitcoinLatam, precioLatam, bitcoin, "Error en valor Bitcoin");

					utn_divFloat(&precioKilometroAerolineas, precioAerolineas, kilometrosIngresados, "Error en precio por kilometro");
					utn_divFloat(&precioKilometroLatam, precioLatam, kilometrosIngresados, "Error en precio por kilometro");

					if(precioAerolineas>precioLatam)
					{
						utn_restaFloat(&diferenciaPrecioLatamAerolineas, precioAerolineas, precioLatam, "Error en diferencia de precio");

					}
					else
					{
						utn_restaFloat(&diferenciaPrecioLatamAerolineas, precioLatam, precioAerolineas, "Error en diferencia de precio");
					}

					utn_printfString("Calculos realizados exitosamente!\n");
					retornoCase3=0;
					}
					else
					{
						utn_printfString("ERROR por favor antes de calcular verificar ingreso de los datos 1 y 2\n");
					}

			break;

			//CASO 4
			case 4:
				do
				{

					if(retornoFuncionKilometros==0 && retornoFuncionPrecioAerolineas==0 && retornoFuncionPrecioLatam==0 && retornoCase3==0)
					{
						menuOpcion4(precioAerolineas, precioLatam,precioDebitoAerolineas, precioDebitoLatam, precioCreditoAerolineas, precioCreditoLatam,
												 precioBitcoinAerolineas,  precioBitcoinLatam,  precioKilometroAerolineas,  precioKilometroLatam,
												 diferenciaPrecioLatamAerolineas);
					}
					else
					{
						utn_printfString("ERROR por favor antes de informar resultados debe ingresar datos y/o calcularlos \n");
					}

					utn_getInt(&case4, "Ingrese 1 para volver al menu principal", "ERROR opcion no valida", 1, 1, 10);
				}while(case4==0);

			break;
			case 5:
				do
				{
					kilometrosIngresados=7090;
					precioAerolineas=162965;
					precioLatam=159339;

					utn_descuentoRecargoFloat(&precioDebitoAerolineas, precioAerolineas, 10,1, "Error en descuento");
					utn_descuentoRecargoFloat(&precioDebitoLatam, precioLatam, 10,1, "Error en descuento");
					utn_descuentoRecargoFloat(&precioCreditoAerolineas, precioAerolineas, 25, 0,"Error en recargo");
					utn_descuentoRecargoFloat(&precioCreditoLatam, precioLatam, 25, 0,"Error en recargo");
					utn_divFloat(&precioBitcoinAerolineas, precioAerolineas, bitcoin, "Error en valor Bitcoin");
					utn_divFloat(&precioBitcoinLatam, precioLatam, bitcoin, "Error en valor Bitcoin");
					utn_divFloat(&precioKilometroAerolineas, precioAerolineas, kilometrosIngresados, "Error en precio por kilometro");
					utn_divFloat(&precioKilometroLatam, precioLatam, kilometrosIngresados, "Error en precio por kilometro");
					if(precioAerolineas>precioLatam)
					{
						utn_restaFloat(&diferenciaPrecioLatamAerolineas, precioAerolineas, precioLatam, "Error en diferencia de precio");

					}
					else
					{
						utn_restaFloat(&diferenciaPrecioLatamAerolineas, precioLatam, precioAerolineas, "Error en diferencia de precio");
					}
					menuOpcion4(precioAerolineas, precioLatam,precioDebitoAerolineas, precioDebitoLatam, precioCreditoAerolineas, precioCreditoLatam,
							precioBitcoinAerolineas,  precioBitcoinLatam,  precioKilometroAerolineas,  precioKilometroLatam, 	diferenciaPrecioLatamAerolineas);

					utn_getInt(&case5, "Ingrese 1 para volver al menu principal", "ERROR opcion no valida", 1, 1, 10);
				}while(case5==0);
			break;
			case 6:
				finalizar=1;
				utn_printfString("Fin del programa, gracias por utilizarlo \n");
			break;

			default:
				utn_printfString("Opcion no valida \n");
			}
	}while(finalizar==0);


	return 0;
}
