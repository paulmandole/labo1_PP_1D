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
#include "nexo.h"
#define TAMESTADIA 5
#define TAMPERROS 5
int main(void) {
	setbuf(stdout,NULL);
	eEstadia estadia[TAMESTADIA];
	ePerro perro[TAMPERROS]={{7000,"Lobo","Sharpie",2},{7001,"Sheila","Golden",12},{7000,"Reina","Galgo",13}};
	int opcion;

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
											 "-------------------------------------\n",
											 "Ingrese una opcion: "
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
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
					case 7:
						break;
				}

	}while(opcion!=7);

	return EXIT_SUCCESS;
}
