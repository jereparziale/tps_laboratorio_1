#include "Usuario.h"

static int myId=1;

static int myIdGenerator()
{
	return myId++;
}

int validarIngreso(Usuario* arrayUsuarios, int tam)
{
	int rtn = 0;
	char auxiliarCorreo[25];
	char auxiliarPassword[10];
	int contadorUsuarios=0;
	int i;

	if (arrayUsuarios != NULL)
	{
		if (tam > 0)
		{
			for(i=0;i<tam;i++)
			{
				if(arrayUsuarios[i].isEmpty==ACTIVO)
				{
					contadorUsuarios++;
				}
			}
			if(contadorUsuarios>0)
			{
				if(utn_getEmail(auxiliarCorreo, "Ingrese su mail:", "ERROR", 25, 5)==0 &&
				utn_getPassword(auxiliarPassword, "Ingrese su contraseña:", "ERROR", 10,4, 5)==0)
				{
					for(int i=0;i<tam;i++)
					{
						if(arrayUsuarios[i].isEmpty==ACTIVO)
						{
							if(strncmp(arrayUsuarios[i].correo,auxiliarCorreo,25)==0 &&
									strncmp(arrayUsuarios[i].password,auxiliarPassword,10)==0)
							{
								rtn=i;
								break;
							}
							else
							{
								rtn=-5; //EMAIL Y/O CONTRASEÑA INVALIDOS
							}
						}
						else
						{
							rtn=-4; //NO HAY DADOS DE ALTA
						}
					}
				}
				else
				{
					rtn=-3; //EMAIL Y/O CONTRASEÑA INVALIDOS
				}
			}
			else
			{
				rtn=-6; //NO HAY USUARIOS DE ALTA
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

void eUsuario_imprimirUno(Usuario arrayUsuarios)
{
	printf("ID  |CORREO                   |\n");
	printf("----+-------------------------+\n");
	printf("\n%-4d|%-25s|",arrayUsuarios.idUsuario,arrayUsuarios.correo);
}

void eUsuario_imprimirUnoAuxiliar(Usuario arrayUsuarios)
{

	char auxiliarEstado[15];
	switch(arrayUsuarios.isEmpty)
	{
	case 0:
		strncpy(auxiliarEstado,"ACTIVO",15);
		break;
	case 1:
		strncpy(auxiliarEstado,"BAJA",15);
		break;
	default:
	puts("\nERROR, opcion invalida");
	break;
	}
	printf("\n%-4d|%-25s|%-8s|",arrayUsuarios.idUsuario,arrayUsuarios.correo,auxiliarEstado);
}


int eUsuario_imprimirTodosEstado(Usuario arrayUsuarios[], int tam, int soloActivos_1_SI_0_NO)
{
	int rtn = 0;
	int i;
	int contadorUsuarios=0;

	if (arrayUsuarios != NULL)
	{
		if (tam > 0)
		{
			for(i=0;i<tam;i++)
			{
				if(arrayUsuarios[i].isEmpty==ACTIVO && arrayUsuarios[i].tipo != ADMIN)
				{
					contadorUsuarios++;
				}
			}
			if(contadorUsuarios>0)
			{
				switch(soloActivos_1_SI_0_NO)
				{
				case 0:
					printf("ID  |CORREO                   |ESTADO  |\n");
					printf("----+-------------------------+--------+\n");
					for (i = 0; i < tam; i++)
					{
						if (arrayUsuarios[i].isEmpty != LIBRE && arrayUsuarios[i].tipo != ADMIN)
						{
							eUsuario_imprimirUnoAuxiliar(arrayUsuarios[i]);
						}

					}
					break;
				case 1:
					printf("ID  |CORREO                   |ESTADO  |\n");
					printf("----+-------------------------+--------+\n");
					for (i = 0; i < tam; i++)
					{
						if (arrayUsuarios[i].isEmpty == ACTIVO)
						{
							eUsuario_imprimirUnoAuxiliar(arrayUsuarios[i]);
						}

					}
					break;
				default:
					puts("\nERROR, opcion invalida");
				break;
				}
				rtn=0; //EXISTEN USUARIOS
			}
			else
			{
				rtn=-3; //NO EXISTEN USUARIOS A LISTAR
			}
		}
		else
		{
			rtn = -2;
		}
	}
	else
	{
		rtn = -1;
	}
	return rtn;
}



int eUsuario_Inicializar(Usuario arrayUsuarios[], int tam)
{
	int rtn = -1;
	int i;

	if(arrayUsuarios != NULL && tam>0)
	{
		for (i = 0; i < tam; i++)
		{
			arrayUsuarios[i].isEmpty=LIBRE;
			rtn = 0;
		}
	}

	return rtn;
}

int eUsuario_BuscarEspacioLibre(Usuario arrayUsuarios[], int tam)
{
	int rtn = -1;
	int i;

	if(arrayUsuarios != NULL && tam>0)
	{
		for (i = 0; i<tam ; i++)
		{
			if(arrayUsuarios[i].isEmpty==LIBRE)
			{
			rtn = i;
			break;
			}
		}
	}

	return rtn;
}

int eUsuarioPedirId(Usuario* arrayUsuarios, int tam, int* auxiliarId)
{
	int rtn = 0;

	if (arrayUsuarios != NULL)
	{
		if (tam > 0)
		{
			utn_getInt(auxiliarId, "\nIngrese el ID a buscar:", "ERROR", 1, 100, 5);
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

int eUsuarioBuscarIndicePorId(Usuario arrayUsuarios[], int tam, int id)
{
	int rtn = 0;
	int i;
	int flag=0;

	if (arrayUsuarios != NULL)
	{
		if (tam > 0)
		{
			for (i = 0; i < tam; i++)
			{
				if (arrayUsuarios[i].isEmpty == ACTIVO)
				{
					if(arrayUsuarios[i].idUsuario == id)
					{
					rtn = i;
					flag=1;
					break;
					}
				}
			}
			if(flag==0)
			{
				rtn=-3; //NO EXISTE EL ID INDICADO O NO ESTA ACTIVO
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

int eUsuario_Alta(Usuario arrayUsuarios[], int tam)
{
	int rtn = -1;
	int indiceLibre;
	int continuar;
	Usuario auxiliarUsuario;
	if(arrayUsuarios != NULL)
	{
		if(tam >0)
		{
			indiceLibre=eUsuario_BuscarEspacioLibre(arrayUsuarios,tam);
			if(indiceLibre>=0)
			{
					auxiliarUsuario= eProducto_CargarUnaUsuario();
					if(auxiliarUsuario.idUsuario != -1)
					{
						auxiliarUsuario.idUsuario=myIdGenerator();
						eUsuario_imprimirUno(auxiliarUsuario);
						utn_getInt(&continuar, "\nDESEA GUARDAR Y DAR EL ALTA?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
						if(continuar==1)
						{
							auxiliarUsuario.isEmpty = ACTIVO;
							arrayUsuarios[indiceLibre]=auxiliarUsuario;
							rtn= indiceLibre;
						}
						else
						{
							rtn=-4; //OPERACION CANCELADA.
						}
					}
					else
					{
						rtn=-5; //ERROR EN INGRESO DE DATOS
					}
			}
			else
			{
				rtn=-3; //ARRAY LLENO
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

Usuario eProducto_CargarUnaUsuario()
{
	Usuario auxiliarUsuario;
	if(
	utn_getInt(&auxiliarUsuario.tipo, "Ingrese el tipo de usuario ADMIN (1) --- USUARIO (2)", "ERROR, usuario incorrecto", 1, 2, 5)==0 &&
	utn_getEmail(auxiliarUsuario.correo, "Ingrese su email", "ERROR email invalido", 25, 5)==0 &&
	utn_getPassword(auxiliarUsuario.password, "Ingrese su contraseña (min. 4 y max. 10 caracteres)", "ERROR, contraseña invalida", 10,4, 5)==0 &&
	utn_getString(auxiliarUsuario.direccion, "Ingrese su direccion", "ERROR, direccion invalida", 50, 5)== 0&&
	utn_getInt(&auxiliarUsuario.codPostal, "Ingrese su codigo postal", "ERROR, codigo postal incorrecto", 1, 9999, 5)==0
	)
	{
		auxiliarUsuario.idUsuario=0;
	}
	else
	{
		auxiliarUsuario.idUsuario=-1;
	}
	return auxiliarUsuario;

}

int eUsuario_Baja(Usuario arrayUsuarios[], int tam)
{
	int rtn = -1;
	int indiceBaja;
	int continuar;
	int idAuxiliar;
	if(arrayUsuarios != NULL)
	{
		if(tam >0)
		{
			eUsuario_imprimirTodosEstado(arrayUsuarios, tam, 1);
			if(eUsuarioPedirId(arrayUsuarios, tam, &idAuxiliar)==0)
			{
				indiceBaja=eUsuarioBuscarIndicePorId(arrayUsuarios,tam,idAuxiliar);
				if(indiceBaja>=0)
				{
					eUsuario_imprimirUno(arrayUsuarios[indiceBaja]);
					utn_getInt(&continuar, "\nDESEA DAR DE BAJA EL ID INGRESADO?\nIngrese 1 (SI) -- 0 (NO)", "ERROR, opcion no valida", 0, 1, 5);
					if(continuar==1)
					{
						arrayUsuarios[indiceBaja].isEmpty=BAJA;
						rtn=indiceBaja;
					}
					else
					{
						rtn=-5; //OPERACION CANCELADA.
					}
				}
				else
				{
					rtn=-4; //ID NO ENCONTRADO O NO DADO DE ALTA!
				}
			}
			else
			{
				rtn=-3; //ID NO ENCONTRADO O NO DADO DE ALTA!
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

