/*
 * perros.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Paul
 */

#ifndef PERROS_H_
#define PERROS_H_
#define TAMCHAR 21
typedef struct
{
	int id;
	char nombre[TAMCHAR];
	char raza[TAMCHAR];
	int edad;
	int vacio;
}ePerro;

int perro_inicializarPerros(ePerro* perro,int tam);
int perro_buscarIndicelibre(ePerro* perro,int tam, int* indiceVacio);
int perro_agregarPerro(ePerro* perro,int tam);
int perro_buscarPerroCargado(ePerro* perro,int tam,int* indice,int idPerro);
int perro_ListarPerros(ePerro* perro,int tam);
void perro_ListarPerro(ePerro perro);
#endif /* PERROS_H_ */
