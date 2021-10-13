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


int estadia_ordenarPorfecha(eEstadia* estadia,int tamEstadia)
{
	int ret=-1;
	int i;
	int j;
	eEstadia auxEstadia;

	if(estadia!=NULL && tamEstadia>0)
	{
			for(i=0;i<tamEstadia-1;i++)
			{
				for(j=i+1;j<tamEstadia;j++)
				{
					if(estadia[i].vacio==OCUPADO && estadia[j].vacio==OCUPADO)
					{
						if(estadia[i].fecha.anio<estadia[j].fecha.anio)
						{
							auxEstadia=estadia[i];
							estadia[i]=estadia[j];
							estadia[j]=auxEstadia;
						}
						else
						{
							if(estadia[i].fecha.anio==estadia[j].fecha.anio)
							{
								if(estadia[i].fecha.mes<estadia[j].fecha.mes)
								{
									auxEstadia=estadia[i];
									estadia[i]=estadia[j];
									estadia[j]=auxEstadia;
								}
								else
								{
									if(estadia[i].fecha.mes==estadia[j].fecha.mes)
									{
										if(estadia[i].fecha.dia<estadia[j].fecha.dia)
										{
											auxEstadia=estadia[i];
											estadia[i]=estadia[j];
											estadia[j]=auxEstadia;
										}
										else
										{
											if(estadia[i].fecha.dia==estadia[j].fecha.dia)
											{
												if(strcmp(estadia[i].nombreDuenio,estadia[j].nombreDuenio)==1)
												{
													auxEstadia=estadia[i];
													estadia[i]=estadia[j];
													estadia[j]=auxEstadia;
												}
											}
										}
									}
								}
							}

						}
					}
				}
			}

		ret=0;
	}
	return ret;
}
int estadia_buscarEstadiaCargada(eEstadia* estadia,int tam,int* indice,int idEstadia)
{
	int ret=-1;
	if(estadia!=NULL && tam>0)
	{
		*indice=-1;
		for(int i=0;i<tam;i++)
		{
			if(estadia[i].vacio==OCUPADO)
			{
				if(idEstadia==estadia[i].id)
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
