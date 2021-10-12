/*
 * estadia.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Paul
 */

#ifndef ESTADIA_H_
#define ESTADIA_H_
#define TAMSTRING 35
#define OCUPADO 1
#define LIBRE 0
typedef struct
{
	int id;
	char nombreDuenio[TAMSTRING];
	char telefonoContacto[10];
	int idPerro;
	char fecha[10];
	int vacio;

}eEstadia;
int estadia_inicializarEstadiaLibre(eEstadia* estadia,int tam);
int estadia_buscarIndicelibre(eEstadia* estadia,int tam, int* idVacio);
int estadia_eliminarEstadia(eEstadia* estadia,int tam,int* contEstadias);
#endif /* ESTADIA_H_ */
