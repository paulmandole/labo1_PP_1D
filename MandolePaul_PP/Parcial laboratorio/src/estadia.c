/*
 * estadia.c
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

int estadia_eliminarEstadia(eEstadia* estadia,int tam,int* contEstadias)
{
	int ret=-1;
	int idEstadia;
	if(estadia!=NULL && tam>0)
	{



		ret=0;
	}
	return ret;
}
int estadia_buscarIndicelibre(eEstadia* estadia,int tam, int* idVacio)
{
	int ret=-1;
	if(estadia!=NULL && tam>0)
	{
		*idVacio=-1;
		for(int i=0;i<tam;i++)
		{
			if(estadia[i].vacio==LIBRE)
			{
				*idVacio=i;
				break;
			}
		}
		ret=0;
	}
	return ret;
}

int estadia_inicializarEstadiaLibre(eEstadia* estadia,int tam)
{
	int ret=-1;
	int i;
	if(estadia!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			estadia[i].vacio=LIBRE;
		}
		ret=0;
	}
	return ret;
}
