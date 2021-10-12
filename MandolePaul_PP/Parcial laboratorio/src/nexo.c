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

int estadia_reservarEstadiaConPerroCargado(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro, int* ultimoId)
{
	int ret=-1;
	int idVacio;
	eEstadia auxEstadia;
	int idPerro;
	int indicePerro;
	if(estadia!=NULL && tamEstadia>0 && perro!=NULL && tamPerro>0)
	{
		if(estadia_buscarIndicelibre(estadia, tamEstadia, &idVacio))
		{
			printf("ERROR.En el tamaño o el puntero a estadia.\n");
		}
		if(idVacio!=-1)
		{
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
				//mostrar el perro
				printf("\n%-5s %-20s %-20s %-5s\n\n","ID","NOMBRE","RAZA","EDAD");
				perro_ListarPerro(perro[indicePerro]);
				auxEstadia.idPerro=idPerro;
				auxEstadia.id=*ultimoId;
				if(requestNameOrLastName(auxEstadia.nombreDuenio, "Ingrese el nombre del dueño: ", "ERROR.El nombre no debe contener ningun signo y un maximo de 35 caracteres.\nReingrese el nombre del dueño", 35))
				{
					printf("ERROR.En el puntero a string\n");
				}
				if(requestString(auxEstadia.telefonoContacto,"Ingrese un numero contacto del dueño de la mascota: ", "ERROR.El Numero ingresado no es valido,no debe contener letras o caracteres y debe tener un 10digitos.\nReingrese numero de contacto: ", 10))
				{
					printf("ERROR.En el puntero a num\n");
				}
				//modificar que sea el formato fecha
				if(requestString(auxEstadia.fecha, "ingrese una fecha en formato dia/mes/año: ", "ERROR.El la fecha debe contener el formato dia/mes/año.\nReingrese fecha: ", 10))
				{
					printf("ERROR.En el puntero a string\n");
				}
				//mostrar el aux estadia
				printf("\n%-20s %-20s %-20s %-5s %-20s %-20s\n\n","ID ESTADIA","NOMBRE DUEÑO","CONTACTO","ID PERRO","NOMBRE PERRO","FECHA DE ESTADIA");
				estadia_listarEstadiaConPerro(auxEstadia, perro[indicePerro]);
				if(!requestCharacterAnswer("ingrese (s) para cargar la estadia: "))
				{
					*ultimoId=*ultimoId+1;
					estadia[idVacio]=auxEstadia;
					printf("Se cargo correctamente la estadia.\n");
				}
				else
				{
					printf("Se cancelo la carga de la estadia.\n");
				}
			}
			else
			{
				printf("ERROR.El id ingresado no pertenece a un perro cargado.\n");
			}
		}
		else
		{
			printf("ERROR. No hay Espacio libre para cargar mas estadias\n");
		}
		ret=0;
	}
	return ret;
}

int estadia_listarEstadiasConPerros(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro)
{
	int ret=-1;
	int i;
	int indice;
	if(estadia!=NULL && tamEstadia>0 && perro!=NULL && tamPerro>0)
	{
		printf("\n%-20s %-20s %-20s %-5s %-20s %-20s\n\n","ID ESTADIA","NOMBRE DUEÑO","CONTACTO","ID PERRO","NOMBRE PERRO","FECHA DE ESTADIA");
		for(i=0;i<tamEstadia;i++)
		{
			if(estadia[i].vacio==OCUPADO)
			{
				indice=i;
				if(perro_buscarPerroCargado(perro, tamPerro, &indice, estadia[i].idPerro))
				{
					printf("ERROR.En el puntero a perro o en el tam menor a 0\n");
				}
				estadia_listarEstadiaConPerro(estadia[i], perro[indice]);
			}
		}

		ret=0;
	}
	return ret;
}
void estadia_listarEstadiaConPerro(eEstadia estadia,ePerro perro)
{
	printf("%-20d %-20s %-20s %-5d %-20s %-20s\n",estadia.id,estadia.nombreDuenio,estadia.telefonoContacto,perro.id,perro.nombre,estadia.fecha);
}

