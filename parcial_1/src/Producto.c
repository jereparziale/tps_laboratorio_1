#include "Producto.h"


void eProducto_imprimirUno(Producto arrayProductos)
{
	char auxiliarCategoria[20];
	switch(arrayProductos.categoria)
	{
	case 1:
		strncpy(auxiliarCategoria,"Belleza",20);
	break;
	case 2:
		strncpy(auxiliarCategoria,"Muebles",20);
	break;
	case 3:
		strncpy(auxiliarCategoria,"Electrodomesticos",20);
	break;
	case 4:
		strncpy(auxiliarCategoria,"Herramientas",20);
	break;
	case 5:
		strncpy(auxiliarCategoria,"Hogar",20);
	break;
	case 6:
		strncpy(auxiliarCategoria,"Tecnologia",20);
		break;
	default:
		puts("\nERROR, opcion invalida");
	break;
	}
	printf("ID  |NOMBRE         |PRECIO   |CATEGORIA           |STOCK |\n");
	printf("----+---------------+---------+--------------------+--------+");
	printf("\n%-4d|%-15s|$%-8.f|%-20s|%-8d",arrayProductos.idProducto,arrayProductos.nombreProducto,arrayProductos.precio,auxiliarCategoria,arrayProductos.stock);
}

void eProducto_imprimirUnoAuxiliar(Producto arrayProductos)
{
	char auxiliarCategoria[20];
	switch(arrayProductos.categoria)
	{
	case 1:
		strncpy(auxiliarCategoria,"Belleza",20);
	break;
	case 2:
		strncpy(auxiliarCategoria,"Muebles",20);
	break;
	case 3:
		strncpy(auxiliarCategoria,"Electrodomesticos",20);
	break;
	case 4:
		strncpy(auxiliarCategoria,"Herramientas",20);
	break;
	case 5:
		strncpy(auxiliarCategoria,"Hogar",20);
	break;
	case 6:
		strncpy(auxiliarCategoria,"Tecnologia",20);
	break;
	default:
		puts("\nERROR, opcion invalida");
	break;
	}
	printf("\n%-4d|%-15s|$%-8.f|%-20s|%-8d",arrayProductos.idProducto,arrayProductos.nombreProducto,arrayProductos.precio,auxiliarCategoria,arrayProductos.stock);
}

int eProducto_imprimirTodosEstado(Producto arrayProductos[], int tam, int estado)
{
	int rtn = 0;
	int i;
	int flag=0;

	if (arrayProductos != NULL)
	{
		if (tam > 0)
		{
			for(i=0;i<tam;i++)
			{
				if(arrayProductos[i].isEmpty == estado)
				{
				flag++;
				}
			}
			if(flag>0)
			{
				printf("ID  |NOMBRE         |PRECIO   |CATEGORIA           |STOCK |\n");
				printf("----+---------------+---------+--------------------+--------+");
				for (i = 0; i < tam; i++)
				{
					if (arrayProductos[i].isEmpty == estado)
					{
						eProducto_imprimirUnoAuxiliar(arrayProductos[i]);
					}

				}
				rtn=0;
			}
			else
			{
				rtn=-3; //NO EXISTEN PRODUCTOS PARA LISTAR
			}
		} else
		{
			rtn = -2;
		}
	} else
	{
		rtn = -1;
	}
	return rtn;
}
int eProducto_Inicializar(Producto arrayProductos[], int tam)
{
	int rtn = -1;
	int i;

	if(arrayProductos != NULL && tam>0)
	{
		for (i = 0; i < tam; i++)
		{
			arrayProductos[i].isEmpty=LIBRE;
			rtn = 0;
		}
	}

	return rtn;
}

int eProducto_BuscarEspacioLibre(Producto arrayProductos[], int tam)
{
	int rtn = -1;
	int i;

	if(arrayProductos != NULL && tam>0)
	{
		for (i = 0; i<tam ; i++)
		{
			if(arrayProductos[i].isEmpty==LIBRE)
			{
			rtn = i;
			break;
			}
		}
	}

	return rtn;
}



Producto eProducto_CargarUnaProducto()
{
	Producto auxiliarProducto;
	utn_getInt(&auxiliarProducto.categoria, "Ingrese la categoria del producto:"
			"\n1.Belleza\n2.Electrodomesticos\n3.Herramientas\n4.Hogar\n5.Muebles\n6.Tecnologia", "ERROR, no existe categoria", 1, 5, 5);
	utn_getFloatNuevo(&auxiliarProducto.precio, "\nIngrese el precio del producto", "ERROR, precio invalido", 1, 9999999, 5);
	utn_getString(auxiliarProducto.nombreProducto, "\nIngrese el nombre del producto", "\nERROR", 25, 5);
	utn_getInt(&auxiliarProducto.stock, "Ingrese el stock disponible", "ERROR, stock invalido", 1, 10000, 5);

	return auxiliarProducto;
}

int eProductoPedirId(Producto* arrayProductos, int tam, int* auxiliarId)
{
	int rtn = 0;

	if (arrayProductos != NULL)
	{
		if (tam > 0)
		{
			utn_getInt(auxiliarId, "\nIngrese el ID a buscar:", "ERROR", 1000, 3000, 5);
			rtn= 0;
		}
		else
		{
			rtn = -2; //TAM MAL DEFINIDO
		}
	}
	else
	{
		rtn = -3; //ARRAY NULO
	}

	return rtn;
}

int eProductoBuscarIndicePorId(Producto arrayProductos[], int tam, int id,int soloActivos_1_SI_0_NO)
{
	int rtn = 0;
	int i;
	int flag=0;

	if (arrayProductos != NULL)
	{
		if (tam > 0)
		{
			switch(soloActivos_1_SI_0_NO)
			{
				case 0:
					for (i = 0; i < tam; i++)
					{
						if (arrayProductos[i].isEmpty != LIBRE)
						{
							if(arrayProductos[i].idProducto == id)
							{
							rtn = i;
							flag=1;
							break;
							}
						}
					}
				break;
				case 1:
					for (i = 0; i < tam; i++)
					{
						if (arrayProductos[i].isEmpty == OCUPADO)
						{
							if(arrayProductos[i].idProducto == id)
							{
							rtn = i;
							flag=1;
							break;
							}
						}
					}
				break;
			}
			if(flag==0)
			{
				rtn=-3; //NO EXISTE EL ID INDICADO O NO ESTA OCUPADO
			}
		}
		else
		{
			rtn = -2; //TAM MAL DEFINIDO
		}
	}
	else
	{
		rtn = -1; //ARRAY NULO
	}

	return rtn;
}

int eProducto_Baja(Producto arrayProductos[], int tam)
{
	int rtn = -1;
	int indiceBaja;
	int continuar;
	int idAuxiliar;
	if(arrayProductos != NULL)
	{
		if(tam >0)
		{
			if(eProducto_imprimirTodosEstado(arrayProductos, tam, OCUPADO)>=0)
			{
				if(eProductoPedirId(arrayProductos, tam, &idAuxiliar)==0)
				{
					indiceBaja=eProductoBuscarIndicePorId(arrayProductos,tam,idAuxiliar,1);
					if(indiceBaja>=0)
					{
						eProducto_imprimirUno(arrayProductos[indiceBaja]);
						utn_getInt(&continuar, "\nDESEA DAR DE BAJA EL ID INGRESADO?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
						if(continuar==1)
						{
							arrayProductos[indiceBaja].isEmpty=BAJA;
							rtn=indiceBaja;
						}
						else
						{
							rtn=-6; //OPERACION CANCELADA.
						}
					}
					else
					{
					rtn=-5; //ID NO ENCONTRADO O NO DADO DE ALTA!
					}
				}
				else
				{
					rtn=-4; //ID NO ENCONTRADO O NO DADO DE ALTA!
				}
			}
			else
			{
				rtn=-3; //NO EXISTEN PRODUCTOS A DAR DE BAJA
			}
		}
		else
		{
			rtn=-2; //TAM MAL DEFINIDO
		}
	}
	else
	{
		rtn=-1; //ARRAY NULO
	}

	return rtn;
}

int eProductoOrdenarCategoria(Producto arrayProductos[], int tam, int id_FKcomprador)
{
	int rtn=-1;
	int flagSwap;
	int flagCantidad=0;
	int i;
	int nuevoTam;
	Producto auxiliarProducto[tam];
	Producto bufferAux;

	if(arrayProductos != NULL)
	{
		if(tam >0)
		{
			eProducto_Inicializar(auxiliarProducto, tam);

			for (i = 0; i < tam; i++)
			{

				if(arrayProductos[i].isEmpty==OCUPADO)
				{
					if(arrayProductos[i].FK_idVendedor != id_FKcomprador && arrayProductos[i].stock>0)
					{
						auxiliarProducto[i]=arrayProductos[i];
						flagCantidad=1;
					}

				}
			}
			if(flagCantidad!=0)
			{
				do
				{
					flagSwap=0;
					nuevoTam= tam-1;
					for (i = 0; i < nuevoTam; i++) //hago tam-1 para que no intercambie con una varibale que no existe
					{
						if(auxiliarProducto[i].isEmpty==OCUPADO && auxiliarProducto[i+1].isEmpty==OCUPADO)
						{
							if (auxiliarProducto[i].categoria>auxiliarProducto[i+1].categoria)
							{
								flagSwap=1;
								bufferAux=auxiliarProducto[i];
								auxiliarProducto[i]=auxiliarProducto[i+1];
								auxiliarProducto[i+1]=bufferAux;
							}
						}
					}
					tam--;
					rtn=0;
				}while(flagSwap);
				puts("PRODUCTOS ORDENADOS POR CATEGORIA");
				eProducto_imprimirTodosEstado(auxiliarProducto, tam, OCUPADO);
			}
		}
	}
	return rtn;
}

int eProductoOrdenarCategoriaAdmin(Producto arrayProductos[], int tam)
{
	int rtn=-1;
	int flagSwap;
	int flagCantidad=0;
	int i;
	int nuevoTam;
	Producto auxiliarProducto[tam];
	Producto bufferAux;

	if(arrayProductos != NULL)
	{
		if(tam >0)
		{
			eProducto_Inicializar(auxiliarProducto, tam);

			for (i = 0; i < tam; i++)
			{
				if(arrayProductos[i].isEmpty==OCUPADO)
				{
					if(arrayProductos[i].stock>0)
					{
						auxiliarProducto[i]=arrayProductos[i];
						flagCantidad=1;
					}

				}
			}
			if(flagCantidad!=0)
			{
				do
				{
					flagSwap=0;
					nuevoTam= tam-1;
					for (i = 0; i < nuevoTam; i++) //hago tam-1 para que no intercambie con una varibale que no existe
					{
						if(auxiliarProducto[i].isEmpty==OCUPADO && auxiliarProducto[i+1].isEmpty==OCUPADO)
						{
							if (auxiliarProducto[i].categoria>auxiliarProducto[i+1].categoria)
							{
								flagSwap=1;
								bufferAux=auxiliarProducto[i];
								auxiliarProducto[i]=auxiliarProducto[i+1];
								auxiliarProducto[i+1]=bufferAux;
							}
						}
					}
					tam--;
					rtn=0;
				}while(flagSwap==1);
				//ORDENO POR NOMBRE DENTRO DE LA CATEGORIA
				do
				{
					flagSwap=0;
					nuevoTam= tam-1;
					for (i = 0; i < nuevoTam; i++) //hago tam-1 para que no intercambie con una varibale que no existe
					{
						if(auxiliarProducto[i].isEmpty==OCUPADO && auxiliarProducto[i+1].isEmpty==OCUPADO)
						{
							if (auxiliarProducto[i].categoria==auxiliarProducto[i+1].categoria)
							{
								if(strncmp(auxiliarProducto[i].nombreProducto,auxiliarProducto[i+1].nombreProducto,25)>0)
								{
									flagSwap=1;
									bufferAux=auxiliarProducto[i];
									auxiliarProducto[i]=auxiliarProducto[i+1];
									auxiliarProducto[i+1]=bufferAux;
								}
							}
						}
					}
					tam--;
					rtn=0;
				}while(flagSwap==1);
				puts("PRODUCTOS ORDENADOS POR CATEGORIA");
				eProducto_imprimirTodosEstado(auxiliarProducto, tam, OCUPADO);
			}
			else
			{
				rtn=-3; //NO HAY PRODUCTOS EN ALTA
			}
		}
		else
		{
			rtn=-2; //TAM MAL DEFINIDO
		}
	}
	else
	{
		rtn=-1; //ARRAY NULO
	}
	return rtn;
}
