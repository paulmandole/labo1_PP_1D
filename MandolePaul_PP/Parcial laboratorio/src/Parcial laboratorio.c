/*
 ============================================================================
 Name        : Parcial.c
 Author      : Paul Mandole
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "nexo.h"
#define TAMESTADIAS 5
#define TAMPERROS 5

int main(void) {
	setbuf(stdout,NULL);
	eEstadia estadia[TAMESTADIAS];
	ePerro perro[TAMPERROS]={{7000,"Lobo","Sharpie",2,OCUPADO},{7001,"Sheila","Golden",12,OCUPADO},{7002,"Reina","Galgo",13,OCUPADO}};
	int opcion;
	int ultimoId=100000;
	int contEstadias=0;

	if(estadia_inicializarEstadiaLibre(estadia, TAMESTADIAS))
	{
		printf("ERROR.En el tamaño o el puntero a estadia.\n");
	}
	if(perro_inicializarPerros(perro, TAMPERROS))
	{
		printf("ERROR.En el tamaño o el puntero a perros.\n");
	}

	do
	{

		requestNumber(&opcion,			     "-------------------------------------\n"
											 "1. RESERVAR Estadia\n"
											 "2. MODIFICAR Estadia\n"
											 "3. CANCELAR Estadia\n"
											 "4. LISTAR Estadia\n"
											 "5. LISTAR Perros\n"
											 "6. PROMEDIO de edad Perros\n"
											 "7. SALIR\n"
											 "-------------------------------------\n"
											 "Ingrese una opcion: ",
											 "-------------------------------------\n"
											 "1. RESERVAR Estadia\n"
											 "2. MODIFICAR Estadia\n"
											 "3. CANCELAR Estadia\n"
											 "4. LISTAR Estadia\n"
											 "5. LISTAR Perros\n"
											 "6. PROMEDIO de edad Perros\n"
											 "7. SALIR\n"
											 "-------------------------------------\n"
											 "Opcion invalida, reingrese: ", 1, 7);

				switch(opcion)
				{
					case 1:
						if(estadia_reservarEstadiaConPerroCargado(estadia, TAMESTADIAS, perro, TAMPERROS, &ultimoId))
						{
							printf("ERROR.En el puntero a estadia,perro o tamanios del array menor a 0.\n");
						}
						systemPause("Pulse una tecla para continuar.....");
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						if(perro_ListarPerros(perro, TAMPERROS))
						{
							printf("ERROR.En el puntero a perro o tamanio del array menor a 0.\n");
						}
						systemPause("Pulse una tecla para continuar.....");
						break;
					case 6:
						break;
					case 7:
						break;
				}

	}while(opcion!=7);

	return EXIT_SUCCESS;
}
