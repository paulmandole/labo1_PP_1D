/*
 * nexo.c
 *
 *  Created on: 8 oct. 2021
 *      Author: Paul
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "nexo.h"

int perros_listarPerroConMasEstadias(ePerro* perro,int tamPerro,eEstadia* estadia,int tamEstadia)
{
	int ret=-1;
	int contPerroLobo=0;
	int contPerroSheila=0;
	int contPerroReina=0;
	int i;
	if(perro!=NULL && tamPerro>0 && estadia!=NULL && tamEstadia>0)
	{
		for(i=0;i<tamEstadia;i++)
		{
			if(estadia[i].vacio==OCUPADO)
			{
				switch(estadia[i].idPerro)
				{
					case 7000:
						contPerroLobo++;
						break;
					case 7001:
						contPerroSheila++;
						break;
					case 7002:
						contPerroReina++;
						break;
				}
			}

		}

			if(contPerroLobo>contPerroSheila && contPerroLobo>contPerroReina)
			{
				printf("El perro con mas estadias es: \n");
				printf("\n%-5s %-20s %-20s %-5s\n\n","ID","NOMBRE","RAZA","EDAD");
				perro_ListarPerro(perro[0]);
				printf("tiene una cantidad de %d estadias.\n",contPerroLobo);
			}
			else if(contPerroSheila>contPerroLobo && contPerroSheila>contPerroReina)
			{
				printf("El perro con mas estadias es: \n");
				printf("\n%-5s %-20s %-20s %-5s\n\n","ID","NOMBRE","RAZA","EDAD");
				perro_ListarPerro(perro[1]);
				printf("tiene una cantidad de %d estadias.\n",contPerroSheila);
			}
			else
			{
				if(contPerroReina>contPerroSheila && contPerroReina>contPerroLobo)
				{
					printf("El perro con mas estadias es: \n");
					printf("\n%-5s %-20s %-20s %-5s\n\n","ID","NOMBRE","RAZA","EDAD");
					perro_ListarPerro(perro[2]);
					printf("tiene una cantidad de %d estadias.\n",contPerroReina);
				}
				else
				{
					if(contPerroReina==contPerroSheila && contPerroReina==contPerroLobo)
					{
						printf("El perros con mas estadias son: \n");
						printf("\n%-5s %-20s %-20s %-5s\n\n","ID","NOMBRE","RAZA","EDAD");
						for(i=0;i<tamPerro;i++)
						{
							perro_ListarPerro(perro[i]);
						}
						printf("tienen una cantidad de %d estadias.\n",contPerroLobo);
					}
					else if(contPerroReina==contPerroSheila)
					{
						printf("El perros con mas estadias son: \n");
						printf("\n%-5s %-20s %-20s %-5s\n\n","ID","NOMBRE","RAZA","EDAD");
						perro_ListarPerro(perro[2]);
						perro_ListarPerro(perro[1]);

					}
					else if(contPerroReina==contPerroLobo)
					{
						printf("El perros con mas estadias son: \n");
						printf("\n%-5s %-20s %-20s %-5s\n\n","ID","NOMBRE","RAZA","EDAD");
						perro_ListarPerro(perro[2]);
						perro_ListarPerro(perro[0]);
						printf("tienen una cantidad de %d estadias.\n",contPerroLobo);
					}
					else
					{
						printf("El perros con mas estadias son: \n");
						printf("\n%-5s %-20s %-20s %-5s\n\n","ID","NOMBRE","RAZA","EDAD");
						perro_ListarPerro(perro[1]);
						perro_ListarPerro(perro[0]);
						printf("tienen una cantidad de %d estadias.\n",contPerroLobo);
					}
				}

			}

		ret=0;
	}
	return ret;
}
void perro_listarPerroConEstadia(ePerro perro,eEstadia estadia)
{
	printf(" %-5d       %-20s %-20d %d/%d/%d\n",perro.id,perro.nombre,estadia.id,estadia.fecha.dia,estadia.fecha.mes,estadia.fecha.anio);
}

int perros_listarPerrosConSusEstadias(ePerro* perro,int tamPerro,eEstadia* estadia,int tamEstadia)
{
	int ret=-1;
	int i;
	int indice;
	if(estadia!=NULL && tamEstadia>0 && perro!=NULL && tamPerro>0)
	{
		printf("%-5s    %-20s %-20s %-20s\n\n","ID PERRO","NOMBRE PERRO","ID ESTADIA","FECHA DE ESTADIA");
		for(i=0;i<tamEstadia;i++)
		{
			if(estadia[i].vacio==OCUPADO)
			{
				perro_buscarPerroCargado(perro, tamPerro, &indice, estadia[i].idPerro);
				perro_listarPerroConEstadia(perro[indice], estadia[i]);
			}

		}

		ret=0;
	}
	return ret;
}

void estadia_swapEstadias(eEstadia* estadia,int tamEstadia,int i)
{
	eEstadia auxEstadia;

	auxEstadia=estadia[i];
	estadia[i]=estadia[i+1];
	estadia[i+1]=auxEstadia;
}

int estadia_ordenarPorfechaYNombre(eEstadia* estadia,int tamEstadia,eDuenio* duenio,int tamDuenio)
{
	int ret=-1;
	int i;
	int flagSwap;
	int newLimite;
	int indiceDuenio;
	int indiceDuenio2;

	if(estadia!=NULL && tamEstadia>0)
	{
		newLimite=tamEstadia;
		do
		{
			flagSwap=0;
			for(i=0;i<newLimite;i++)
			{
				if(estadia[i].vacio==OCUPADO && estadia[i+1].vacio==OCUPADO)
				{
					if(estadia[i].fecha.anio<estadia[i+1].fecha.anio)
					{
						estadia_swapEstadias(estadia, tamEstadia, i);
						flagSwap=1;
					}
					else if(estadia[i].fecha.anio==estadia[i+1].fecha.anio)
					{
						if(estadia[i].fecha.mes<estadia[i+1].fecha.mes)
						{
								estadia_swapEstadias(estadia, tamEstadia, i);
								flagSwap=1;
						}
						else if(estadia[i].fecha.mes==estadia[i+1].fecha.mes)
						{
							if(estadia[i].fecha.dia<estadia[i+1].fecha.dia)
							{
								estadia_swapEstadias(estadia, tamEstadia, i);
								flagSwap=1;
							}
							else if(estadia[i].fecha.dia==estadia[i+1].fecha.dia)
							{
								duenio_buscarDuenioCargado(duenio, tamDuenio, &indiceDuenio, estadia[i].idDuenio);
								duenio_buscarDuenioCargado(duenio, tamDuenio, &indiceDuenio2, estadia[i+1].idDuenio);
								if(strcmp(duenio[indiceDuenio].nombre,duenio[indiceDuenio2].nombre)==1)
								{
									estadia_swapEstadias(estadia, tamEstadia, i);
									flagSwap=1;
								}
							}
						}
					}
				}
			}

			newLimite--;
		}while(flagSwap);
		ret=0;
	}
	return ret;
}


int estadia_modificarEstadiaDePerro(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro,eDuenio* duenio,int tamDuenio)
{
	int ret=-1;
	int idEstadia;
	int indice;
	int indicePerro;
	int opcion;
	int idPerro;
	int indiceDuenio;

	eEstadia auxEstadia;
	eDuenio auxDuenio;
	if(estadia!=NULL && perro!=NULL && tamEstadia>0 && tamPerro>0)
	{
		if(estadia_listarEstadiasConPerros(estadia, tamEstadia, perro, tamPerro,duenio ,tamDuenio))
		{
			printf("ERROR.En el puntero a perro , estadia o tamanio de los array menor a 0.\n");
		}
		if(requestNumber(&idEstadia, "Ingrese el Id de la estadia a modificar: ", "ERROR.El id Ingresado no es valido.\nReingrese id de Estadia: ", 100000, 200000))
		{
			printf("ERROR.En el puntero a mensaje ,numero o mensaje error.\n");
		}
		if(estadia_buscarEstadiaCargada(estadia, tamEstadia, &indice, idEstadia))
		{
			printf("ERROR.En el puntero estadia o tamanio de array menor a 0.\n");
		}
		if(indice!=-1)
		{

			perro_buscarPerroCargado(perro, tamPerro, &indicePerro, estadia[indice].idPerro);
			duenio_buscarDuenioCargado(duenio, tamDuenio, &indiceDuenio, estadia[indice].idDuenio);
			estadia_listarEstadiaConPerro(estadia[indice], perro[indicePerro],duenio[indiceDuenio]);
			printf("\n");

			do
			{
				perro_buscarPerroCargado(perro, tamPerro, &indicePerro, estadia[indice].idPerro);
				duenio_buscarDuenioCargado(duenio, tamDuenio, &indiceDuenio, estadia[indice].idDuenio);
				auxEstadia=estadia[indice];
				requestNumber(&opcion,		 "-------------------------------------\n"
											 "1. MODIFICAR telefono de contacto\n"
											 "2. MODIFICAR Perro\n"
											 "3. ATRAS\n"
											 "-------------------------------------\n"
											 "Ingrese una opcion: ",
											 "-------------------------------------\n"
											 "1. MODIFICAR telefono de contacto\n"
											 "2. MODIFICAR Perro\n"
											 "3. ATRAS\n"
											 "-------------------------------------\n"
											 "Opcion invalida, reingrese: ", 1,3);
				switch(opcion)
				{
					case 1:

						estadia_listarEstadiaConPerro(estadia[indice], perro[indicePerro],duenio[indiceDuenio]);
						duenio_buscarDuenioCargado(duenio, tamDuenio, &indiceDuenio, estadia[indice].idDuenio);
						auxDuenio=duenio[indiceDuenio];
						requestNumberPhone(auxDuenio.contacto, "Ingrese el nuevo contacto del duenio: ", "ERROR.El contacto ingresado no puede contener letras,signos y debe tener 10 digitos.\nReingrese contacto: ", 10);

						printf("\nEstadia luego de la modificacion: \n\n");
						estadia_listarEstadiaConPerro(estadia[indice], perro[indicePerro],auxDuenio);
						if(!requestCharacterAnswer("ingrese (s) para modificar la estadia: "))
						{
							duenio[indiceDuenio]=auxDuenio;
							printf("\n\nLa modificacion se realizo correctamente.\n\n");
						}
						else
						{
							printf("\n\nSe cancelo la modificacion del contacto.\n\n");
						}

						break;
					case 2:
						estadia_listarEstadiaConPerro(estadia[indice], perro[indicePerro],duenio[indiceDuenio]);
						printf("\n\n");
						if(perro_ListarPerros(perro, tamPerro))
						{
							printf("ERROR.En el puntero perro o tamanio de array menor a 0.\n");
						}
						if(requestNumber(&idPerro, "Ingrese el id del perro que estara en la estadia: ", "ERROR.El numero ingresado es invalido, no puede contener caracteres,signos y el rango es (7000 a 8000).\nReingrese id del perro que estara en la estadia: ", 7000, 8000))
						{
							printf("ERROR.En el puntero a num\n");
						}
						if(perro_buscarPerroCargado(perro, tamPerro, &indicePerro, idPerro))
						{
							printf("ERROR.En el puntero a perro o en el tam menor a 0\n");
						}

						if(indicePerro!=-1)
						{
							auxEstadia.idPerro=idPerro;
							printf("\nEstadia luego de la modificacion: \n\n");
							printf("\n%-20s %-20s %-20s %-5s    %-20s %-20s\n\n","ID ESTADIA","NOMBRE DUEÑO","CONTACTO","ID PERRO","NOMBRE PERRO","FECHA DE ESTADIA");
							estadia_listarEstadiaConPerro(estadia[indice], perro[indicePerro],duenio[indiceDuenio]);
							if(!requestCharacterAnswer("ingrese (s) para modificar la estadia: "))
							{
								estadia[indice]=auxEstadia;
								printf("\n\nLa modificacion se realizo correctamente.\n\n");
							}
							else
							{
								printf("\n\nSe cancelo la modificacion del Perro.\n\n");
							}

						}
						else
						{
							printf("\n\nERROR.El id ingresado no pertenece a un perro cargado.\n");
						}

						break;
					case 3:
						printf("\nSe regreso al menu anterior.\n");
						break;
				}

			}while(opcion!=3);



		}
		else
		{
			printf("\n\nERROR.El id ingresado no se encuentra cargado.\n");
		}


		ret=0;
	}
	return ret;
}
int estadia_eliminarEstadiaDePerro(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro,eDuenio* duenio,int tamDuenio,int* contEstadias)
{
	int ret=-1;
	int idEstadia;
	int indice;
	int indicePerro;
	int indiceDuenio;
	if(estadia!=NULL && perro!=NULL && tamEstadia>0 && tamPerro>0)
	{
		if(estadia_listarEstadiasConPerros(estadia, tamEstadia, perro, tamPerro,duenio ,tamDuenio))
		{
			printf("ERROR.En el puntero a perro , estadia o tamanio de los array menor a 0.\n");
		}
		if(requestNumber(&idEstadia, "Ingrese el Id de la estadia a dar de baja: ", "ERROR.El id Ingresado no es valido.\nReingrese id de Estadia: ", 100000, 200000))
		{
			printf("ERROR.En el puntero a mensaje ,numero o mensaje error.\n");
		}
		if(estadia_buscarEstadiaCargada(estadia, tamEstadia, &indice, idEstadia))
		{
			printf("ERROR.En el puntero estadia o tamanio de array menor a 0.\n");
		}
		if(indice!=-1)
		{
			perro_buscarPerroCargado(perro, tamPerro, &indicePerro, estadia[indice].idPerro);
			duenio_buscarDuenioCargado(duenio, tamDuenio, &indiceDuenio, estadia[indice].idDuenio);
			estadia_listarEstadiaConPerro(estadia[indice], perro[indicePerro],duenio[indiceDuenio]);
			printf("\n");
			if(!requestCharacterAnswer("ingrese (s) para dar de baja la estadia: "))
			{
				*contEstadias=*contEstadias-1;
				estadia[indice].vacio=LIBRE;
				printf("\n\nLa baja se realizo correctamente.\n\n");
			}
			else
			{
				printf("\n\nSe cancelo la baja de la estadia.\n\n");
			}

		}
		else
		{
			printf("\n\nERROR.El id ingresado no se encuentra cargado.\n");
		}
		ret=0;
	}
	return ret;
}

int estadia_reservarEstadiaConPerroCargado(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro, eDuenio* duenio,int tamDuenio, int* ultimoId,int* contEstadias)
{
	int ret=-1;
	int idVacio;
	eEstadia auxEstadia;
	int idPerro;
	int idDuenio;
	int indicePerro;
	int indiceDuenio;
	if(estadia!=NULL && tamEstadia>0 && perro!=NULL && tamPerro>0)
	{
		if(estadia_buscarIndicelibre(estadia, tamEstadia, &idVacio))
		{
			printf("ERROR.En el tamaño o el puntero a estadia.\n");
		}
		if(idVacio!=-1)
		{
			if(perro_ListarPerros(perro, tamPerro))
			{
				printf("ERROR.En el tamaño o el puntero a perro.\n");
			}
			if(requestNumber(&idPerro, "Ingrese el id del perro que estara en la estadia: ", "ERROR.El numero ingresado es invalido, no puede contener caracteres,signos y el numero maximo es 8000.\nReingrese id del perro que estara en la estadia: ", 7000, 8000))
			{
				printf("ERROR.En el puntero a num\n");
			}
			if(perro_buscarPerroCargado(perro, tamPerro, &indicePerro, idPerro))
			{
				printf("ERROR.En el puntero a perro o en el tam menor a 0\n");
			}
			if(indicePerro!=-1)
			{
				printf("\n%-5s %-20s %-20s %-5s\n\n","ID","NOMBRE","RAZA","EDAD");
				perro_ListarPerro(perro[indicePerro]);
				printf("\n");
				auxEstadia.idPerro=idPerro;
				duenio_listarDuenios(duenio, tamDuenio);
				requestNumber(&idDuenio, "INgrese el id del Duenio q estara en el estadia: ",  "ERROR.El numero ingresado es invalido, no puede contener caracteres,signos y el numero  minimo es 30000 y maximo es 30002.\nReingrese id duenio que estara en la estadia: ", 30000, 30002);
				duenio_buscarDuenioCargado(duenio, tamDuenio, &indiceDuenio, idDuenio);
				if(indiceDuenio!=-1)
				{
					printf("\n%-5s %-20s %-20s\n\n","ID","NOMBRE","CONTACTO");
					duenio_listarDuenio(duenio[indiceDuenio]);
					printf("\n");
					auxEstadia.idDuenio=idDuenio;
				}
				auxEstadia.id=*ultimoId;
				auxEstadia.vacio=OCUPADO;
				requestDate(&auxEstadia.fecha.dia, &auxEstadia.fecha.mes, &auxEstadia.fecha.anio);
				printf("\n%-20s %-20s %-20s %-5s    %-20s %-20s\n\n","ID ESTADIA","NOMBRE DUEÑO","CONTACTO","ID PERRO","NOMBRE PERRO","FECHA DE ESTADIA");

				estadia_listarEstadiaConPerro(auxEstadia, perro[indicePerro],duenio[indiceDuenio]);
				printf("\n");
				if(!requestCharacterAnswer("ingrese (s) para cargar la estadia: "))
				{
					*ultimoId=*ultimoId+1;
					*contEstadias=*contEstadias+1;
					estadia[idVacio]=auxEstadia;
					printf("\n\nSe cargo correctamente la estadia.\n");
				}
				else
				{
					printf("\n\nSe cancelo la carga de la estadia.\n");
				}
			}
			else
			{
				printf("\n\nERROR.El id ingresado no pertenece a un perro cargado.\n");
			}
		}
		else
		{
			printf("\n\nERROR. No hay Espacio libre para cargar mas estadias\n");
		}
		ret=0;
	}
	return ret;
}

int estadia_listarEstadiasConPerros(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro,eDuenio* duenio,int tamDuenio)
{
	int ret=-1;
	int i;
	int indice;
	int indiceDuenio;
	if(estadia!=NULL && tamEstadia>0 && perro!=NULL && tamPerro>0 && duenio!=NULL && tamDuenio>0)
	{
		printf("\n%-20s %-20s %-20s %-5s    %-20s %-20s\n\n","ID ESTADIA","NOMBRE DUEÑO","CONTACTO","ID PERRO","NOMBRE PERRO","FECHA DE ESTADIA");
		for(i=0;i<tamEstadia;i++)
		{
			if(estadia[i].vacio==OCUPADO)
			{
				indice=i;
				if(perro_buscarPerroCargado(perro, tamPerro, &indice, estadia[i].idPerro))
				{
					printf("ERROR.En el puntero a perro o en el tam menor a 0\n");
				}
				duenio_buscarDuenioCargado(duenio, tamDuenio, &indiceDuenio, estadia[i].idDuenio);
				estadia_listarEstadiaConPerro(estadia[i], perro[indice],duenio[indiceDuenio]);
			}
		}
		printf("\n");

		ret=0;
	}
	return ret;
}

void estadia_listarEstadiaConPerro(eEstadia estadia,ePerro perro,eDuenio duenio)
{
	printf("%-20d %-20s %-20s %-5d       %-20s %d/%d/%d\n",estadia.id,duenio.nombre,duenio.contacto,perro.id,perro.nombre,estadia.fecha.dia,estadia.fecha.mes,estadia.fecha.anio);
}

