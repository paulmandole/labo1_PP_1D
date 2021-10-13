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
	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct
{
	int id;
	char nombreDuenio[TAMSTRING];
	char telefonoContacto[10];
	int idPerro;
	eFecha fecha;
	int vacio;

}eEstadia;

/**
 * @fn int estadia_inicializarEstadiaLibre(eEstadia*, int)
 * @brief inicializa el array de estadias en vacio
 *
 * @param estadia recive un array de estadias
 * @param tam recive el tamanio del array
 * @return retorna 0 si pudo realizar su funcion bien o -1 si el puntero a eEstadia es NULL o el tam es < a 0
 */
int estadia_inicializarEstadiaLibre(eEstadia* estadia,int tam);

/**
 * @fn int estadia_buscarIndicelibre(eEstadia*, int, int*)
 * @brief busca un indice vacio en el array devuelve el indice si encuenta o -1 si no hay uno vacio
 *
 * @param estadia recive el array de estadias
 * @param tam recive el tam del array de estdias
 * @param idVacio recive un puntero al que devolver el indice vacio
 * @return retorna 0 si pudo realizar su funcion bien o -1 si el puntero a eEstadia es NULL o el tam es < a 0
 */
int estadia_buscarIndicelibre(eEstadia* estadia,int tam, int* idVacio);

/**
 * @fn int estadia_buscarEstadiaCargada(eEstadia*, int, int*, int)
 * @brief busca una estadia cargada apartir de un id y devuelve el indice, en caso de no existir devuelve -1
 *
 * @param estadia recive el array de estadias
 * @param tam recive el tam del array de estdias
 * @param indice recive un puntero al q devuelve el indice encontrado
 * @param idEstadia recive el id a buscar
 * @return retorna 0 si pudo realizar su funcion bien o -1 si el puntero a eEstadia es NULL o el tam es < a 0
 */
int estadia_buscarEstadiaCargada(eEstadia* estadia,int tam,int* indice,int idEstadia);

/**
 * @fn int estadia_ordenarPorfecha(eEstadia*, int)
 * @brief ordena el array de estadias por fecha ante igualdad de fecha por nombre
 *
 * @param estadia recive el array de estadias
 * @param tamEstadia recive el tam del array de estdias
 * @return retorna 0 si pudo realizar su funcion bien o -1 si el puntero a eEstadia es NULL o el tam es < a 0
 */
int estadia_ordenarPorfecha(eEstadia* estadia,int tamEstadia);


#endif /* ESTADIA_H_ */
