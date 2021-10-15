/*
 * nexo.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Paul
 */

#ifndef NEXO_H_
#define NEXO_H_
#include "perros.h"
#include "functions.h"
#include "estadia.h"
#include "duenio.h"

/**
 * @fn void estadia_swapEstadias(eEstadia*, int, int)
 * @brief swapea una estructura a un axiliar de estructura
 *
 * @param estadia recive el array de estadias
 * @param tamEstadia recive el tam del array de estadias
 * @param i recive el indice de la estadias a swap
 */
void estadia_swapEstadias(eEstadia* estadia,int tamEstadia,int i);
/**
 * @fn int estadia_ordenarPorfecha(eEstadia*, int)
 * @brief ordena el array de estadias por fecha ante igualdad de fecha por nombre
 *
 * @param estadia recive el array de estadias
 * @param tamEstadia recive el tam del array de estdias
 * @return retorna 0 si pudo realizar su funcion bien o -1 si el puntero a eEstadia es NULL o el tam es < a 0
 */
int estadia_ordenarPorfechaYNombre(eEstadia* estadia,int tamEstadia,eDuenio* duenio,int tamDuenio);
/**
 * @fn int estadia_reservarEstadiaConPerroCargado(eEstadia*, int, ePerro*, int, int*, int*)
 * @brief carga una estadia pidiendole datos al usuario a partir de un perro cargado
 *
 * @param estadia recive el array de estadias
 * @param tamEstadia recive el tam del array  estadias
 * @param perro recive el array de perros
 * @param tamPerro recive el tam del array de perros
 * @param ultimoId recive un puntero al ultimo id cargado
 * @param contEstadias recive un contador de la cantidad de estadias cargadas
 * @return retorna 0 si pudo realizar su funcion bien o -1 si el puntero a eperro o eEstadia es NULL o el tamEstadia y tamPerro es < a 0
 */
int estadia_reservarEstadiaConPerroCargado(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro, eDuenio* duenio,int tamDuenio, int* ultimoId,int* contEstadias);

/**
 * @fn int estadia_listarEstadiasConPerros(eEstadia*, int, ePerro*, int)
 * @brief muestra una lista de las estadias con el nombre y id del perro cargada en la misma
 *
 * @param estadia  recive el array de estadias
 * @param tamEstadia recive el tam del array  estadias
 * @param perro recive el array de perros
 * @param tamPerro recive el tam del array de perros
 * @return retorna 0 si pudo realizar su funcion bien o -1 si el puntero a eperro o eEstadia es NULL o el tamEstadia y tamPerro es < a 0
 */
int estadia_listarEstadiasConPerros(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro,eDuenio* duenio,int tamDuenio);

/**
 * @fn void estadia_listarEstadiaConPerro(eEstadia, ePerro)
 * @brief muestra una estadia con el nombre y id del perro que esta en la misma
 *
 * @param estadia una estadia
 * @param perro un perro
 */
void estadia_listarEstadiaConPerro(eEstadia estadia,ePerro perro,eDuenio duenio);

/**
 * @fn int estadia_eliminarEstadiaDePerro(eEstadia*, int, ePerro*, int, int*)
 * @brief hace una baja logica de una estadia
 *
 * @param estadia recive el array de estadias
 * @param tamEstadia recive el tam del array  estadias
 * @param perro recive el array de perros
 * @param tamPerro recive el tam del array  perros
 * @param contEstadias recive un puntero a el contador de estadias
 * @return retorna 0 si pudo realizar su funcion bien o -1 si el puntero a eperro o eEstadia es NULL o el tamEstadia y tamPerro es < a 0
 */
int estadia_eliminarEstadiaDePerro(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro,eDuenio* duenio,int tamDuenio,int* contEstadias);

/**
 * @fn int estadia_modificarEstadiaDePerro(eEstadia*, int, ePerro*, int)
 * @brief  permite modificar el  perro que se encuentra en la estadia o el telefono de contacto de la estadia
 *
 * @param estadia recive el array de estadias
 * @param tamEstadia recive el tam del array  estadias
 * @param perro recive el array de perros
 * @param tamPerro recive el tam del array  perros
 * @return retorna 0 si pudo realizar su funcion bien o -1 si el puntero a eperro o eEstadia es NULL o el tamEstadia y tamPerro es < a 0
 */
int estadia_modificarEstadiaDePerro(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro,eDuenio* duenio,int tamDuenio);

int perros_listarPerrosConSusEstadias(ePerro* perro,int tamPerro,eEstadia* estadia,int tamEstadia);
void perro_listarPerroConEstadia(ePerro perro,eEstadia estadia);
int perros_listarPerroConMasEstadias(ePerro* perro,int tamPerro,eEstadia* estadia,int tamEstadia);




#endif /* NEXO_H_ */
