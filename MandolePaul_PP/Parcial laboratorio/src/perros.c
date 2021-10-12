/*
 * perros.c
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
#define OCUPADO 1
#define LIBRE 0


void perro_ListarPerro(ePerro perro)
{
	printf("%-5d %-20s %-20s %-5d\n",perro.id,perro.nombre,perro.raza,perro.edad);
}
int perro_ListarPerros(ePerro* perro,int tam)
{
	int ret=-1;
	if(perro!=NULL && tam>0)
	{
		printf("\n%-5s %-20s %-20s %-5s\n\n","ID","NOMBRE","RAZA","EDAD");
		for(int i=0;i<tam;i++)
		{
			if(perro[i].vacio==OCUPADO)
			{
				perro_ListarPerro(perro[i]);
			}
		}
		ret=0;
	}
	return ret;
}
int perro_inicializarPerros(ePerro* perro,int tam)
{
	int ret=-1;
	if(perro!=NULL && tam>0)
	{
		for(int i=3;i<tam;i++)
		{
			perro[i].vacio=LIBRE;
		}
		ret=0;
	}
	return ret;
}

int perro_buscarIndicelibre(ePerro* perro,int tam, int* indiceVacio)
{
	int ret=-1;
	if(perro!=NULL && tam>0)
	{
		*indiceVacio=-1;
		for(int i=0;i<tam;i++)
		{
			if(perro[i].vacio==LIBRE)
			{
				*indiceVacio=i;
				break;
			}
		}
		ret=0;
	}
	return ret;
}
int perro_agregarPerro(ePerro* perro,int tam)
{
	int ret=-1;
	int indiceVacio;
	ePerro auxPerro;
	int indice;
	if(perro!=NULL && tam>0)
	{
		if(perro_buscarIndicelibre(perro, tam, &indiceVacio))
		{
			printf("ERROR.En el tamaño o el puntero a perro.\n");
		}
		if(indiceVacio!=-1)
		{
			if(requestNumber(&auxPerro.id, "Ingrese un id para el Perro: ", "ERROR.El Id ingresado no es valido no puede contener signos o letras y debe ser entre 7000 y 8000.\nReingrese Id del perro; ", 7000, 8000))
			{
				printf("ERROR.En el puntero a num.\n");
			}
			if(perro_buscarPerroCargado(perro, tam, &indice, auxPerro.id))
			{
				printf("ERROR.En el puntero perro ,puntero a indice o tam menor a 0.\n");
			}
			if(indice==-1)
			{
				if(requestNameOrLastName(auxPerro.nombre, "Ingrese el nombre del perro: ", "ERROR.El nombre ingresado no es valido , no debe tener signos,numeros y un maximo de 20 caracteres.\nReingrese el nombre: ", TAMCHAR))
				{
					printf("ERROR.En el puntero a string.\n");
				}
				if(requestNameOrLastName(auxPerro.raza, "Ingrese la raza del perro: ", "ERROR.La raza ingresada no es valida , no debe tener signos,numeros y un maximo de 20 caracteres.\nReingrese la raza: ", TAMCHAR))
				{
					printf("ERROR.En el puntero a string.\n");
				}
				if(requestNumber(&auxPerro.edad, "Ingrese la Edad del perro: ", "ERROR.La edad no puede contener letras ni signos un maximo de 30 años.\nReingrese Edad del perro: ", 0, 30))
				{
					printf("ERROR.En el puntero a num.\n");
				}
				auxPerro.vacio=OCUPADO;
			}
			else
			{	//mostrar el perro cargado
				printf("El id ingresado ya pertenece a un perro cargado.\n");
			}
			//mostrar auxAcargar
			if(!requestCharacterAnswer("ingrese (s) para cargar el Perro: ") && indice==-1)
			{
				perro[indiceVacio]=auxPerro;
				printf("Se a cargado el perro correctamente.\n");
			}
			else
			{
				printf("Se cancelo la carga del perro.\n");
			}

		}
		else
		{
			printf("ERROR.No es posible agregar mas perritos.\n");
		}


	}
	return ret;
}
int perro_buscarPerroCargado(ePerro* perro,int tam,int* indice,int idPerro)
{
	int ret=-1;
	if(perro!=NULL && tam>0 && indice!=NULL)
	{
		*indice=-1;
		for(int i=0;i<tam;i++)
		{
			if(perro[i].vacio==OCUPADO)
			{
				if(perro[i].id==idPerro)
				{
					*indice=i;
					break;
				}
			}
		}
		ret=0;
	}
	return ret;
}
